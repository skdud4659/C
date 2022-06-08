#include <stdio.h>

int main() {
  int math = 90, korean = 95, english = 96;
  int sum = math + korean + english;
  double avg = sum / 3;

  printf("평균 점수 : %f\n", avg); // 93.000000

  double avg2 = (double)sum / 3;
  printf("평균 점수 : %f\n", avg2); // 93.666667
}