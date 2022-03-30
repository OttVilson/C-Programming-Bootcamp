#include <cstdlib>
#include <iostream>
#include <cmath>
#include <ctime>

using namespace std;

int main() {
    cout << "abs(-10) : " << abs(-10) << "\n";
    cout << "max(2, 7) : " << max(2, 7) << "\n";
    cout << "min(2, 7) : " << min(2, 7) << "\n";
    cout << "ceil(10.45) : " << ceil(10.45) << "\n";
    cout << "floor(10.45) : " << floor(10.45) << "\n";
    cout << "round(10.55) : " << round(10.55) << "\n";
    cout << "pow(2, 3) : " << pow(2, 3) << "\n";
    cout << "sqrt(1.21) : " << sqrt(1.21) << "\n";
    cout << "cbrt(343) : " << cbrt(343) << "\n";

    srand(time(NULL));
    int secretNum = rand() % 11;
    cout << "Secret number : " << secretNum;

    return 0;
}