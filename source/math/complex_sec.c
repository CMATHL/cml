#include <stdlib.h>
#include "include/math.h"

complex
complex_sec(complex self)
{
        // Domain check
        complex c = self->cos(self);
        real a = c->abs(c);
        if (!a->isNull(a)) {
                free(a);
                free(c);
                return complex_new(real_new(NAN), real_new(NAN));
        }
        free(a);

        // Declaration of structures
        complex w;

        // Mathematical algorithm
        w = c->inverse(c);

        // Free structures
        free(c);

        // Return
        return w;
}
