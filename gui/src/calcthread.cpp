#include "calcthread.h"
#include <QDebug>


CalcThread::CalcThread(QObject *parent, bool b) :
    QThread(parent), Stop(b)
{
}

void CalcThread::setFlags(bool flag_w, bool flag_c, char flag_h, char flag_t, bool flag_r)
{
    this->flag_w = flag_w;
    this->flag_c = flag_c;
    this->flag_h = flag_h;
    this->flag_t = flag_t;
    this->flag_r = flag_r;
}

void CalcThread::setWords(const QString &words)
{
    // copy words instead of using reference
    this->words = words;
}

// run() will be called when a thread starts
void CalcThread::run()
{

    // Write your code here
    
    this->msleep(5000);
    emit calcFinished(QString("Processed Result:\n") + words);
}