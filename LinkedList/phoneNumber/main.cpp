#include <iostream>
#include <cstring>
#include "DoubleLinkedList.h"

using namespace std;

int main(){
    DLinkedList phoneNumber;

    char name[20];
    char phone[14];
    string addMore;

    while (true)
    {
        cout << "이름: ";
        cin >> name;
        cout << "전화번호: ";
        cin >> phone;

        phoneNumber.Add(name, phone);

        cout << "추가로 입력하시겠습니까? : ";
        cin >> addMore;

        if (addMore == "yes"){
            continue;
        } else {
            phoneNumber.PrintAllList();
            break;
        }
    }
    

    return 0;
}