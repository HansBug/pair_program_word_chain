#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include "calcthread.h"

namespace Ui
{
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

  public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

  public slots:
    // 计算完毕后，接收计算的答案
    void onCalcFinished(const QString &string);

  private slots:
    void on_loadButton_clicked();
    void on_calcButton_clicked();
    void on_saveButton_clicked();
    void on_inputTextEdit_textChanged();

  private:
    Ui::MainWindow *ui;
    CalcThread *calcThread;
    QLabel *statusBarLabel;
};

#endif // MAINWINDOW_H