#ifndef CMDLIB_H__
#define CMDLIB_H__

#if _MSC_VER >= 1000
#pragma once
#endif

//#define MODIFICATIONS_STRING "Submit detailed bug reports to (zoner@gearboxsoftware.com)\n"
//#define MODIFICATIONS_STRING "Submit detailed bug reports to (merlinis@bigpond.net.au)\n"
//#define MODIFICATIONS_STRING "Submit detailed bug reports to (amckern@yahoo.com)\n"
#define MODIFICATIONS_STRING "Submit detailed bug reports to (vluzacn@163.com)\n" //--vluzacn

#ifdef _DEBUG
#define ZHLT_VERSIONSTRING "v3.4 dbg"
#else
#define ZHLT_VERSIONSTRING "v3.4"
#endif

#define HACK_VERSIONSTRING "VL34" //--vluzacn

#if !defined (HLCSG) && !defined (HLBSP) && !defined (HLVIS) && !defined (HLRAD) && !defined (RIPENT) //--vluzacn
#error "You must define one of these in the settings of each project: HLCSG, HLBSP, HLVIS, HLRAD, RIPENT. The most likely cause is that you didn't load the project from the sln file."
#endif
#if !defined (VERSION_32BIT) && !defined (VERSION_64BIT) && !defined (VERSION_LINUX) && !defined (VERSION_OTHER) //--vluzacn
#error "You must define one of these in the settings of each project: VERSION_32BIT, VERSION_64BIT, VERSION_LINUX, VERSION_OTHER. The most likely cause is that you didn't load the project from the sln file."
#endif

#ifdef VERSION_32BIT
#define PLATFORM_VERSIONSTRING "32-bit"
#define PLATFORM_CAN_CALC_EXTENT
#endif
#ifdef VERSION_64BIT
#define PLATFORM_VERSIONSTRING "64-bit"
#define PLATFORM_CAN_CALC_EXTENT
#endif
#ifdef VERSION_LINUX
#define PLATFORM_VERSIONSTRING "linux"
#define PLATFORM_CAN_CALC_EXTENT
#endif
#ifdef VERSION_OTHER
#define PLATFORM_VERSIONSTRING "???"
#endif

//=====================================================================
// AJM: Different features of the tools can be undefined here
//      these are not officially beta tested, but seem to work okay

// ZHLT_* features are spread across more than one tool. Hence, changing
//      one of these settings probably means recompiling the whole set
//#define ZHLT_DETAIL                         // HLCSG, HLBSP - detail brushes     //should never turn on
//#define ZHLT_PROGRESSFILE                   // ALL TOOLS - estimate progress reporting to -progressfile //should never turn on
//#define ZHLT_NSBOB //should never turn on
//#define ZHLT_XASH // build the compiler for Xash engine //--vluzacn
	#ifdef ZHLT_XASH
//#define ZHLT_XASH2 // build the compiler for Xash engine with change in bsp format //--vluzacn
	#endif
//#define ZHLT_HIDDENSOUNDTEXTURE //--vluzacn


	#ifdef SYSTEM_WIN32
#define RIPENT_PAUSE //--vluzacn
	#endif

// tool specific settings below only mean a recompile of the tool affected


	#ifdef SYSTEM_WIN32
#define HLCSG_GAMETEXTMESSAGE_UTF8 //--vluzacn
	#endif
//#define HLBSP_SUBDIVIDE_INMID // this may contribute to 'AllocBlock: full' problem though it may generate fewer faces. --vluzacn




#define HLRAD_REDUCELIGHTMAP //--vluzacn
	#ifdef HLRAD_REDUCELIGHTMAP
#define HLRAD_AUTOCORING //--vluzacn
	#endif
#define HLRAD_OPAQUEINSKY_FIX //--vluzacn
#define HLRAD_SUNSPREAD //--vluzacn
#define HLRAD_SUNDIFFUSE //--vluzacn
#define HLRAD_FASTMODE //--vluzacn
#define HLRAD_OVERWRITEVERTEX_FIX //--vluzacn
#define HLRAD_TEXLIGHT_SPOTS_FIX //--vluzacn
#define HLRAD_BOUNCE_STYLE //--vluzacn
#define HLRAD_BLUR //--vluzacn
#define HLRAD_ACCURATEBOUNCE //--vluzacn
	#ifdef HLRAD_TEXLIGHT_SPOTS_FIX
	#ifdef HLRAD_ACCURATEBOUNCE
#define HLRAD_ACCURATEBOUNCE_TEXLIGHT // note: this reduces the compile time in '-extra' mode //--vluzacn
	#endif
	#endif
	#ifdef HLRAD_AUTOCORING
#define HLRAD_ACCURATEBOUNCE_SAMPLELIGHT //--vluzacn
	#endif
	#ifdef HLRAD_ACCURATEBOUNCE_TEXLIGHT
#define HLRAD_ACCURATEBOUNCE_ALTERNATEORIGIN //--vluzacn
	#endif
#define HLRAD_ACCURATEBOUNCE_REDUCEAREA //--vluzacn
#define HLRAD_CUSTOMTEXLIGHT_COLOR //--vluzacn
#define HLRAD_SUBDIVIDEPATCH_NEW //--vluzacn
#define HLRAD_DIVERSE_LIGHTING //--vluzacn
	#ifdef HLRAD_BLUR
#define HLRAD_GROWSAMPLE //--vluzacn
	#endif
	#ifdef HLRAD_BLUR
#define HLRAD_AVOIDNORMALFLIP //--vluzacn
	#endif
	#ifdef HLRAD_BLUR
	#ifdef HLRAD_GROWSAMPLE
#define HLRAD_BLUR_MINIMALSQUARE //--vluzacn
	#endif
	#endif
	#ifdef HLRAD_BLUR_MINIMALSQUARE
#define HLRAD_AVOIDWALLBLEED //--vluzacn
	#endif
#define HLRAD_PRESERVELIGHTMAPCOLOR //--vluzacn
#define HLRAD_MORE_PATCHES //--vluzacn
#define HLRAD_SPARSEVISMATRIX_FAST //--vluzacn
	#ifdef HLRAD_GROWSAMPLE
#define HLRAD_LOCALTRIANGULATION //--vluzacn
	#endif
	#ifdef HLRAD_LOCALTRIANGULATION
#define HLRAD_BILINEARINTERPOLATION //--vluzacn
	#endif
#define HLRAD_TEXLIGHTGAP //--vluzacn
	#ifdef HLRAD_LOCALTRIANGULATION
#define HLRAD_FARPATCH_FIX //--vluzacn
	#endif
#define HLRAD_TRANSPARENCY_FAST //--vluzacn

#if defined (ZHLT_XASH) || defined (ZHLT_XASH2)
#if !defined (HLRAD_AUTOCORING) || !defined (HLRAD_AVOIDNORMALFLIP)
#error "ZHLT_XASH has not been implemented for current configuration"
#endif
#endif
//=====================================================================

#if _MSC_VER <1400
#define strcpy_s strcpy //--vluzacn
#define sprintf_s sprintf //--vluzacn
#endif
#if _MSC_VER >= 1400
#pragma warning(disable: 4996)
#endif

#ifdef __MINGW32__
#include <io.h>
#endif

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#if 0 //--vluzacn
// AJM: gnu compiler fix
#ifdef __GNUC__
#define _alloca __builtin_alloca
#define alloca __builtin_alloca
#endif
#endif

#include "win32fix.h"
#include "mathtypes.h"

#ifdef SYSTEM_WIN32
#pragma warning(disable: 4127)                      // conditional expression is constant
#pragma warning(disable: 4115)                      // named type definition in parentheses
#pragma warning(disable: 4244)                      // conversion from 'type' to type', possible loss of data
// AJM
#pragma warning(disable: 4786)                      // identifier was truncated to '255' characters in the browser information
#pragma warning(disable: 4305)                      // truncation from 'const double' to 'float'
#pragma warning(disable: 4800)                     // forcing value to bool 'true' or 'false' (performance warning)
#endif


#ifdef STDC_HEADERS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <ctype.h>
#include <time.h>
#include <stdarg.h>
#include <limits.h>
#endif

#include <stdint.h> //--vluzacn

#ifdef HAVE_SYS_TIME_H
#include <sys/time.h>
#endif
#ifdef HAVE_UNISTD_H
#include <unistd.h>
#endif

#ifdef ZHLT_NETVIS
#include "c2cpp.h"
#endif

#ifdef SYSTEM_WIN32
#define SYSTEM_SLASH_CHAR  '\\'
#define SYSTEM_SLASH_STR   "\\"
#endif
#ifdef SYSTEM_POSIX
#define SYSTEM_SLASH_CHAR  '/'
#define SYSTEM_SLASH_STR   "/"
#endif

// the dec offsetof macro doesn't work very well...
#define myoffsetof(type,identifier) ((size_t)&((type*)0)->identifier)
#define sizeofElement(type,identifier) (sizeof((type*)0)->identifier)

#ifdef SYSTEM_POSIX
extern char*    strupr(char* string);
extern char*    strlwr(char* string);
#endif
extern const char* stristr(const char* const string, const char* const substring);
extern bool CDECL FORMAT_PRINTF(3,4) safe_snprintf(char* const dest, const size_t count, const char* const args, ...);
extern bool     safe_strncpy(char* const dest, const char* const src, const size_t count);
extern bool     safe_strncat(char* const dest, const char* const src, const size_t count);
extern bool     TerminatedString(const char* buffer, const int size);

extern char*    FlipSlashes(char* string);

extern double   I_FloatTime();

extern int      CheckParm(char* check);

extern void     DefaultExtension(char* path, const char* extension);
extern void     DefaultPath(char* path, char* basepath);
extern void     StripFilename(char* path);
extern void     StripExtension(char* path);

extern void     ExtractFile(const char* const path, char* dest);
extern void     ExtractFilePath(const char* const path, char* dest);
extern void     ExtractFileBase(const char* const path, char* dest);
extern void     ExtractFileExtension(const char* const path, char* dest);

extern short    BigShort(short l);
extern short    LittleShort(short l);
extern int      BigLong(int l);
extern int      LittleLong(int l);
extern float    BigFloat(float l);
extern float    LittleFloat(float l);

#endif //CMDLIB_H__
