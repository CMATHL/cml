#include <stdlib.h>
#include "include/math.h"

/*
 * Log(z) = ln|z| + i*arg(z)
 */

complex
complex_log(complex z)
{
        // Declaration of structures
        complex w;
        real a, x, y;

        // Mathematic algorithm
        a = complex_abs(z);
        x = real_ln(a);
        y = complex_arg(z);
        w = complex_new(x, y);

        // Free structures
        free(a);
        free(x);
        free(y);

        // Return
        return w;
}
