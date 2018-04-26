#include <iostream>
#include <random>

void count_playerpoints();
void show_result();
void show_poker(int[]);

using namespace std;
int playerpoints;     // 玩家的点数
int arr[14];
bool haspoke = false;
bool isover = false;
int pokersum; // 牌数(其实只要一开始发牌，玩家就有两张牌了)
int playerpoker[21]; // 假设玩家最多能拿21张牌
int bankerpoints; // 庄家的点数
bool can_over = false; // 开牌

void game_main()
{
    int choice = 1;
    while (choice == 1)
    {
        cout << "开始发牌输入1：\n";
        cout << "继续发牌输入2：\n";
        cout << "开牌输入3：\n";
        cin >> choice;
        switch(choice)
        {
        case 1:
            // 随机产生庄家的点数
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
            // 继续发牌，所以产生一个新的随机数，并且玩家牌数+1
            playerpoker[pokersum] = rand() % 13;
            pokersum++;
            break;

            count_playerpoints();

        case 3:
            can_over = true;
            break;

            if (playerpoints > 21)
            {
                cout << "开始发牌输入1：\n";
                show_result();
            }
            if (can_over)
            {
                cout << "开牌输入3：\n";
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
        cout << "你现在的点数是：" << playerpoints << endl;
    }
    if (playerpoints > 21)
    {
        cout << "你已经爆了！！！\n";
    }
    if (can_over)
    {
        if (playerpoints > bankerpoints)
        {
            cout << "你赢了！\n";
        }
        else if (playerpoints == bankerpoints)
        {
            cout << "你的点数和庄家的一样，所以庄家赢了！\n";
        }
        else
        {
            cout << "你输了！\n";
        }
        can_over = false;
        cout << "庄家的点数是：" << bankerpoints << endl;
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
