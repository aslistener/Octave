/*

Copyright (C) 1996, 1997 John W. Eaton

This file is part of Octave.

Octave is free software; you can redistribute it and/or modify it
under the terms of the GNU General Public License as published by the
Free Software Foundation; either version 2, or (at your option) any
later version.

Octave is distributed in the hope that it will be useful, but WITHOUT
ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
for more details.

You should have received a copy of the GNU General Public License
along with Octave; see the file COPYING.  If not, write to the Free
Software Foundation, 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.

*/

#if !defined (octave_builtin_h)
#define octave_builtin_h 1

#if defined (__GNUG__)
#pragma interface
#endif

#include <string>

#include "oct-fcn.h"

class octave_value;
class octave_value_list;

// Builtin functions.

class
octave_builtin : public octave_function
{
public:

  typedef octave_value_list (*fcn) (const octave_value_list&, int);

  octave_builtin (fcn ff, const string& nm = string (),
		  const string& ds = string ())
    : octave_function (nm, ds), f (ff) { }

  ~octave_builtin (void) { }

  octave_value eval (void);

  octave_value_list eval (int nargout, const octave_value_list& args);

private:

  octave_builtin (void);

  octave_builtin (const octave_builtin& m);

  // A pointer to the actual function.
  fcn f;
};

#endif

/*
;;; Local Variables: ***
;;; mode: C++ ***
;;; End: ***
*/
