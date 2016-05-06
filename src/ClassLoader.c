#include "ClassLoader.h"

void ClassLoader(){
	PHP_METHOD(Framework_App_ClassLoader, __construct);
	PHP_METHOD(Framework_App_ClassLoader, register2System);

	ZEND_BEGIN_ARG_INFO_EX(Framework_App_ClassLoader_autoload, 0, 0, 1)
			ZEND_ARG_INFO(0, className)
	ZEND_END_ARG_INFO()
	PHP_METHOD(Framework_App_ClassLoader, autoload);

	ZEND_BEGIN_ARG_INFO_EX(Framework_App_ClassLoader_useModule, 0, 0, 1)
				ZEND_ARG_INFO(0, alias)
		ZEND_END_ARG_INFO()
	PHP_METHOD(Framework_App_ClassLoader, useModule);

	ZEND_BEGIN_ARG_INFO_EX(Framework_App_ClassLoader_loadFile, 0, 0, 1)
				ZEND_ARG_INFO(0, path)
		ZEND_END_ARG_INFO()
	PHP_METHOD(Framework_App_ClassLoader, loadFile);

	zend_function_entry meClsLoader[] = {
		ZEND_ME(Framework_App_ClassLoader, __construct, NULL, ZEND_ACC_PROTECTED|ZEND_ACC_CTOR)
		ZEND_ME(Framework_App_ClassLoader, register2System, NULL, ZEND_ACC_PUBLIC)
		ZEND_ME(Framework_App_ClassLoader, autoload, Framework_App_ClassLoader_autoload, ZEND_ACC_PUBLIC)
		ZEND_ME(Framework_App_ClassLoader, useModule, Framework_App_ClassLoader_useModule, ZEND_ACC_PUBLIC)
		ZEND_ME(Framework_App_ClassLoader, loadFile, Framework_App_ClassLoader_loadFile, ZEND_ACC_PUBLIC)
		{	NULL,NULL, NULL}
	};

	zend_class_entry ce;
	INIT_CLASS_ENTRY(ce, "Framework\\App\\ClassLoader", meClsLoader);
	p_ceClsLoader = zend_register_internal_class(&ce TSRMLS_CC);

	zend_declare_property_string(p_ceClsLoader, "mUsedModule", sizeof("mUsedModule") - 1, "", ZEND_ACC_PROTECTED);
}

PHP_METHOD(Framework_App_ClassLoader, __construct){
}

PHP_METHOD(Framework_App_ClassLoader, register2System){
	static zend_bool bRegistered = false;
	if( ! bRegistered ){
//		bRegistered = true;
//
//		zval fnName;
//		ZVAL_STRING(&fnName, "spl_autoload_register");
//		zval* this = getThis();
//		call_user_function(CG(function_table),&this,&fnName,NULL,1,NULL TSRMLS_DC);
	}
}

PHP_METHOD(Framework_App_ClassLoader, autoload){

}

PHP_METHOD(Framework_App_ClassLoader, useModule){

}

PHP_METHOD(Framework_App_ClassLoader, loadFile){

}
