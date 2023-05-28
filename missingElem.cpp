#include <iostream>
using namespace std;

int main(){

    int arr[] = {8, 3, 6, 4, 6, 5, 6, 8, 2, 7};
    int newArr[9] = {0};
    for (int i = 0; i < 10; i++)
    {
        newArr[arr[i]]++;
    }
    for (int i =0; i < 9; i++)
    {
        if (newArr[i] > 1)
        {
            cout << "num of duplicate is " << newArr[i] << " at " << i << endl;
        }
    }

    return 0;
}