#include <iostream>
#include <string> //有用到 string就要 include
using namespace std;
// literal字面量 is immutable, evaluated at compile time

int main()
{
    // define variable
    double init_vel = 10;
    double acceleration = 2;
    int time = 5;
    // calculate displacement
    double displacement = init_vel * time + 0.5 * acceleration * time * time;
    // output result
    cout << "EXERCISE 2-1 result: " << endl;
    cout << "Initial Velocity: " << init_vel << endl;
    cout << "Acceleration: " << acceleration << endl;
    cout << "Time: " << time << endl;
    cout << "Displacement: " << displacement << endl;
    return 0;
}