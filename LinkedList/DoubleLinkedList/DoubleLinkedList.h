#pragma once

typedef struct nodeRecord{
    struct nodeRecord *Prev;
    int Data;
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
    void Add(int Item);

    // 노드 삭제
    void Remove(int Item);
    void RemoveLastNode();
    void RemoveAll();

    // 전체 노드 개수
    int Count();

    // 모든 노드 출력
    void PrintAllList();

    // 모든 노드 반대로 출력
    void PrintAllListReverse(); 

    // 리스트 존재 여부 확인
    bool Exist(int Item);

    // 삽입 함수
    void InsertAfter(int TargetItem, int Item);
    void InsertBefore(int TargetItem, int Item);
};

