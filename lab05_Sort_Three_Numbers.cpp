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

int main()
{
    // reads three integers from the user, and then outputs them in non-decreasing order.
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
