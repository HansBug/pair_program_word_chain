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

    // call this before calling start()
    void setFlags(bool flag_w, bool flag_c, char flag_h, char flag_t, bool flag_r);
    // call this before calling start()
    void setWords(const QString &words);

    // if Stop = true, the thread will break
    // out of the loop, and will be disposed
    bool Stop;

signals:
    // To communicate with Gui Thread
    // we need to emit a signal
    void calcFinished(const QString &result);

public slots:
    
private:
    bool flag_w;
    bool flag_c;
    char flag_h;
    char flag_t;
    bool flag_r;
    QString words;
};

#endif // CALCTHREAD_H_