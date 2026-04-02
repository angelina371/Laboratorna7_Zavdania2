#include <iostream>
#include <fstream>
#include <Windows.h>
using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    ifstream Fin("Matrix.txt");

    if (!Fin.is_open()) {
        cout << "Ôàéë íå â³äêðèòî!" << endl;
        system("pause");
        return 1;
    }

    double m[3][3];

    cout << "Ìàòðèöÿ ç ôàéëó:\n";

    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            Fin >> m[i][j];
            cout << m[i][j] << "\t";
        }
        cout << endl;
    }

    Fin.close();

    
    double prod = 1;
    bool hasNeg = false;

    for (int i = 1; i < 3; i += 2) {
        for (int j = 0; j < 3; j++) {
            if (m[i][j] < 0) {
                prod *= m[i][j];
                hasNeg = true;
            }
        }
    }

    if (hasNeg)
        cout << "Äîáóòîê â³ä’ºìíèõ ó ïàðíèõ ðÿäêàõ = " << prod << endl;
    else
        cout << "Â ïàðíèõ ðÿäêàõ íåìàº â³ä’ºìíèõ åëåìåíò³â\n";

    
    double a[9];
    int k = 0;

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            a[k++] = m[i][j];

   
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8 - i; j++) {
            if (j % 2 == 0 && a[j] > a[j + 1]) swap(a[j], a[j + 1]);
            if (j % 2 != 0 && a[j] < a[j + 1]) swap(a[j], a[j + 1]);
        }

    cout << "\nÂ³äñîðòîâàíà ìàòðèöÿ:\n";
    for (int i = 0; i < 9; i++) {
        cout << a[i] << "\t";
        if ((i + 1) % 3 == 0) cout << endl;
    }

    system("pause");
    return 0;
}
