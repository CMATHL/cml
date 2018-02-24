#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cml/math.h>

double
cml_nan()
{
        return (double) NAN;
}


double
cml_inf()
{
        return (double) POSINF;
}


double
cml_ninf()
{
        return (double) NEGINF;
}


char *
cml_as_string(double x)
{
        long double value = (long double) x;

        #ifndef PREDEF_STANDARD_C99
        char * string = (char*) malloc(80);
        sprintf(string, "%Lg", value);
        #else
        int size = snprintf(NULL, 0, "%Lg", value) + 1;
        char * string = (char*) malloc(size);
        snprintf(string, size, "%Lg", value);
        #endif

        return string;
}
