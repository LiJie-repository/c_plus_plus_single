#include <iostream> //乘法表
using namespace std;

int main()
{
    for (int i = 1; i <= 9; i++)
    {
        // 列数<=当前的行数
        // i->行数
        // j->列数
        for (int j = 1; j <= i; j++)
        {
            cout << i << "*" << j << "=" << i * j << "  " /*<< endl*/;
        }
        cout << endl;
    }
}