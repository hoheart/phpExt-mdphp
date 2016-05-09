#include "php_wrapper.h"

#include "php.h"

zval* createObj(zend_class_entry* pClsEntry) {
	zval* p = NULL;
	MD_MAKE_STD_ZVAL(p);
	object_init_ex(p, pClsEntry);

	return p;
}

zval* call(zval* pObj, const char* szFn, zval* params) {
	zval zvFnName = { 0 };
	ZVAL_STRING(&zvFnName, szFn);
	zval* ret = NULL;
	MD_MAKE_STD_ZVAL(ret);
	if (NULL == pObj) {
		if ( NULL == params) {
			call_user_function(EG(function_table), NULL, &zvFnName, ret, 0,
			NULL TSRMLS_DC);
		} else {
			call_user_function(EG(function_table), NULL, &zvFnName, ret,
					zend_array_count(Z_ARR(*params)), params TSRMLS_DC);
		}
	} else {
		if ( NULL == params) {
			call_user_function(NULL, pObj, &zvFnName, ret, 0, NULL TSRMLS_DC);
		} else {
			call_user_function(NULL, pObj, &zvFnName, ret,
					zend_array_count(Z_ARR(*params)), params TSRMLS_DC);
		}
	}
//	zvalDel(&zvFnName);

	return ret;
}

void del(void* p) {
	efree(p);
}

void zvalDel(zval* p) {
	zval_ptr_dtor(p);
}
