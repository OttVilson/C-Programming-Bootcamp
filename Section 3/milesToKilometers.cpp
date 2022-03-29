#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

int main() {
    cout << "Enter Miles : ";
    string sMiles;
    double dMiles, dKilometers;

    cin >> sMiles;

    dMiles = stod(sMiles);
    dKilometers = dMiles * 1.60;

    printf("%.1f miles equals %.4f kilometers.", dMiles, dKilometers);
    return 0;
}