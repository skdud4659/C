#include <stdio.h>

int main() {
  // 증감 연산자
  int a = 5;
  printf("a는 원래 %d였다.\n", a); // > 5
  a++; // = a += 1
  printf("1이 증가해서 %d가 되었다!\n", a); // > 6
  a--; // = a -= 1
  printf("1이 감소해서 %d가 되었다!\n", a); // > 5
  // 전치 증가 연산
  int b;
  b = ++a;
  printf("a = %d\n", a); // 6
  printf("b = %d\n", b); // 6
  // 후치 증가 연산
  b = a++;
  printf("a = %d\n", a); // 7
  printf("b = %d\n", b); // 6
}