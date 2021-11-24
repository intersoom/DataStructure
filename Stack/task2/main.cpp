#include <iostream>
#include "StackByLinkedList.h"

using namespace std;

void toPostFix(char []);

int main(){
    char str[100];

    while (true)
    {
        cout << "후위 표기법으로 변환할 문자열을 입력하세요." << endl
             << "'0'을 입력하면 프로그램이 종료됩니다." << endl;
        cin >> str;

        if (str[0] == '0'){
            return 0;
        }

        toPostFix(str);

        cout << endl;
    }

    return 0;
}

void toPostFix(char str[]){
    StackByLinkedList stack;

    int i = 0;
    while (true)
    {
        char currChar = str[i];
        
        switch (currChar)
        {
        case '(':
            break;
        case '*':
        case '+':
        case '-':
        case '/':
            stack.Push(currChar);
            break;
        case ')':
            cout << stack.Pop();
        case NULL:
            while (stack.GetTop() > -1){
                cout << stack.Pop();
            }
        default:
            cout << currChar;
        }
        i++;
    }
    
}