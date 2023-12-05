/* phpconfbr extension for PHP */

#ifndef PHP_PHPCONFBR_H
# define PHP_PHPCONFBR_H

extern zend_module_entry phpconfbr_module_entry;
# define phpext_phpconfbr_ptr &phpconfbr_module_entry

# define PHP_PHPCONFBR_VERSION "0.1.0"

# if defined(ZTS) && defined(COMPILE_DL_PHPCONFBR)
ZEND_TSRMLS_CACHE_EXTERN()
# endif

#endif	/* PHP_PHPCONFBR_H */