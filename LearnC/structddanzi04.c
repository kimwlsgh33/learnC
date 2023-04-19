//
//  structddanzi04.c
//  LearnC
//
//  Created by 김진호 on 2023/02/23.
//

#include <stdio.h>

// typedef 이용하여 형 재 선언 하기 - 구조체 사용시 struct 예약어 안써도됨!
// struct USERDATA2 > USERDATA2
typedef struct USERDATA2{
    char szName[32];
    char szPhone[32];
    struct USERDATA2 *pNext;
} USERDATA2;

int main2(void){
    USERDATA2 userList[4] = {
        {"김어준", "1234", NULL },
        {"정봉주", "2334", NULL },
        {"주진우", "3658", NULL },
        {"김용민", "4567", NULL }
    };
    
    USERDATA2 *pUser = NULL;
    
    // pNext에 주소 저장 ( 연결, 연결리스트 관점에서 노드라고 불리는 것들 )
    userList[0].pNext = &userList[1];
    userList[1].pNext = &userList[2];
    userList[2].pNext = &userList[3];
    
    // 시작 주소 저장
    pUser = &userList[0];
    
    // 다음 구조체의 주소가 없을 때 까지 반복
    while(pUser != NULL){
        // 현재 포인터의 주소속의 구조체 요소출력
        printf("%s, %s\n", pUser->szName, pUser->szPhone);
        
        // pUser속에 들어있는 다음 구조체의 주소를 가져옴
        pUser = pUser -> pNext;
    }
    
    return 0;
}
