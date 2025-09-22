#include <iostream>
#include <fstream>
#include <string>
#include <iomanip> // 輸出格式相關控制
using namespace std;
int exam1()
{
    ifstream fin("week3ex1.txt"); // 針對檔案資料的讀入叫做 ifstream(輸入檔案串流), 令變數為 fin,後可接指定檔案名稱
    string words;
    int num1 = 0, num2 = 0;
    // fin.open("week3ex1.txt"); 如果line 8已指定檔案名稱, 則不需再open
    if (!fin.is_open())
    {
        cout << "fails to open file" << endl;
    }
    while (fin >> num1 >> num2)
    {
        cout << "Sum=" << num1 + num2 << ", ";
        cout << "Diff=" << num1 - num2 << ", ";
        cout << "Prod=" << num1 * num2 << ", ";
        cout << "Quot=" << num1 / num2 << endl;
    }

    return 0;
}

int exam2()
{
    string productName;
    int quantity;
    double unitPrice;
    string cashierName;
    double total;
    cout << "enter product name: ";
    getline(cin, productName); // read the whole line
    cout << "enter quantity and unit price: ";
    cin >> quantity >> unitPrice; // cin get data from keyboard with ">>"
    cin.ignore();                 // if mixing cin and getline, cin leaves '\n' in the buffer, remove it, 不輸入參數默認為移除 1 個字元
    cout << "enter cashier name: ";
    getline(cin, cashierName);
    total = quantity * unitPrice;
    cout << fixed << setprecision(2);   // 設定float/double的精確度, fixed 指固定decimal format for output
    cout << left << setw(20) << "Item"; // 像左靠齊並設定欄寬20
    cout << right << setw(6) << "Qty";
    cout << right << setw(10) << "Unit";
    cout << right << setw(12) << "Total" << endl;

    cout << left << setw(20) << productName;
    cout << right << setw(6) << quantity;
    cout << right << setw(10) << unitPrice;
    cout << right << setw(12) << total << endl;

    cout << "Cashier: " << cashierName << endl;

    return 0;
}

int main()
{
    exam1();
    exam2();
    return 0;
}