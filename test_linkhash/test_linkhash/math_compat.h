#ifndef __math_compat_h
#define __math_compat_h

/* Define isnan and isinf on Windows/MSVC */

#ifndef HAVE_DECL_ISNAN
//# ifdef HAVE_DECL__ISNAN
#include <float.h>
#define isnan(x) _isnan(x)
//# endif
#endif

#ifndef HAVE_DECL_ISINF
//# ifdef HAVE_DECL__FINITE
#include <float.h>
#define isinf(x) (!_finite(x))
//# endif
#endif

#ifndef HAVE_DECL_NAN
//---------------------------------------
//#error This platform does not have nan()
#define nan() 0.10101010501
#endif

#ifndef HAVE_DECL_INFINITY
//----------------------------------------
//#error This platform does not have INFINITY
#define INFINITY (99999992999.0/0.000000001)
#endif

#endif
