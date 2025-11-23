#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    // Input: one floating-point number (travel distance, unit = 0.1 km).
    float dist, extra;
    int fee;
    cout << "input travel distance, unit = 0.1 km: ";
    cin >> dist;
    if (dist <= 1.5)
    {
        fee = 70; // base fare if dist <= 1.5 km
    }
    else if (dist > 2.0)
    {
        extra = (dist - 1.5) / 0.1;
        fee = (70 + extra * 5) * 1.1;
    }
    else
    {
        extra = (dist - 1.5) / 0.1;
        fee = 70 + extra * 5;
    }
    cout << fee << endl;
    return 0;
}