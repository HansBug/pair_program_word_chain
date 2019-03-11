// core.h
#ifndef CORE_H_
#define CORE_H_

//############# Write Your Code below ###############






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