/* This is a generated file, edit the .stub.php file instead.
 * Stub hash: 54b0ffc3af871b189435266df516f7575c1b9675 */

/* Function */
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_base64_validate, 0, 0, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, str, IS_STRING, 0, "\"\"")
ZEND_END_ARG_INFO()

ZEND_FUNCTION(base64_validate);

static const zend_function_entry ext_functions[] = {
	ZEND_FE(base64_validate, arginfo_base64_validate)
	ZEND_FE_END
};

zend_bool is_base64(zend_string *str);

/* Class */
zend_class_entry *phpconfbr_ce;

ZEND_METHOD(PHPConfBR, base64_validate);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_PHPConfBR_base64_validate, 0, 0, _IS_BOOL, 0)
    ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, str, IS_STRING, 0, "\"\"")
ZEND_END_ARG_INFO()

static const zend_function_entry class_PHPConfBR_methods[] = {
    ZEND_ME(PHPConfBR, base64_validate, arginfo_class_PHPConfBR_base64_validate, ZEND_ACC_PUBLIC)
    ZEND_FE_END
};
