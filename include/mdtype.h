#ifndef __MDPHP_MDTYPE_H__
#define __MDPHP_MDTYPE_H__

#if PHP_MAJOR_VERSION < 7
	#define MD_MAKE_STD_ZVAL(p)						MAKE_STD_ZVAL(p)
#else
	#define MD_MAKE_STD_ZVAL(p)						zval _stack_zval_##p; p = &(_stack_zval_##p)
#endif

#define true  1
#define false 0

#endif
