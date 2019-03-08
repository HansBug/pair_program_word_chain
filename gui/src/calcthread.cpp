#include "calcthread.h"
#include <QDebug>


CalcThread::CalcThread(QObject *parent, bool b) :
    QThread(parent), Stop(b)
{
}

// run() will be called when a thread starts
void CalcThread::run()
{
    
    this->msleep(5000);
    emit calcFinished("This is a sample output");

    // for(int i = 0; i <= 100; i++)
    // {
    //     QMutex mutex;
    //     // prevent other threads from changing the "Stop" value
    //     mutex.lock();
    //     if(this->Stop) break;
    //     mutex.unlock();

    //     // emit the signal for the count label
    //     emit calcFinish("This is a");

    //     // slowdown the count change, msec
    //     this->msleep(500);
    // }
}