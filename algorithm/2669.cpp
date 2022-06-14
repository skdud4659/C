#include <stdio.h>

int main() {
  int arr[101][101] = {0};
  int cnt = 0, x1, y1, x2, y2;

  for (int i = 0; i < 4; i++) {
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
    for (int x = x1; x < x2; x++) {
      for (int y = y1; y < y2; y++) {
        arr[x][y] = 1;
      }
    }
  }
  for (int i = 0; i < 101; i++) {
    for (int j = 0; j < 101; j++) {
      if (arr[i][j] == 1) cnt++;
    }
  }
  printf("%d", cnt);
  return 0;
}

