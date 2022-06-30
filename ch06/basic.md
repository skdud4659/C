# 함수
```cpp
// printf 정의
#include <stdio.h>

int main() {
  // printf 함수의 호출
  // main 함수의 정의
  printf("hello, world\n")
}
```

## 스코프
### 블록스코프
- 블록 : 함수의 중괄호 안에 여러 줄의 코드를 묶은 것
```cpp
if (i <= 10) {
  // 블록
  int a = 5;
  printf("%d", a);
  i++
}
```
  + 블록 내에 선언된 a는 블록의 밖에서 사용할 수 없다. = 블록은 a의 스코프가 된다.
- 중첩 블록
```cpp
if (i <= 10) {
  // 블록 1
  int a = 5;
  printf("%d", a);
  if (j <= 10) {
    //  블록 2
    int b = 10;
    printf("%d", b)
  }
  i++
}
```
- 다른 스코프에서 만들어진 같은 이름의 변수는 다른 변수이다.
```cpp
  int main() {
    if (조건) {
      int a = 10;
    }
    if (조건2) {
      int a = 20;
    }
  }
``` 
## 함수의 반환
- return
```cpp
 int buyItem(int cost) {
   if (money < cost) {
     // 아이템을 구매할 수 없을 때는 -1을 리턴하고 함수 종료.
     return -1;
   }
   // 아이템 구매 코드
 }
```

## c에서 함수에 인수를 넘겨주는 방법.
### call-by-value
- 변수에 들어있는 "값"이 함수에 복사되는 형태로 전달되는 것.
```cpp
#include <stdio.h>

void swap(int x, int y) {
  int tmp = x;
  x = y;
  y = tmp;
}

int main() {
  int a, b;
  scanf("%d%d", &a, &b); // 3. 5
  swap(a, b);
  printf("a=%d, b=%d\n", a, b); // 3, 5
}
```
- swap 함수가 호출되면 x, y라는 매개변수가 새로 만들어지기 때문에 a의 값인 3이 x에 복사되고 b의 값인 5가 y에 복사되지만 이는 a,b와는 다른 새로운 변수이기 때문에 기존 a,b의 값은 바뀌지 않는다.
### call-by-address
- 주솟값을 함수에 전달하는 것.
```cpp
#include <stdio.h>

void swap(int *px, int *py) {
  int tmp = *px;
  *px = *py;
  *py = tmp;
}

int main() {
  int a, b;
  scanf("%d%d", &a, &b); // 3. 5
  swap(&a, &b);
  printf("a=%d, b=%d\n", a, b); // 5, 3
}
```
- a, b의 주솟값을 매개변수로 전달하면서 해당 주소에 주솟값의 값이 담긴다.
### call-by-reference
- C++ 에만 존재.
- 변수에 별명을 붙여 전달.
- 레퍼런스 변수는 선언과 동시에 특정 변수를 가리켜야 한다.
```cpp
  int &ra = a;
  int &ra = a + 5; // error : 우변이 별명을 붙이고자하는 변수명이여한다.
  int &ra; // error : 선언과 동시에 변수를 가리켜야 한다.
```
```cpp
#include <stdio.h>

void swap(int &x, int &y) {
  int tmp = x;
  x = y;
  y = tmp;
}

int main() {
  int a, b;
  scanf("%d%d", &a, &b); // 3. 5
  swap(a, b);
  printf("a=%d, b=%d\n", a, b); // 5, 3
}
```

## 재귀함수
- 함수 내에서 함수 본인을 호출
```cpp
#include <stdio.h>

void rec() {
  printf("rec() 호출됨\n");
  rec();
}

int main() {
  rec();
}
```
  + 위 코드를 실행하면 "rec() 호출됨"이 무한 반복된다.
### 무한 루프에 빠지지 않게 하려면?
- 한계값 적용
```cpp
#include <stdio.h>

void rec(int n) {
  if (n > 5) {
    // n이 5보다 크면 함수가 종료.
    return;
  }
  rec(n+1)
}

int main() {
  rec(1)
}
```

## 배열을 매개변수로 넘기기
### 일차원 배열 매개변수
```cpp
#include <stdio.h>
void printArr(int parr[4]) {
  printf("parr의 값 : %d\n", parr); // 18349192
}

int main() {
  int arr[4] = {1, 2, 3, 4};
  printf("arr의 값 : %d\n", arr); // 18349192
  printArr(arr) // 배열의 내용물이 아닌 &arr[0]의 값이 넘어간다.
} 
```
- 겉으로는 배열처럼 보여도 내부적으로는 주솟값이 넘어가는 call-by-address 형태로 넘어간다.