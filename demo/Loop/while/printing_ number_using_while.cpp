#include "iostream" //ʹ��whileѭ����ӡ����
using namespace std;
int main()
{
    int num;
    int a = 0;
    cout << "����Ҫ��ӡ����" << endl;
    cin >> num;
    while (a < num + 1)
    {
        cout << a << endl;
        a++;
    }
}
