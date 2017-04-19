#include "conversor.h"
#include <gtest/gtest.h>

/** 
	Teste para função transformaArabico().\n
	Objetivo: Transformar um conjunto de simbolos romanos em um array de seus respectivos valores em arabico.\n
	Teste: Testado somente um valor de entrada correto "MDCLXXI". Uma vez que ele sempre recebera os valores no formato correto.\n
	A função passou no teste realizado.\n
*/
TEST(transformaArabico, Entrada_correta){
    int *numeros;
    
    numeros = transformaArabico((char*)"MDCLXXI");
    EXPECT_EQ(7,numeros[0]);//Quantidade de termos no array
    EXPECT_EQ(1000,numeros[1]);//M
    EXPECT_EQ(500,numeros[2]);//D
    EXPECT_EQ(100,numeros[3]);//C
    EXPECT_EQ(50,numeros[4]);//L
    EXPECT_EQ(10,numeros[5]);//X
    EXPECT_EQ(10,numeros[6]);//X
    EXPECT_EQ(1,numeros[7]);//I
    
    free(numeros);
}

/** 
	Teste para função computaNumero().\n
	Objetivo: Computar o array de numero arabicos gerado pela função transformaArabico, retornando o valor correspondente em arabico.\n
	Teste: Testado somente um valor de entrada correto (Entrada "MDCLXXI" Saida esperada 1671). Uma vez que ele sempre recebera os valores no formato correto.\n
	A função passou no teste realizado.\n
*/
TEST(computaNumero, Entrada_correta){
    int *numeros;
    int numero_arabico;
    
    numeros = transformaArabico((char*)"MDCLXXI");
    EXPECT_EQ(7,numeros[0]);//Quantidade de termos no array
    EXPECT_EQ(1000,numeros[1]);//M
    EXPECT_EQ(500,numeros[2]);//D
    EXPECT_EQ(100,numeros[3]);//C
    EXPECT_EQ(50,numeros[4]);//L
    EXPECT_EQ(10,numeros[5]);//X
    EXPECT_EQ(10,numeros[6]);//X
    EXPECT_EQ(1,numeros[7]);//I
    
    EXPECT_EQ(1671,computaNumero(numeros));
}

/** 
	Teste para função subdivideNumero().\n
	Objetivo: Transformar um numero arabico em um array de 4 algarismos, separando o número em seus 4 algarismos (EX: 1234 -> [1,2,3,4]).\n
	Teste: Testado somente um valor de entrada correto (Entrada 299, Saida [0,2,9,9]). Uma vez que ele sempre recebera os valores no formato correto.\n
	A função passou no teste realizado.\n
*/
TEST(subdivideNumero, Entrada_correta){
    int *numeros;
    
    numeros = subdivideNumero(299);
    
    EXPECT_EQ(0,numeros[0]);
    EXPECT_EQ(2,numeros[1]);
    EXPECT_EQ(9,numeros[2]);
    EXPECT_EQ(9,numeros[3]);
    
    free(numeros);
}

/** 
	Teste para função transformaRomano().\n
	Objetivo: transformar um conjunto de algarismo arabicos em um array de seus respectivos valores em romanos.\n
	Teste: Testado somente um valor de entrada correto (Entrada [0,2,9,9], Saida "CCXCIX").\n
	A função passou no teste realizado.\n
*/
TEST(transformaRomano, Entrada_correta){
    int *numeros;
    char* symbolos;
    
    numeros = subdivideNumero(299);
    symbolos = transformaRomano(numeros);
    
    EXPECT_EQ('C',symbolos[0]);
    EXPECT_EQ('C',symbolos[1]);
    EXPECT_EQ('X',symbolos[2]);
    EXPECT_EQ('C',symbolos[3]);
    EXPECT_EQ('I',symbolos[4]);
    EXPECT_EQ('X',symbolos[5]);
    
    free(symbolos);
}


/**
	Teste para função converteArabico().\n
	Objetivo: transformar um numero romano em um numero arabico, utiliza das demais funções para tal, sendo que seu principal objetivo
	é confirmar a veracidade do valor antes de retornar para o usuario.\n
	Teste: Testado somente um valor de entrada correto.\n
	A função passou no teste realizado.\n
*/
TEST(converteArabico, Entrada_correta){
    EXPECT_EQ(1,converteArabico((char*)"I"));
    EXPECT_EQ(9,converteArabico((char*)"IX"));
    EXPECT_EQ(11,converteArabico((char*)"XI"));
    EXPECT_EQ(20,converteArabico((char*)"XX"));
    EXPECT_EQ(29,converteArabico((char*)"XXIX"));
    EXPECT_EQ(39,converteArabico((char*)"XXXIX"));
    EXPECT_EQ(40,converteArabico((char*)"XL"));
    EXPECT_EQ(49,converteArabico((char*)"XLIX"));
    EXPECT_EQ(50,converteArabico((char*)"L"));
    EXPECT_EQ(89,converteArabico((char*)"LXXXIX"));
    EXPECT_EQ(99,converteArabico((char*)"XCIX"));
    EXPECT_EQ(200,converteArabico((char*)"CC"));
    EXPECT_EQ(299,converteArabico((char*)"CCXCIX"));
    EXPECT_EQ(400,converteArabico((char*)"CD"));
    EXPECT_EQ(535,converteArabico((char*)"DXXXV"));
    EXPECT_EQ(555,converteArabico((char*)"DLV"));
    EXPECT_EQ(1000,converteArabico((char*)"M"));
    EXPECT_EQ(2000,converteArabico((char*)"MM"));
    EXPECT_EQ(2038,converteArabico((char*)"MMXXXVIII"));
    EXPECT_EQ(2449,converteArabico((char*)"MMCDXLIX"));
    EXPECT_EQ(2999,converteArabico((char*)"MMCMXCIX"));
    EXPECT_EQ(3000,converteArabico((char*)"MMM"));
}

/**
    Teste da função converteArabico().\n
    \n
    Esta funcao deve tratar todos os casos de entrada do usuario.\n 
    Logo todas as anteriores somente iram receber valores corretos de entrada.\n 
    Foi testado os seguintes casos de entrada:\n
		- Symbolos em letras maiusculas e minuscolas;\n
		- Repetições excessivas;\n
		- Romanos incorretas;\n
		- Romanos inexistentes;\n
		- Acima do valor permitido (3000);\n
		\n
    Retornado -1 para erros de entrada ou valores inexistentes, retornado o número arabico correto no caso de entradas corretas.\n 
	OBS: o programa não verifica as seguintes entradas: '[' , ']' , '\' , '^' , '_' , ''' , ''.\n
 */
TEST(converteArabico, Entradas_incorretas){
    //ENTRADAS COM REPETICAO EXCESSIVA
    EXPECT_EQ(-1,converteArabico((char*)"IIII"));
    EXPECT_EQ(-1,converteArabico((char*)"VV"));
    EXPECT_EQ(-1,converteArabico((char*)"XXXX"));
    EXPECT_EQ(-1,converteArabico((char*)"LL"));
    EXPECT_EQ(-1,converteArabico((char*)"CCCC"));
    EXPECT_EQ(-1,converteArabico((char*)"DD"));
    
    //ENTRADAS MINUSCULAS
    EXPECT_EQ(2038,converteArabico((char*)"MMxXXVIIi"));
    EXPECT_EQ(2449,converteArabico((char*)"MMCdXLIx"));
    EXPECT_EQ(2999,converteArabico((char*)"mmCMXCIX"));
    
    //ENTRADAS ERRADAS
    EXPECT_EQ(-1,converteArabico((char*)"ICCC"));
    EXPECT_EQ(-1,converteArabico((char*)"VM"));
    
    //ENTRADAS INEXISTENTES
    EXPECT_EQ(-1,converteArabico((char*)"WI"));
    EXPECT_EQ(-1,converteArabico((char*)"-12"));
    
    //ENTRADA ACIMA DO PERMITIDO
    EXPECT_EQ(-1,converteArabico((char*)"MMMi"));
    
    //O PROGRAMA NAO VERIFICA AS SEGUINTES ENTRADAS INEXISTENTES:
    // '[' , ']' , '\' , '^' , '_' , ''' , '' 
}

int main(int argc, char **argv){
    testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}
