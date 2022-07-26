# 동적 할당과 객체 복사
- 객체가 하는 중요한 일 중 하나는 메모리를 할당하고 관리하는 것.

## 동적 할당
### 정적 할당
```cpp
// 전역 변수 b는 프로그램이 시작할 때 생기고, 프로그램이 끝날 때 소멸된다.
int b;
void foo() {
  // 지역 변수 a는 foo 함수가 선언되는 시점에 생기고 끝나면 사라진다.
  int a;
}
int main() {
  foo();
}
```
- 위 변수 예제는 정적 할당.
- 선언된 변수들이 메모리를 얼마나 사용할지를 컴파일 시간에 예측할 수 있다.
- 사용이 편리하다.
- 메모리가 언제 할당되고 해제되는지 정해져 있기 때문에 통제할 수 있는 방법이 없다.
### 동적 할당
- 프로그램 실행 <b>도중에</b> 새로운 메모리 공간을 사용할 수 있게 할당하는 것
- 정확히 언제 메로리를 얼마만큼 할당하고, 그 할당된 메모리를 언제 해제할 것인지를 직접 지정할 수 있다.
  - 필요한 만큼만 메모리를 할당해서 쓰고 필요 없을 때는 폐기할 수 있어 메모리를 좀 더 효율적으로 사용이 가능하다.
#### 변수 동적 할당
```cpp
// 정적 할당
int a = 5;
int a(5);
int a = int(5);
// 다 같은 표현

// 동적 할당
int *a = new int(5);
```
- new 키워드가 붙으면 동적할당이라고 판단.
1. 메모리상에 int를 담는 공간 하나가 동적으로 생성됨
2. 1번에 5라는 값이 들어감.
3. 값이 들어간 1번 공간의 주솟값이 리턴됨.
> 메모리상의 공간은 이름은 없지만 a라는 포인터가 이 공간을 가리키고 있으므로 a를 통해 이 공간에 접근이 가능하다.   
```cpp
// *a : a가 가리키는 공간
cout << *a << endl;
// 그 공간에 새로운 값 10이 들어감.
*a = 10;
```
#### 메모리 해제
- = 더 이상 이 메모리 공간을 사용하지 않는다.
- 메모리를 해제하지 않으면 나중에 새로운 메모리 공간이 필요할 때 그 공간을 다시 쓰지 못하게 되므로 메모리 낭비가 발생 = 메모리 누수
- 모든 동적 할당된 메모리는 <b>반드시 해제</b>되어야 하고, 반드시 <b>한 번만 해제</b>되어야한다.
> 프로그램이 종료되면 다시 메모리를 사용할 수 있지만 실행되는 동안에는 메모리 관리가 제대로 되지 않는다.
```cpp
// 메모리 해제
delete a;
```
```cpp
int main() {
  // 동적 할당 > a 포인터 선언
  int *a = new int(5);

  // 포인터 자체
  cout << a << endl; // 008C9EB0(주솟값)
  // 포인터가 가르키는 변수
  cout << *a << endl; // 5
  *a = 10;
  cout << a << endl; // 008C9EB0(주솟값)
  cout << *a << endl; // 10

  delete a;
}
```
#### 배열 동적 할당
```cpp
int *arr = new int[10];
```
- 10칸짜리 int형 배열이 생기고 그 첫번째 칸의 주솟값이 리턴되어 arr로 들어감
- 🌟 arr는 배열 포인터가 아니라 int 하나를 가리키는 포인터이다.
```cpp
// 동적 할당 초기화
int *arr = new int[5] {1,2,3,4,5};
```
- 동적 할당 배열의 칸수에는 변수를 넣을 수 있다.
```cpp
int n = 5;
int *arr = new int[n];
n++; // n의 값이 변한다는거지 배열의 칸수가 변한다는 뜻은 아님!
```
- 메모리 해제
```cpp
delete[] arr;
```
#### 객체 동적 할당
- new 뒤에 객체의 생성자를 호출
- 객체의 생성자는 객체가 생성되는 new에서 실행되고, 소멸자는 객체가 소멸되는 delete에서 실행.
---
## 깊은 복사와 얕은 복사
### 얕은 복사
- 참조만 복사되었다.
- 주솟값만 복사되었다.
```cpp
int *a = new int(3);
// b라는 포인터를 만들고 a에 들어 있는 주솟값을 b에도 넣으라는 말
// = a,b 모두 같은 공간을 가리키고 있음.
int *b = a;
*a = 5;
cout << *a << endl; // 5
cout << *b << endl; // 5
delete a;
```
- int *b = a에서 실제 int를 담는 공간과 그 공간에 들어있는 값이 복사된 것이 아니라 주솟값만 복사되어 공간이 같아진다.
### 깊은 복사
```cpp
int *a = new int(3);
// b는 a가 가리키는 공간이 아닌 새로 만들어진 int 공간을 가리키고 있고 그 공간에 단순히 *a(a가 가리키는 공간에 들어있는 값)이 들어간다. > 3
int *b = new int(*a);
*a = 5;
cout << *a << endl; // 5
cout << *b << endl; // 3
delete a;
```
> ex

```cpp
class A {
  public:
    A(int x, int *y): x(x), y(y) {}
    int x;
    int *y;
}
int main() {
  A a(1, new int(2));
  // 어떤 객체를 다른 객체에 대입하려고 하면 모든 멤버가 복사
  // a.y와 b.y는 같은 공간을 가리키므로 얉은 복사
  A b = a;
  // a.x와 b.x는 다른 공간에 존재함으로 b.x에 반영되지 않음.
  a.x = 3;
  // a.y가 가리키는 공간이 4로 값이 바뀌었으니 복사된 b.y도 동일
  *a.y = 4;
  cout << b.x << endl; // 1
  cout << *b.y << endl; // 4
  delete a.y;
}
```
---
## 복사 생성자와 복사 대입 연산자
### String 클래스 만들기
- 문자열을 저장하는 string 자료형(실제로는 클래스)
```cpp
class String {
  public:
    // 아무런 매개변수도 받지 않는다.
    String() {
      strData = NULL;
      len = 0;
    }
    // 포인터 형태의 문자열을 받고 있다.
    String(const char *str) {
      // 1. strlen 함수를 사용해 문자열의 길이를 알아내고
      // 2. len에 그 길이를 저장
      len = strlen(str);
      // 3. 문자열을 저장할 공간을 동적 할당(NULL 문자 때문에 문자열의 길이보다 한 칸 많은 공간을 할당해야함.)
      strData = new char[len + 1];
      // 4. strcpy를 사용해 strData에 str 복사.
      strcpy(strData, str); // 깊은 복사
    }

  ~String() {
      if (strData != NULL) {
        delete[] strData;
      }
    }

  const char *GetStrData() const {
    if (strData) return strData;
    return "";
  }
  int GetLen() const {
    return len;
  }

  private:
    // C스타일 문자열(널 문자로 끝나는 char배열)을 동적 할당 후 포인터로 가리킴.
    char *strData;
    // 문자열의 길이
    int len;
}

int main() {
  String s1;
  String s2("hello");

  cout << s1.GetLen() << endl; // 0
  cout << s1.GetStrData() << endl; // ""
  cout << s2.GetLen() << endl; // 5
  cout << s2.GetStrData() << endl; // hello
}
```
### 복사 생성자 오버로딩
```cpp
// 위 예제에서 main 함수만 수정
int main() {
  String s1("hello");
  String s2 = s1;

  cout << s2.GetLen() << endl; // 5
  cout << s2.GetStrData() << endl; // hello
}
```
- 런타임 에러가 발생한다.

> String s2 = s1; 과 같이 객체를 복사하면 모든 멤버의 값이 다른 객체로 복사된다.    s1.strData와 s2.strData는 같은 메모리 상의 공간을 가리키게 된다. 그런 상황에서 s1의 소멸자와 s2의 소멸자가 호출될 때, 같은 메모리를 두 번 해제하려고 하기 때문에 런타임 에러가 발생한다.

#### 실제 일어났으면 하는 일
- 애초에 String 객체가 복사될 때부터 strData가 가리키는 데이터를 얕은 복사가 아닌 깊은 복사를 하여 동적 할당된 "hello" 문자열 자체가 복사되는 것.

#### 복사 생성자
- 객체가 복사 생성될 때 실행되는 생성자
```cpp
// 복사 생성 : 아래와 같이 객체를 선언하는 동시에 어떤 다른 객체의 값으로 초기화하는 경우
String s2 = s1;
String S2(S1);
```
- 복사 생성자를 특별히 만들어 놓지 않은 상태에서 복사 생성을 하게 되면 모든 멤버가 단순히 복사된다.
- 깊은 복사를 위해서는 복사 생성자를 별도로 만들어야 한다.
```cpp
String(const String &rhs) {
  len = rhs.len;
  strData = new char[len + 1];
  strcpy(strData, rhs.strData);
}
```
#### 복사 생성자에서 매게변수를 call-by-reference로 받는 이유
- call-by-value로 받게 되면 복사 생성자 안에서 부득이하게 다시 복사 생성자를 호출할 수밖에 없는 상황이 벌어진다.
- 객체 하나당 멤버 변수가 100개라면, 객체 하나를 매개변수로 넘기기 위해서 멤버 변수 100개를 일일이 복사해야하기 때문에 그냥 레퍼런스로 넘기는 것.

#### 복사 대입 연산자 오버로딩
- 객체가 선언된 이후에 대입하면 어떡하지?
```cpp
String s1("hello");
String s2; // 선언
s2 = s1; // 대입
```
- c++에서 단순 대입은 어떠한 객체도 새로 생겨나지 않기 때문에 생성자가 호출되지 않고 생성자는 객체가 처음 생성될 때만 호출될 수 있으며 한 번 생성된 객체의 생성자를 다시 호출할 수 있는 방법은 없다.
```cpp
String &operator=(const String &rhs) {...}
```
- s2 = s1;은 s2.operator=(s1)과 같은 말이기 때문에 String 객체에서 String 객체로 단순 대입을 할 경우 위와 같이 생긴 연산자가 호출된다.
- 대입 연산자에 등호가 있는 이유는 a=b=c는 a=(b=c)와 동일하고 b=c는 b의 값을 리턴하여 a에 대입하기 때문에 복사 대입을 수행한 후 자기 자신을 리턴하게끔 만들면 된다.
```cpp
String &operator=(const String &rhs) {
  // 만약 자기 자신에 자기 자신을 대입할 경우 delete로 메모리를 해제시키면 본인도 사라져서 더 이상 문자열을 찾을 수 없기 때문에 제대로 작동하지 않는다.
  if (this != &rhs) {
    len = rhs.len;
    // 대입 연산 실행 전, 이미 할당된 문자열들이 있는데 이를 지우고 새로 할당된 공간의 주소값을 넣으면 기존의 공간은 삭제되지 않은 채 더 이상 접근할 방법이 없어지기 때문에 메모리 해제를 먼저 시켜준다.
    delete[] strData;
    strData = new char[len+1];
    strcpy(strData, rhs.strData);
  }
  return *this;
}
```

#### 최종 코드
```cpp
class String {
  public:
    // 아무런 매개변수도 받지 않는다.
    String() {
      strData = NULL;
      len = 0;
    }
    // 포인터 형태의 문자열을 받고 있다.
    String(const char *str) {
      // 1. strlen 함수를 사용해 문자열의 길이를 알아내고
      // 2. len에 그 길이를 저장
      len = strlen(str);
      // 3. 문자열을 저장할 공간을 동적 할당(NULL 문자 때문에 문자열의 길이보다 한 칸 많은 공간을 할당해야함.)
      strData = new char[len + 1];
      // 4. strcpy를 사용해 strData에 str 복사.
      strcpy(strData, str); // 깊은 복사
    }
    // 복사 생성자
    String(const String &rhs) { 
      len = rhs.len;
      strData = new char[len + 1];
      strcpy(strData, rhs.strData);
    }

    // 소멸자
    ~String() {
      if (strData != NULL) {
        delete[] strData;
      }
    }

    // 복사 대입 연산자
    String &operator=(const String &rhs) {
      if (this != &rhs) {
        len = rhs.len;
        delete[] strData;
        strData = new char[len+1];
        strcpy(strData, rhs.strData);
      }
      return *this;
    }

    const char *GetStrData() const {
      if (strData) return strData;
      return "";
    }
    int GetLen() const {
      return len;
    }

  private:
    // C스타일 문자열(널 문자로 끝나는 char배열)을 동적 할당 후 포인터로 가리킴.
    char *strData;
    // 문자열의 길이
    int len;
}

int main() {
  String s1("hello");
  String s2("hello");
  s2 = s1;
  cout << s1.GetStrData() << endl; // hello
  cout << s2.GetStrData() << endl; // hello
}
```

### result
1. 객체 내에서 동적 할당된 메모리는 특별한 이유가 없으면 깊은 복사가 일어나야 한다.
2. 객체 내에서 동적 할당된 메모리는 특별한 이유가 없으면 객체 내에서 해제되어야 한다.
3. 한 번 할당된 메모리는 반드시 해제되어야 하고, 한 번만 해제되어야 한다.

## 얕은 복사를 일부러 발생시키는게 나은 경우
### 이동 시맨틱
- 의도적으로 얕은 복사를 해 데이터를 복사하지 않고 "이동"만 시키도록 하는 문법
- 복사가 일어나는 상황에서 만약 원본 객체가 곧 사라질 것이라면 굳이 깊은 복사를 하지 않고 원본 객체가 가지고 있는 데이터를 대상 객체로 얕은 복사 즉 이동시킨다.
  - 원본 객체가 사라진다면 깊은 복사를 해줄 의미가 없기 때문에
```cpp
// class String은 앞 예제와 동일
String getName() {
  String res("Doodle");
  return res;
}

int main() {
  String a;
  a = getName();
}
```
- getName 함수가 리턴된 후 그 리턴 값을 a에 대입.
  - 대입 연산이 함수 종료 이후에 나타나기 때문에 res 객체를 바로 a로 복사할 수 없다. 함수가 종료되면 그 함수의 지역 객체인 res도 사라지기 때문
- c++에는 리턴 값을 저장하는 특별한 공간 = 임시 객체가 존재
  - 함수의 지역 객체가 아니기 때문에 함수가 종료되면 res는 사라지지만 임시 객체는 사라지지 않고 임시 객체에서 a로 복사된다.
- 위 예제처럼 return 값이 존재하여 res도 더 이상 쓰지 않고 사라질 객체이고 임시 객체도 a에 대입된 후에는 사라질 객체이기 때문에 원본 객체는 복사 직후에 바로 소멸될 객체이므로 얕은 복사를 해주어도 문제가 되지 않는다.
