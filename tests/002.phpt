--TEST--
base64_validate not parameter
--EXTENSIONS--
phpconfbr
--FILE--
<?php
var_dump(base64_validate());
?>
--EXPECTF--
Fatal error: Uncaught ArgumentCountError: base64_validate() expects exactly 1 argument, 0 given in %s:%d
Stack trace:
#0 %s(%d): base64_validate()
#1 {main}
  thrown in %s on line %d