#include "App.h"

#include "ClassLoader.h"

zend_class_entry* p_ceApp = NULL;

void App(){
	ClassLoader();

	PHP_METHOD(Framework_App, __construct);

	ZEND_BEGIN_ARG_INFO_EX(Framework_App_Instance, 0, 0, 1)
		ZEND_ARG_INFO(0, rootDir)
	ZEND_END_ARG_INFO()
	PHP_METHOD(Framework_App, Instance);

	PHP_METHOD(Framework_App, registerAutoloader);
	PHP_METHOD(Framework_App, init);

	zend_function_entry cmApp[] = {
		ZEND_ME(Framework_App, __construct, NULL, ZEND_ACC_PROTECTED|ZEND_ACC_CTOR)
		ZEND_ME(Framework_App, Instance, Framework_App_Instance, ZEND_ACC_PUBLIC | ZEND_ACC_STATIC)
		ZEND_ME(Framework_App, registerAutoloader, NULL, ZEND_ACC_PUBLIC)
		ZEND_ME(Framework_App, init, NULL, ZEND_ACC_PUBLIC)
		{	NULL,NULL, NULL}
	};

	zend_class_entry ce;
	INIT_CLASS_ENTRY(ce, "Framework\\App", cmApp);
	p_ceApp = zend_register_internal_class(&ce TSRMLS_CC);

	/**
	 *本框架的版本
	 */
	zend_declare_class_constant_string(p_ceApp, "FRAMEWORK_VERSION",
			sizeof("FRAMEWORK_VERSION") - 1, "1.0.1" TSRMLS_DC);

	/**
	 *整个APP的根目录
	 */
	zend_declare_property_string(p_ceApp, "ROOT_DIR", sizeof("ROOT_DIR") - 1,
			"", ZEND_ACC_PUBLIC | ZEND_ACC_STATIC TSRMLS_DC);

	zend_declare_property_null(p_ceApp, "mClassLoader",
			sizeof("mClassLoader") - 1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(p_ceApp, "mErrorHandler",
			sizeof("mErrorHandler") - 1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(p_ceApp, "mModuleManager",
			sizeof("mModuleManager") - 1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(p_ceApp, "mServiceManager",
			sizeof("mServiceManager") - 1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(p_ceApp, "mRequest", sizeof("mRequest") - 1,
			ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(p_ceApp, "mCurrentController",
			sizeof("mCurrentController") - 1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(p_ceApp, "mViewRender",
			sizeof("mViewRender") - 1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(p_ceApp, "mOutputStream",
			sizeof("mOutputStream") - 1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(p_ceApp, "mResponse", sizeof("mResponse") - 1,ZEND_ACC_PROTECTED TSRMLS_CC);
}

PHP_METHOD( Framework_App, __construct) {
}

PHP_METHOD( Framework_App, Instance) {
	static zval* pMe = NULL;
	if ( NULL == pMe) {
		//先赋值静态成员变量
		zval* p_zvRootDir = NULL;
		int iLen = 0;
		if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &p_zvRootDir , &iLen )== FAILURE) {
			RETURN_NULL();
		}

		zend_update_static_property(p_ceApp, "ROOT_DIR", sizeof("ROOT_DIR") - 1, p_zvRootDir TSRMLS_DC);

		chdir(Z_STRVAL(*p_zvRootDir));

		MD_MAKE_STD_ZVAL(pMe);
		object_init_ex(pMe, p_ceApp);
	}

	RETURN_ZVAL(pMe, 0, 0);
}

PHP_METHOD(Framework_App, registerAutoloader){
	zval* pAutoLoader = NULL;
	MD_MAKE_STD_ZVAL(pAutoLoader);
	object_init_ex(pAutoLoader, p_ceClsLoader);
	zend_update_property(p_ceApp , getThis() , "mClassLoader" , sizeof("ClassLoader") - 1 , pAutoLoader);

	zval* fnName;
	MD_MAKE_STD_ZVAL(fnName);
	ZVAL_STRING(fnName, "register2System");
	zval ret;
	call_user_function(NULL,pAutoLoader,fnName,&ret,0,NULL TSRMLS_DC);
}

PHP_METHOD(Framework_App, init){

}

