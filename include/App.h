#ifndef __MDPHP_APP_H__
#define __MDPHP_APP_H__

zend_class_entry* p_ceApp;

static zend_function_entry cmApp[] = { { NULL, NULL, NULL } };

ZEND_MINIT_FUNCTION( test) {
	zend_class_entry ce;
	INIT_CLASS_ENTRY(ce, "Framework\\App", cmApp);
	p_ceApp = zend_register_internal_class(&ce TSRMLS_CC);

	return SUCCESS;
}

#endif
