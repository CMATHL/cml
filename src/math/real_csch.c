#include <stdlib.h>
#include <cml.h>

/*
 * "csch(x)" function developed by using Euler relationships
 *
 * @param real x
 *
 * @return real csch(x)
 */

real
real_csch(real x)
{
        /* Domain check */

        /* Declaration of variables and structures */
        real y, h;

        /* Mathematical algorithm */
        y = real_sinh(x);
        h = real_inverse(y);

        /* Free structures */
        free(y);

        /* Return */
        return h;
}
