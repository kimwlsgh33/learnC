//
//  main.c
//  LearnC
//
//  Created by 김진호 on 2023/02/17.
//

// (컴파일) 전처리기 - 컴파일 전에, 소스코드에 특정작업 실시
// .h파일 : 선언 파일
#include <stdio.h> // 컴파일 전에, 소스코드에 stdio.h 파일 삽입
#include <stdlib.h> // malloc, free
#include <string.h>

// 함수 선언
// 반환 이름(매개변수)
// main() : program start function

void recOne(void){
    // 절차적으로 코드 작성 ( 순서 )
    printf("Hello, World!\n"); // 1줄 : 구문, 1줄을 나눈 것 : 항
    printf("Hello, Jinho!\n"); // "~~~~" : 문자(배)열 ( 배열 ㅋㅋ )
    printf("%f\n", 123.0 + 20.0);
    //===============================================================================================
    //===============================================================================================
    printf("%f\n", 123.45F);    //float - 32bit 라서 정확도가 떨어진다.
    printf("%f\n", 123.45);     //double
    //===============================================================================================
    //===============================================================================================
    printf("%f\n", 2147483648.0F - 20); // 오차 존재
    printf("%f\n", 2147483648.0);
    
    // char szBuffer[12] = {'H', 'e', 'l'};
    char szBuffer[12] = {"Hel"};
    puts(szBuffer);
}

void typePromo(void){
    int num1 = 0,num2 = 0;
    
    printf("두 정수를 입력하세요.: ");
    scanf("%d %d", &num1, &num2);
    printf("AVG : %.2f\n", (num1 + num2)/2.0);
}

void secTime(void){
    int second;
    scanf("%d", &second);
    printf("%d초는 %02d시간 %02d분 %02d초 입니다.\n", second, second/(60*60), second/60%60, second%60);
}

void testList(void){
    char cList[5];
    int aList[5] = { 0 };
//    printf("%d\n", sizeof(aList));
//    printf("%d\n", 20);
    aList[0] = 10;
    aList[1] = 20;
    aList[2] = 30;
    
    printf("aList : %p, %ld\n", aList, sizeof(aList));
    printf("&aList : %p, %ld\n", &aList, sizeof(&aList));
    printf("aList + 1 : %p\n", aList + 1);
    printf("aList + 2 : %p\n", aList + 2);
    // aList + 1                    // int[5] + 1 (4byte == int)
    // aList address + sizeof(int)
    // aList address + 4
    for(int i = 0; i < 20; i++){
        putchar('*');
    }
    putchar('\n');
    
    printf("cList : %p, %ld\n", cList, sizeof(cList));
    printf("cList + 1 : %p\n", cList + 1);
    // cList + 1                    // char[5] + 1 (1byte == char)
    
}

void testing(void){
    int height;
    printf("키를 입력하세요 : ");
    scanf("%d", &height);
    printf("결과 : %s\n", height >= 150 ? "합격" : "불합격" );
}

void busBil(void){
    int age, price = 1000;
    printf("나이를 입력하세요 : ");
    scanf("%d", &age);
    
    if(age < 14){
        if(age < 4){
            price = 0;
        } else {
//            printf("%f\n", 1 - 0.5);
            price = price - price * 0.5; // 모든 사칙 연산에 type promotion 적용됨
        }
    } else {
        if(age < 20){ // 청소년
            price = price - price * 0.25;
        }
    }
    
    printf("최종요금 : %d원\n", price);
    
}

void rectangle(void){
    int i = 0, j = 0;
    while(i<5){
        while(j<5){
            printf("*\t");
            j++;
        }
        printf("\n\n");
        j = 0;
        i++;
    }
}

void testSort(void){
    int aList[5] = { 30, 40, 10, 50, 20 };
    int i = 0, j = 0, nTmp = 0;
    
    // select
    int nIndexMin = 0;
    
    for(i = 0; i < 5; nIndexMin = ++i){
        // nIndexMin = i;
        for(j = i + 1; j < 5; j++){
            // 최소값 인덱스 구해서, nIndexMin에 넣기
            if(aList[nIndexMin] > aList[j]){
                nIndexMin = j;
            }
        }
        
        if(nIndexMin != i){
            nTmp = aList[i];
            aList[i] = aList[nIndexMin];
            aList[nIndexMin] = nTmp;
        }
    }

    
    // bubble
    /*
    for(i = 0; i < 5; i++){
        for(j = i + 1; j < 5; j++){
            if(aList[i] > aList[j]){
                nTmp = aList[i];
                aList[i] = aList[j];
                aList[j] = nTmp;
            }
        }
    }
     */
    
    for(i = 0; i < 5; i++){
        printf("%d\t",aList[i]);
    }
    putchar('\n');
}

void sqSort(void){
    int aList[5][5] = { 0 };
    int i = 0, j = 0, nCounter = 0;
    
    for(i = 0; i < 5; ++i){
        // 홀짝 구분
        if(i % 2 == 0)
            // 짝수 행
            for(j = 0; j < 5; ++j)
                //순방향으로 행을 채움
                aList[i][j] = ++nCounter;
        else
            // 홀수행
            for(j = 0; j < 5; ++j)
                aList[i][4-j] = ++nCounter;
    }
    
    // 배열 출력
    for(i = 0; i < 5; ++i){
        for(j = 0; j < 5; ++j)
            printf("%d\t", aList[i][j]);
        
        putchar('\n');
    }
}

void cochlea(void){
    int arData[5][5] = {};
    // 좌표
    int nX = -1, nY = 0;
    int nCount = 5; // 배열 칸수
    int nMaxCount = (nCount * 2) - 1; // 9
    // 증가하는 수
    int nData = 1;
    
    // 더하는 수
    int nAdd = 1;
    
    //
    int nFlag = 0;
    
    for (int i = 0; i < nMaxCount; i++) {
        // nCount = nCount - i % 2 // i가 홀수 일때 1뺌
        nCount -= i % 2;
        for (int j = 0; j < nCount; j++) {
            if (nFlag == 0) {
                nX += nAdd;
            } else {
                nY += nAdd;
            }
            arData[nY][nX] = nData++;
        }
        nFlag++;
        
        if (nFlag == 2) {
            nFlag = 0;
            nAdd *= -1;
        }
    }
    
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%2d ", arData[i][j]);
        }
        printf("\n");
    }
}



void lookup(void){
    // 나이정보는 선형구조이다.
    double aRate[10] = {
        0.0, 0.1, 0.25,
        0.5, 0.5,
        0.6, 0.65,
        0.8, 0.82, 0.97
    };
    
    int nAge = 0, i = 0, nFee = 1000;
    
    // 요금표를 출력한다.
    printf("요금표\n");
    for (i = 1; i <= 10; ++i)
        printf("%d세 요금 :\t%d원\n", i, (int)(nFee * aRate[i-1]) ); // 가격 * 과률금률
    putchar('\n');
    /*
     if(i == 0) { ... }
     else if(i == 1) { ...}
     ...
     else { ... }
     
     이런 중복된 반복문을 작성하지 않아도 된다!
     */
    
    printf("나이를 입력하세요. : ");
    scanf("%d", &nAge);
    
    // 입력 범위를 초과하면, 최소&최대값으로 강제조정
    if(nAge < 1)        nAge = 1;
    else if (nAge > 10) nAge = 10;
    
    // 나이에 맞는 배열요소를 선택하고 별다른 제어문 없이 즉시 값을 출력
    printf("최종요금 : %d원\n", (int)(nFee * aRate[nAge - 1]));
    putchar('\n');
}

void arraycross03(void){
    int aList[5][5] = { 0 };
    int i = 0, j = 0, nCounter = 0, nOffset = 1;
    
    for (i = 0; i < 5; ++i){
        // 행이 변경 될때마다, nCounter 초기값 변경
        
        // 짝수이면 행 * 5에서 시작
        // 0, 10, 20
        if(i%2 == 0)   nCounter = i * 5;
        // 홀수이면 i + 1후, * 5 + 1에서 시작
        // 11, 21
        else            nCounter = (i + 1) * 5 + 1;
        
        for(j = 0; j < 5; ++j){
            // nOffset이 양수면 nCount증가
            // 음수면 반대로 nCount감소
            nCounter += nOffset;
            // 항상 순방향으로 채움
            aList[i][j] = nCounter;
        }
        
        // 토글 스위치처럼 행마다 양수/음수 변경 - 홀수 == 음수
        // '-' : 부호변경 연산자
        nOffset = -nOffset;
    }
    
    for(i = 0; i < 5; ++i){
        for(j = 0; j < 5; ++j){
            printf("%d\t", aList[i][j]);
        }
        putchar('\n');
    }
}

void arraycross04(void){
    int aList[5][5] = {0};
    // nFlag 변수는 반복문 내부에서 매번 참/거짓으로 바뀐다.
    int i = 0, j = 0, nCounter = 0, nFlag = 1;
    
    for(i = 0; i < 5; ++i){
       // 토글을 위한 플래그 변수
        if(nFlag){
            // 정방향 채우기
            for(j = 0; j < 5; ++j)
                aList[i][j] = ++nCounter;
            // 다음 반복에서 거짓인 경우가 선택되도록 만듬
            nFlag = 0;
        } else {
            // 역방향 채우기
            for(j = 0; j < 5; ++j){
                aList[i][4-j] = ++nCounter;
            }
            // 다음 반복에서 참인 경우가 선택되도록 만듬
            nFlag = 1;
        }
    }
    
    // print
    for(i = 0; i < 5; ++i){
        for(j = 0; j < 5; ++j){
            printf("%d\t", aList[i][j]);
        }
        putchar('\n');
    }
}

void arraycross05(void){
    int aList[5][5] = {0};
    int i = 0, j = 0, nCounter = 0, nOffset = 1, nFlag = 1;
    
    for(i = 0; i < 5; ++i){
        if(nFlag == 1)  nCounter = i * 5;
//        else            nCounter =
        
        // 행열 토글
        if(nFlag){
            // 순방향 채우기
            for(j = 0; j < 5; ++j){
                nCounter += nOffset;
                if(nFlag)   aList[i][j] = nCounter;
                else        aList[j][i] = nCounter;
            }
            nFlag = 0;
        } else {
            // 역방향 채우기
            for(j = 0; j < 5; ++j){
                nCounter += nOffset;
                // 홀짝 토글
                if(nFlag)   aList[i][4-j] = nCounter;
                else        aList[4-i][j] = nCounter;
            }
            nFlag = 1;
        }
        
        // 순방향 역방향 토글
        nOffset = -nOffset;
    }
    
    for(i = 0; i < 5; ++i){
        for(j = 0; j < 5; ++j){
            printf("%d\t", aList[i][j]);
        }
        putchar('\n');
    }
}

void arraycross06(void){
    int aList[5][5] = { 0 };
    
    // 현재 위치 나타낼 인덱스 변수, 해당 칸에 적을 데이터
    int x = -1, y = 0, nCounter = 0;
    
    // 반복문에 사용할 변수
    int i = 0, j = 0, nLength = 9, nDirection = 1;
    
    // 9,7,5,3,1 (채워지는 개수), 총 다섯번 반복 // 증가, 감소에 따라 교차 결정 ( 증가, 감소 )
    for(nLength = 9; nLength > 0; nLength -=2){
        for(i = 0; i < nLength; ++i){
            // ( 행 -> 열 순으로 움직임 )
            // 행 움직임
            // 0 ~ 4 (5번 더함 - 마지막 인덱스 : -1 + 5 = 4)
            if(i < nLength / 2 + 1) x += nDirection;
            // 열 움직임
            // 5 ~ 8 (4번 더함 - 마지막 인덱스 : 0 + 4 = 4)
            else                    y += nDirection;
            
            // aList[0,0]부터 시작하기 위해서, 처음에 x에 더해진 nDirection값을 빼주어야 한다. ( x초깃값 -1 )
            aList[y][x] = ++nCounter;
        }
        // 방향 변경
        nDirection = -nDirection;
    }
    
    // 배열 출력
    for(i = 0; i < 5; ++i){
        for(j = 0; j < 5; ++j){
            printf("%d\t", aList[i][j]);
        }
        putchar('\n');
    }
}

void arraycross07(void){
    int aList[5][5] = { 0 };
    
    // 시작 지점이 aList[0][4]
    int x = 5, y = 0, nCounter = 0;
    int i = 0, j = 0, nLength = 9, nDirection = 1;
    
    for(nLength = 9; nLength > 0; nLength -= 2){
        for(i = 0; i < nLength; ++i){
            // 0 ~ 4, 5번 감소
            if(i < nLength / 2 + 1) x -= nDirection;
            else                    y += nDirection;
            // x가 감소 할때, y는 증가
            
            aList[y][x] = ++nCounter;
        }
        // 방향 변경
        nDirection = -nDirection;
    }
    
    for(i = 0; i < 5; ++i){
        for(j = 0; j < 5; ++j){
            printf("%d\t", aList[i][j]);
        }
        putchar('\n');
    }
}

// void (*)(void)
void pointerEx(void){
    int nData = 300;
    int *pnData = &nData;
    
    // 직접 지정
    *((int*)0x16FDFF240) = 600;
    
    // 간접 지정
    *pnData = 600;
    
    int aList[5] = { 40, 20, 50, 30, 10 };
    int *paList = aList;
    
    *(paList + 1) = 10; // int형 변수로 지정된다.
    paList[1] = 10;
}

void TestFunc2(int nParam){
    printf("TestFunc2() : %d\n", nParam);
    // TestFunc2(10);
    // 16진수, 직접지정 함수 호출
    ((void(*)(int))0x16FDFF240)(10);
    // 10진수, 직접지정 함수 호출
    ((void(*)(int))4264896)(10);
}

void pointerEx2(void){
    int nData = 10;
    int *pnData = &nData;

    printf("%d\n", *pnData);
    
}

void pointerEx3(void){
    int aList[5] = { 40, 20, 50, 30, 10 };
    int nTotal = 0;
    
    int *paList = aList;
    
    while(paList < aList + 5){
        // paList를 간접지정해서(저장된 주소에 있는값을 int로 해석), 있는 곳의 정보 가져옴
        nTotal += *paList;
        // 주소 + 1 , int : 4byte
        paList++;
    }
    printf("nTotal : %d\n", nTotal);
}


void memoryEx1(void){
    int *pList = NULL;
    
    pList = malloc(sizeof(int) * 3);
    
    pList[0] = 10;
    pList[1] = 20;
    pList[2] = 30;
    
    free(pList);
}

void putStr(void){
    char szBuffer[6] = { "Hello" };
    puts(szBuffer);
}

void subAdd(void){
    char hello[6] = "Hello";
    printf("%d\n", &hello[2] - hello);
    
    int aList[5] = { 1, 2, 3, 4, 5 };
    printf("%d\n", &aList[2] - aList);
}

void typePtr(void){
    char szBuffer[12] = "I am a boy";
    
    int nData = *((int*)szBuffer);
    
    puts(&nData);
}

void Swap(int *pLeft, int *pRight){
    int nTmp = *pLeft;
    *pLeft = *pRight;
    *pRight = nTmp;
}

int GetFactorial(int nParam){
    int nResult = 0;
    if(nParam == 1) return 1;
    
    nResult = nParam * GetFactorial(nParam - 1);
    return nResult;
}

void PutData(char *pszParam){
    if(*pszParam == '\0')
       return;
    
    PutData(++pszParam);
    
    putchar(*pszParam);
}

typedef struct USERDATA{
    unsigned int nAge;
    char szName[12];
    char szPhone[12];
    unsigned char sex;
} USERDATA;

void Structure(void){
    USERDATA a;
    a.nAge = 27;
    strncpy(a.szName, "Jinho", sizeof(a.szName));
//    strcpy(a.szName, "Jinho");
    strncpy(a.szPhone,"01091186277", sizeof(a.szPhone));
//    strcpy(a.szPhone, "01091186277");
    a.sex = 'M';
}

void GetUserData(USERDATA *pUser){
    // 주소값을 받아와서, 값을 초기화하므로
    // 지역변수에서 해당 구조체를 복사할 필요가 없어진다. ( 스택 메모리 확보 )
    scanf("%d%*c", &pUser -> nAge);
    fgets(pUser -> szName, sizeof(pUser -> szName), stdin);
    // fgets로 받은 문자열의 마지막요소 ('\n')을 0으로 변경
    // user.szName[strlen(user.szName) - 1] = 0;
    fgets(pUser -> szPhone, sizeof(pUser -> szPhone), stdin);
}

void structfunc01(void){
    // user : 구조체 메모리 공간을 의미
    USERDATA user = { 0 };
    
    // Call by reference
    // &user : 구조체 메모리 주소를 의미
    GetUserData(&user);
    printf("%d살\t%s\t%s\n", user.nAge, user.szName, user.szPhone);
}

USERDATA GetUserData2(void){
    // 메모리 할당
    USERDATA user = { 0 };
    user.nAge = 26;
    strncpy(user.szName, "Hoseong", sizeof(user.szName));
    strncpy(user.szPhone, "3847", sizeof(user.szPhone));
    return user;
}

void structfunc02(void){
    // 메모리 할당
    USERDATA user = { 0 };
    
    // 값 복사
    user = GetUserData2();
    
    printf("%d살\t%s\t%s\n", user.nAge, user.szName, user.szPhone);
}

int main1717(int argc, const char * argv[]) { // BlockScope ( 중괄호, 변위 ) - 여러 구문을 한 단위로 묶는 것
    structfunc02();
    return 0;
}

