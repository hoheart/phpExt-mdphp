#include "php_mdphp.h"

//module entry
zend_module_entry mdphp_module_entry = {
#if ZEND_MODULE_API_NO >= 20010901
		STANDARD_MODULE_HEADER,
#endif
		"mdphp", //extesion name
		NULL, /* Functions */
		PHP_MINIT(mdphp), /* MINIT */
		NULL, /* MSHUTDOWN */
		NULL, /* RINIT */
		NULL, /* RSHUTDOWN */
		NULL, /* MINFO */
#if ZEND_MODULE_API_NO >= 20010901
		"1.0", //这个地方是我们扩展的版本
#endif
		STANDARD_MODULE_PROPERTIES };

#ifdef COMPILE_DL_MDPHP
ZEND_GET_MODULE(mdphp)
#endif

PHP_MINIT_FUNCTION( mdphp) {
#include "include/App.h"
	App();
//#include "src/Config.c"
//	Config();

	return SUCCESS;
}
