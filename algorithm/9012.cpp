#include <stdio.h>

int main() {
  int num;
  scanf("%d", &num);

  char bracket[50];
  for (int i=0; i<num; i++) {
    int cnt = 0;
    scanf("%s", bracket);
    for (int j=0; j<strlen(bracket);j++){
      if (bracket[j] == '(') {
        cnt++;
      } else {
        cnt --;
      }

      if (cnt < 0) {
        printf("NO\n");
        break;
      }
    }
    if (cnt == 0) {
      printf("YES\n");
    } else if (cnt > 0) {
      printf("NO\n");
    }
  }
}