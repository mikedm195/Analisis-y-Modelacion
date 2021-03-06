#include<iostream>
using namespace std;

class ArrayPositiveInts;

class Proxy
{
private:
    ArrayPositiveInts& arr;
    int idx;
    
public:
    Proxy(ArrayPositiveInts& arr, int idx)
    : arr(arr), idx(idx){}
    
    Proxy& operator=(int value);
};

class ArrayPositiveInts
{
private:
    int* values;
    int size;
public:
    friend class Proxy;
    ArrayPositiveInts()
    {
        size = 100;
        values = new int[size];
    }
    int& operator[](int idx) //se devuelve un elemento del arreglo por referencia
    {
        Proxy temp(*this, idx); //ejecuto el proxy
        return values[idx];  //devuelvo el elemento
    }
};

Proxy& Proxy::operator=(int value)
{
        if(value>=0)
        {
            *(arr.values + idx) = value;
            return *this;
        }
        else
        {
            cout << "error" << endl;
            return *this;
        }
}

int main()
{
    ArrayPositiveInts a;
    a[0]=1;
    cout << a[0];
}
