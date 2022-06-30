#include <stdio.h>

int fact(int num) {
  if (num == 1) return 1;
  if (num == 2) return 2;
  if (num == 3) return 4;

	return fact(num - 1) + fact(num - 2) + fact(num - 3);
}

int main() {
	int n, result[12];
	int arr[12];
	int i;
	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	
	for (i = 0; i < n; i++) {
		result[i] = fact(arr[i]);
		printf("%d\n", result[i]);
	}

	return 0;
}