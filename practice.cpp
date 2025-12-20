#include <iostream>
#include <string>
using namespace std;

int main()
{
    int grade[5] = {67, 88, 28, 55, 33};
    for (int n : grade)
    {
        if (n >= 60)
        {
            cout << n << " pass" << endl;
        }
        else
        {
            cout << n << " fail" << endl;
        }
    }
    char str[] = "tomorrow is exam day"; // c-style string
    string s1 = str;                     // c-style string不能直接轉，使用賦值轉換
    string s2 = (" so sad.");
    string s3 = s1 + "," + s2;
    cout << s3 << endl;
    int num;
    cout << "test if odd or even, enter a number: ";
    cin >> num;
    cout << ((num & 1) ? "odd" : "even") << endl;
    cout << "test if leap year, enter a year: ";
    cin >> num;
    if (!(num % 100 == 0 && num % 400 != 0) && (num % 4 == 0))
    {
        cout << num << " is a leap year." << endl;
    }
    else
    {
        cout << num << " is a normal year." << endl;
    }

    return 0;
}