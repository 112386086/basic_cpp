#include <iostream>
#include <string>
using namespace std;

int ex1()
{
    char x[30];
    int i = 0, count = 0;
    cout << "Enter number: ";
    cin.getline(x, 30); // 也能直接用getline(cin, s_input);

    while (x[i] != '1' && x[i] != '\0') //'\0'表示 null character, 字串結束符號
    {
        if (x[i] == '0')
        {
            count++;
        }
        i++;
    }
    cout << "number of zeros: " << count << endl;
    return 0;
}

int ex2()
{
    int n; // 就算後續input為浮點數也會自動轉成整數
    do
    {
        cout << "enter the number of the pyramid levels: " << endl;
        cin >> n;
    } while (n < 0 || n > 9);

    for (int lev = 1; lev <= n; lev++)
    {
        for (int space = 1; space <= lev; space++)
        {
            cout << " ";
        }
        int max_num = n - lev + 1;
        for (int i = 1; i <= max_num; i++)
        {
            cout << i;
        }

        for (int j = max_num - 1; j > 0; j--)
        {
            cout << j;
        }
        cout << endl;
    }
    return 0;
}

int main()
{
    ex1();
    ex2();
    return 0;
}