#ifndef __MDPHP_H__
#define __MDPHP_H__

//加载config.h，如果配置了的话
#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

//加载php头文件
#include "php.h"

#define p_meMdphp &mdphp_module_entry
extern zend_module_entry mdphp_module_entry;

PHP_MINIT_FUNCTION (mdphp);
PHP_MSHUTDOWN_FUNCTION(mdphp);

#endif
