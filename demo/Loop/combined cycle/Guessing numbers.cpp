#include <iostream> //������
using namespace std;
// timeϵͳʱ��ͷ�ļ�����
#include <ctime>
int main()
{
    // ������������ ���ã����õ�ǰϵͳʱ���������������ֹÿ�����ɵ��������һ��
    srand((unsigned int)time(NULL));
    // ϵͳ���������
    int num = rand() % 100 + 1; // ϵͳ���������  0+1~99+1
    while (1)
    {
        int val = 0;
        cout << "�������²����" << endl;
        cin >> val;
        if (val > num)
        {
            cout << "�²����" << endl;
        }
        else if (val < num)
        {
            cout << "�²��С" << endl;
        }
        else
        {
            cout << "��ϲ�����¶���" << endl;
            break;
        }
    }
}
