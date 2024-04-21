#include <iostream>
using namespace std;

int main()
{
    int arr[11] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int *p = arr;

    for (int i = 0; i < 11; i++)
    {
        cout << *p << " kongge";
        p++;
    }

    return 0;
}