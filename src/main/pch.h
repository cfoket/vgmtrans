#if defined(_MSC_VER) && !defined(VGMTRANS_FOR_QT)
#include "stdafx.h"
#endif

#if !defined(PCH_H)
#define PCH_H

// Fix for error: error: 'swprintf' was not declared in this scope seen in appveyor
//#if defined(__MINGW32__) || defined(__MINGW32_MAJOR_VERSION)
////#undef __STRICT_ANSI__
////#define swprintf _snwprintf
////#define snprintf _snprintf
//#endif
//
//#if defined(_WIN32) && defined(__MINGW32__) && !defined(__NO_ISOCEXT)
//# define swprintf snwprintf
////#else
////# define FMT_SWPRINTF swprintf
//#endif // defined(_WIN32) && defined(__MINGW32__) && !defined(__NO_ISOCEXT)

#include <assert.h>
#include <wchar.h>
#include <cmath>
#include <math.h>
#include <algorithm>
#include <limits.h>
#include <stdio.h>
#include <stdint.h>

#include <fstream>
#include <vector>
#include <list>
#include <map>
#include <string>
#include <cstring>
#include <sstream>
#include <unordered_set>
#include <iterator>
#include <iostream>
#include <iomanip>
#include <wchar.h>
#include <ctype.h>

#include "portable.h"


// countof definition with fallbacks. Taken from: http://www.g-truc.net/post-0708.html
//  TODO: replace this with ibkt the simple C++11 definition when VS2015 is released

// Any compiler claiming C++11 supports, Visual C++ 2015 and Clang version supporting constexp
#if __cplusplus >= 201103L || _MSC_VER >= 1900 // C++ 11 implementation
	template <typename T, std::size_t N>
	constexpr std::size_t countof(T const (&)[N]) noexcept
	{
		return N;
	}

#elif _MSC_VER // Visual C++ fallback
	#define countof(arr) _countof(arr)

#else
	#define countof(arr) sizeof(arr) / sizeof(arr[0])

#endif

using namespace std;

#endif // !defined(PCH_H)