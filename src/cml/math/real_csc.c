#include <stdlib.h>
#include <cml.h>

/*
 * Computes real cosecant
 *
 * @param real_t x
 * @return real_t
 */

real_t
real_csc(real_t x)
{
        /* Declaration of variables and structures */
        real_t y, h;

        /* Mathematical algorithm */
        y = real_sin(x);
        h = real_inverse(y);

        /* Return */
        return h;
}
