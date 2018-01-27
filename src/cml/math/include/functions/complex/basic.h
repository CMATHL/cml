#ifndef CML_COMPLEX_BASIC_FUNC_H
#define CML_COMPLEX_BASIC_FUNC_H

real_t complex_abs(complex_t);
real_t complex_arg(complex_t);

complex_t complex_add(complex_t, complex_t);
complex_t complex_conjugate(complex_t);
complex_t complex_div(complex_t, complex_t);
complex_t complex_inverse(complex_t);
complex_t complex_prod(complex_t, complex_t);
complex_t complex_scalar_prod(complex_t, real_t);
complex_t complex_sub(complex_t, complex_t);

#endif
