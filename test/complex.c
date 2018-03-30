#include <time.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include <cml/math.h>
#include <cml/complex.h>
#include "include/test.h"

struct cml_complex_tests
{
        char *name;
        cml_complex_t (*f) (cml_complex_t);
        double arg_re;
        double arg_im;
        double res_re;
        double res_im;
};

struct cml_complex_tests list_tst[] =
{
#include "data/complex.dat"
        { "", NULL, 0.0, 0.0, 0.0, 0.0 }
};


int
run_complex_tests()
{
        CATEGORY_BEGIN(Complex)
        {
                TEST_BEGIN(Initialization)
                {
                        cml_complex_t z = cml_complex(1.0, 4.0);
                        EXPECT_FLOAT_EQ(z.re, 1.0);
                        EXPECT_FLOAT_EQ(z.im, 4.0);
                }
                TEST_END()

                TEST_BEGIN(Functions)
                {
                        size_t i;

                        for (i = 0; list_tst[i].f != NULL; i++ )
                        {
                                struct cml_complex_tests t = list_tst[i];
                                cml_complex_t arg = cml_complex(t.arg_re, t.arg_im);
                                cml_complex_t res = (t.f)(arg);

                                #ifdef CML_NO_MATH
                                EXPECT_NEAR(res.re, t.res_re, 1e-4);
                                EXPECT_NEAR(res.im, t.res_im, 1e-4);
                                #else
                                EXPECT_FLOAT_EQ(res.re, t.res_re);
                                EXPECT_FLOAT_EQ(res.im, t.res_im);
                                #endif
                        }
                }
                TEST_END()
        }
        CATEGORY_END()

        return 0;
}
