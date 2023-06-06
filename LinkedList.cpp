#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next = nullptr;
};

class LinkedList{
    private:
        Node* head;
        int LLsize;
    public:
        LinkedList();
        ~LinkedList();
        void Display();
        void Insert(int arr[], int size);
        void InsertAt(int index, int val);
        void Merge(LinkedList* head2);
        void RemoveDuplicate();
        void Reverse();
};

LinkedList::LinkedList(){head = nullptr; LLsize = 0;}

LinkedList::~LinkedList(){}

void LinkedList::Display(){
    Node* curr = head;
    while (curr != nullptr){
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

void LinkedList::Insert(int arr[], int size){
    for (int i = 0; i < size; i++){
        Node* newNode = new Node;
        newNode->data = arr[i];
        if (head == nullptr){
            head = newNode;
        }else{
            Node* curr = head;
            while(curr->next != nullptr){
                curr = curr->next;
            }
            curr->next = newNode;
        }
        LLsize++;
    }
}

void LinkedList::InsertAt(int index, int val){
    int count = 1;
    Node* curr = head;
    if (index < 0 or index > LLsize){
        cout << "Invalid index" << endl;
        return;
    }
    Node* newNode = new Node;
    newNode->data = val;

    while(count < index){
        count++;
        curr = curr->next;
    }
    if (index == 0){
        newNode->next = head;
        head= newNode;
        return;
    }
    Node *next = curr->next;
    curr->next = newNode;
    newNode->next = next;
    LLsize++;
}


void LinkedList::Merge(LinkedList* head2){
    Node* ll1 = nullptr, *ll2 = nullptr, *prev = nullptr, *small = nullptr;
    if (this->head->data < head2->head->data){
        ll1 = this->head;
        ll2= head2->head;
    }else{
        ll1 = head2->head;
        ll2 = this->head;
        this->head = ll1;
    }
    while(ll2 != nullptr and ll1->next != nullptr){        
        if(ll2->data > ll1->data or ll2->data == ll1->data){
            prev = ll1;
            ll1 = ll1->next;
        }else{
            prev->next = ll2;
            small = ll2;
            ll2 = ll2->next;
            small->next = ll1;
            prev = small;
        }
    }
    if (ll1->next == nullptr){
        ll1->next = ll2;
    }else{
        prev->next = ll1;
    }
}

void LinkedList::RemoveDuplicate(){
    Node* curr = head->next, *prev = head, *last = nullptr;

    while(curr != nullptr){
        if (curr->data != prev->data){
            last = prev;
            prev = curr;
            curr = curr->next;
        }else{
            delete prev;
            last->next = curr;
            prev = last;
        }
    }
}

void LinkedList::Reverse(){
    Node* curr = head, *prev = nullptr, *last = nullptr;
    for (int i = 0; i < LLsize ; i++){
        prev = curr;
        curr = curr->next;
        prev->next = last;
        last = prev;
    }
    head = prev;
}


int main(){
    int arr[] = {0, 1, 2, 3, 40, 50, 50};
    LinkedList big;
    LinkedList *small =  new LinkedList;
    int arr2[] = {1, 9, 10};


    big.Insert(arr, sizeof(arr)/ sizeof(arr[0]));
    
    return 0;
}