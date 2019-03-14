#ifndef ERROR_H_
#define ERROR_H_


#define ERR_FAILED_OPEN_FILE        "failed open file"
#define ERR_MISSING_OPTION_W_C      "missing option -w or -c"
#define ERR_DUPLICATE_OPTION_W_C    "duplicate option -w or -c"
#define ERR_WRONG_FORMAT_OPTION_H   "wrong format of option -h"
#define ERR_WRONG_FORMAT_OPTION_T   "wrong format of option -t"
#define ERR_NO_VALID_WORDS          "no valid english words"
#define ERR_UNEXPECTED_CIRCLE_IN_WORDS "given words have unexpected circle"
#define ERR_NO_WORD_CHAIN           "can't find a word chain"
#define ERR_NO_MATCHED_WORD_CHAIN     "no word chain matches given head or tail character"
#define ERR_WORDS_NUM_EXCEEDED   "number of words exceeded"

void error(const char *msg);


#endif // ERROR_H_