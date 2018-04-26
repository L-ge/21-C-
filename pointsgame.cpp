#include <iostream>
#include <random>

void count_playerpoints();
void show_result();
void show_poker(int[]);

using namespace std;
int playerpoints;     // ��ҵĵ���
int arr[14];
bool haspoke = false;
bool isover = false;
int pokersum; // ����(��ʵֻҪһ��ʼ���ƣ���Ҿ�����������)
int playerpoker[21]; // ��������������21����
int bankerpoints; // ׯ�ҵĵ���
bool can_over = false; // ����

void game_main()
{
    int choice = 1;
    while (choice == 1)
    {
        cout << "��ʼ��������1��\n";
        cout << "������������2��\n";
        cout << "��������3��\n";
        cin >> choice;
        switch(choice)
        {
        case 1:
            // �������ׯ�ҵĵ���
            bankerpoints = rand() % 22;
            if (bankerpoints < 10)
            {
                bankerpoints = bankerpoints + 10;
            }

            haspoke = true;
            pokersum = 2;
            for (int i = 0; i < 2; i++)
            {
                playerpoker[i] = rand() % 13;
            }
            break;
        case 2:
            // �������ƣ����Բ���һ���µ�������������������+1
            playerpoker[pokersum] = rand() % 13;
            pokersum++;
            break;

            count_playerpoints();

        case 3:
            can_over = true;
            break;

            if (playerpoints > 21)
            {
                cout << "��ʼ��������1��\n";
                show_result();
            }
            if (can_over)
            {
                cout << "��������3��\n";
            }
        }
        choice = 0;
    }

}

void count_playerpoints()
{
    playerpoints = 0;
    for (int i = 0; i < pokersum; i++)
    {
        playerpoints = playerpoints + arr[i] + 1;
    }
}

void show_result()
{
    if (haspoke)
    {
        show_poker(playerpoker);
        cout << "�����ڵĵ����ǣ�" << playerpoints << endl;
    }
    if (playerpoints > 21)
    {
        cout << "���Ѿ����ˣ�����\n";
    }
    if (can_over)
    {
        if (playerpoints > bankerpoints)
        {
            cout << "��Ӯ�ˣ�\n";
        }
        else if (playerpoints == bankerpoints)
        {
            cout << "��ĵ�����ׯ�ҵ�һ��������ׯ��Ӯ�ˣ�\n";
        }
        else
        {
            cout << "�����ˣ�\n";
        }
        can_over = false;
        cout << "ׯ�ҵĵ����ǣ�" << bankerpoints << endl;
    }
}

void show_poker(int playerpoker[])
{
    cout << "Now I have : ";
    for (int i = 0; i < pokersum; ++i)
    {
        if (playerpoker[i] == 0 && i != pokersum-1)
            cout << "A ";
        else if (playerpoker[i] == 10 && i != pokersum-1)
            cout << "J ";
        else if (playerpoker[i] == 11 && i != pokersum-1)
            cout << "Q ";
        else if (playerpoker[i] == 12 && i != pokersum-1)
            cout << "K ";
        else if (i != pokersum-1)
            cout << playerpoker[i] + 1 << ' ';
        else
            cout << playerpoker[i] + 1 << '. ';
    }
}
