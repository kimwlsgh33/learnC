//
//  fileIO.c
//  LearnC
//
//  Created by 김진호 on 2023/02/24.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void gets01(void){
    char szName[32] = {0};
    
    printf("이름을 입력하세요");
    
    // 매개변수로 메모리(버퍼) 주소를 받음
    // 표준입력(stdin) => 메모리(버퍼)
    gets(szName);
    
    printf("당신의 이름은 ");
    
    // 메모리(버퍼) => 표준출력(stdout)
    puts(szName);
    puts("입니다.");
}

void scanf01(void){
    char szName[32] = {0};
    int nAge = 0;
    
    printf("나이를 입력하세요. : ");
    scanf("%d", &nAge);
    
    // 입력 버퍼 초기화 하기
    // fflush(stdin);
    fpurge(stdin);
    
    printf("이름을 입력하세요. : ");
    // 버퍼에 '\n'이 존재하기 때문에, 해당내용을 바로 복사해버린다.
    gets(szName);
    
    printf("%d, %s\n", nAge, szName);
}

void file01(void){
    // 파일 생성후, 포인터에 주소 저장
    // "w" : 이미 존재하면 삭제하고 생성
    // PRN, CON, COM1
    FILE *fp = fopen("Test.txt", "w");
    
    fprintf(stdout, "Hello File I/O\n");
    
    // 해당 파일 닫기
    fclose(fp);
    
    system("Test.txt");
}

void fileflush(void){
    // stdin == 표준입력 버퍼 == 파일
    FILE *fp = stdin;
    printf("Input string: ");
    
    // 사용자에게 "문자열"을 입력받은 후, 첫 글자를 읽어와 출력
    printf("getchar( ) - %c\n", getchar( ));
}

int main_file123(void){
    fileflush();
    
    return 0;
}
