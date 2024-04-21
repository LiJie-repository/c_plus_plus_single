#include "iostream" //使用while循环打印数字
using namespace std;
int main()
{
    int num;
    int a = 0;
    cout << "输入要打印的数" << endl;
    cin >> num;
    while (a < num + 1)
    {
        cout << a << endl;
        a++;
    }
}
