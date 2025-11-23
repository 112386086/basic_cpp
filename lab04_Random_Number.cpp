#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <vector>
#include <random> //practice for C++11 random library
using namespace std;

int main()
{
    int num1, num2, min_num, max_num, res1, res2;
    srand(time(0)); // 使用時間作為亂數種子,設定一次就好
    cout << "enter two integers: ";
    cin >> num1 >> num2;
    min_num = min(num1, num2);
    max_num = max(num1, num2);
    res1 = rand() % (max_num - min_num + 1) + min_num; // 產生 [min , max] 的整數亂數
    cout << "generated random number by rand(): " << res1 << endl;

    random_device rd;                                            // 隨機設備
    default_random_engine gen(rd());                             // 亂數產生器，把隨機設備的值當作亂數種子
    uniform_int_distribution<int> distributed(min_num, max_num); // 亂數的機率均勻分布
    res2 = distributed(gen);                                     // 產生 [min , max] 的整數亂數
    cout << "generated random number by random device: " << res2 << endl;
    return 0;
}