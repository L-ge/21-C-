#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

void count_playerpoints();
void show_result();
void show_poker();
void begin_poker();
void add_poker();
void game_over();

using namespace std;
int playerpoints;     // ��ҵĵ���
bool haspoker = false;
bool isover = false;
int pokersum = 2; // ����(��ʵֻҪһ��ʼ���ƣ���Ҿ�����������)
int playerpoker[11]; // ��������������11����(4��A,4��2,3��3)
int bankerpoints = 0; // ׯ�ҵĵ���
bool can_over; // ����
bool continue_game = true;
bool hasA = false;

void game_main() // �����￪ʼ����
{
    can_over = false;
    if (continue_game)
    {
        cout << "Game begin...\n";
        cout << "��ʼ����...\n";

        begin_poker();
        if (!hasA)
           show_result();
        cout << "������������1, ";
        cout << "��������2��";
        int t;
        while(cin >> t)
        {
            if (t == 1)
            {
                add_poker();
                show_result();
                cout << "������������1, ";
                cout << "��������2��";
            }
            else
            {
                can_over = true;
                show_result();
            }
        }
    }
}

void count_playerpoints()
{
    playerpoints = 0;
    for (int i = 0; i < pokersum; i++)
    {
        playerpoints = playerpoints + playerpoker[i];
    }
}

void show_result()
{
    if (haspoker)
    {
        show_poker();
        count_playerpoints();
        cout << "�����ڵĵ����ǣ�" << playerpoints << endl;
    }
    if (playerpoints > 21)
    {
        cout << "���Ѿ����ˣ�����\n";
        cout << "ׯ�ҵĵ����ǣ�" << bankerpoints << endl << endl;
        game_over();
    }
    if (can_over)
    {
        if (playerpoints > bankerpoints)
        {
            cout << "��Ӯ�ˣ�\n";
            cout << "ׯ�ҵĵ����ǣ�" << bankerpoints << endl << endl;
            game_over();
        }
        else if (playerpoints == bankerpoints)
        {
            cout << "��ĵ�����ׯ�ҵ�һ��������ׯ��Ӯ�ˣ�\n";
            cout << "ׯ�ҵĵ����ǣ�" << bankerpoints << endl << endl;
            game_over();
        }
        else
        {
            cout << "�����ˣ�\n";
            cout << "ׯ�ҵĵ����ǣ�" << bankerpoints << endl << endl;
            game_over();
        }
    }
}

void show_poker()
{
    cout << "���������е�����: ";
    for (int i = 0; i < pokersum; ++i)
    {
        if (playerpoker[i] == 1)
            cout << "A ";
        else if (playerpoker[i] == 11)
            cout << "J ";
        else if (playerpoker[i] == 12)
            cout << "Q ";
        else if (playerpoker[i] == 13)
            cout << "K ";
        else
            cout << playerpoker[i] << ' ';
    }
    cout << endl;
}

void begin_poker()
{
    int temp;
    // ����ׯ�ҵĵ���
    bankerpoints = 0;
    while (bankerpoints < 17)
    {
        srand(GetTickCount());
        temp = rand() % 13 + 1;
        if (temp > 10)
        {
            bankerpoints += 10;
        }
        else if (temp == 1)
        {
            int t1 = rand() % 2;
            if (t1 == 1 && bankerpoints <= 11)
            {
                bankerpoints += 11; // ��AΪ10.
            }
            else
            {
                bankerpoints += 1; // ��AΪ1.
            }
        }
        else
        {
            bankerpoints += temp;
        }
    }
    if (bankerpoints > 21)
    {
        cout << "ׯ���Ѿ�����\n������Ӯ��\n";
        game_over();
    }


    // ������ҵĵ���
    haspoker = true;
    pokersum = 2;
    for (int i = 0; i < 2; i++)
    {
        temp = rand() % 13 + 1;
        if (temp > 10)
        {
            playerpoker[i] = 10;
        }
        else
        {
            playerpoker[i] = temp;
        }
    }
    for (int i = 0; i < 2; ++i)
    {
        if (playerpoker[i] == 1)
        {
            hasA = true;
            show_poker();
            cout << "������������һ��A��ѡ1����1��ѡ11����2��";
            int t2;
            cin >> t2;
            if (t2 == 1)
            {
                playerpoker[i] = 1;
            }
            else
            {
                playerpoker[i] = 11;
            }
        }
    }
}

void add_poker()
{
    srand(GetTickCount());
    int temp = rand() % 13 + 1;
    if (temp > 10)
    {
        playerpoker[pokersum] = 10;
    }
    else if (temp == 1)
    {
        cout << "��������һ��A��ѡ1����1��ѡ11����2��";
        int t2;
        cin >> t2;
        if (t2 == 1)
        {
            playerpoker[pokersum] = 1;
        }
        else
        {
            playerpoker[pokersum] = 11;
        }
    }
    else
    {
        playerpoker[pokersum] = temp;
    }
    pokersum++;
}

void game_over()
{
    int choice = 0;
    cout << "������Ϸ����1��";
    cout << "�˳���Ϸ����2��";
    cin >> choice;
    if (choice == 1)
    {
        cout << "==========================================\n";
        game_main();
    }
    else
    {
        exit(0);
    }
}
