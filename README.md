# Desenvolvendo sua primeira extens�o em C para PHP

Este reposit�rio exemplifica conceitos abordados durante a minha apresenta��o na **PHP Conference Brasil 2023**.

A extens�o criada, adiciona uma fun��o nomeada `base64_validate()`, al�m de uma classe chamada `PHPConBR`, com as seguintes assinaturas:

```php
<?php

function base64_validate(string $str = ''): bool{}

class PHPConfBR
{
    public function base64_validate(string $str = ''): bool {}
}
```

Alguns exemplos de uso:

```php
<?php

$str = base64_encode('');
var_dump(base64_validate($str)); // false

$str = base64_encode('PHPConf');
var_dump(base64_validate($str)); // true

$PHPConfBR = new PHPConfBR();
$str = base64_encode('');
var_dump($PHPConfBR->base64_validate($str)); // false

$str = base64_encode('PHPConf');
var_dump($PHPConfBR->base64_validate($str)); // true
```

## Depend�ncias

- Docker

Voc� pode realizar o processo sem o `Docker`, utilizando simplesmente o `PHP` e as depend�ncias `php-dev` instaladas em sua m�quina.

Para fazer isso, omita as instru��es relacionadas ao Docker.

## Imagem

A imagem descrita no `Dockerfile` inclui:

- Debian 11
- Nano
- PHP 8.3.0
- Pacotes essenciais para compilar uma extens�o PHP em C

## Fa�a a constru��o da imagem conforme definido no `Dockerfile`:

```shell
docker build -t phpconfbr_2023 .
```

## Mapeie o volume e acesse o `shell` interativo da imagem:

```shell
docker run -it -v $(pwd):/var/www phpconfbr_2023
```

## Para compilar e instalar a extens�o:

```shell
phpize
./configure
make
make install
```

## Para executar os testes ap�s compilar:

```shell
make test
```

## Para habilitar a extens�o no `php-cli`:

Acesse o arquivo de configura��o `php.ini` do PHP para habilitar a extens�o.

```shell
# Para descobrir o diret�rio do php.ini
php --ini

# Para editar o arquivo com o nano
nano /etc/php/8.3/cli/php.ini

# Adicione no final do arquivo
extension=phpconfbr.so
```

Voc� pode adicionar uma linha ao final do arquivo sem utilizar o `nano`, escreva:

```shell
echo "extension=phpconfbr.so" >> /etc/php/8.3/cli/php.ini
```

## Para verificar se a extens�o foi carregada

```shell
php -m

# Para pesquisar pela extens�o espec�ficamente
php -m | grep "phpconfbr"
```

# Cr�ditos

Marcos Marcolin | marcolindev@gmail.com | [marcosmarcolin.com.br](https://marcosmarcolin.com.br)