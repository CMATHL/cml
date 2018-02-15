#include <stdlib.h>
#include <cml.h>

#ifndef CML_NO_EASING_FUNCTIONS
/* Easing functions - Elastic */
__CML_EXTERN_INLINE real_t
ease_elastic_in(real_t p)
{
        return real_sin(13.0 * M_PI_2 * p) * real_pow(2.0, 10.0 * (p - 1.0));
}

__CML_EXTERN_INLINE real_t
ease_elastic_out(real_t p)
{
        return real_sin(-13.0 * M_PI_2 * (p + 1.0)) * real_pow(2.0, -10.0 * p) + 1.0;
}

__CML_EXTERN_INLINE real_t
ease_elastic_in_out(real_t p)
{
        real_t f = 0.0;

        if (p < 0.5)
        {
                f = 0.5 * real_sin(13.0 * M_PI_2 * (2.0 * p)) * real_pow(2.0, 10.0 * ((2.0 * p) - 1.0));
        }
        else
        {
                f = 0.5 * (real_sin(-13.0 * M_PI_2 * ((2.0 * p - 1.0) + 1.0)) * real_pow(2.0, -10.0 * (2.0 * p - 1.0)) + 2.0);
        }

        return f;
}
#endif
