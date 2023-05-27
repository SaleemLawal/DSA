#include <iostream>
using namespace std;

class arrayADT
{
    private:
        int *A;
        int length, size;
        
    public:
        arrayADT(int* a, int l, int s): A(a), length(l), size(s){}
        void add(int x){
            if (length != size)
            {
                A[length++] = x;
            }
            
        }
        void display(){
            for (int i =0; i < length; i++)
            {
                cout << A[i] << " ";
            }
            cout << endl;
        }
        
        void insert(int index, int x){
            if (index > 0 and  index<= length)
            {
                for (int i = length; i > index; i--)
                {
                    A[i] = A[i-1];
                }
                A[index] = x;
                length++;
            }
            
        }
};

int main(){
    int *x = new int [5];
    for (int i =0; i < 5; i++)
    {
        x[i] = i;
    }
    arrayADT a = {x, 5, 20};
    a.add(10);
    return 0;
}
