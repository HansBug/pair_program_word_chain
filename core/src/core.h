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

// for C++ code using C style function
#ifdef __cplusplus    // If used by C++ code, 
extern "C" {          // we need to export the C interface
#endif

// Source: http://programmingexamples.wikidot.com/blog:1
#ifdef NO_DLL
#define EXPORT
#elif defined(DLL_EXPORTS)   // we define DLL_EXPORTS in core.cpp when we create DLL
#define EXPORT  __declspec(dllexport)   // export DLL information
#else                // we didn't define DLL_EXPORTS when we use this DLL
#define EXPORT  __declspec(dllimport)   // import DLL information
#endif


EXPORT int TEST_LIB_PLUS(int a, int b);

EXPORT int gen_chain_word(char *words[], int len, char *result[],
                          char head, char tail, bool enable_loop);

EXPORT int gen_chain_char(char *words[], int len, char *result[],
                          char head, char tail, bool enable_loop);

// for C++ code using C style function
#ifdef __cplusplus
}
#endif


#endif // CORE_H_