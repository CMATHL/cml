#ifndef CML_H
#define CML_H

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

#ifdef __cplusplus
        #ifdef __cplusplus
                #if __cplusplus >= 199901L
                        #define PREDEF_STANDARD_CPP99
                        #if __cplusplus >= 201112L
                                #define PREDEF_STANDARD_CPP11
                        #endif
                #endif
        #endif
#endif

#ifdef _MSC_VER
        #define _CML_INLINE __forceinline
#else
        #define _CML_INLINE inline __attribute__((always_inline))
#endif

#include "config.h"

/* Use `extern inline` for C99 or later */
#ifdef PREDEF_STANDARD_C99
        #define _CML_EXTERN_INLINE extern _CML_INLINE
#else
        #undef _CML_EXTERN_INLINE
        #undef CML_SINGLE_PRECISION
        #undef mfloat_t

        #define _CML_EXTERN_INLINE
        #define mfloat_t double
#endif

#ifndef PREDEF_STANDARD_C11
        #undef _CML_NO_GENERIC
        #define _CML_NO_GENERIC
#endif

#define _CML_ARGS_FIRST(A, ...) A

#ifndef __type
#define __type(__e, __t)                                                \
        __builtin_types_compatible_p(__typeof(__e), __t)
#endif

#ifndef __same_type
        #define __same_type(__a, __b) \
        __builtin_types_compatible_p(__typeof(__a), __typeof(__b))
#endif

#include "cml/include/math.h"

/*
 #ifndef CML_NO_STRUCTURES
 #include "cml/include/structures.h"
 #endif
 */

#ifndef CML_NO_EASING_FUNCTIONS
        #include "cml/include/easings.h"
#endif

#endif
