#include <iostream> //猜数字
using namespace std;
// time系统时间头文件包含
#include <ctime>
int main()
{
    // 添加随机数种子 作用：利用当前系统时间生成随机数，防止每次生成的随机数都一样
    srand((unsigned int)time(NULL));
    // 系统生成随机数
    int num = rand() % 100 + 1; // 系统生成随机数  0+1~99+1
    while (1)
    {
        int val = 0;
        cout << "输入您猜测的数" << endl;
        cin >> val;
        if (val > num)
        {
            cout << "猜测过大" << endl;
        }
        else if (val < num)
        {
            cout << "猜测过小" << endl;
        }
        else
        {
            cout << "恭喜您，猜对了" << endl;
            break;
        }
    }
}
