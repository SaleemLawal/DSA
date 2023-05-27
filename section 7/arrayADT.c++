#include <iostream>
using namespace std;

class arrayADT
{
    private:
        int *A;
        int length, size;
        
    public:
        arrayADT(int* a, int l, int s): A(a), length(l), size(s){}
        void append(int x)
        {
            /*
                append a value at the last index of an array
            */
            if (length != size)
            {
                A[length++] = x;
            }
            
        }
        void display()
        {
            /*
                Loops through an array and display each item at each index
            */
            for (int i =0; i < length; i++)
            {
                cout << A[i] << " ";
            }
            cout << endl;
        }
        
        void insert(int index, int x)
        {
            /*
                insert a value at specifi index
            */
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
        int remove(int index)
        {
            /*
                remove a value at a specified index and return the value removed            
            */
            if (index >= 0 and index < length)
            {
                int x = A[index];
                for (int i = index; i < length - 1; i++){
                    A[i] = A[i+1];
                }length--;
                return x;
            }
            return 0;
        }
};

int main(){
    int *x = new int [5];
    for (int i =0; i < 5; i++)
    {
        x[i] = i;
    }
    arrayADT a = {x, 5, 20};
    a.append(10);
    return 0;
}
