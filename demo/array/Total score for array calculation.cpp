#include <iostream> //用数组计算总分
#include <string>
using namespace std;

int main()
{
    int arr[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int sum = 0;
    string name[3] = {"张三", "李四", "王五"};
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            sum += arr[i][j];
        }

        cout << name[i] << "学生的总成绩为 " << sum << endl;
    }

    return 0;
}