#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

#define High 20 // ��Ϸ����ߴ� ������Ϊx�������ᣬ����ΪY��������
#define Width 30

// ȫ�ֱ���
int moveDirection;             // С���ƶ�λ�� ���������ҷֱ���1,2,3,4��ʾ
int food_x, food_y;            // ʳ���λ��
int canvas[High][Width] = {0}; // ��ά����洢��Ϸ�����ж�ӦԪ��

// �ú��������ڿ��� ����̨�Ĺ����ƶ�
void gotoxy(int x, int y)
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE); // ����
    COORD pos;                                       // ����һ������
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(handle, pos);
}

// �ú�����Ϊ���ߵ������˶��Լ���֤ʳ��ĳ�������
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

    if (moveDirection == 1) // �����ƶ�
    {
        newHead_i = oldHead_i - 1;
        newHead_j = oldHead_j;
    }
    if (moveDirection == 2) // �����ƶ�
    {
        newHead_i = oldHead_i + 1;
        newHead_j = oldHead_j;
    }
    if (moveDirection == 3) // �����ƶ�
    {
        newHead_i = oldHead_i;
        newHead_j = oldHead_j - 1;
    }
    if (moveDirection == 4) // �����ƶ�
    {
        newHead_i = oldHead_i;
        newHead_j = oldHead_j + 1;
    }

    // ����Ե�ʳ��
    if (canvas[newHead_i][newHead_j] == -2)
    {
        canvas[food_x][food_y] = 0;
        // ����һ���µ�ʳ��
        food_x = rand() % (High - 5) + 2;
        food_y = rand() % (Width - 5) + 2;
        canvas[food_x][food_y] = -2;

        // ԭ���ľ���β�������Զ�����1
    }

    else // ����Ϊ�˱��ֳ��Ȳ��䣬ԭ���ľ���β����
    {
        canvas[oldTail_i][oldTail_j] = 0;
    }

    // С���Ƿ�ײǽ���ߺ�������ײ����Ϸʧ��
    if (canvas[newHead_i][newHead_j] > 0 || canvas[newHead_i][newHead_j] == -1)
    {
        printf("��Ϸʧ�ܣ�\n");
        Sleep(2000);     // Windows API����Ϊ�˲�ռ����cpu��Դ���ó�������
        system("pause"); // C���Ա�׼���еĺ������ó���ʵ�ֶ�����Ļ�����ڹ۲�����ִ�н��
        exit(0);         // c���Ա�׼���еĺ�����������ֹ����
    }
    else
    {
        canvas[newHead_i][newHead_j] = 1; // Ϊ�µ���ͷ��ֵ
    }
}

// ��ʼ��ʱ�ĺ���
void startup()
{
    int i, j;
    // ��ʼ���߿�
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

    // ��ʼ����ͷ
    canvas[High / 2][Width / 2] = 1;
    // ��ʼ����������Ԫ�طֱ�Ϊ2,3,4,5
    for (i = 1; i <= 4; i++)
        canvas[High / 2][Width / 2 - i] = i + 1;

    // ��ʼС�������ƶ�
    moveDirection = 4;

    food_x = rand() % (High - 5) + 2; // rand()������c���Ա�׼���еĺ��������ڲ��������
    food_y = rand() % (Width - 5) + 2;
    canvas[food_x][food_y] = -2;
}

// һ���������Ƕ���Ļ����ϵ����ݶ��ֱ�Ϊ�û����ֲ�ͬ�Ӿ�Ч���ĺ���
void show()
{
    gotoxy(0, 0);
    int i, j;
    for (i = 0; i < High; i++)
    {
        for (j = 0; j < Width; j++)
        {
            if (canvas[i][j] == 0) // 0Ϊ�ո�-1Ϊ�߿�#��-2Ϊʳ��F��1Ϊ��ͷ@������1Ϊ����*
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

// ���û��޹صĸ��µĺ���
void updateWithoutInput()
{
    moveSankeByDirection();
}

// ���û��йصĸ��µĺ��� ���ж��û�������
void updateWithInput()
{
    char input;
    if (kbhit()) // kbhit��conio���еĺ������ж��Ƿ�������
    {
        input = getch();  // �����û���ͬ���������ƶ�����������س�
        if (input == 'a') // input��getch��conio���еĺ���,�������������ַ�
        {
            moveDirection = 3; // λ������
            moveSankeByDirection();
        }
        if (input == 'd')
        {
            moveDirection = 4; // λ������
            moveSankeByDirection();
        }
        if (input == 'w')
        {
            moveDirection = 1; // λ������
            moveSankeByDirection();
        }
        if (input == 's')
        {
            moveDirection = 2; // λ������
            moveSankeByDirection();
        }
    }
}

int main()
{
    startup(); // ���ݳ�ʼ��
    while (1)  // ��Ϸѭ��ִ��
    {
        show(); // ��ʾ����
        updateWithoutInput();
        updateWithInput();
    }
    return 0;
}
