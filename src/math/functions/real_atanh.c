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

#include "../../../includes/cml.h"

/*
 * atanh(x) function developed by using trigonometric identities
 *
 * @param real x
 *
 * @return real atanh(x)
 */

real real_atanh(real x)
{
        // Declaration of structures
        real y;
        double value, ai_n, p;
        int i;

        // Domain check
        y = x->abs(x);
        if (!isgreater(1.0, y->value(y))) {
                return real_new(NAN);
        }

        // Mathematical algorithm
        value = x->value(x);
        ai_n = value;
        p = ai_n;
        for (i = 1; i <= TOPL; i += 2) {
                ai_n = ai_n*value*value;
                p = p + ai_n/(i+2);
        }

        // Free structures
        free(y);

        // Return
        return real_new(p);
}
