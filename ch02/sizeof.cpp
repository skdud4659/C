#include <stdio.h>

int main() {
  printf("%d %d %d %d\n", sizeof(int), sizeof(char), sizeof(float), sizeof(double)); // 4 1 4 8
  int a;
  char b;
  float c;
  double d;

  printf("%d %d %d %d\n", sizeof(a), sizeof(b), sizeof(c), sizeof(d)); // 4 1 4 8
}