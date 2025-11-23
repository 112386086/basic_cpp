#include <iostream>
#include <fstream>
#include <string>
#include <iomanip> // 輸出格式相關控制
using namespace std;

int main()
{
    ifstream fin("lab3ex1.txt"); // 針對檔案資料的讀入叫做 ifstream(輸入檔案串流), 令變數為 fin,後可接指定檔案名稱
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
    fin.close(); // release memory
    return 0;
}
