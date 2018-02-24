/* This code to solve the differential equations is based on the definition
   provided by GNU Scientific Library (GSL), adapting it to the definitions
   provided by CML as well as the practices provided by it. */

#include <stdlib.h>
#include <cml/deriv.h>
#include <cml/errno.h>
#include <cml/math.h>

__CML_EXTERN_INLINE int
cml_diff_backward(const cml_function_t *f,
              double x, double *result, double *abserr)
{
        /* Construct a divided difference table with a fairly large step
           size to get a very rough estimate of f''.  Use this to estimate
           the step size which will minimize the error in calculating f'. */

        int i, k;
        long double h = CML_SQRT_DBL_EPSILON;
        long double a[3], d[3], a2;

        /* Algorithm based on description on pg. 204 of Conte and de Boor
           (CdB) - coefficients of Newton form of polynomial of degree 2. */

        for (i = 0; i < 3; i++)
        {
                a[i] = x + (i - 2.0L) * h;
                d[i] = FN_EVAL(f, a[i]);
        }

        for (k = 1; k < 4; k++)
        {
                for (i = 0; i < 3 - k; i++)
                {
                        d[i] = (d[i + 1] - d[i])/(a[i + k] - a[i]);
                }
        }

        /* Adapt procedure described on pg. 282 of CdB to find best value of
           step size. */

        a2 = cml_abs(d[0] + d[1] + d[2]);

        if (a2 < 100.0L * CML_SQRT_DBL_EPSILON)
        {
                a2 = 100.0L * CML_SQRT_DBL_EPSILON;
        }

        h = cml_sqrt(CML_SQRT_DBL_EPSILON/(2.0L * a2));

        if (h > 100.0L * CML_SQRT_DBL_EPSILON)
        {
                h = 100.0L * CML_SQRT_DBL_EPSILON;
        }

        *result = (FN_EVAL(f, x) - FN_EVAL(f, x - h))/h;
        *abserr = cml_abs(10.0L * a2 * h);

        return CML_SUCCESS;
}


__CML_EXTERN_INLINE int
cml_diff_forward(const cml_function_t *f,
             double x, double *result, double *abserr)
{
        /* Construct a divided difference table with a fairly large step
           size to get a very rough estimate of f''.  Use this to estimate
           the step size which will minimize the error in calculating f'. */

        int i, k;
        long double h = CML_SQRT_DBL_EPSILON;
        long double a[3], d[3], a2;

        /* Algorithm based on description on pg. 204 of Conte and de Boor
           (CdB) - coefficients of Newton form of polynomial of degree 2. */

        for (i = 0; i < 3; i++)
        {
                a[i] = x + i * h;
                d[i] = FN_EVAL(f, a[i]);
        }

        for (k = 1; k < 4; k++)
        {
                for (i = 0; i < 3 - k; i++)
                {
                        d[i] = (d[i + 1] - d[i])/(a[i + k] - a[i]);
                }
        }

        /* Adapt procedure described on pg. 282 of CdB to find best value of
           step size. */

        a2 = cml_abs(d[0] + d[1] + d[2]);

        if (a2 < 100.0L * CML_SQRT_DBL_EPSILON)
        {
                a2 = 100.0L * CML_SQRT_DBL_EPSILON;
        }

        h = cml_sqrt(CML_SQRT_DBL_EPSILON/(2.0L * a2));

        if (h > 100.0L * CML_SQRT_DBL_EPSILON)
        {
                h = 100.0L * CML_SQRT_DBL_EPSILON;
        }

        *result = (FN_EVAL(f, x + h) - FN_EVAL(f, x))/h;
        *abserr = cml_abs(10.0L * a2 * h);

        return CML_SUCCESS;
}


__CML_EXTERN_INLINE int
cml_diff_central(const cml_function_t *f,
             double x, double *result, double *abserr)
{
        /* Construct a divided difference table with a fairly large step
           size to get a very rough estimate of f'''.  Use this to estimate
           the step size which will minimize the error in calculating f'. */

        int i, k;
        long double h = CML_SQRT_DBL_EPSILON;
        long double a[4], d[4], a3;

        /* Algorithm based on description on pg. 204 of Conte and de Boor
           (CdB) - coefficients of Newton form of polynomial of degree 3. */

        for (i = 0; i < 4; i++)
        {
                a[i] = x + (i - 2.0L) * h;
                d[i] = FN_EVAL(f, a[i]);
        }

        for (k = 1; k < 5; k++)
        {
                for (i = 0; i < 4 - k; i++)
                {
                        d[i] = (d[i + 1] - d[i])/(a[i + k] - a[i]);
                }
        }

        /* Adapt procedure described on pg. 282 of CdB to find best
           value of step size. */

        a3 = cml_abs(d[0] + d[1] + d[2] + d[3]);

        if (a3 < 100.0L * CML_SQRT_DBL_EPSILON)
        {
                a3 = 100.0L * CML_SQRT_DBL_EPSILON;
        }

        h = cml_pow(CML_SQRT_DBL_EPSILON/(2.0L * a3), 1.0/3.0);

        if (h > 100.0L * CML_SQRT_DBL_EPSILON)
        {
                h = 100.0L * CML_SQRT_DBL_EPSILON;
        }

        *result = (FN_EVAL(f, x + h) - FN_EVAL(f, x - h))/(2.0L * h);
        *abserr = cml_abs(100.0L * a3 * h * h);

        return CML_SUCCESS;
}
