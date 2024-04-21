#include <iostream> //为电影打分
using namespace std;
int main()
{
    int score = 0;
    cout << "请为电影打分，在下方输入分数" << endl;
    cin >> score;

    switch (score)
    {
    case 10:
        cout << "您认为电影很好" << endl;
        break;
    case 8:
        cout << "您认为电影好" << endl;
        break;
    default:
        cout << "您认为电影不好" << endl;
        break;
    }
}