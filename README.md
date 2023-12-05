# Desenvolvendo sua primeira extensão em C para PHP

Este repositório exemplifica conceitos abordados durante a minha apresentação na **PHP Conference Brasil 2023**.

A extensão criada, adiciona uma função nomeada `base64_validate()`, além de uma classe chamada `PHPConBR`, com as seguintes assinaturas:

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

## Dependências

- Docker

Você pode realizar o processo sem o `Docker`, utilizando simplesmente o `PHP` e as dependências `php-dev` instaladas em sua máquina.

Para fazer isso, omita as instruções relacionadas ao Docker.

## Imagem

A imagem descrita no `Dockerfile` inclui:

- Debian 11
- Nano
- PHP 8.3.0
- Pacotes essenciais para compilar uma extensão PHP em C

## Faça a construção da imagem conforme definido no `Dockerfile`:

```shell
docker build -t phpconfbr_2023 .
```

## Mapeie o volume e acesse o `shell` interativo da imagem:

```shell
docker run -it -v $(pwd):/var/www phpconfbr_2023
```

## Para compilar e instalar a extensão:

```shell
phpize
./configure
make
make install
```

## Para executar os testes após compilar:

```shell
make test
```

## Para habilitar a extensão no `php-cli`:

Acesse o arquivo de configuração `php.ini` do PHP para habilitar a extensão.

```shell
# Para descobrir o diretório do php.ini
php --ini

# Para editar o arquivo com o nano
nano /etc/php/8.3/cli/php.ini

# Adicione no final do arquivo
extension=phpconfbr.so
```

Você pode adicionar uma linha ao final do arquivo sem utilizar o `nano`, escreva:

```shell
echo "extension=phpconfbr.so" >> /etc/php/8.3/cli/php.ini
```

## Para verificar se a extensão foi carregada

```shell
php -m

# Para pesquisar pela extensão específicamente
php -m | grep "phpconfbr"
```

# Créditos

Marcos Marcolin | marcolindev@gmail.com | [marcosmarcolin.com.br](https://marcosmarcolin.com.br)