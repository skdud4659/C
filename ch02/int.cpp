#include <stdio.h>

int main() {
  int a= 5;
  int b = 3;

  // 덧셈
  int add = a + b;
  // 뺄셈
  int sub = a - b;
  // 곱셈
  int mul = a * b;
  // 몫
  int div = a / b;
  // 나머지
  int mod = a % b;

  printf("%d + %d = %d\n", a, b, add); // 5 + 3 = 8
  printf("%d - %d = %d\n", a, b, sub);  // 5 - 3 = 2
  printf("%d * %d = %d\n", a, b, mul);  // 5 * 3 = 15
  printf("%d / %d = %d\n", a, b, div);  // 5 / 3 = 1
  printf("%d %% %d = %d\n", a, b, mod);  // 5 % 3 = 2
}