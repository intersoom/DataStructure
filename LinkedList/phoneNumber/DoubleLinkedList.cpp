#include <iostream>
#include <cstring>
#include "DoubleLinkedList.h"

using namespace std;

DLinkedList::DLinkedList(void){
    Head = NULL;
    Tail = NULL;
}

DLinkedList::~DLinkedList(void){
    RemoveAll();
}

// 노드 추가
void DLinkedList::Add(char Name[], char Phone[]){
    NODE *temp = new NODE;

    if (Exist(Phone)){
        cout << "입력한 이름은 이미 리스트에 등록되어 있습니다." << endl;
        return;
    } else {
        strcpy(temp->Data.name, Name);
        strcpy(temp->Data.phone, Phone);
        temp->Prev = NULL; // DLinkedList 추가
        temp->Next = NULL;

        if (Head == NULL){
            Head = temp;
            Tail = temp;
        } 
        else{
            Tail->Next = temp;
            temp->Prev = Tail; // DLinkedList 추가
            Tail = temp;
        }
    }
}

// 노드 삭제
void DLinkedList::Remove(char Phone[]){
    if (Head == NULL){
        cout << "비어 있는 리스트입니다." << endl;
        return;
    }

    NODE *temp = Head;
    NODE *prev = NULL;

    // 삭제 대상 노드를 찾음
    while (temp != NULL && temp->Data.phone != Phone)
    {
        prev = temp;
        temp = temp->Next;
    }
    
    // 삭제 대상 노드가 없음
    if (temp == NULL){
        cout << "삭제할 노드가 없습니다." << endl;
        return;
    }

    // temp가 한 번도 전진하지 않았음 => 삭제 대상이 첫 노드임
    if (prev == NULL){
        Head = Head->Next;

        // DLinkedList  추가
        if (Head !=NULL){
            Head->Prev = NULL;
        }

        delete temp;
    }
    else // 삭제 대상이 있음
    {
        prev->Next = temp->Next;

        // DLinkedList cnrk
        if (temp->Next != NULL){
            temp->Next->Prev = prev;
        }

        if (prev->Next == NULL){
            Tail = prev;
        }

        delete temp;
    }
}

void DLinkedList::RemoveLastNode(){
    if (Head == NULL){
        cout << "비어 있는 리스트입니다." << endl;
        return;
    }

    NODE *temp = Head;
    NODE *prev = NULL;

    // 리스트에 노드가 하나만 있는 경우 첫 번째 노드 삭제
    if (Head->Next == NULL){
        delete Head;
        Head = NULL;
        return;
    }
    else{
        prev = Tail->Prev;
        prev->Next = NULL;

        delete Tail;
        Tail = prev;
    }
}

void DLinkedList::RemoveAll(){
    NODE *temp = Head;

    while (Head != NULL)
    {
        temp = Head;
        Head = Head->Next;
        delete temp;
        temp =  NULL;
    }

    Tail = NULL;
}

// 전체 노드 개수
int DLinkedList::Count(){
    int count = 0;
    NODE *temp = Head;

    while (temp != NULL)
    {
        count ++;
        temp = temp->Next;
    }

    return count;
}

// 모든 노드 출력
void DLinkedList::PrintAllList(){
    cout << "전화번호부 = (";
    NODE *temp = Head;

    while (temp != NULL)
    {
        cout << "이름: " << temp->Data.name << ", 전화번호: " << temp->Data.phone;
        temp = temp->Next;

        if (temp != NULL){
            cout << ", ";
        }
    }

    cout << ")" << endl;
}

// 모든 노드 반대로 출력
void DLinkedList::PrintAllListReverse(){
    cout << "거꾸로 전화번호부 = (";
    NODE *temp = Tail;

    while (temp != NULL)
    {
        cout << "이름: " << temp->Data.name << ", 전화번호: " << temp->Data.phone << endl;
        temp = temp->Prev;

        if (temp != NULL){
            cout << ", ";
        }
    }
    
    cout << ")" << endl;
}

// 리스트 존재 여부 확인
bool DLinkedList::Exist(char Phone[]){
    NODE *temp = Head;

    while (temp != NULL){
        if (strcmp(Phone, temp->Data.phone) == 0){
            return true;
        }
        else{
            temp = temp->Next;
        }
        
    }
    return false;
}

void DLinkedList::InsertAfter(char Number[], char NewNumber[], char NewName[]){
    NODE *temp = Head;
    NODE *newNode = new NODE;

    if (Exist(Number) == false){
        cout << "입력한 번호는 리스트에 존재하지 않습니다." << endl;
        return;
    } else {
        // TargetItem 찾기
        while (temp != NULL){
            if (temp->Data.name == Number){
                if (Tail == temp){
                    newNode->Prev= temp;
                    newNode->Next = NULL;
                    temp->Next = newNode;
                    Tail = newNode;
                    return;
                }
                else {
                    newNode->Prev= temp;
                    newNode->Next = temp->Next;
                    temp->Next->Prev = newNode;
                    temp->Next = newNode;
                    return;
                }
            } 
            else {
                temp = temp->Next;
            }
        }
    }
}

void DLinkedList::InsertBefore(char Number[], char NewNumber[], char NewName[]){
    NODE *temp = Head;
    NODE *newNode = new NODE;

    if (Exist(Number) == false){
        cout << "입력한 번호는 리스트에 존재하지 않습니다." << endl;
        return;
    } else {
        // TargetItem 찾기
        while (temp != NULL){
            if (temp->Data.name == Number){
                if (Head == temp){
                    newNode->Prev= NULL;
                    newNode->Next = temp;
                    temp->Prev = newNode;
                    Head = newNode;
                    return;
                }
                else {
                    newNode->Prev= temp->Prev;
                    newNode->Next = temp;
                    temp->Prev->Next = newNode;
                    temp->Prev = newNode;
                    return;
                }
            }
            else {
                temp = temp->Next;
            }
        }
    }
}