#include <iostream>
#include <string>
using namespace std;

int main()
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