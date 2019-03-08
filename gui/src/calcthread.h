// calcthread.h
#ifndef CALCTHREAD_H_
#define CALCTHREAD_H_

#include <QThread>

class CalcThread : public QThread
{
    Q_OBJECT
public:
    explicit CalcThread(QObject *parent = 0, bool b = false);
    void run();

    // if Stop = true, the thread will break
    // out of the loop, and will be disposed
    bool Stop;

signals:
    // To communicate with Gui Thread
    // we need to emit a signal
    void calcFinished(const QString &result);

public slots:
    
};

#endif // CALCTHREAD_H_