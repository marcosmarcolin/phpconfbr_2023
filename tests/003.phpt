--TEST--
PHPConfBR class
--EXTENSIONS--
phpconfbr
--FILE--
<?php
var_dump(class_exists('PHPConfBR'));
?>
--EXPECT--
bool(true)
