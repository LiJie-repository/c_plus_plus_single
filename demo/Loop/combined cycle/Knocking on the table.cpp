#include <iostream> //ÇÃ×À×Ó
using namespace std;
int num = 0;
int main()
{
    for (; num <= 200; num++)
    {
        if (num % 10 == 7 || num / 10 % 10 == 7 ||
            num / 100 == 7 || num % 7 == 0)

        {
            cout << "ÇÃ×À×Ó" << endl;
        }
        else
        {
            cout << num << endl;
        }
    }
}