# include <iostream>
# include <string>

using namespace std;

int main(){
    int m, n, a = 0, b = 0;
    cin >> m >> n;
    while (m < -200 || n > 200) { //rule
        cout << "Please enter valid integers for m and n (m >= -200, n <= 200): ";
        cin >> m >> n;
    }
    int mA[2][3];
    int mB[3][4];
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            mA[i][j] = m + a;
            a++;
        }
    }
    for (int j = 0; j < 4; j++) {
        for (int i = 0; i < 3; i++) {
            mB[i][j] = n + b;
            b++;
        }
    }
    int sum = 0;
    int mC[2][4] = {0};
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 4; j++) {
            for (int k = 0; k < 3; k++) {
                mC[i][j] += mA[i][k] * mB[k][j];
            }
            sum += mC[i][j];
        }
    }
    cout << sum << endl;
    return 0;
}