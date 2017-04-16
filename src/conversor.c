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
        
        switch(toupper(roman[i-1])){
            case 'I':
                numbers[i] = 1;
                break;
            case 'V':
                numbers[i] = 5;
                break;
            case 'X':
                numbers[i] = 10;
                break;
            case 'L':
                numbers[i] = 50;
                break;
            case 'C':
                numbers[i] = 100;
                break;
            case 'D':
                numbers[i] = 500;
                break;
            case 'M':
                numbers[i] = 1000;
                break;
            default:
                return NULL;
        }
    }

    return numbers;
}
