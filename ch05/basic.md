# 배열과 포인터

## 배열
- 서로 같은 자료형의 변수를 특정 개수만큼 나열해 놓은 것
```cpp
int arr[5]; // 5칸짜리 배열이 만들어짐.

// 값 추가
arr[0] = 1;
arr[1] = 3;
arr[2] = 5;
arr[3] = 7;
arr[4] = 9;

// 배열의 초기화
int arr2[5] = { 1, 3, 5, 7, 9 }
```
- 배열의 칸 개수를 할당하고 싶지 않을 때에는 빈칸으로 두면 자동으로 만들어진다.
```cpp
int arr[] = { 1, 3, 5, 7, 9} // 5칸짜리 배열
```
- 칸수를 명시했는데 중괄호 안 수의 개수가 칸의 개수보다 적으면 나머지 칸들은 0으로 채워진다.

## 다차원 배열
### 이차원 배열
- 일차원 배열 여러 개를 또다시 늘어놓은 배열
- 표
- arr[i][j]는 arr의 i번 행(가로)의 j번 칸을 의미한다.
```cpp
// 이차원 배열의 초기화
int arr[2][3] = { { 1, 2, 3}, { 4, 5, 6 } }
```
- 행의 개수는 생략할 수 있지만 열은 불가하다.
```cpp
int arr[][3] = { { 1, 2, 3}, { 4, 5, 6 } }
```
### 삼차원 배열
- arr[i][j][z]

## 문자열
```cpp
char s[6] = "hello";
```
- 위 예제의 문자열 hello는 5글자 인데 배열을 6칸으로 잡았다.
  + 모든 문자열의 끝에는 널문자가 있기 때문에.
  + 중간에 널문자가 있으면 그 전까지만 출력된다.
  ```cpp
  char s[6] = "hello";

  // 동일하다
  char s[6] = { 'h', 'e', 'l', 'l', 'o', '\0' } // '\0'의 ASCII 값이 0
  char s[6] = { 'h', 'e', 'l', 'l', 'o', 0 }

  char noNull[] = "hello\0 world" // hello
  ```
- 문자열을 입력받을때는 &를 생략한다.
```cpp
scanf("%s", s)
```
  + 공백으로 구분된 여러 개의 단어를 입력하면 그중 가장 첫 번째 단어만 받아진다.
### 관련 함수
- strleng = string length
- strcpy = string copy
  + strncpy
    * 최대 n칸만 복사
    * 대상 문자열의 범위를 벗어날 경우 널문자는 복사되지 않는다.
    * strncpy(s, "hello world", sizeof(s));
- strcat = string concatenate
  + strncat
    * 최대 n글자만 복사
    * 끝에 널문자가 항상 자동으로 추가
    * 복사할 수 있는 최대 글자 수는 sizeof(s) - strlen(s) - 1
- strcmp = string compare
  + 일치할 경우 0, 앞 문자열이 사전순으로 빠를 경우 음수, 늦을 경우 양수

## 포인터(pointer)
- 변수의 주소를 저장하는 변수
```cpp
#include <stdio.h>

int main() {
  int a = 20;
  
  // 일반 변수와 구분하기 위에 *를 붙임.
  // 가리킬 변수의 형과 통일.
  int *ptr_a;
  
  // & : 주소값 > &a : a의 주소값
  ptr_a = &a;
  
  printf("a의 값 : %d\n", a); // 20
  printf("a의 주솟값 : %d\n", &a); // 1636216
  printf("ptr_a에 저장된 값 : %d\n", ptr_a); // 1636216 
  printf("ptr_a가 가리키는 변수의 값 : %d\n", *ptr_a); // 20
}
```
### 포인터의 *
- 포인터를 선언할 때(또는 초기화 할 때)
```cpp
int *ptr_a;
```
- 포인터 자체를 의미할 때는 *를 쓰지 않는다.
```cpp
ptr_a;
```
- 포인터가 가리키는 변수를 의미할 때는 *를 쓴다.
```cpp
*ptr_a;
```
### 더블 포인터
```cpp
#include <stdio.h>

int main() {
  int a = 10;
  
  int *ptr;
  ptr = &a;

  int **ptr_ptr;
  ptr_ptr = &ptr;

  printf("a = %d\n", a); // 10
  printf("&a = %d\n", &a);  // 1636216
  printf("ptr = %d\n", ptr);  // 1636216
  printf("&ptr = %d\n", &ptr); // 1834528
  printf("ptr_ptr = %d\n", ptr_ptr); // 1834528
}
```
### 배열 포인터
```cpp
int (*p_arr)[10];

// p_arr이 가리키는 배열의 i번 칸(주소)
(*p_arr)[i]

// p_arr의 i번 칸이 가리키는 대상
*p_arr[i]
```
### 포인터 배열
- 포인터들로 이루어진 배열
```cpp
  int *ptr[3];
```
