#include <stdlib.h>
#include "include/math.h"

real
real_prod(real x, real y)
{
        double k, w;
        k = x->value(x);
        w = y->value(y);
        return real_new((double) k*w);
}
