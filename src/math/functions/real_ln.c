/* Copyright (C) 2017 CMATHL

   This file is part of CML.

   CML is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   CML is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with CML. If not, see <http://www.gnu.org/licenses/>.     */

#include "../../../includes/math/cml.h"

/*
 * ln(x) function developed by using hyperbolic definition of Taylor Series
 * where ln(x) = arctanh((x^2 - 1)/(x^2 + 1))
 *
 * @param real x
 *
 * @return real log(x)
 */

real real_ln(real x)
{
        // Declaration of structures
        real y, z, w, k, h;
        // Mathematical algorithm
        y = x->prod(x, x);
        z = real(y->value(y) - 1);
        w = real(y->value(y) + 1);
        k = z->div(z, w);
        h = x->value(x) > 0 ? k->atanh(k) : real(NAN);
        // Free structures
        y->free(y);
        z->free(z);
        w->free(w);
        k->free(k);
        // Return
        return h;

}
