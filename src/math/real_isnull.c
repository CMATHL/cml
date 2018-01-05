#include <stdlib.h>
#include <cml.h>


CML_EXTERN_INLINE bool
__isnull(cml_t x)
{
        return x == 0.0;
}

bool
real_isnull(real x)
{
        return __isnull(x->value(x));
}
