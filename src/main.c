#include "conversor.h"

int main(int argc, char **argv){

    char numeroromano[15];
    gets(numeroromano);

    printf("Romano: %s\nArabico: %d\n", numeroromano, computeNumber(convertArabic(numeroromano)));

    return 0;
}