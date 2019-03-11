#define DLL_EXPORTS // put this before #include "core.h"
#include "core.h"
#include <iostream>

//############# Write Your Code below ###############








// Write your code here








//############# Write Your Code above ###############

EXPORT int TEST_LIB_PLUS(int a, int b)
{
    return a + b;
}

EXPORT int gen_chain_word(char *words[], int len, char *result[],
                          char head, char tail, bool enable_loop)
{
    for (int i = 0; i < len / 2; i++) {
        result[i] = words[i];
    }
    return len / 2;
}

EXPORT int gen_chain_char(char *words[], int len, char *result[],
                          char head, char tail, bool enable_loop)
{
    for (int i = 0; i < len / 2; i++) {
        result[i] = words[i];
    }
    return len / 2;
}