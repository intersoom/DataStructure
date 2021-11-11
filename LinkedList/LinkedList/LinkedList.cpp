#include <iostream>
#include "LinkedList.h"

using namespace std;

CLinkedList::CLinkedList(void){
    Head = NULL;
    Tail = NULL;
}

CLinkedList::~CLinkedList(void){
    RemoveAll();
}


// 노드 추가
void CLinkedList::Add(int Item){
    NODE *temp = new NODE;

    temp->Data = Item;
    temp->Next = NULL;

    if (Head == NULL){
        Head = temp;
        Tail = temp;
    }
    else {
        Tail->Next = temp;
        Tail = temp;
    }
}

// 노드 삭제
void CLinkedList::Remove(int Item){
    if(Head == NULL){
        cout << "비어 있는 리스트입니다." << endl;
        return;
    }

    NODE *temp = Head;
    NODE *prev = NULL;

    // 삭제 대상 노드를 찾음
    while(temp != NULL && temp->Data != Item){
        prev = temp;
        temp = temp->Next;
    }

    // 삭제 대상 노드가 없음
    if(temp == NULL){
        cout << "삭제할 노드가 없습니다." << endl;
        return;
    }

    // temp가 한번도 전진하지 않았음 => 삭제 대상이 첫 노드임
    if (prev == NULL){
        Head = Head->Next;
        delete temp;
    } 
    else // 삭제 대상이 있움
    {
        prev->Next = temp->Next;
        delete temp;
    }  
}

void CLinkedList::RemoveLastNode(){
    if(Head == NULL){
        cout << "비어 있는 리스트입니다." << endl;
        return;
    }

    NODE *temp = Head;
    NODE *prev = NULL;

    // 리스트에 노드가 하나만 있는 경우 첫 번째 노드 삭제
    if(Head->Next == NULL){
        delete Head;
        Head = NULL;
        return;
    }
    else{
        prev = Head;
        temp = Head->Next;

        while (temp->Next != NULL)
        {
            prev = temp;
            temp = temp->Next;
        }

        delete temp;
        prev->Next = NULL;
    }
}

void CLinkedList::RemoveAll(){
    NODE *temp = Head;

    while (Head != NULL)
    {
        temp = Head;
        Head = Head->Next;
        delete temp;
        temp = NULL;
    }

    Tail = NULL;   
}

// 전체 노드 개수
int CLinkedList::Count(){
    int count = 0;
    NODE *temp = Head;

    while(temp != NULL){
        count ++;
        temp = temp->Next;
    }
    
    return count;
}

// 모든 노드 출력
void CLinkedList::PrintAllList(){
    cout << "List = (";
    NODE *temp = Head;

    while (temp != NULL)
    {
        cout << temp->Data;
        temp = temp ->Next;

        if (temp != NULL){
            cout << ", ";
        }
    }

    cout << ")" << endl;
}
