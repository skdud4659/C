#include <stdio.h>

int main() {
    int a = 10;
    int b = 20;

    int *ptr;

    ptr = &a;
    printf("ptr이 가리키는 변수에 저장된 값 : %d\n", *ptr); // 10
    printf("a의 값 : %d\n", a); // 10
    *ptr = 20;
    printf("a의 값 : %d\n", a); // 20

    ptr = &b;
    printf("ptr이 가리키는 변수에 저장된 값 : %d\n", *ptr); // 20
}
