#include <iostream>
#include <random>

void count_playerpoints();
void show_result();
void show_poker(int[]);
void begin_poker();
void add_poker();
void game_over();

using namespace std;
int playerpoints;     // ��ҵĵ���
bool haspoker = false;
bool isover = false;
int pokersum = 2; // ����(��ʵֻҪһ��ʼ���ƣ���Ҿ�����������)
int playerpoker[11]; // ��������������21����
int bankerpoints; // ׯ�ҵĵ���
bool can_over; // ����
bool continue_game = true;

void game_main() // �����￪ʼ����
{
    can_over = false;
    if (continue_game)
    {
        cout << "Game begin...\n";
        int choice;
        cout << "��ʼ��������1, ";
        cout << "������Ϸ����2��";
        cin >> choice;
        if (choice == 1)
        {
            begin_poker();
            show_result();
            cout << "������������1, ";
            cout << "������Ϸ����2��";
            int t;
            while(cin >> t)
            {
                if (t == 1)
                {
                    add_poker();
                    show_result();
                    cout << "������������1, ";
                    cout << "������Ϸ����2��";
                }
                else
                {
                    can_over = true;
                    show_result();
                }
            }
        }
    }
}

void count_playerpoints()
{
    playerpoints = 0;
    for (int i = 0; i < pokersum; i++)
    {
        playerpoints = playerpoints + playerpoker[i] + 1;
    }
}

void show_result()
{
    if (haspoker)
    {
        show_poker(playerpoker);
        count_playerpoints();
        cout << "\n�����ڵĵ����ǣ�" << playerpoints << endl;
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

void show_poker(int playerpoker[])
{
    cout << "Now I have : ";
    for (int i = 0; i < pokersum; ++i)
    {
        if (playerpoker[i] == 0)
            cout << "A ";
        else if (playerpoker[i] == 10)
            cout << "J ";
        else if (playerpoker[i] == 11)
            cout << "Q ";
        else if (playerpoker[i] == 12)
            cout << "K ";
        else
            cout << playerpoker[i] + 1 << ' ';
    }
}

void begin_poker()
{
    bankerpoints = rand() % 22;
    if (bankerpoints < 10)
    {
        bankerpoints = bankerpoints + 10;
    }
    haspoker = true;
    pokersum = 2;
    for (int i = 0; i < 2; i++)
    {
        playerpoker[i] = rand() % 13;
    }
}

void add_poker()
{
    playerpoker[pokersum] = rand() % 13;
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
        game_main();
    }
    else
    {
        exit(0);
    }
}
