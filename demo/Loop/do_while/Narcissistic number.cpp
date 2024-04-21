#include <iostream> //水仙花数
using namespace std;
int main()
{
    int num = 0;
    do
    {
        int a = 0; // 数字的个位
        int b = 0; // 数字的十位
        int c = 0; // 数字的百位

        a = num % 10;
        b = num / 10 % 10;
        c = num / 100;

        if (a * a * a + b * b * b + c * c * c == num)
        {
            cout << num << endl;
        }
        num++;
    } while (num < 1000);
}