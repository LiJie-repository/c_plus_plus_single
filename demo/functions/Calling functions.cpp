#include <iostream> //�����ĵ���
using namespace std;

int add(int a, int b) // ��ʽ����
{
    int c = a + b;
    return c;
}

int main()
{
    int a, b;
    cout << "Enter two numbers:(�ÿո����)" << endl;
    cin >> a >> b; // ʵ�ʲ���
    // �����ú���ʱ��ʵ�ʲ����ᱻ�滻Ϊ��ʽ����
    cout << add(a, b) << endl;
    return 0;
}