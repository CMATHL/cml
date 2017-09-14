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

#include <stdlib.h>
#include "../../../includes/cml.h"

/*
 * pow(f, g) function developed by using the exponentiation process
 * where pow(f, g) = sgn(f)e^(glog(|f|))
 *
 * @param real x
 *
 * @return real pow(f, g)
 */


real real_pow(real x, real n)
{
        // Domain check
        if (x->isNull(x)) {
                return n->isNull(n) ? real_new(NAN) : x;
        }

        // Declaration of structures
        real s, y, z, w, k, h;

        // Mathematical algorithm
        s = x->sgn(x);
        y = x->abs(x);
        z = y->ln(y);
        w = n->prod(n, z);
        k = w->exp(w);
        h = s->prod(s, k);

        // Free structures
        free(s);
        free(y);
        free(z);
        free(w);
        free(k);

        // Return
        return h;
}
