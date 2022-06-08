#include <stdio.h>

int main() {
  printf("%c + %c = %c\n", '2', '3', '2'+'3'); //2 + 3 = e
  // 2의 ASCII(50) + 3의 ASCII(51) = 101 = ASCII 'e'

  char a = 'A';
  printf("%c의 ASCII값은 %d\n", a, a); // A의 ASCII값은 65
}