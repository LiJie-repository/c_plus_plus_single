#include <iostream> //Ϊ��Ӱ���
using namespace std;
int main()
{
    int score = 0;
    cout << "��Ϊ��Ӱ��֣����·��������" << endl;
    cin >> score;

    switch (score)
    {
    case 10:
        cout << "����Ϊ��Ӱ�ܺ�" << endl;
        break;
    case 8:
        cout << "����Ϊ��Ӱ��" << endl;
        break;
    default:
        cout << "����Ϊ��Ӱ����" << endl;
        break;
    }
}