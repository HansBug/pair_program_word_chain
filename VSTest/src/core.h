// core.h
#ifndef CORE_H_
#define CORE_H_

//############# Write Your Code below ###############
#define NO_START_CHAR       (0)  // use this when start char is not necessary
#define NO_END_CHAR         (0)  // use this when end char is not necessary

#define NO_SOLUTION_FOUND   (-10)  // no solution found (only possible when both start and end char are limited
#define NOT_IMPLEMENT       (-11)  // function not implement yet

// This is all the possible return value for exported dll function
#define CORE_WORDS_HAS_CIRCLE        (-1)
#define CORE_WORDS_HAS_EMPTY         (-2)
#define CORE_WORDS_HAS_INVALID       (-3)
#define CORE_NO_WORD_CHAIN           (-4)  // no word chain
#define CORE_NO_MATCHED_WORD_CHAIN   (-10) // we found word chains, but they don't match start or end characters.

// Write your code here

//############# Write Your Code above ###############




int TEST_LIB_PLUS(int a, int b);

int gen_chain_word(char *words[], int len, char *result[],
                          char head, char tail, bool enable_loop);

int gen_chain_char(char *words[], int len, char *result[],
                          char head, char tail, bool enable_loop);



#endif // CORE_H_