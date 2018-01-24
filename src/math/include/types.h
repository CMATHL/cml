#ifndef CML_H
#error "Never use <math/include/types.h> directly; include <cml.h> instead."
#endif

#ifndef CML_TYPES_H
#define CML_TYPES_H

/* Quick boolean definition */
#ifdef CML_NO_STDBOOL
        #include "types/bool.h"
#else
        #include <stdbool.h>
#endif

#ifndef mint_t
        #ifdef CML_NO_STDINT
                #define mint_t int
        #else
                #include <stdint.h>
                #define mint_t int32_t
        #endif
#endif

#ifndef mfloat_t
        #include <float.h>
        #define mfloat_t float
#endif

#ifdef CML_DOUBLE_PRECISION
        #define cml_math_t double
        #define MFLOAT_T(x) x
#else
        #define cml_math_t mfloat_t
        #define MFLOAT_T(x) x ## f
#endif

#define real(X) MFLOAT_T(X)

#include "types/real.h"
#include "types/complex.h"

#ifndef creal
        #define creal(X) (X)->p[0]
#endif

#ifndef cimag
        #define cimag(X) (X)->p[1]
#endif

#endif
