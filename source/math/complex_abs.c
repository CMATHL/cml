#include <stdlib.h>
#include "include/math.h"

real
complex_abs(complex z)
{
        // Declaration of structures
        real *x;
        real n, a, b, w, h;


        // Mathematical algorithm
        x = complex_get_parts(z);
        n = real_new(2.0);
        a = real_pow(x[0], n);
        b = real_pow(x[1], n);
        w = real_add(a, b);
        h = real_sqrt(w);

        // Free structures
        free(x);
        free(n);
        free(a);
        free(b);
        free(w);

        // Return
        return h;
}
