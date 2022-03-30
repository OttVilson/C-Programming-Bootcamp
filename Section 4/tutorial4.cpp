#include <cstdlib>
#include <iostream>

using namespace std;

int main() {
    string sAge;
    int nAge;

    cout << "Enter your age : ";
    cin >> sAge;
    nAge = stoi(sAge);

    if ((nAge >=1 && nAge <= 18) || nAge == 21 || nAge == 50 || nAge >= 65)
        cout << "Important birthday.\n";
    else
        cout << "Not an important birthday.\n";
}