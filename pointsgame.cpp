#include <iostream>
#include <random>

void count_playerpoints();
void show_result();
void show_poker(int[]);
void begin_poker();
void add_poker();
void game_over();

using namespace std;
int playerpoints;     // 玩家的点数
bool haspoker = false;
bool isover = false;
int pokersum = 2; // 牌数(其实只要一开始发牌，玩家就有两张牌了)
int playerpoker[11]; // 假设玩家最多能拿21张牌
int bankerpoints; // 庄家的点数
bool can_over; // 开牌
bool continue_game = true;

void game_main() // 从这里开始运行
{
    can_over = false;
    if (continue_game)
    {
        cout << "Game begin...\n";
        int choice;
        cout << "开始发牌输入1, ";
        cout << "结束游戏输入2：";
        cin >> choice;
        if (choice == 1)
        {
            begin_poker();
            show_result();
            cout << "继续发牌输入1, ";
            cout << "结束游戏输入2：";
            int t;
            while(cin >> t)
            {
                if (t == 1)
                {
                    add_poker();
                    show_result();
                    cout << "继续发牌输入1, ";
                    cout << "结束游戏输入2：";
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
        cout << "\n你现在的点数是：" << playerpoints << endl;
    }
    if (playerpoints > 21)
    {
        cout << "你已经爆了！！！\n";
        cout << "庄家的点数是：" << bankerpoints << endl << endl;
        game_over();
    }
    if (can_over)
    {
        if (playerpoints > bankerpoints)
        {
            cout << "你赢了！\n";
            cout << "庄家的点数是：" << bankerpoints << endl << endl;
            game_over();
        }
        else if (playerpoints == bankerpoints)
        {
            cout << "你的点数和庄家的一样，所以庄家赢了！\n";
            cout << "庄家的点数是：" << bankerpoints << endl << endl;
            game_over();
        }
        else
        {
            cout << "你输了！\n";
            cout << "庄家的点数是：" << bankerpoints << endl << endl;
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
    cout << "继续游戏输入1：";
    cout << "退出游戏输入2：";
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
