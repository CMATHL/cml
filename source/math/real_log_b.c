#include <stdlib.h>
#include "include/math.h"


/*
 * The logarithm logb(x) can be computed from the logarithms of x and b with respect to an arbitrary base k using the following formula:
 * log_b{x} = log_k{x} / log_k(b)
 *
 * @param real x
 *
 * @return real log_b(x)
 */

real
real_log_b(real x, real b)
{
        // Declaration of structures
        real y, z, w;

        // Mathematical algorithm
        y = x->ln(x);
        z = b->ln(b);
        w = y->div(y, z);

        // Free structures
        free(y);
        free(z);

        // Return
        return w;

}
