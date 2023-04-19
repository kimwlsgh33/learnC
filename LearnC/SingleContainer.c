//
//  SingleContainer.c
//  LearnC
//
//  Created by 김진호 on 2023/02/26.
//

#include <stdio.h>

// Single linked list == Container ( 자료를 담는 것 )
/*
 자료 구조 == 데이터베이스
 
 Data => 구조체 형식으로
 
 그 구조체를 배열에 담기 ( 길이가 짧아짐 )
 
 디버깅을 잘써서, 메모리를 추척한다.
 - 리스트 출력은 별도 함수로 분리 ( 디버깅에 용이 )
 
 장난질을 친다.
 
 
 
 선형 구조
 포인터가 한개
 자기 다음을 가리킨다.
 
 Node에 담는다.
 Node속에 포인터가 있다.
 포인터는 또 다른 Node를 가리킨다.
 마지막 Node는 NULL을 가리킨다.
 */
