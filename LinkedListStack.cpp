#include <iostream>
using namespace std;

struct Node{
    Node(int d):data(d){}
    int data;
    Node *next;
};

class Stack{
    private:
        Node* top = nullptr;
    public:
        void Push(int val){
            Node* newNode = new Node(val);
            if(!top){
                newNode->next = nullptr;
                top = newNode;
            }else{
                newNode->next = top;
                top = newNode;
            }
        }

        int Pop(){
            int x = -1;
            Node* prevNode = top;
            if(top){
                x = prevNode->data;
                top = top->next;
                delete prevNode;
            }else{cout << "Stack is empty" << endl;}
            return x;
        }

        int peek(int pos){
            int x = -1;
            Node* curr = top;
            for (int i = 0; i < pos and curr != nullptr; i++){
                curr = curr-> next;
            }
            if (curr){x = curr -> data;}
            return x;
        }

        void Display(){
            Node* curr = top;
            while(curr){
                cout << curr->data << "  ";
                curr = curr->next;
            }
            cout << endl;

        }

};

int main(){
    Stack myStack;
    myStack.Push(1);
    myStack.Push(2);
    myStack.Push(3);
    myStack.Push(4);
    myStack.Push(5);
    cout << myStack.peek(100);
    // myStack.Display();

}