#include <cstdlib>
#include <iostream>

using namespace std;

int main() {

    string sAge;
    int nAge;

    cout << "Enter your age : ";
    cin >> sAge;
    nAge = stoi(sAge);

    if (nAge < 5) 
        cout << "Too young for school.\n";
    else if (nAge == 5)
        cout << "Go to kindergarten.\n";
    else if (nAge >= 6 && nAge <= 17) 
        cout << "Go to grade " << nAge - 5 << ".\n";
    else
        cout << "Go to college.\n";

    return 0;
}