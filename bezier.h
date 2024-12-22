#ifndef BEZIER_H
#define BEZIER_H

#include <QWidget>
#include <QWidget>
#include <QPainter>
#include <QMouseEvent>
#include <QKeyEvent>
#include <QLineEdit>
#include <QLabel>
#include <QVBoxLayout>
#include <QPushButton>
#include <QPointF>
#include <vector>
#include <cmath>

QT_BEGIN_NAMESPACE
namespace Ui { class Bezier; }
QT_END_NAMESPACE

class Bezier : public QWidget
{
    Q_OBJECT

public:
    Bezier(QWidget *parent = nullptr);
    ~Bezier();

    void paintEvent(QPaintEvent* event) override;
    void mousePressEvent(QMouseEvent* event) override;
    void mouseMoveEvent(QMouseEvent* event) override;
    void mouseReleaseEvent(QMouseEvent* event) override;
    void keyPressEvent(QKeyEvent* event) override;
    float calculateBezierY(float t); // 计算贝塞尔曲线的纵坐标
    std::vector<QPointF> controlPoints; // 控制点
    QPolygonF bezierPoints;

    // 根据t计算贝塞尔曲线的x和y
    QPointF calculateBezierPoint(float t) {
        int n = controlPoints.size() - 1;
        float x = 0.0f;
        float y = 0.0f;
        for (int i = 0; i <= n; ++i) {
            float binomialCoefficient = std::tgamma(n + 1) / (std::tgamma(i + 1) * std::tgamma(n - i + 1));
            float basis = binomialCoefficient * std::pow(1 - t, n - i) * std::pow(t, i);
            x += basis * controlPoints[i].x();
            y += basis * controlPoints[i].y();
        }
        return QPointF(x, y);
    }

    // 根据给定的x值来逼近对应的y值（使用二分法查找t）
    float findTForX(float x, int numPoints = 100) {
        float t0 = 0.0f, t1 = 1.0f;
        float tolerance = 1e-5;

        while (t1 - t0 > tolerance) {
            float t_mid = (t0 + t1) / 2.0f;
            QPointF point = calculateBezierPoint(t_mid);
            float x_mid = point.x();

            if (x_mid < x) {
                t0 = t_mid;  // 如果中点的x值小于目标x，说明t值应该更大
            }
            else {
                t1 = t_mid;  // 如果中点的x值大于目标x，说明t值应该更小
            }
        }

        return (t0 + t1) / 2.0f;  // 返回逼近的t值
    }

    // 根据x值找到对应的y值
    float getYForX(float x) {
        float t = findTForX(x);
        QPointF point = calculateBezierPoint(t);
        return point.y();
    }

private:
   
    QPointF hoveredPoint;  // 鼠标靠近的贝塞尔曲线点
    QPoint mousePos;       // 鼠标当前位置
   
    QPointF selectedPoint; // 被选中的控制点
    bool isDragging = false; // 是否正在拖动
    
    void drawBezierCurve(QPainter& painter); // 绘制贝塞尔曲线
    void drawControlPoints(QPainter& painter); // 绘制控制点
    void updateUI(); // 更新UI显示坐标信息

private:
    Ui::Bezier *ui;
};
#endif // BEZIERGUI_H
