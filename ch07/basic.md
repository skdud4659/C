# 구조체
- 여러 정보를 묶은 하나의 대상.

## typedef (type definition)
- 기존 자료형에 별칭
  + 긴 자료형 이름을 편리한 이름으로 줄일 수 있다.
  + 변수가 어떤 정보를 저장하는지 좀 더 분명히 드러난다.
```cpp
// typedef 원래_타입_이름 새로운_타입_이름;
typedef unsigned short int age_t;
age_t userAge; 
```

## 구조체 만들기
- 구조체 멤버는 모두 같은 타입일 필요는 없다.
```cpp
// 자료형
struct { float x, y; }
// pos라는 구조체 변수
// 구조체에 속한 변수 : 멤버 변수
struct { float x, y; } pos;

// 아래 방법으로 접근이 가능함.
pos.x
pos.y

// 구조체 초기화
struct { float x, y; } pos = { 1.5, 2.2};

// c++에서만 가능
struct { float x, y; } pos
pos = { 1.5, 2.2 };
```

## 구조체 타입 정의하기
- typedef를 통해 별칭을 붙일 수 있다
```cpp
typedef struct { float x, y; } Point;
Point pos = { 1.5, 2.2 };

// 다른 방법
// struct 구조체이름 { 멤버 선언 };
struct Point { float x, y; };
// C++
Point pos = { 1.5, 2.2 };
// C
struct Point pos = { 1.5, 2.2 };
```
  + C에서만 구조체 변수 선언 앞에 struct를 붙여야 한다.

### 구조체 활용
```cpp
#include <stdio.h>

struct ProductInfo {
  int num;
  char name[100]
  int cost;
}

int main() {
  ProductInfo myProduct = { 4797283, "제주 한라봉", 19900};
}
```
#### 구조체 정렬
- 위 예제 ProductInfo myProduct = { 4797283, "제주 한라봉", 19900};의 size는 108이다.
  + int num(4) + char name[100](100) + int const(4) = 108
  만약, myProduct.name이 4의 배수가 아닌 101이라면?
    * 4 + (100 + 4(:1 + 3)) + 4 = 112 > 컴파일러가 다음 멤버인 cost를 할당할 때 cost의 주솟값을 크기의 배수가 되게 맞추려는 경향이 있기 때문에 아무데도 사용되지 못하는 메모리가 생긴다.
    낭비되는 메모리 공간이 생기지만, 멤버들을 모두 붙여놓는다면 일부 시스템에서 실행 효율이 낮아질 수 있다.

### 멤버 함수
- 구조체에 함수를 멤버로 두는 것
```cpp
#include <stdio.h>

struct Time {
  int h, m, s;

  int totalSec() {
    return 60 * 60 * h + 60 * m + s;
  }
};

int main() {
  Time t = { 1, 22, 48};
  printf("%d\n", t.totalSec())
}
```

## 구조체 변수 포인터
```cpp
#include <stdio.h>

struct ProductInfo {
  int num;
  char name[100]
  int cost;
}

int main() {
  ProductInfo myProduct = { 4797283, "제주 한라봉", 19900};
  ProductInfo *ptr_product = &myProduct;

  printf("상품 번호 : %d\n", (*ptr_product).num )
}
``` 