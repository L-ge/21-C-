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
int playerpoints;     // 玩家的点数
bool haspoker = false;
bool isover = false;
int pokersum = 2; // 牌数(其实只要一开始发牌，玩家就有两张牌了)
int playerpoker[11]; // 假设玩家最多能拿11张牌(4张A,4张2,3张3)
int bankerpoints = 0; // 庄家的点数
bool can_over; // 开牌
bool continue_game = true;
bool hasA = false;

void game_main() // 从这里开始运行
{
    can_over = false;
    if (continue_game)
    {
        cout << "Game begin...\n";
        cout << "开始发牌...\n";

        begin_poker();
        if (!hasA)
           show_result();
        cout << "继续发牌输入1, ";
        cout << "开牌输入2：";
        int t;
        while(cin >> t)
        {
            if (t == 1)
            {
                add_poker();
                show_result();
                cout << "继续发牌输入1, ";
                cout << "开牌输入2：";
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
        cout << "你现在的点数是：" << playerpoints << endl;
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

void show_poker()
{
    cout << "现在你手中的牌是: ";
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
    // 产生庄家的点数
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
                bankerpoints += 11; // 即A为10.
            }
            else
            {
                bankerpoints += 1; // 即A为1.
            }
        }
        else
        {
            bankerpoints += temp;
        }
    }
    if (bankerpoints > 21)
    {
        cout << "庄家已经爆了\n所以你赢了\n";
        game_over();
    }


    // 产生玩家的点数
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
            cout << "所以你现在有一个A，选1输入1，选11输入2：";
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
        cout << "你现在有一个A，选1输入1，选11输入2：";
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
    cout << "继续游戏输入1：";
    cout << "退出游戏输入2：";
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
