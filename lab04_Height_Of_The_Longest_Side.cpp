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
    //  calculates the height of the longest side of a triangle by Heron's formula.
    int a, b, c;
    double s, area, height;
    cout << "enter three sides of a triangle: ";
    cin >> a >> b >> c;
    vector<int> v1 = {a, b, c};
    s = (a + b + c) / 2.0;
    area = sqrt(s * (s - a) * (s - b) * (s - c));
    height = (2 * area) / *max_element(v1.begin(), v1.end());
    cout << "the height of the longest side is " << height << endl;
    return 0;
}