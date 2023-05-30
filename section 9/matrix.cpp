#include <iostream>
using namespace std;

int main(){
    char name[] ="Saleem";
    int count = 0, i = 0;
    while(name[i] != '\0'){
        count++, i++;
    }
    for (int i = 0, j = count-1; i < j; i++, j--)
    {
        char temp = name[i];
        name[i] = name[j];
        name[j] = temp;

    }
    for (int i = 0; i < 6; i++){
        cout << name[i];
    }
}