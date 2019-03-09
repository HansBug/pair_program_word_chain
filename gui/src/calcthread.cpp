#include "calcthread.h"
#include <QDebug>
#include "../core/core.h" // change this is necessary 

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
    // maybe you can convert `QString words` to `vector<string> words`

    // copy words instead of using reference

    this->words = words;
}

// run() will be called when a thread starts
void CalcThread::run()
{
    // After calling setWords() and setFlags(), 
    // we have all we need to calculate
    
    // You can use these variables below
    // QString words;
    // bool flag_w, flag_c, flag_r;
    // char flag_h, flag_t;

    // convert QString to char*words[]


    // An example for calling functions in lib
    // char *result[1000];  // an array of size 1000, content is char*
    // int len = gen_chain_word(char *words[], int len, char *result[],
    //                          char head, char tail, bool enable_loop);
    
    // // convert to QString
    // QString output;
    // QTextStream stream(&output);
    // for (int i = 0; i < len; i++) {
    //     stream << result[i] << std::endl;
    // }
    
    this->msleep(5000);
    emit calcFinished(QString("Processed output:") + this->words);
}