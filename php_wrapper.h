#ifndef __MDPHP_PHP_WRAPPER_H__
#define __MDPHP_PHP_WRAPPER_H__

#include "php.h"

#define true  1
#define false 0

#if PHP_MAJOR_VERSION < 7
	#define MD_MAKE_STD_ZVAL(p)						MAKE_STD_ZVAL(p)
#else
	#define MD_MAKE_STD_ZVAL(p)						zval _stack_zval_##p; p = &(_stack_zval_##p)
#endif

zval* createObj(zend_class_entry* pClsEntry);
zval* call(zval* pObj, const char* szFn, zval* params);
void del(void* p);
void zvalDel(zval* p);


#endif
