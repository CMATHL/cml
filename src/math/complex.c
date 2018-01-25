#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cml.h>

complex_t
complex_create(real_t real_part, real_t imaginary_part)
{
        complex_t z;

        z.re = real_part;
        z.im = imaginary_part;

        return z;
}

complex_t*
complex_new(real_t real_part, real_t imaginary_part)
{
        complex_t* z = (complex_t*) malloc(sizeof (complex_t));
        (*z) = complex_create(real_part, imaginary_part);

        return z;
}

complex_t*
complex_clone(complex_t* w)
{
        complex_t* z = (complex_t*) malloc(sizeof (complex_t));
        (*z) = complex_create(w->re, w->im);

        return z;
}

void
complex_free(complex_t* z)
{
        printf("%s\n", "You should free memory by using the function 'free' on the struct.");
}

char *
complex_as_string(complex_t* z)
{
        char *x, *y, op[5], im[5];
        real_t im_value;

        im_value = (z->im);

        x = (char*) real_as_string(z->re);
        y = (char*) real_as_string(z->im);

        strcpy(op, (im_value >= 0.0 ? " + " : " "));
        strcpy(im, "i");
        strcat(x, op);
        strcat(y, im);
        strcat(x, y);

        return x;
}
