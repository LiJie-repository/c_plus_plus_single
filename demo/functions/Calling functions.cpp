#include <iostream> //函数的调用
using namespace std;

int add(int a, int b) // 形式参数
{
    int c = a + b;
    return c;
}

int main()
{
    int a, b;
    cout << "Enter two numbers:(用空格隔开)" << endl;
    cin >> a >> b; // 实际参数
    // 当调用函数时，实际参数会被替换为形式参数
    cout << add(a, b) << endl;
    return 0;
}