//
//  Recursion.c
//  LearnC
//
//  Created by 김진호 on 2023/02/26.
//

#include "Recursion.h"

int testRecursion(int a){
    // for(a = 5;조건; a-1)
    if(a <= 0) return 0;
    printf("test(%d)\n", a);
    return testRecursion(a - 1);
}
