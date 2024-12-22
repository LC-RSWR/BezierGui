#include "beziergui.h"
#include "ui_beziergui.h"

BezierGui::BezierGui(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::BezierGui)
{
    ui->setupUi(this);
    bezier = new Bezier(this);
    ui->verticalLayout_2->addWidget(bezier);
}

BezierGui::~BezierGui()
{
    delete ui;
}




void BezierGui::on_add_clicked()
{
    if (!ui->lineEdit->text().isEmpty() && !ui->lineEdit_2->text().isEmpty()) {
        float x = ui->lineEdit->text().toFloat();
        float y = ui->lineEdit_2->text().toFloat();

        bezier->controlPoints.push_back(QPointF(x, y));
    }
    else {
        // 输入框为空时的处理（可以加上提示）
    }
    update();
   
}

void BezierGui::on_clac_clicked()
{
    bool ok;
    float x = ui->lineEdit->text().toFloat(&ok);
    if (ok) {

       
        float y = bezier->getYForX(x);
        ui->lineEdit_2->setText(QString::number(y));
    }
    update();
}

void BezierGui::on_clear_clicked()
{
   
    bezier->controlPoints.clear();
    bezier->bezierPoints.clear();
    update();
}
