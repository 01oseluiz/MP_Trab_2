#ifndef CONVERSOR_H
#define CONVERSOR_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int computaNumero(int*);//--------Computa o array de números
int* transformaArabico(char*);//--Transfoma um simbolo em seu respectivo número

int* subdivideNumero(int);//------Subdivide um inteiro em dezenas/centenas..
char* transformaRomano(int*);//---Transforma o array subdvidido em romanos

int converteArabico(char*);//-----Compara o número romano obtido com o de entrada e trata excessoes

#endif
