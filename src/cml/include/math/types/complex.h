#ifndef CML_COMPLEX_H
#define CML_COMPLEX_H

typedef struct _complex
{
        union
        {
                real_t p[2];
                struct
                {
                        real_t re;
                        real_t im;
                };
        };
} complex_t;

complex_t complex(real_t, real_t);
complex_t complex_nan();
complex_t complex_inf();
complex_t complex_clone(complex_t);
char * complex_as_string(complex_t);

#ifndef CML_NO_ALIASES
        #define cnan() complex_nan()
        #define cinf() complex_inf()
#endif

#endif
