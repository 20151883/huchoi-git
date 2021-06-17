<?php

$cfg['blowfish_secret'] = 'Ih8,y]8//tN0s3TEJii1CDK.JXgQ7v0Z';

/**
 * Only one server
 */
$i = 1;

/* Authentication type */
$cfg['Servers'][$i]['auth_type'] = 'cookie';
/* Server parameters */
$cfg['Servers'][$i]['compress'] = false;
$cfg['Servers'][$i]['AllowNoPassword'] = false;

/**
 * Variable definition
 */
$cfg['Servers'][$i]['host'] = 'mysql';
#dns시스템을 제공하는듯
#$cfg['Servers'][$i]['port'] = '3306'; 이 부분 정의안하면 자동으로 3306으로 설정됨.
$cfg['Servers'][$i]['user'] = 'admin';
$cfg['Servers'][$i]['password'] = 'admin';

$cfg['UploadDir'] = '';
$cfg['SaveDir'] = '';
