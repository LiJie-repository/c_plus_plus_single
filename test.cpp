#include <iostream>
using namespace std;

void swap(int a, int b)
{
    int temp = a;
    a = b;
    b = temp;
    cout << "After swap: a = " << a << " b = " << b << endl;
}

int main()
{
    int a, b;
    cin >> a >> b;
    swap(a, b);
    // cout << "After swap: a = " << a << " b = " << b << endl;
    return 0;
}