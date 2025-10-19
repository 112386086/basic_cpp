#include <iostream>
#include <string> //有用到 string就要 include
using namespace std;
// literal字面量 is immutable, evaluated at compile time

int practice()
{
    const float CONVERSION_FACTOR = 9.0 / 5.0;
    const int OFFSET = 32;
    float temp_c = 0;
    float temp_f = 0;
    cout << "請輸入攝氏溫度(°C): " << endl;
    cin >> temp_c;

    temp_f = (temp_c * CONVERSION_FACTOR) + OFFSET;
    cout << temp_c << " in C = " << temp_f << " in F" << endl;
    return 0;
}

int exercise2()
{
    // define constants
    const double W_MATH = 1.0;
    const double W_PHY = 1.5;
    const double W_CHEM = 2.5;
    const double W_ENG = 3.3;

    int math = 20;
    int physics = 40;
    int chemistry = 60;
    int english = 80;
    double Weighted_Score = 0.0;

    Weighted_Score = (math * W_MATH + physics * W_PHY + chemistry * W_CHEM + english * W_ENG) / (W_MATH + W_PHY + W_CHEM + W_ENG);
    cout << "EXERCISE 2-2 result: " << endl;
    cout << "Math: " << math << endl;
    cout << "Physics: " << physics << endl;
    cout << "Chemistry: " << chemistry << endl;
    cout << "English: " << english << endl;
    cout << "Weighted Score: " << Weighted_Score << endl;
    return 0;
}

int exercise1()
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

int main()
{
    exercise1();
    exercise2();
    return 0;
}