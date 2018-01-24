#include <stdlib.h>
#include <cml.h>

_CML_EXTERN_INLINE cml_math_t
__atan__(cml_math_t x)
{
        mint_t i;
        cml_math_t ai_n = x,
                   p = ai_n;

        for (i = 1; i <= CML_SERIES_TOP_IT_L; i += 2) {
                ai_n = -ai_n*x*x;
                p += ai_n/((cml_math_t) i + 2.0);
        }

        return p;
}


real_t
real_atan(real_t x)
{
        /* Domain check */
        real_t a;
        // real_t u;
        a = real_abs(x);
        // u = MFLOAT_T(1.0);

        /*
           if (real_isgreater_or_equals(a, u)) {
                free(a);
                free(u);
                return real_new(NAN);
           }
         */


        /* Declaration of variables and structures */
        real_t s, w;

        /* Mathematical algorithm */
        s = real_sgn(x);
        w = real_prod(s, __atan__(a));

        /* Return */
        return w;
}
