#include "calcthread.h"
#include <QDebug>
#include <unordered_set>
#include <sstream>
#include <iostream>
#include <cstdio>
#include "../core/src/core.h" // change this is necessary 

#define MAX_WORDS_NUM 10001
#define ERR_WORDS_NUM_EXCEEDED  (-1)

/**
 * Convert QString to char* words[]
 * 
 * If success, return a interger >= 0;
 * If error, return  ERR_WORDS_NUM_EXCEEDED < 0.
 */
int QString2words(QString str_words, char *words[])
{
    char ch;
    bool empty = true;   
    std::stringstream word;
    std::unordered_set<std::string> words_set;

    // read char by char
    for (QChar qchar : str_words) {
        ch = qchar.toLatin1();
        if (std::isalpha(ch)) {
            word << (char)std::tolower(ch);
            empty = false;
        } else if (!empty) {
            words_set.insert(word.str());
            word.str("");
            empty = true;
        }
    }

    if (!empty) {
        words_set.insert(word.str());
    }
    
    int count = 0;
    for (std::string word : words_set) {
        //https://stackoverflow.com/questions/13294067/how-to-convert-string-to-char-array-in-c
        // TODO: find a better way to handle memory leak here !!!
        char * w = new char [word.length()+1];
        strcpy(w, word.c_str());
        assert(*(w + word.length()) == '\0');
        if (count >= MAX_WORDS_NUM) {
            return ERR_WORDS_NUM_EXCEEDED;
        }
        words[count++] = w;
    }
    
    return count;
}

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

void CalcThread::setQStringWords(const QString &words)
{
    // maybe you can convert `QString words` to `vector<string> words`

    // copy words instead of using reference

    this->str_words = words;
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

    // Step 1: convert QString to required data structure
    char *words[MAX_WORDS_NUM];
    int words_count = QString2words(str_words, words);
    if (words_count == ERR_WORDS_NUM_EXCEEDED) {
        emit calcFinished("error: number of words exceeded the limit of 10001");
        return;
    }

    std::cout << "words count: " << words_count << std::endl;
    std::cout << "good";

    // Step 2: calling functions in
    char* result[MAX_WORDS_NUM];
    int result_count;  // result is words count if success, else error code.
    if (!(flag_c ^ flag_w)) {
        std::cout << "impossible";
    }
    
    printf("w:%d, c:%d, h:%c(ascii: %d), t:%c(ascii: %d), r:%d\n", 
        flag_w, flag_c, flag_h, flag_h, flag_t, flag_t, flag_r);
    if (flag_c) {
        result_count = gen_chain_char(words, words_count, result, flag_h, flag_t, flag_r);
    } else { // params.flag_w
        result_count = gen_chain_word(words, words_count, result, flag_h, flag_t, flag_r);
    }

    std::cout << "good";

    // Step 3: check errors
    if (result_count <= 0) {
        switch (result_count)
        {
            case CORE_WORDS_HAS_CIRCLE:
                emit calcFinished(QString("error: unexpected circle in words"));
                return;
            case CORE_NO_WORD_CHAIN:
                emit calcFinished(QString("error: can't find a word chain"));
                return;
            case CORE_NO_MATCHED_WORD_CHAIN:
                emit calcFinished(QString("error: can't find a word chain that matches the given head or tail character"));
                return;
            case CORE_WORDS_HAS_EMPTY:
                emit calcFinished(QString("error: no valid english words"));
                return;
            case CORE_WORDS_HAS_INVALID:
                emit calcFinished(QString("unexpected error: words have invalid character"));
                return;
            default:
                emit calcFinished(QString("unexpected error: unknown code ") + QString::number(result_count));
                return;
        }
    }

    std::cout << "good";

    // Step 4: convert char* word[] to QString
    QString res;
    for (int i = 0; i < result_count; i++) {
        res.append(result[i]);
        res.append('\n');
    }

    std::cout << "good";

    // Step 5: return the result
    emit calcFinished(res);
}
