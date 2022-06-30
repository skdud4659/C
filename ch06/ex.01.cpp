#include <stdio.h>

// 전역변수
int itemCnt = 0;
int money = 100;


// void : return 값이 없는 함수
// cost : 매개변수
void buyItem(int cost) {
  itemCnt++;
  money -= cost;
  printf("아이템을 구매했습니다.\n");
  printf("아이템 개수 : %d\n", itemCnt);
  printf("잔액 : %d\n", money);
}

int main() {
  // 30 : 인수.
  buyItem(30);
  buyItem(40);
}