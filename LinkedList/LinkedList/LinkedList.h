#pragma once

typedef struct nodeRecord{
    int Data;
    struct nodeRecord *Next;
} NODE;

class CLinkedList{
    private:
        NODE *Head, *Tail;
    public:
        CLinkedList(void);
        ~CLinkedList(void);

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
};


