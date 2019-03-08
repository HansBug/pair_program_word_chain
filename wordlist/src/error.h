#ifndef ERROR_H_
#define ERROR_H_


#define ERR_FAILED_OPEN_FILE        "failed open file"
#define ERR_MISSING_OPTION_W_C      "missing option -w or -c"
#define ERR_WRONG_FORMAT_OPTION_H   "wrong format of option -h"
#define ERR_WRONG_FORMAT_OPTION_T   "wrong format of option -t"
#define ERR_NO_VALID_WORDS          "no valid english words"

void error(const char *msg);


#endif // ERROR_H_