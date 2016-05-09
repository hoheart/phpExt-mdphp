#include "ClassLoader.h"

zend_class_entry* p_ceClsLoader = NULL;

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
		bRegistered = true;

		zval zvFnName = {0};
		ZVAL_STRING(&zvFnName, "spl_autoload_register");
		zval ret = {0};
		call_user_function(NULL,getThis(),&zvFnName,&ret,0,NULL TSRMLS_DC);
		zval_ptr_dtor(&zvFnName);
		zval_ptr_dtor(&ret);
	}
}

PHP_METHOD(Framework_App_ClassLoader, autoload){
//	zval zvClsName = {0};
//	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &zvClsName )== FAILURE) {
//		RETURN_FALSE;
//	}
//
//	zval zvModuleDir = {0};
//	zval zvModuleAlias = {0};
//	zval zvModuleName = {0};
//	zval zvCallerModule = {0};
//
//	zval zvFnName = {0};
//	HashTable
//	ZVAL_STRING(&zvFnName, "GetModuleNameByClass");
//	call_user_function(NULL,p_ceApp,&zvFnName,&zvModuleName,1,zvClsName TSRMLS_DC);
//	zval_ptr_dtor(&zvFnName);
//	ZVAL_STRING(&zvFnName, "GetCallerModule");
//	call_user_function(NULL,p_ceApp,&zvFnName,&zvCallerModule,0,NULL TSRMLS_DC);
//	zval_ptr_dtor(&zvFnName);
//
//	zval* p_zvCallerAlias = zend_hash_index_find(Z_ARR(zvModuleName),0);
//	zval* p_zvCallerName = zend_hash_index_find(Z_ARR(zvModuleName),1);
//
//	if( 0 == strcmp( Z_STRVAL(*p_zvCallerAlias) , Z_STRVAL(*p_zvCallerAlias) ) )

}

PHP_METHOD(Framework_App_ClassLoader, useModule){

}

PHP_METHOD(Framework_App_ClassLoader, loadFile){

}
