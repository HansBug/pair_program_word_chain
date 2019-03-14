#include <QMessageBox>
#include <QFileDialog>
#include <QString>
#include <Qlabel>
#include <QTextStream>
#include <sstream>
#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),   // 初始化父类
                                          ui(new Ui::MainWindow) // 设置自身的属性
{
    ui->setupUi(this);
    statusBarLabel = new QLabel();
    statusBar()->addWidget(statusBarLabel);
    statusBarLabel->setText("准备就绪");
    
    // create an instance of CalcThread
    calcThread = new CalcThread(this);
    // connect signal/slot
    connect(calcThread, SIGNAL(calcFinished(const QString&)),
            this, SLOT(onCalcFinished(const QString&)));
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
    if (filename.isEmpty()) {
        // user cancelled selecting files
        return;
    }
    QFile file(filename);
    if (!file.open(QFile::ReadOnly | QFile::Text)) {
        // TODO:
        QMessageBox::warning(this, "文件打开失败", "你选择的文件不存在或者拒绝访问");
        return;
    }
    QTextStream in(&file);
    QString input = in.readAll();
    if (input.isEmpty()) {
        QMessageBox::warning(this, "文件读取失败", "你选择的是空文件或者拒绝读取内容");
    }
    ui->inputTextEdit->setPlainText(input);
}

void MainWindow::on_calcButton_clicked()
{
    if (calcThread->isRunning()) {
        QMessageBox::information(this, NULL, "计算正在进行中，请等待计算完成");
        return;
    }

    // here is all the parameters
    bool flag_w = ui->flag_w->isChecked();
    bool flag_c = ui->flag_c->isChecked();
    char flag_h = ui->flag_h->currentIndex();
    if (flag_h != 0) {
        flag_h = flag_h - 1 + 'a';
    }
    char flag_t = ui->flag_t->currentIndex();
    if (flag_t != 0) {
        flag_t = flag_t - 1 + 'a';
    }
    bool flag_r = ui->flag_r->isChecked();

    // Maybe you can comment below codes
    std::stringstream ss;
    ss << "参数：\n"
        << "flag_w:" << flag_w << " flag_c:" << flag_c 
        << " flag_h:" << flag_h << " flag_t:" << flag_t
        << " flag_r:" << flag_r << std::endl << std::endl
        << "点击 Yes 开始计算";
    if (QMessageBox::question(this, "参数确认？", QString::fromStdString(ss.str()),
            QMessageBox::Yes|QMessageBox::Cancel) != QMessageBox::Yes) {
        return;
    }

    calcThread->setFlags(flag_w, flag_c, flag_h, flag_t, flag_r);
    calcThread->setQStringWords(ui->inputTextEdit->toPlainText());
    calcThread->start();

    statusBarLabel->setText("正在计算... ...");
    ui->calcButton->setText("(●'◡'●)");
}

void MainWindow::on_clearButton_clicked()
{
    ui->resultTextEdit->clear();
    statusBar()->showMessage("结果已清空", 2000);
    statusBarLabel->setText("准备就绪");
}

void MainWindow::on_saveButton_clicked()
{
    QString filename = QFileDialog::getSaveFileName(this, 
        NULL,  "solution.txt", "Text files (*.txt)");
    if (filename.isEmpty()) {
        // User cancelled selecting file
        return;
    }
    QFile qFile(filename);
    if (!qFile.open(QIODevice::WriteOnly)) {
        QMessageBox::warning(this, "文件打开失败", "你选择的文件拒绝访问");
        return;
    }
    QTextStream stream(&qFile); 
    stream << ui->resultTextEdit->toPlainText();
    qFile.close();
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
    ui->calcButton->setText("开始计算");
}