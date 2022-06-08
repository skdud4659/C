#include <stdio.h>

int main() {
  float a= 9.8;
  float b = 3.14;

  // 덧셈
  float add = a + b;
  // 뺄셈
  float sub = a - b;
  // 곱셈
  float mul = a * b;
  // 몫
  float div = a / b;

  printf("%f + %f = %f\n", a, b, add); // 9.8 + 3.14 = 12.940001
  printf("%f - %f = %f\n", a, b, sub);  // 9.8 - 3.14 = 6.660000
  printf("%f * %f = %f\n", a, b, mul);  // 9.8 * 3.14 = 30.772001
  printf("%f / %f = %f\n", a, b, div);  // 9.8 / 3.14 = 3.121019
}