#include "App.h"

void App() {
	ZEND_METHOD(p_ceApp, __construct);

	static zend_function_entry cmApp[] = {
	ZEND_ME(p_ceApp, __construct, NULL, ZEND_ACC_PUBLIC) { NULL, NULL, NULL } };

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
	zend_declare_property_null(p_ceApp, "mResponse", sizeof("mResponse") - 1,
	ZEND_ACC_PROTECTED TSRMLS_CC);

	ZEND_METHOD(p_ceApp, __construct);
	ZEND_METHOD(p_ceApp, Instance);
}

ZEND_METHOD( p_ceApp, __construct) {

}

