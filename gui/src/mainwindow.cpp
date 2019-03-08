#include <QMessageBox>
#include <QFileDialog>
#include <QString>
#include <Qlabel>
#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),   // 初始化父类
                                          ui(new Ui::MainWindow) // 设置自身的属性
{
    ui->setupUi(this);
    statusBarLabel = new QLabel();
    statusBar()->addWidget(statusBarLabel);
    statusBarLabel->setText("准备就绪");
}

MainWindow::~MainWindow()
{
    delete ui;
    delete calcThread;
    delete statusBarLabel;
}

void MainWindow::on_loadButton_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this,
        NULL, NULL, "Text files (*.txt);; *.*");
    if (!filename.isEmpty()) {
        QMessageBox::information(this, "", filename);
    }
}

void MainWindow::on_calcButton_clicked()
{
    // create an instance of MyThread
    calcThread = new CalcThread(this);

    // connect signal/slot
    connect(calcThread, SIGNAL(calcFinished(const QString&)),
            this, SLOT(onCalcFinished(const QString&)));

    calcThread->start();

    statusBarLabel->setText("正在计算...");
}

void MainWindow::on_saveButton_clicked()
{
    QString filename = QFileDialog::getSaveFileName(this, 
        NULL,  "result.txt", "Text files (*.txt)");
    if (!filename.isEmpty()) {
        QMessageBox::information(this, NULL, filename);
    }
}

void MainWindow::on_inputTextEdit_textChanged()
{
    if (!calcThread->isRunning()) {
        statusBarLabel->setText("准备就绪");
    }
}

void MainWindow::onCalcFinished(const QString &result)
{
    ui->resultTextEdit->setPlainText(result);
    statusBarLabel->setText("计算完毕, 耗时5s");
}