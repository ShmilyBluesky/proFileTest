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
    test_define();
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

void MainWidget::test_define()
{
#ifdef PLATFORM_ARM_ZLG
    qDebug() << "global define: " << "PLATFORM_ARM_ZLG";
#endif
#ifdef PLATFORM_ARM_TOPEET
    qDebug() << "global define: " << "PLATFORM_ARM_TOPEET";
#endif
#ifdef PLATFORM_WIN_MINGW
    qDebug() << "global define: " << "PLATFORM_WIN_MINGW";
#endif
#ifdef PLATFORM_WIN_VS
    qDebug() << "global define: " << "PLATFORM_WIN_VS";
#endif


#ifdef GLOBALDEFINE_PLATFORM_ARM_ZLG
    qDebug() << "global define: " << "GLOBALDEFINE_PLATFORM_ARM_ZLG";
#endif
#ifdef GLOBALDEFINE_PLATFORM_ARM_TOPEET
    qDebug() << "global define: " << "GLOBALDEFINE_PLATFORM_ARM_TOPEET";
#endif
#ifdef GLOBALDEFINE_PLATFORM_WIN_MINGW
    qDebug() << "global define: " << "GLOBALDEFINE_PLATFORM_WIN_MINGW";
#endif
#ifdef GLOBALDEFINE_PLATFORM_WIN_VS
    qDebug() << "global define: " << "GLOBALDEFINE_PLATFORM_WIN_VS";
#endif
}
