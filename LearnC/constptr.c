//
//  constptr.c
//  LearnC
//
//  Created by 김진호 on 2023/02/24.
//

#include "constptr.h"

#define MAX_LEN 32

void ConstPtr(void){
    char szBuffer[MAX_LEN] = { "I am a boy. " };
    
    // szBuffer를 상수화한 포인터
    // pszBuffer 포인터를 사용해서, 대상을 변경할 수 없음 ( 읽기 전용 포인터 )
    const char *pszBuffer = szBuffer;
    
    
    char aszBuffer[MAX_LEN] = {"hello"};
    // 상수 포인터가 아니므로, 주소 자체는 변경가능
    pszBuffer = aszBuffer;
    
    szBuffer[0] = 'i';
    
    // 해당 포인터를 통해서 찾아간 대상은, l-value로 사용할 수 없음
    // *pszBuffer = 'i';
    
    char* const pNewBuffer = aszBuffer;
    
    // 상수포인터
    // 할당된 주소를 변경할 수 없음
    // pNewBuffer = szBuffer;
}

void PrintValue(const char *pszBuffer){
    //
    // pszBuffer[0] = 'i';
    puts(pszBuffer);
}

int main_constptr(void){
    
    // void (*)(const char*)형의 데이터의 주소를 저장하고 있는 변수
    void (*pfPrintValue)(const char*) = PrintValue;
    
    char szBuffer[MAX_LEN] = { "I am a boy. " };
    
    PrintValue(szBuffer);
    
    ConstPtr();
    return 0;
}
