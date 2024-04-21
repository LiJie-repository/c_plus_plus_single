#include <iostream> //Ã°ÅİÅÅĞò
using namespace std;

int main()
{
    int i;
    int j;
    int t;
    int arr[10] = {4, 2, 8, 0, 5, 7, 1, 3, 9, 10};

    cout << "ÅÅĞòÇ°" << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Ã°ÅİÅÅĞò
    cout << "ÅÅĞòºó" << endl;
    for (i = 0; i < 9; i++)
    {
        for (j = 0; j < 9 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                t = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = t;
            }
        }
    }

    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}