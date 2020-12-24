#include "primos.h"

int ehprimo(int num){
    int flag = 0, i;

    //flag incrementa quando eh divisivel
    for(i = 2; i <= num/2; i++){
        if(num%i==0){
            flag++;
            break;
        }
    }
    if(flag == 0){
        //eh um numero primo
        return 1;
    }
    else{
        //nao eh um numero primo
        return 0;
    }
}