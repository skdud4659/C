// 링크드 리스트 구현

#include <iostream>
using namespace std;

// Node 생성
struct Node {
  int data;
  // Node 구조체 자체를 가리키는 포인터이기 때문에 struct로 선언.
  struct Node* next;
}

class LinkedList {
  // head node
  Node *head = NULL;
  // tail node
  Node *tail = NULL;
  // 조회 - 돌아다니며 조회하는 아이
   Node *cur = NULL;

  // 리스트 생성
  void addNode(int x) {
    // 새로 만들 노드
    Node* NewNode = new Node
    // 노드에 데이터 저장
    NewNode->data = x;
    // 노드의 next 변수 초기화
    NewNode->next = Null;

    // 리스트가 비었을 경우 첫번째 노드를 head가 가리키게 한다.
    if (head == Null) head = NewNode;
    // 노드 삽입 = 첫번째 노드가 아니라면
    else tail->next = newNode;  

    // 노드의 끝을 tail이 가리키게 함
    // 리스트가 비었을 경우에는 head와 tail이 같은 노드를 가리키게 된다.
    // 리스트가 비어있지 않을 경우 tail 포인터가 맨 마지막 노드를 가리킬 수 있도록 해준다.
    // 정리하면 head는 첫번째 노드를, tail은 마지막 노드를 가리킨다.
    tail = newNode;
  }

  // 데이터 조회
  void searchNode() {
    if (head == NULL) {
      cout << "리스트 비어있음" << endl;
    } else {
      // 우선 헤더부터 시작
      cur = head;
      // head 출력
      cout << cur->data << “ “;

      // 첫번째 노드에 연결된 노드가 존재할 경우
      while (cur->next != Null)
      {
        // cur이 다음 노드를 가리키게 함
        cur = cur->next;
        // 노드 데이터 출력
        cout << cur->data << “ “;
      }
    }
  }

  // 데이터 삭제
  void deleteNode() {
    // 첫번째 노드가 없을 경우 스킵
    if (head == NULL) {
      return 0;
    } else {
      // 삭제할 노드
      Node *delNode = head;
      // 삭제할 노드 다음 노드
      // 다음 노드는 현재 노드만 그 주솟값을 알고 있기 때문에 다음 노드를 모른채 현재 노드만 삭제하면 다음 노드의 주소를 알 수 없다.
      // 따라서 현재 노드가 가리키는 주솟값을 저장해두지 않으면 다음 노드에도 접근이 불가하다.
      Node *delNextNode = head->next;

      cout << head->data << “ 을 삭제합니다” << endl;

      // 첫번재 노드 삭제
      // 특정 데이터를 삭제하려면 첫번째 노드가 삭제되면 head 포인터를 다음 노드로 옮겨야한다.
      free(delNode);

      // 둘 이상의 노드가 존재할 경우
      while (delNextNode != NULL)
      {
          delNode = delNextNode; 
          delNextNode = delNextNode->next;
          cout << delNode->data << “ 을 삭제합니다” << endl;
          free(delNode); // 해당 노드 삭제
      }
    }
  }
}