#include "conversor.h"
#include <gtest/gtest.h>


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

TEST(subdivideNumero, Entrada_correta){
    int *numeros;
    
    numeros = subdivideNumero(299);
    
    EXPECT_EQ(0,numeros[0]);
    EXPECT_EQ(2,numeros[1]);
    EXPECT_EQ(9,numeros[2]);
    EXPECT_EQ(9,numeros[3]);
    
    free(numeros);
}

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

/*
    TESTE DA FUNÇÃO converteArabico()
    
    Esta funcao deve tratar todos os casos de entrada do usuario
    Logo todas as anteriores somente iram receber valores corretos de entrada
    
    Esperado -1 para erros de entrada e o número arabico correto no caso de entradas corretas
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

int main(int argc, char **argv){
    
    testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}
