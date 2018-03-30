#ifndef CML_DERIV_H
#define CML_DERIV_H

#define _CML_COMMON_H_
#include <cml/_common/default.h>
#include <cml/_common/inline.h>
#include <cml/_common/machine.h>
#undef _CML_COMMON_H_

#include <cml/math.h>

__CML_BEGIN_DECLS

int cml_deriv_central(const cml_function_t *f,
                      double x, double h,
                      double *result, double *abserr);

int cml_deriv_backward(const cml_function_t *f,
                       double x, double h,
                       double *result, double *abserr);

int cml_deriv_forward(const cml_function_t *f,
                      double x, double h,
                      double *result, double *abserr);

__CML_END_DECLS

#endif
