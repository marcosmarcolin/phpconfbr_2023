--TEST--
base64_validate
--EXTENSIONS--
phpconfbr
--FILE--
<?php
$PHPConfBR = new PHPConfBR();
$str = base64_encode('');
var_dump($PHPConfBR->base64_validate($str));

$str = base64_encode('PHPConf');
var_dump($PHPConfBR->base64_validate($str));

$str = base64_encode('123');
var_dump($PHPConfBR->base64_validate($str));

$str = base64_encode(' ');
var_dump($PHPConfBR->base64_validate($str));
?>
--EXPECT--
bool(false)
bool(true)
bool(true)
bool(true)