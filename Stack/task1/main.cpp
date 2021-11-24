#include <iostream>
#include "StackByLinkedList.h"

using namespace std;

bool TestPair(char[]);

int main(){
    char str[100];

    while (true)
    {
        cout << "검사할 수식을 입력하세요." << endl
             << "'0'을 입력하면 프로그램이 종료됩니다." << endl;
        cin >> str;

        if (str[0] == '0'){
            return 0;
        }

        bool result = TestPair(str);


        cout << result << endl;
    }
    
    return 0;
}

bool TestPair(char str[]){
    StackByLinkedList stack;

    int i = 0;
    while (true)
    {
        char currChar = str[i];
        
        switch (currChar)
        {
        case '(':
        case '[':
        case '{':
            stack.Push(str[i]);
            break;
        case ')':
            if (stack.Pop() != '('){
                return false;
            }
            break;
        case ']':
            if (stack.Pop() != '['){
                return false;
            }
            break;
        case '}':
            if (stack.Pop() != '{'){
                return false;
            }
            break;
        case NULL:
            if (stack.IsEmpty()){
                return true;
            }
            else {
                return false;
            }
        }
        i++;
    }
    
}