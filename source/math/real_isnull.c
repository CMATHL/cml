#include <stdlib.h>
#include "includes/cml.h"


CML_EXTERN_INLINE bool
__isnull(double x)
{
        return x == 0.0;
}

bool
real_isnull(real x)
{
        return __isnull(x->value(x));
}
