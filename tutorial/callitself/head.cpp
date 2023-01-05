#include "head.h"
// int mul(int x)
int mul(int x){
    if(x == 0){
        return 1;
    }
    else{
        return x * mul(x - 1);
    }
}
