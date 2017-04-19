#include "conversor.h"

/**
	Objetivo: Computar um array de inteiros (valores de uma numero Romano), retornando um numero arabico.\n
	Parametros: Array de inteiros (tamanho variavel).\n
	Retorno: Numero inteiro.\n
	OBS: Funciona somente para entradas corretas.\n
*/
int computaNumero (int *simbolos){
    int numero = 0; //valor de saida
    int i;//var controle
    
    /*Percore ao inverso o vetor de inteiros (simbolos), computando os valores*/
    for(i=simbolos[0]; i>0; i--){
        if(i==1 || simbolos[i] <= simbolos[i-1]){
            numero +=simbolos[i];
        }
        else if(simbolos[i]>simbolos[i-1]){
            numero +=(simbolos[i] - simbolos[i-1]);
            i--;
        }
    }
    
    free(simbolos); //ponteiro criado na funcao posterior
    return numero;
}

/**
	Objetivo: Transformar um numero romano em um array de inteiro corresponte as letras do numero romano.\n
	Parametros: Uma string.\n
	Retorno: Array de inteiros.\n
	OBS: Funciona somente para entradas corretas.\n
*/
int* transformaArabico (char *roman){
    int i;//var controle
    int *numeros;

    numeros = (int *) malloc((strlen(roman)+1)*sizeof(int));
    numeros[0] = strlen(roman);

    for(i=1; i<=strlen(roman); i++){
        
        switch(roman[i-1]){
            case 'I':
                numeros[i] = 1;
                break;
            case 'V':
                numeros[i] = 5;
                break;
            case 'X':
                numeros[i] = 10;
                break;
            case 'L':
                numeros[i] = 50;
                break;
            case 'C':
                numeros[i] = 100;
                break;
            case 'D':
                numeros[i] = 500;
                break;
            case 'M':
                numeros[i] = 1000;
                break;
        }
    }

    return numeros;
}

/**
	Objetivo: Subdivider um numero inteiro de 4 algarismos em um array com seus respectivos algarismos.\n
	Parametros: Um inteiro.\n
	Retorno: Array de inteiros.\n
	OBS: Funciona somente para entradas corretas.\n
*/
int* subdivideNumero(int numero){
    int *sub_numeros;
    
    sub_numeros = (int *) malloc(4*sizeof(int));
    
    sub_numeros[0] = (numero / 1000);
    sub_numeros[1] = (numero%1000)/100;
    sub_numeros[2] = ((numero%1000)%100)/10;
    sub_numeros[3] = (((numero%1000)%100)%10);
    
    return sub_numeros;
}

/**
	Objetivo: Transformar um array de inteiros em um numero romano.\n
	Parametros: Array de inteiros.\n
	Retorno: String.\n
	OBS: Funciona somente para entradas corretas.\n
*/
char* transformaRomano(int* sub_numeros){
    int i;
    
    char centenas[10][5] = {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
    char dezenas[10][5] = {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
    char unidades[10][5] = {"","I","II","III","IV","V","VI","VII","VIII","IX"};
    
    char *numeroRomano;
    numeroRomano = (char*) malloc(30*sizeof(char));
    
    for(i=0; i<sub_numeros[0]; i++){                    //Adiciona simbologia de milhares caso haja
        numeroRomano[i] = 'M';
    }
    numeroRomano[i] = '\0';
    
    strcat(numeroRomano, centenas[sub_numeros[1]]);     //Concatena centenas
    strcat(numeroRomano, dezenas[sub_numeros[2]]);      //dezenas
    strcat(numeroRomano, unidades[sub_numeros[3]]);     //e unidades
    
    free(sub_numeros); //Ponteiro criado na funcao anterior
    
    return numeroRomano;
}

/**
	Objetivo: Converter um numero romano em um numero arabico.\n
	Parametros: String.\n
	Retorno: Numero inteiro.\n
	OBS: Realiza tratamento de excessões, para entradas diferentes das corretas.\n
		 Para tal realiza a conversão contraria fazendo uma prova real.\n
*/
int converteArabico(char *simbolos_entrada){
    int i;
    int Numero;
    char *check_simbolos, simbolos[30];
    
    strcpy(simbolos, simbolos_entrada); // Copia todos os dados para uma varial estatica
    
    for(i=0; i<strlen(simbolos); i++){              // Converte para maiusculo
        if(simbolos[i]>=65 && simbolos[i]<=122)     // Verifica se são letras
            simbolos[i] = toupper(simbolos[i]);
        else
            return -1;
    }
    
    Numero = computaNumero(transformaArabico(simbolos));            //Converte numero romano em arabico
    check_simbolos = transformaRomano(subdivideNumero(Numero));     //Converte numero arabico obtido acima para romano
    
    if(strcmp(simbolos,check_simbolos) == 0 && Numero <=3000){      //Compara tamanho maximo do número permitido (3000)
        free(check_simbolos);                                       //e semelhanca entre valor esperado e obtido para fins de prova real
        return Numero;
    }
    else{
        free(check_simbolos);
        return -1;
    }

}
