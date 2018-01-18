#include <stdlib.h>
#include <cml.h>

/*
 * cos(x) function developed by using Taylor Series
 *
 * @param real x
 *
 * @return real cos(x)
 */

real
real_cos(real x)
{
        // Declaration of structures
        real half_pi, y, z, h;

        // Mathematical algorithm
        half_pi = real_new(HALFPI);
        y = real_abs(x);
        z = real_add(y, half_pi);
        h = real_sin(z);

        // Free structures
        free(half_pi);
        free(y);
        free(z);

        // Return
        return h;
}
