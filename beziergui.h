#ifndef BEZIERGUI_H
#define BEZIERGUI_H

#include <QWidget>
#include "bezier.h"
QT_BEGIN_NAMESPACE
namespace Ui { class BezierGui; }
QT_END_NAMESPACE

class BezierGui : public QWidget
{
    Q_OBJECT

public:
    BezierGui(QWidget *parent = nullptr);
    ~BezierGui();

private slots:


    void on_add_clicked();

    void on_clac_clicked();

    void on_clear_clicked();

private:
    Bezier* bezier =nullptr;
    Ui::BezierGui *ui;
};
#endif // BEZIERGUI_H
