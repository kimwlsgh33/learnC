//
//  union01.c
//  LearnC
//
//  Created by 김진호 on 2023/02/24.
//

#include <stdio.h>

// union : 공용체, 같은 크기의 메모리를 다른 방식으로 해석하겠다고 정의
typedef union _IP_ADDR{
    // 모두다 4byte크기
    int nAddress;
    short awData기[2];
    unsigned char addr[4];
} IP_ADDR;

int fefjefj124134124(void){
    IP_ADDR addr;
    addr.addr[0] = 192;
    addr.addr[1] = 168;
    addr.addr[2] = 0;
    addr.addr[3] = 1;
    
    printf("%d\n", addr.nAddress);
    
    return 0;
}
