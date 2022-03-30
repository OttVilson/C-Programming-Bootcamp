#include <cstdlib>
#include <iostream>

using namespace std;

int main() {
    double yearlyInvestment;
    double interestRate;

    cout << "How much to invest yearly : ";
    cin >> yearlyInvestment;
    cout << "Interest rate : ";
    cin >> interestRate;

    double total = yearlyInvestment;

    for (int i = 1; i <= 10; i++) {
        total = total * (interestRate + 100) / 100 + yearlyInvestment;
    }

    cout << total;

    return 0;
}
/*
 
    for (int i = 0; i < 10; i++) {
        cout << i << "\n";
    }

    // int arr[] = {1, 2, 3};
    // int size = sizeof(arr) / sizeof(arr[0]);

    // for (int i = 0; i < size; i++) {
    //     cout << arr[i] << endl;
    // }

    // for (auto x : arr) cout << x << endl;

    for (int i = 0; i <= 20; i++)
        if (i % 2 == 1)
            cout << i << "\n";


}*/