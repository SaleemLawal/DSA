#include <iostream>
using namespace std;

class arrayADT
{
    private:
        int *A;
        int length, size;
        void Swap(int &val1, int &val2)
        {
            int temp = val1;
            val1 = val2;
            val2 = temp;
        }
    public:
        arrayADT(int* a, int l, int s): A(a), length(l), size(s){}
        int GetLength()
        {
            return length;
        }
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

        int IteratebinarySeach(int val)
        {
            int low = 0, high = length - 1;
            while (low <= high)
            {
                int mid = (low + high) / 2;
                if (val == A[mid])
                {
                    return mid;
                }
                else if (val < A[mid])
                {
                    high = mid - 1;
                }
                else
                {
                    low = mid + 1;
                }

            }
            return -1;
        }

        int RecurBinarySearch(int low, int high, int val)
        {
            /*
                Iterative version takes less time complexity due to Recusive function being a tail recursion           
            */
            if (low <= high)
            {
                int mid = (low + high) / 2;
                if (val == A[mid])
                {
                    return mid;
                }
                else if (val < A[mid])
                {
                    return RecurBinarySearch(low, mid - 1, val);
                }
                else
                {
                    return RecurBinarySearch(mid+1, high, val);
                }
            }
            return -1;
        }

        void ReverseArray()
        {
            /*
                An array is reversed by implementing a temp variable and Swapping the elements 
            */
            for (int i = 0, j = length - 1; i < j; i++, j--){
                int temp = A[i];
                A[i] = A[j];
                A[j] = temp;
            }
        }

        void LeftShift()
        {
            /*
                shifts an array to the left [1, 2, 3, 4, 5] becomes [2, 3, 4, 5, 0]
            */
           for (int i = 0; i < length - 1; i++)
           {
                A[i] = A[i+1];
           }
           A[length-1] = 0;
        }

        void LeftRotate()
        {
            /*
                Rotates an array to the left [1, 2, 3, 4, 5] becomes [2, 3, 4, 5, 1]
            */
           int firstElem = A[0];
           LeftShift();
           A[length-1] = firstElem;
        }
        
        void RightShift()
        {
            /*
                shifts an array to the right [1, 2, 3, 4, 5] becomes [0, 1, 2, 3, 4]
            */
          for (int i = length - 1; i >= 0; i--)
          {
            A[i] = A[i-1];
          }
          A[0] = 0;
           
        }

        void RightRotate()
        {
            /*
                Rotates an array to the Right [1, 2, 3, 4, 5] becomes [5, 1, 2, 3, 4]
            */
           int lastElem = A[length-1];
           RightShift();
           A[0] = lastElem;
        }

        void negPosSort()
        {
            /*
                sort the negative values to the left and positive to the right
            */
            int i = 0, j = length - 1;
            while (i < j)
            {
                while(A[i] < 0) {i++;}
                while(A[j] >= 0){j--;}
                if (i < j)
                {
                    Swap(A[j], A[i]);
                }
            }
                
        }

        bool isSorted()
        {
            /*
                checks if an array is sorted
            */
            for(int i = 0; i < length - 1; i++)
            {
                if (A[i] > A[i+1])
                {
                    return false;
                }
            }
            return true;
        }

};

int main(){
    int *x = new int [5];
    x[0] = -6;
    x[1] = 2;
    x[2] = 5;
    x[3] = -10;
    x[4] = -9;

    arrayADT a = {x, 5, 5};
    delete [] x;
    return 0;
}
