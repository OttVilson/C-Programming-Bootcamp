#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

int main() {
    string message ("Enter a number : ");
    string sNum1, sNum2;
    cout << message;
    cin >> sNum1;
    cout << message;
    cin >> sNum2;
    int dNum1 = stoi(sNum1);
    int dNum2 = stoi(sNum2); 

    printf("%d + %d = %d\n", dNum1, dNum2, sNum1 + sNum2);
    printf("%d - %d = %d\n", dNum1, dNum2, dNum1 - dNum2);
    printf("%d * %d = %d\n", dNum1, dNum2, dNum1 * dNum2);
    printf("%d / %d = %d\n", dNum1, dNum2, dNum1 / dNum2);
    printf("%d %% %d = %d\n", dNum1, dNum2, dNum1 % dNum2);

    string milesMessage = "Enter miles : ";
    cout << milesMessage;
    
    string sMiles;
    cin >> sMiles;
    double dMiles = stod(sMiles);

    float kilometersPerMile = 1.60987;
    printf("%.4f miles equals %.4f kilometers.\n", dMiles, dMiles * kilometersPerMile);

    return 0;
}