<?php
use Framework\App;

$r = new \ReflectionClass('Framework\App');
print_r($r . '');

$r = new \ReflectionClass('Framework\App\ClassLoader');
print_r($r . '');

$app = App::Instance('/home/devops/che001');
$app->registerAutoloader();

