#include <iostream>
using namespace std;

class Queue{
    private:
        int front;
        int rear;
        int *arr;
        int size;
    public:
        Queue(int size){
            front = rear = -1;
            this->size = size;
            arr = new int[size];
        }

        void Push(int val){
            if (rear == size - 1){cout << "Queue is full" << endl;}
            else{
                arr[++rear] = val;
            }
            
        }

        int Pop(){
            int x = -1;
            if (IsEmpty()){
                cout << "Queue is empty" << endl;
            }else{
                x = arr[++front];
            }
            return x;
        }

        int GetFront(){
            return arr[front + 1];
        }

        int GetBack(){
            return arr[rear];
        }

        bool IsEmpty(){
            return front == rear;
        }
};

int main(){
    int arr[] = {1, 2, 3, 4, 5};
    Queue q(sizeof(arr)/ sizeof(arr[0]));

    for (int i = 0; i < 5; i++){
        q.Push(arr[i]);
    }
    cout << q.GetBack() << endl;
    q.Push(10);
    cout << q.GetBack() << endl;
    return 0;}
