#include <stdlib.h>
#include <cml.h>

_CML_EXTERN_INLINE cml_math_t
__sin__(cml_math_t x)
{
        cml_math_t ai, p;
        mint_t i;

        ai = x;
        p = ai;

        for (i = 1; i <= CML_SERIES_TOP_IT_L; ++i) {
                ai = -ai*(x)*(x)/(2*i*(2*i+1));
                p = p + ai;
        }

        return p;
}

/*
 * Computes real sine function by using Taylor Series
 *
 * @param real_t x
 * @return real_t
 */

real_t
real_sin(real_t x)
{
        /* Domain check */
        if (real_is_mult(x, (PI))) {
                return (0.0);
        }

        /* Declaration of variables and structures */
        real_t s, y, z, w, h;

        /* Mathematical algorithm */
        s = real_sgn(x); /* sin(-x) = -sin(x) */
        y = real_abs(x);
        z = real_ared(y);
        w = ((mfloat_t) __sin__(z));
        h = real_prod(w, s);

        /* Return */
        return h;
}
