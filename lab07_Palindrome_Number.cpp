#include <iostream>
using namespace std;

int reverse(int n)
{
    int rev = 0;
    while (n > 0)
    {
        rev = rev * 10 + n % 10;
        n /= 10;
    }
    return rev;
}

bool isPalindrome(int n)
{
    return n == reverse(n);
}

int main()
{
    int n = 0;
    do
    {
        cout << " Enter a positive integer: ";
        cin >> n;
    } while (n <= 0 || n > 1000000);

    if (isPalindrome(n))
    {
        cout << n << " is a palindrome." << endl;
    }
    else
    {
        cout << n << " is not a palindrome." << endl;
    }
    return 0;
}
