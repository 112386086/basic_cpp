#include <iostream>
using namespace std;

void climb(int start, int target, string path)
{
    if (start == target)
    { // reached
        cout << path << endl;
        return;
    }
    else if (start > target)
    { // exceeded
        return;
    }
    else
    {
        int next_step = start + 1;
        if (next_step % 3 != 0 || next_step == target)
        {
            climb(next_step, target, path + to_string(next_step) + " ");
        }
        int next2_step = start + 2;
        if (next2_step % 3 != 0 || next2_step == target)
        {
            climb(next2_step, target, path + to_string(next2_step) + " ");
        }
    }
}
int climbStairs(int n)
{
    if (n % 3 == 0 && n != 0)
    {
        cout << "no solution" << endl;
        return 0;
    }
    else if (n < 1 || n > 10)
    {
        cout << "invalid input" << endl;
        return 0;
    }
    climb(0, n, "0 ");
    return 0;
}

int main()
{
    int s = 0;
    cout << " Enter the number of stairs: ";
    cin >> s;
    climbStairs(s);
    return 0;
}