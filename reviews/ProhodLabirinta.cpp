#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <fstream>
#include <iomanip>

#define ll long long

using namespace std;

// структура позиции ячейки на поле 
struct position
{
    ll x, y;
    void init(ll _x, ll _y)
    {
        x = _x; y = _y;
    }
};

// Задача - проход лабиринта
int main() {
    // Ввод поля
    ll n, m;  // Размеры поля n-строки m-столбцы
    cin >> n >> m;
    ll field[n][m];  // матрица символов - точь-в-точь как в файле. #-стена .-пусто S-старт F-финиш
    ll dp[n][m];  // динамика - каждая ячейка содержит число, минимальный путь до клетки, или -1 если дойти невозможно
    position start, finish;  // позиции старта и финиша
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            cin >> field[i][j];
            dp[i][j] = -1;
        }
    }    
    ll x, y;
    cin >> y >> x;
    start.init(x-1,y-1);
    cin >> y >> x;
    finish.init(x-1,y-1);
    vector<position> queue_pos = {start};  // очередь последних посещённых ячеек
    dp[start.x][start.y] = 0;  // 0 на старте (чтобы добраться от старта до старта длина пути 0)

    // Обход поля
    while (queue_pos.size() > 0)  // пока не обойдем все ячейки
    {
        position cur_pos = queue_pos[0];  // текущая ячейка
        queue_pos.erase(queue_pos.begin());  // удаляем её
        // пытаемся идти во все ячейки вокруг(налево,направо,вверх,вниз), если там нет стены и эта ячейка ещё не была посещена. Длина пути до этих ячеек = длина пути до текущей ячейки +1.
        if (cur_pos.x-1 >= 0 && field[cur_pos.x - 1][cur_pos.y] == 0 && dp[cur_pos.x - 1][cur_pos.y] == -1)
        {
            dp[cur_pos.x - 1][cur_pos.y] = dp[cur_pos.x][cur_pos.y] + 1;
            position new_pos = {cur_pos.x - 1, cur_pos.y};
            queue_pos.push_back(new_pos);
        }
        if (cur_pos.x+1 < n && field[cur_pos.x + 1][cur_pos.y] == 0 && dp[cur_pos.x + 1][cur_pos.y] == -1)
        {
            dp[cur_pos.x + 1][cur_pos.y] = dp[cur_pos.x][cur_pos.y] + 1;
            position new_pos = {cur_pos.x + 1, cur_pos.y};
            queue_pos.push_back(new_pos);
        }
        if (cur_pos.y-1 >= 0 && field[cur_pos.x][cur_pos.y - 1] == 0 && dp[cur_pos.x][cur_pos.y - 1] == -1)
        {
            dp[cur_pos.x][cur_pos.y - 1] = dp[cur_pos.x][cur_pos.y] + 1;
            position new_pos = {cur_pos.x, cur_pos.y - 1};
            queue_pos.push_back(new_pos);
        }
        if (cur_pos.y+1 < m && field[cur_pos.x][cur_pos.y + 1] == 0 && dp[cur_pos.x][cur_pos.y + 1] == -1)
        {
            dp[cur_pos.x][cur_pos.y + 1] = dp[cur_pos.x][cur_pos.y] + 1;
            position new_pos = {cur_pos.x, cur_pos.y + 1};
            queue_pos.push_back(new_pos);
        }
        

        // for (ll i = 0; i < n; i++)
        // {
        //     for (ll j = 0; j < m; j++)
        //     {
        //         cout << setfill(' ') << setw(2) << dp[i][j] << ' ';
        //     }
        //     cout << '\n';
            
        // }
        // cout << '\n';
    }


    // длина кратчайшего пути до финиша 
    cout << dp[finish.x][finish.y] << '\n';   
      
}
