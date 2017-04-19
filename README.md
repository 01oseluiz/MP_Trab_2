# MP_Trab_2
2º Trabalho de MP

###############################################################
#         Conversor número Romano -> número Arabico           #
###############################################################

Author: José Luiz Gomes.
Materia: Metodos de Programação.
Data: 19/04/2017.

-> COMO USAR/ COMPILAR

Com o g++, gcc e gteste, devidamente instalados:
  Abrir o terminal na pasta src.
  Escrever a linha de comando:
    make
    ./conversor
    
Assim será compilado os arquivos, conversor.c (modulo do conversor), main.c (testes), conversor.h
e executado os testes, bem como gerado os arquivos gerados pelo gcov, dado que esta incluso ao makefile as flags para uso do gcov.

OBS: caso ocorra algum erro ao compilar utilizando o comando make, é possível que o local de intalação de seu gteste esteja em local diferente do usualmente utilizado, sugere-se que seja alterado o local de instalação do gteste para junto com os arquivos source do sistema, ou altere no makefile a variavel CFLAGS para incluir o local onde foi realizado a intalação.
