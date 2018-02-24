#ifndef CML_H
#error "Never use <cml/default.h> directly; include <cml.h> instead."
#endif

#ifndef CML_DEFAULT_H
#define CML_DEFAULT_H

/* Check C standard */
#ifdef __STDC__
        #define PREDEF_STANDARD_C89
        #ifdef __STDC_VERSION__
                #if __STDC_VERSION__ >= 199901L
                        #define PREDEF_STANDARD_C99
                        #if __STDC_VERSION__ >= 201112L
                                #define PREDEF_STANDARD_C11
                        #endif
                #endif
        #endif
#endif

#define __CML_BEGIN_DECLS
#define __CML_END_DECLS

#ifdef __cplusplus
        #undef __CML_BEGIN_DECLS
        #undef __CML_END_DECLS

        #define __CML_BEGIN_DECLS extern "C" {
        #define __CML_END_DECLS }

        #if __cplusplus >= 199901L
                #define PREDEF_STANDARD_CPP99
                #if __cplusplus >= 201112L
                        #define PREDEF_STANDARD_CPP11
                #endif
        #endif
#endif

#ifndef PREDEF_STANDARD_C11
        #undef __CML_NO_GENERIC
        #define __CML_NO_GENERIC
#endif

#define __CML_ARGS_FIRST(A, ...) A

#ifndef __CML_TYPE
        #define __CML_TYPE(__e, __t) \
        __builtin_types_compatible_p(__typeof(__e), __t)
#endif

#ifndef __CML_SAME_TYPE
        #define __CML_SAME_TYPE(__a, __b) \
        __builtin_types_compatible_p(__typeof(__a), __typeof(__b))
#endif

#endif
