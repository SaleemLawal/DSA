#include <iostream>
using namespace std;


class Stack{
    private:
        int size;
        int top;
        int *arr;
    public:
        Stack(int s):size(s), top(-1){SetArr();}
        void SetArr(){
            arr = new int[size];
        }

        void Push(int x){
            if (IsFull()){
                cout << "Stack Overflow" << endl;
            }else{
                arr[++top] = x;
            }
        }

        int Pop(){
            int x = -1;
            if (IsEmpty()){
                cout << "Stack Undeflow" << endl;
            }else{
                x = arr[top];
                arr[top--] = 0;
            }
            return x;
        }

        bool IsEmpty(){
            return top == -1;
        }

        bool IsFull(){
            return top == size - 1;
        }

        int Peek(int index) {
            int x = -1;
            if (top-index+1 < 0 || top-index+1 == size){
                cout << "Invalid position!" << endl;
            } else {
                x = arr[top-index+1];
            }
            return x;
        }

        void Display(){
            for (int i=top; i>=0; i--){
                cout << arr[i] << " | " << flush;
            }
            cout << endl;
        }

        void StackTop(){
            if (IsEmpty()){
                cout << "Empty Stack";
            }else{
                cout << arr[top] << endl;
            }
        }

};

int main(){
    int s;
    cout << "Enter a stack size: ";
    cin >> s;
    Stack myStack(s);
    myStack.Push(1);
    myStack.Push(2);
    myStack.Push(3);
    myStack.Push(4);
    
    myStack.StackTop();
}