#include "mainwidget.h"
#include "ui_mainwidget.h"
#include <QDebug>

MainWidget::MainWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWidget)
{
    ui->setupUi(this);

    func_defines();
    func_platform();
    func_debug_or_release();
    func_bits();
}

MainWidget::~MainWidget()
{
    delete ui;
}

void MainWidget::func_defines()
{
#ifdef CustomWinMingw
    qDebug() << "Enviroment config: " << "Windows Mingw";
#endif

#ifdef CustomWinVS
    qDebug() << "Enviroment config: " << "Windows VS";
#endif

#ifdef CustomLinuxX86_64
    qDebug() << "Enviroment config: " << "Linux X86_64";
#endif

#ifdef CustomLinuxArm
    qDebug() << "Enviroment config: " << "Linux Arm";
#endif
}

void MainWidget::func_platform()
{
#if ((defined Q_OS_WIN) && (defined Q_CC_GNU))
    qDebug() << "func_platform: " << "Windows Mingw";
#endif

#if ((defined Q_OS_WIN) && (!defined Q_CC_GNU))
    qDebug() << "func_platform: " << "Windows VS";
#endif

#if ((defined Q_OS_LINUX) && (defined Q_PROCESSOR_X86))
    qDebug() << "func_platform: " << "Linux X86_64";
#endif

#if ((defined Q_OS_LINUX) && (defined Q_PROCESSOR_ARM))
    qDebug() << "func_platform: " << "Linux Arm";
#endif
}

void MainWidget::func_debug_or_release()
{
#ifdef QT_DEBUG
    qDebug() << "func_debug_or_release: debug version.";
#endif

#ifdef QT_NO_DEBUG
    qDebug() << "func_debug_or_release: release version.";
#endif
}

void MainWidget::func_bits()
{
#ifdef __x86_64__
    qDebug() << "func_bits: 64.";
#endif

#ifdef __i386__
    qDebug() << "func_bits: 32.";
#endif
}
