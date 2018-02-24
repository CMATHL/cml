#include <stdlib.h>
#include <cml/math.h>

double
complex_abs(complex_t z)
{
        /* Declaration of variables and structures */
        double n, a, b, w, h;

        /* Mathematical algorithm */
        n = 2.0;
        a = real_pow(z.re, n);
        b = real_pow(z.im, n);
        w = real_add(a, b);
        h = real_sqrt(w);

        /* Return */
        return h;
}


double
complex_logabs(complex_t z)
{                               /* return log|z| */
        double xabs = real_abs(z.re);
        double yabs = real_abs(z.im);
        double max, u;

        if (xabs >= yabs)
        {
                max = xabs;
                u = yabs / xabs;
        }
        else
        {
                max = yabs;
                u = xabs / yabs;
        }

        /* Handle underflow when u is close to 0 */
        return real_log(max) + 0.5 * real_log1p(u*u);
}


/*
 * (a + bi) + (c + di) = (a+c) + (b+d)i
 *
 */

complex_t
complex_add(complex_t z, complex_t k)
{
        /* Declaration of variables and structures */
        complex_t w;
        double n, m;

        /* Mathematical algorithm */
        n = real_add(z.re, k.re);
        m = real_add(z.im, k.im);
        w = complex(n, m);

        /* Return */
        return w;
}


double
complex_arg(complex_t z)
{
        /* Declaration of variables and structures */
        double w;

        /* Mathematical algorithm */
        w = real_atan2(z.p[1], z.p[0]);

        /* Return */
        return w;
}

/*
 * Let z = a + bi, define the conjugate of z (w) as w = a - bi
 *
 */

complex_t
complex_conjugate(complex_t z)
{
        /* Declaration of variables and structures */
        complex_t r;

        /* Mathematical algorithm */
        r = complex(z.re, real_opposite(z.im));

        /* Return */
        return r;
}


complex_t
complex_div(complex_t z, complex_t k)
{
        /* Declaration of variables and structures */
        complex_t r, w;

        /* Mathematical algorithm */
        r = complex_inverse(k);
        w = complex_mul(z, r);

        /* Return */
        return w;
}


/*
 * It can be shown that, let z = a + bi a complex number, the multiplicative
 * inverse of z (w), with a⋅b ≠ 0, is W = conjugate(z) / abs(z)^2
 *
 */

complex_t
complex_inverse(complex_t z)
{
        /* Declaration of variables and structures */
        complex_t w, h;
        double a, b, m, n;


        /* Mathematical algorithm */
        w = complex_conjugate(z);
        a = complex_abs(z);
        b = a*a;
        n = real_div(w.p[0], b);
        m = real_div(w.p[1], b);

        h = complex(n, m);

        /* Return */
        return h;
}


/*
 * (a + bi) · (c + di) = (ac − bd) + (ad + bc)i
 *
 */

complex_t
complex_mul(complex_t z, complex_t k)
{
        /* Declaration of variables and structures */
        complex_t w;
        double a, b, c, d;

        /* Mathematical algorithm */
        a = z.p[0];
        b = z.p[1];
        c = k.p[0];
        d = k.p[1];

        w = complex(a*c - b*d, a*d + b*c);

        /* Return */
        return w;
}


complex_t
complex_scalar_mul(complex_t z, double k)
{
        /* Declaration of variables and structures */
        complex_t w;
        double x, y;

        /* Mathematical algorithm */
        x = real_mul(k, z.p[0]);
        y = real_mul(k, z.p[1]);
        w = complex(x, y);

        /* Return */
        return w;
}


complex_t
complex_sub(complex_t z, complex_t k)
{
        /* Declaration of variables and structures */
        complex_t h, w;
        double n, m;

        /* Mathematical algorithm */
        n = real_opposite(k.re);
        m = real_opposite(k.im);
        w = complex(n, m);
        h = complex_add(z, w);

        /* Return */
        return h;
}


complex_t
complex_add_real(complex_t a, double x)
{                               /* z=a+x */
        complex_t z;
        z = complex(a.re + x, a.im);
        return z;
}


complex_t
complex_add_imag(complex_t a, double y)
{                               /* z=a+iy */
        complex_t z;
        z = complex(a.re, a.im + y);
        return z;
}

complex_t
complex_sub_real(complex_t a, double x)
{                               /* z=a-x */
        complex_t z;
        z = complex(a.re - x, a.im);
        return z;
}


complex_t
complex_sub_imag(complex_t a, double y)
{                               /* z=a-iy */
        complex_t z;
        z = complex(a.re, a.im - y);
        return z;
}

complex_t
complex_mul_real(complex_t a, double x)
{                               /* z=a*x */
        complex_t z;
        z = complex(x * a.re, x * a.im);
        return z;
}


complex_t
complex_mul_imag(complex_t a, double y)
{                               /* z=a*iy */
        complex_t z;
        z = complex(-y * a.im, y * a.re);
        return z;
}

complex_t
complex_div_real(complex_t a, double x)
{                               /* z=a/x */
        complex_t z;
        z = complex(a.re / x, a.im / x);
        return z;
}


complex_t
complex_div_imag(complex_t a, double y)
{                               /* z=a/(iy) */
        complex_t z;
        z = complex(a.im / y,  -a.re / y);
        return z;
}
