#include <stdlib.h>
#include "include/math.h"


CML_EXTERN_INLINE bool
__ismult(double x, double y)
{
        double z = x/y;
        int z_int = (int) z;
        return ((z - z_int) == 0);
}

bool
real_ismult(real x, real y)
{
        return __ismult(x->value(x), y->value(y));
}
