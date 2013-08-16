//Copyright (c) 2000-2013 zyl910 <zyl910hero@gmail.com>
//
//Permission is hereby granted, free of charge, to any person obtaining a copy
//of this software and associated documentation files (the "Software"), to deal
//in the Software without restriction, including without limitation the rights
//to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
//copies of the Software, and to permit persons to whom the Software is
//furnished to do so, subject to the following conditions:
//
//The above copyright notice and this permission notice shall be included in
//all copies or substantial portions of the Software.
//
//THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
//THE SOFTWARE.

/** @addtogroup GROUP_ZYLLIBC	zyllibc
 * @{
 */

/** @addtogroup GROUP_TCHARALL	tcharall
 * @{
 */

/**
 * @file	prichar.h
 * @brief	Macros for char types format specifiers (�ַ����͵ĸ�ʽ���ƺ�).
 * @since	@ref GROUP_TCHARALL 1.0
 *
 * Ϊ�ַ������ṩ��ʽ���ƺ꣬�����ο���C99�� `inttypes.h`.
 *
 * Prefix (ǰ׺)--
 * * PRI: print (���).
 * * SCN: scan (����).
 * 
 * Infix (��׺)--
 * * c: char (�ַ�).
 * * s: string (�ַ���).
 * 
 * Suffix (��׺)--
 * * A: char (խ�ַ���).
 * * W: wchar_t (���ַ���).
 * * T: TCHAR (TCHAR��).
 *
 */

#ifndef __PRICHAR_H_INCLUDED
#define __PRICHAR_H_INCLUDED


//#include "tchar.h"

#if defined __cplusplus
extern "C" {
#endif

////////////////////////////////////////
// char
////////////////////////////////////////

#if defined(_MSC_VER)||defined(__BORLANDC__)
	// VC��BCB ��֧��hc/hs���Ǵ���խ�ַ�.
	#define PRIcA	"hc"
	#define PRIsA	"hs"
#elif defined(__GNUC__)||defined(_WIN32)||defined(_WIN64)
	// GCC��խ�溯����ʱ�޷�ʶ��hc/hs, ����溯������֧��hc/hs. ��������Windowsƽ̨�ı�����Ҳ������.
	#if defined(_UNICODE)
		#define PRIcA	"hc"
		#define PRIsA	"hs"
	#else
		#define PRIcA	"c"
		#define PRIsA	"s"
	#endif
#else
	// �ٶ�����ƽֻ̨֧��c/s.
	#define PRIcA	"c"
	#define PRIsA	"s"
#endif

/** @def PRIcA
 * [print format] char .
 */

/** @def PRIsA
 * [print format] char string .
 */


////////////////////////////////////////
// wchar_t
////////////////////////////////////////

// C99��׼�涨lc/ls���Ǵ�����ַ�.
#define PRIcW	"lc"	//!< [print format] wchat_t .
#define PRIsW	"ls"	//!< [print format] wchat_t string .


////////////////////////////////////////
// TCHAR
////////////////////////////////////////

#if defined(_WIN32)||defined(_WIN64)||defined(_MSC_VER)
	// VC��BCB��MinGW��Windowsƽ̨�ϵı�����֧��cΪ����Ӧ, ����խ�ַ�������char, ���ڿ��ַ�������wchar_t.
	#define PRIcT	"c"
	#define PRIsT	"s"
#else
	// ����ƽ̨.
	#if defined(_UNICODE)
		#define PRIcT	PRIcW
		#define PRIsT	PRIsW
	#else
		#define PRIcT	PRIcA
		#define PRIsT	PRIsA
	#endif
#endif

/** @def PRIcT
 * [print format] TCHAR .
 */

/** @def PRIsT
 * [print format] TCHAR string .
 */


////////////////////////////////////////
// SCN
////////////////////////////////////////

#define SCNcA	PRIcA	//!< [scan format] char .
#define SCNsA	PRIsA	//!< [scan format] char string .
#define SCNcW	PRIcW	//!< [scan format] wchat_t .
#define SCNsW	PRIsW	//!< [scan format] wchat_t string .
#define SCNcT	PRIcT	//!< [scan format] TCHAR .
#define SCNsT	PRIsT	//!< [scan format] TCHAR string .


#if defined __cplusplus
};
#endif

#endif	// #ifndef __PRICHAR_H_INCLUDED

/** @} */	// @addtogroup GROUP_TCHARALL
/** @} */	// @addtogroup GROUP_ZYLLIBC
