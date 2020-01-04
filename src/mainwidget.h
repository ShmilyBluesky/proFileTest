#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>

namespace Ui {
class MainWidget;
}

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MainWidget(QWidget *parent = nullptr);
    ~MainWidget();

private:
    void func_defines();
    void func_platform();
    void func_debug_or_release();
    void func_bits();

    void test_define();

private:
    Ui::MainWidget *ui;
};

#endif // MAINWIDGET_H
