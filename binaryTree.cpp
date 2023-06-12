#include <iostream>
#include <queue>
#include <stack>
using namespace std;

struct Node{
    int data;
    Node *lChild;
    Node *rChild;
};

class Tree{
    public:
        Node *root;
        Tree(){root = nullptr;}
        void CreateTree();
        void PreOrder(Node*);
        void IPreOrder(Node*);
        void InOrder(Node*);
        void IterInOrder(Node*);
        void PostOrder(Node*);
        void IPostOrder(Node*);
        void LevelOrder(Node*);
        int Height(Node*);
};

void Tree::CreateTree(){
    Node *newNode, *curr;
    queue <Node*> q;
    int x;
    cout << "Enter root value: ";
    cin >> x;
    root = new Node;
    root->data = x;
    root -> lChild = root -> rChild = nullptr;

    q.push(root);
    while(!q.empty()){
        curr = q.front();
        q.pop();

        cout << "Enter left child of " << curr->data <<": ";
        cin >> x;
        if (x != -1){
            newNode = new Node;
            newNode->data = x;
            newNode->lChild = newNode->rChild = nullptr;
            curr->lChild = newNode;
            q.push(newNode);
        }
        
        cout << "Enter right child of " << curr->data <<": ";
        cin >> x;
        if (x != -1){
            newNode = new Node;
            newNode->data = x;
            newNode->lChild = newNode->rChild = nullptr;
            curr->rChild = newNode;
            q.push(newNode);
        }
    }
}
void Tree::PreOrder(Node* r){
    if (r){
        cout << r->data << endl;
        PreOrder(r->lChild);
        PreOrder(r->rChild);
    }
    

}
void Tree::InOrder(Node* r){
    if (r){
        InOrder(r->lChild);
        cout << r->data << endl;
        InOrder(r->rChild);
    }
}
void Tree::PostOrder(Node* r){
    if (r){
        PostOrder(r->lChild);
        PostOrder(r->rChild);
        cout << r->data << endl;
    }
}
void Tree::LevelOrder(Node *root){
    queue <Node*> q;
    printf("%d ",root->data);
    q.push(root);

    while(!q.empty()){
        root = q.front();
        q.pop();

        if(root->lChild){
            printf("%d ",root->lChild->data);
            q.push(root->lChild);
        }
        if(root->rChild){
            printf("%d ",root->rChild->data);
            q.push(root->rChild);
        }
    }
}
int Tree::Height(Node* curr){
    int x = 0, y = 0;
    if (curr == nullptr){
        return 0;
    }
    x = Height(curr -> lChild);
    y = Height(curr -> rChild);

    if (x > y){
        return x + 1;
    }else
        return y + 1;
}

void Tree::IPreOrder(Node* curr){
    stack<Node *> s;
    while(curr or !s.empty()){
        if (curr){
            cout << curr->data << endl;
            s.push(curr);
            curr = curr->lChild;
        }else{
            curr = s.top();
            s.pop();
            curr = curr->rChild;
        }
    }
}

void Tree::IterInOrder(Node* curr){
    stack<Node *> s;
    while(curr or !s.empty()){
        if (curr){
            s.push(curr);
            curr = curr->lChild;
        }else{
            curr = s.top();
            s.pop();
            cout << curr->data << endl;
            curr = curr->rChild;
        }
    }
}

void Tree::IPostOrder(Node* curr){
    stack<Node *> s;
    Node* prev = nullptr;

    while(curr || !s.empty()){
        if (curr){
            s.push(curr);
            curr = curr->lChild;
        }else{
            Node* temp = s.top();
            if (temp->rChild && temp->rChild != prev){
                curr = temp->rChild;
            }else{
                cout << temp->data << endl;
                prev = temp;
                s.pop();
            }
        }
    }
}

int main(){
    Tree t;
    t.CreateTree();
    t.IPostOrder(t.root);
    return 0;
}