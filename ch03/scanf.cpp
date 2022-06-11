#include <stdio.h>
#include <cmath>

int main() {
  // int a,b;

  // a,b 값을 키보드로 입력받은 후 순서대로 각각 저장한다.
  // 더블을 입력받을 때는 %lf 라는 서식 지정자를 사용해야한다.
  // scanf("%d%d", &a, &b);
  // printf("%d + %d = %d\n", a, b, a+b);

  float c,d;
  scanf("%f%f", &c, &d);
  printf("%.2f + %.2f = %.2f\n", c, d, c+d);

}