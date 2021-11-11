#pragma once

typedef struct nodeData{
    char name[20];  //이름
    char phone[14]; // 010-1234-5678
} NODE_DATA;

typedef struct nodeRecord{
    struct nodeRecord *Prev;
    // int Data;
    NODE_DATA Data;
    struct nodeRecord *Next;
} NODE;

class DLinkedList
{
private:
    NODE *Head, *Tail;
public:
    DLinkedList(void);
    ~DLinkedList(void);

    // 노드 추가
    void Add(char name[], char phone[]);

    // 노드 삭제
    void Remove(char phone[]);
    void RemoveLastNode();
    void RemoveAll();

    // 전체 노드 개수
    int Count();

    // 모든 노드 출력
    void PrintAllList();

    // 모든 노드 반대로 출력
    void PrintAllListReverse(); 

    // 리스트 존재 여부 확인
    bool Exist(char Name[20]);

    // 삽입 함수
    void InsertAfter(char Number[], char NewNumber[], char NewName[]);
    void InsertBefore(char Number[], char NewNumber[], char NewName[]);
};

