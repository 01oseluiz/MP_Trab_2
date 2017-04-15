#include "conversor.h"

int computeNumber (int *symbols){
    int size, number = 0;
    int i;
    for(i=symbols[0]; i>0; i--){
        if(i==1 || symbols[i] <= symbols[i-1]){
            number +=symbols[i];
        }
        else if(symbols[i]>symbols[i-1]){
            number +=(symbols[i] - symbols[i-1]);
            i--;
        }
    }

    return number;
}

int* convertArabic (char *roman){
    int i;
    int *numbers;

    numbers = (int *) malloc((strlen(roman)+1)*sizeof(int));
    numbers[0] = strlen(roman);

    for(i=1; i<=strlen(roman); i++){
        switch(roman[i-1]){
            case 'i':
                numbers[i] = 1;
                break;
            case 'v':
                numbers[i] = 5;
                break;
            case 'x':
                numbers[i] = 10;
                break;
            case 'l':
                numbers[i] = 50;
                break;
            case 'c':
                numbers[i] = 100;
                break;
            case 'd':
                numbers[i] = 500;
                break;
            case 'm':
                numbers[i] = 1000;
                break;
            default:
                exit(3);
        }
    }

    return numbers;
}
