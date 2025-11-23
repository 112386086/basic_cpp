# include <iostream>
# include <string>

using namespace std;


/* -----------exercise----------- */
int linear_search(const int arr[], int target){ // use const to prevent modification of input array
    int x = 20, idx = -1;
    int min = arr[0], max = arr[0];
    for (int i = 0; i < 5; i++) {
        if (arr[i] >= target) {
            idx = i; // return index if found
        }
        min = ((arr[i] < min)? arr[i] : min);
        max = ((arr[i] > max)? arr[i] : max);
    }
    cout << "Min: " << min << ", Max: " << max << endl;
    cout << "idx: " << idx << endl; // return -1 if not found
    return idx;
}

int insertion_sort(int arr[]){
    for (int i = 1; i < 5; i++) {
        for (int j = i; j > 0; j--) {
            if (arr[j] < arr[j - 1]) {
                int temp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = temp;
            }
        }
    }
    cout << "Sorted array: ";
    for (int i = 0; i < 5; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}

void copyArray(const int src[], int dst[], int n){
    for (int i = 0; i < n; i++) {
        dst[i] = src[i]; // copy each element from source to destination
    }
    cout << "dst array after copy: ";
    for (int i = 0; i < n; i++) {
        cout << dst[i] << " ";
    }
    cout << endl;
}

void matrixExample() {
    const int rows = 4;
    const int cols = 4;
    int diagonalSum = 0;
    int matrix[rows][cols] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << " ";
            if (i == j){
                diagonalSum += matrix[i][j];
            }
        }
        cout << endl; //change line after each row
    }
    cout << "Diagonal Sum: " << diagonalSum << endl;
}



int calculate_revenue() {
    int revenue[5] = {100, 120, 90, 130, 110}; // size decided at declaration, can't be changed later
    for (int i = 0; i < 5; i++) { // ensure index is within capacity of array
        cout << "Day " << (i + 1) << " Revenue: $" << revenue[i] << endl;  //use index to access array elements
    }
    return 0;
}

int linear_search() {
    int result;
    int revenue[5] = {100, 120, 90, 130, 110}; //assign before use, otherwise random values
    int dst[sizeof(revenue)] = {0};
    result = linear_search(revenue, 115);
    cout << "Linear Search Result Index: " << result << endl;
    insertion_sort(revenue);
    copyArray(revenue, dst, 5);
    matrixExample();
    return 0;
}

/* -----------week homework----------- */

int main(){
    int k;
    cin >> k;
    int arr[5];
    for (int i = 0; i < 5; i++) {
        cin >> arr[i];
    } 
    while (k < 0 || k > 100) {
        cout << "Please enter a valid rotation count (0-100): ";
        cin >> k;
    }
    int n = sizeof(arr)/sizeof(arr[0]);
    k = k % n;
    int temp[n];
    for (int i = 0; i < n; i++) {
        temp[(i + k) % n] = arr[i];
    }
    for (int i = 0; i < n; i++) {
        cout << temp[i] << " ";
    }
    return 0;
}
