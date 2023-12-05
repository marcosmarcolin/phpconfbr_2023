/* phpconfbr extension for PHP */

#ifdef HAVE_CONFIG_H
# include "config.h"
#endif

#include "php.h"
#include "ext/standard/info.h"
#include "zend_exceptions.h"
#include "php_phpconfbr.h"
#include "phpconfbr_arginfo.h"

/* For compatibility with older PHP versions */
#ifndef ZEND_PARSE_PARAMETERS_NONE
#define ZEND_PARSE_PARAMETERS_NONE() \
	ZEND_PARSE_PARAMETERS_START(0, 0) \
	ZEND_PARSE_PARAMETERS_END()
#endif

PHP_FUNCTION(base64_validate)
{
    zend_string *str;
    zend_bool result;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_STR(str)
    ZEND_PARSE_PARAMETERS_END();

    result = is_base64(str);

    if (result == false) {
        RETURN_FALSE;
    }

    RETURN_TRUE;
}

zend_bool is_base64(zend_string *str)
{
    int len = ZSTR_LEN(str);
    char *val = ZSTR_VAL(str);

    if (len == 0 || len % 4 != 0) {
        return false;
    }

    for (int i = 0; i < len; i++) {
        char c = val[i];
        if (!((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9') || c == '+' || c == '/' || c == '=')) {
            return false;
        }
    }

    return true;
}

PHP_METHOD(PHPConfBR, base64_validate) {
    zend_bool result;
    zend_string *str;

    if (zend_parse_parameters(ZEND_NUM_ARGS(), "S", &str) == FAILURE) {
        RETURN_FALSE;
    }

    result = is_base64(str);
    if (result == false) {
        RETURN_FALSE;
    }

    RETURN_TRUE;
}

PHP_MINIT_FUNCTION(phpconfbr)
{
    zend_class_entry ce;
    INIT_CLASS_ENTRY(ce, "PHPConfBR", class_PHPConfBR_methods);
    phpconfbr_ce = zend_register_internal_class(&ce);
    return SUCCESS;
}

/* {{{ PHP_RINIT_FUNCTION */
PHP_RINIT_FUNCTION(phpconfbr)
{
#if defined(ZTS) && defined(COMPILE_DL_PHPCONFBR)
	ZEND_TSRMLS_CACHE_UPDATE();
#endif

	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MINFO_FUNCTION */
PHP_MINFO_FUNCTION(phpconfbr)
{
	php_info_print_table_start();
	php_info_print_table_row(2, "phpconfbr support", "enabled");
	php_info_print_table_end();
}
/* }}} */

/* {{{ phpconfbr_module_entry */
zend_module_entry phpconfbr_module_entry = {
	STANDARD_MODULE_HEADER,
	"phpconfbr",					/* Extension name */
	ext_functions,					/* zend_function_entry */
	PHP_MINIT(phpconfbr),			/* PHP_MINIT - Module initialization */
	NULL,							/* PHP_MSHUTDOWN - Module shutdown */
	PHP_RINIT(phpconfbr),			/* PHP_RINIT - Request initialization */
	NULL,							/* PHP_RSHUTDOWN - Request shutdown */
	PHP_MINFO(phpconfbr),			/* PHP_MINFO - Module info */
	PHP_PHPCONFBR_VERSION,		/* Version */
	STANDARD_MODULE_PROPERTIES
};
/* }}} */

#ifdef COMPILE_DL_PHPCONFBR
# ifdef ZTS
ZEND_TSRMLS_CACHE_DEFINE()
# endif
ZEND_GET_MODULE(phpconfbr)
#endif
