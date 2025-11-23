#include <iostream>
#include <string>
using namespace std;

int main()
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
