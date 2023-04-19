#include <stdio.h>

// 테스트를 위한 함수
void PrintFunc01(void){
  printf("PrintFunc01\n");
}

void PrintFunc02(void){
  printf("PrintFunc01\n");
}

void PrintFunc03(void){
  printf("PrintFunc01\n");
}

int main(void) {
  // 1. 함수 포인터 배열이 있다.
  // 2. 그 배열속 원소는, 주소값을 가지고 있다. ( 포인터)
  // 3. 그 주소에는, void (*)(void) 타입의 함수가 있다.
  void (*pFunc[3])(void) = {PrintFunc01, PrintFunc02, PrintFunc03};

  int nSelect;
  scanf("%d", &nSelect);
  // 선택한 함수를 호출
  pFunc[nSelect]();

  return 0;
}
