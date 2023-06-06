#include <iostream>
class Matrix
{
    private:
        int* arr;
        int size;
    public:
        Matrix(int n);
        ~Matrix();
        void Create();
        int Get(int i, int j);
        void Set(int i, int j, int x);
        void Display();
};

Matrix::Matrix(int n)
{
    size = n;
    arr = new int[(size * (size+1))/2];
}

Matrix::~Matrix()
{
    delete [] arr;
}

void Matrix::Create()
{
    int x; 
    for (int i = 1; i <= size; i++)
    {
        std::cin >> x;
        for (int j = 1; j <= size; j++)
        {
            if (i == j)
            {
                arr[i-1] = x;
            }
        }
    }
}

int Matrix::Get(int i, int j)
{
    if (i == j)
    {
        return arr[i-1];
    }
    return 0;
}

void Matrix::Set(int i, int j, int x)
{
    if (i==j)
    {
        arr[i-1] = x;
    }
}

void Matrix::Display()
{
    for (int i = 1; i <= size; i++)
    {
        for (int j = 1; j <= size; j++)
        {
            if (i == j)
            {
                std::cout << arr[i-1] << " ";
            }
            else
            {
                std::cout << "0 ";
            }
        }
        std::cout << std::endl;
    }
}

int main()
{
    Matrix m(5);
    m.Create();
    m.Display();
    std::cout << std::endl;
    m.Set(2,2,3);
    m.Display();
    return 0;
}