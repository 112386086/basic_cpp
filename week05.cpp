#include <iostream>
#include <cmath>

using namespace std;
void swap(int *x, int *y)
{
    int tmp = *x;
    *x = *y;
    *y = tmp;
}
void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

int ex1()
{
    int a, b, c, temp;
    int arr[3];
    for (int i = 0; i < 3; i++)
    {
        cin >> arr[i]; // cin不用endl
    }
    // when compares two values, datatypes on both sides should be compatible
    bubbleSort(arr, 3);
    for (int i = 0; i < 3; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}

int ex2()
{
    // Input: one floating-point number (travel distance, unit = 0.1 km).
    float dist, extra;
    int fee;
    cout << "input travel distance, unit = 0.1 km: ";
    cin >> dist;
    if (dist <= 1.5)
    {
        fee = 70;
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

int main()
{
    ex1();
    ex2();
    return 0;
}