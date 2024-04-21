#include <iostream> //数组的最大值
using namespace std;

int main()
{
    int i = 0;
    int arr[5] = {10, 70, 30, 40, 50};
    for (; i < 5; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            cout << "The maximum value of the array is: " << arr[i] << endl;
            break;
        }
    }
    return 0;
}