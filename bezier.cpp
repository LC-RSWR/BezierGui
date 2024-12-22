#include "bezier.h"
#include "ui_bezier.h"

Bezier::Bezier(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Bezier)
{
    ui->setupUi(this);
    setMouseTracking(true);
}

Bezier::~Bezier()
{
    delete ui;
}


void Bezier::paintEvent(QPaintEvent* event)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    drawBezierCurve(painter);
    drawControlPoints(painter);

    // 绘制鼠标靠近的贝塞尔点和坐标
    if (!hoveredPoint.isNull()) {
        painter.setPen(QPen(Qt::red));
        painter.setBrush(QBrush(Qt::red));
        painter.drawEllipse(hoveredPoint, 6, 6);  // 绘制红色圆圈标记

        // 绘制贝塞尔点坐标
        painter.setPen(QPen(Qt::black));
        painter.drawText(hoveredPoint + QPointF(10, -10), QString("(%1, %2)").arg(hoveredPoint.x()).arg(hoveredPoint.y()));
    }
}

void Bezier::mousePressEvent(QMouseEvent* event)
{
    QPointF clickedPos = event->pos();

    // 检查是否点击了某个控制点
    for (auto& point : controlPoints) {
        if (QLineF(clickedPos, point).length() < 20) {
            selectedPoint = point;
            isDragging = true;
            return;
        }
    }

    // 如果没点击控制点，则添加新控制点
    controlPoints.push_back(clickedPos);
    update();
}

void Bezier::mouseMoveEvent(QMouseEvent* event)
{
    if (isDragging) {
        selectedPoint = event->pos();
        // 更新被选中的控制点的位置
        for (auto& point : controlPoints) {
            if (QLineF(selectedPoint, point).length() < 20) {
                point = selectedPoint;
                break;
            }
        }
        update();
    }

    mousePos = event->pos();  // 获取鼠标当前位置

    // 检测鼠标是否靠近贝塞尔曲线上的某个点
    hoveredPoint = QPointF();
    for (auto& it : bezierPoints) {
        QPointF bezierPoint = it;
        if (QLineF(mousePos, bezierPoint).length() < 10) {  // 如果鼠标接近贝塞尔点
            hoveredPoint = bezierPoint;
            break;
        }
    }

    update();  // 触发重新绘制
}

void Bezier::mouseReleaseEvent(QMouseEvent* event)
{
    isDragging = false;
}

void Bezier::keyPressEvent(QKeyEvent* event)
{
  
}

float Bezier::calculateBezierY(float t)
{
    int n = controlPoints.size() - 1;
    float y = 0.0f;

    // 使用贝塞尔曲线公式
    for (int i = 0; i <= n; ++i) {
        float binomialCoefficient = std::tgamma(n + 1) / (std::tgamma(i + 1) * std::tgamma(n - i + 1));
        float term = binomialCoefficient * std::pow(1 - t, n - i) * std::pow(t, i);
        y += term * controlPoints[i].y();
    }

    return y;
}

void Bezier::drawBezierCurve(QPainter& painter)
{
    if (controlPoints.size() < 2) return;

    bezierPoints.clear();
    int numPoints = 100;
    for (int i = 0; i <= numPoints; ++i) {
        float t = float(i) / numPoints;
        float x = 0.0f;
        for (int j = 0; j < controlPoints.size(); ++j) {
            float binomialCoefficient = std::tgamma(controlPoints.size()) /
                (std::tgamma(j + 1) * std::tgamma(controlPoints.size() - j));
            x += binomialCoefficient * std::pow(1 - t, controlPoints.size() - 1 - j) *
                std::pow(t, j) * controlPoints[j].x();
        }

        float y = calculateBezierY(t);
        bezierPoints.append(QPointF(x, y));
    }

    painter.setPen(QPen(Qt::blue, 2));
    painter.drawPolyline(bezierPoints);
}

void Bezier::drawControlPoints(QPainter& painter)
{
    painter.setPen(QPen(Qt::red, 5));
    for (const auto& point : controlPoints) {
        painter.drawPoint(point);
    }
}

void Bezier::updateUI()
{
    // 根据当前控制点坐标更新UI
    // 例如：可以显示控制点坐标或者贝塞尔曲线上的点
}

