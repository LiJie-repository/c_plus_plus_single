#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

#define High 20 // 游戏画面尺寸 以向下为x的正半轴，向右为Y的正半轴
#define Width 30

// 全局变量
int moveDirection;             // 小蛇移动位置 ，上下左右分别用1,2,3,4表示
int food_x, food_y;            // 食物的位置
int canvas[High][Width] = {0}; // 二维数组存储游戏画布中对应元素

// 该函数是用于控制 控制台的光标的移动
void gotoxy(int x, int y)
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE); // 调用
    COORD pos;                                       // 定义一个坐标
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(handle, pos);
}

// 该函数是为了蛇的正常运动以及保证食物的持续出现
void moveSankeByDirection()
{
    int i, j;
    for (i = 1; i < High - 1; i++)
    {
        for (j = 1; j < Width - 1; j++)
        {
            if (canvas[i][j] > 0)
                canvas[i][j]++;
        }
    }

    int oldTail_i, oldTail_j, oldHead_i, oldHead_j;
    int max = 0;

    for (i = 1; i < High - 1; i++)
    {
        for (j = 1; j < Width - 1; j++)
        {
            if (canvas[i][j] > 0)
            {
                if (max < canvas[i][j])
                {
                    max = canvas[i][j];
                    oldTail_i = i;
                    oldTail_j = j;
                }
                if (canvas[i][j] == 2)
                {
                    oldHead_i = i;
                    oldHead_j = j;
                }
            }
        }
    }

    int newHead_i, newHead_j;

    if (moveDirection == 1) // 向上移动
    {
        newHead_i = oldHead_i - 1;
        newHead_j = oldHead_j;
    }
    if (moveDirection == 2) // 向下移动
    {
        newHead_i = oldHead_i + 1;
        newHead_j = oldHead_j;
    }
    if (moveDirection == 3) // 向左移动
    {
        newHead_i = oldHead_i;
        newHead_j = oldHead_j - 1;
    }
    if (moveDirection == 4) // 向右移动
    {
        newHead_i = oldHead_i;
        newHead_j = oldHead_j + 1;
    }

    // 如果吃到食物
    if (canvas[newHead_i][newHead_j] == -2)
    {
        canvas[food_x][food_y] = 0;
        // 产生一个新的食物
        food_x = rand() % (High - 5) + 2;
        food_y = rand() % (Width - 5) + 2;
        canvas[food_x][food_y] = -2;

        // 原来的旧蛇尾，长度自动增加1
    }

    else // 否则，为了保持长度不变，原来的旧蛇尾减掉
    {
        canvas[oldTail_i][oldTail_j] = 0;
    }

    // 小蛇是否撞墙或者和自身相撞，游戏失败
    if (canvas[newHead_i][newHead_j] > 0 || canvas[newHead_i][newHead_j] == -1)
    {
        printf("游戏失败！\n");
        Sleep(2000);     // Windows API函数为了不占过多cpu资源，让程序休眠
        system("pause"); // C语言标准库中的函数，让程序实现冻结屏幕，便于观察程序的执行结果
        exit(0);         // c语言标准库中的函数，用于终止程序
    }
    else
    {
        canvas[newHead_i][newHead_j] = 1; // 为新的蛇头赋值
    }
}

// 初始化时的函数
void startup()
{
    int i, j;
    // 初始化边框
    for (i = 0; i < High; i++)
    {
        canvas[i][0] = -1;
        canvas[i][Width - 1] = -1;
    }
    for (j = 0; j < Width; j++)
    {
        canvas[0][j] = -1;
        canvas[High - 1][j] = -1;
    }

    // 初始化蛇头
    canvas[High / 2][Width / 2] = 1;
    // 初始化蛇身，画布元素分别为2,3,4,5
    for (i = 1; i <= 4; i++)
        canvas[High / 2][Width / 2 - i] = i + 1;

    // 初始小蛇向右移动
    moveDirection = 4;

    food_x = rand() % (High - 5) + 2; // rand()函数是c语言标准库中的函数，用于产生随机数
    food_y = rand() % (Width - 5) + 2;
    canvas[food_x][food_y] = -2;
}

// 一个根据咱们定义的画布上的数据而分别为用户呈现不同视觉效果的函数
void show()
{
    gotoxy(0, 0);
    int i, j;
    for (i = 0; i < High; i++)
    {
        for (j = 0; j < Width; j++)
        {
            if (canvas[i][j] == 0) // 0为空格，-1为边框#，-2为食物F，1为蛇头@，大于1为蛇身*
                printf(" ");
            else if (canvas[i][j] == -1)
                printf("#");
            else if (canvas[i][j] == 1)
                printf("@");
            else if (canvas[i][j] > 1)
                printf("*");
            else if (canvas[i][j] == -2)
                printf("F");
        }
        printf("\n");
    }
    Sleep(100);
}

// 与用户无关的更新的函数
void updateWithoutInput()
{
    moveSankeByDirection();
}

// 与用户有关的更新的函数 ，判断用户的输入
void updateWithInput()
{
    char input;
    if (kbhit()) // kbhit是conio库中的函数，判断是否有输入
    {
        input = getch();  // 根据用户不同的输入来移动，不必输入回车
        if (input == 'a') // input、getch是conio库中的函数,用于输入和输出字符
        {
            moveDirection = 3; // 位置左移
            moveSankeByDirection();
        }
        if (input == 'd')
        {
            moveDirection = 4; // 位置右移
            moveSankeByDirection();
        }
        if (input == 'w')
        {
            moveDirection = 1; // 位置上移
            moveSankeByDirection();
        }
        if (input == 's')
        {
            moveDirection = 2; // 位置下移
            moveSankeByDirection();
        }
    }
}

int main()
{
    startup(); // 数据初始化
    while (1)  // 游戏循环执行
    {
        show(); // 显示画面
        updateWithoutInput();
        updateWithInput();
    }
    return 0;
}
