#include <cstdlib>
#include <iostream>
#include <string>
#include <limits>

using namespace std;

int g_iRandNum = 0;
const double PI = 3.1415;

int main() {
    bool isMarried = true;
    char chMyChar = 'A';

    unsigned short int age = 64000;
    short int value = 32000;
    int nDays = 123;
    long lValue = 20000;

    printf("Boolean -- size: %d, min value: %d, max value: %d\n", sizeof(bool), numeric_limits<bool>::min(),
        numeric_limits<bool>::max());

    printf("Short -- size: %d, min value: %d, max value: %d\n", sizeof(short), numeric_limits<short>::min(),
        numeric_limits<short>::max());

    printf("Short int -- size: %d, min value: %d, max value: %d\n", sizeof(short int), numeric_limits<short int>::min(),
        numeric_limits<short int>::max());

    printf("Unsigned short int -- size: %d, min value: %d, max value: %d\n", sizeof(unsigned short int), 
        numeric_limits<unsigned short int>::min(), numeric_limits<unsigned short int>::max());

    cout << "Unsigned long -- size: " << sizeof(unsigned long long) << ", min value: " << numeric_limits<unsigned long long>::min() <<
        ", max value: " << numeric_limits<unsigned long long>::max() << ".\n"; 

    printf("int -- size: %d, min value: %d, max value: %d\n", sizeof(int), numeric_limits<int>::min(),
        numeric_limits<int>::max());

    printf("long int -- size: %d, min value: %d, max value: %d\n", sizeof(long), numeric_limits<long>::min(),
        numeric_limits<long>::max());

    cout << "Long long int -- size: " << sizeof(long long) << ", min value: " << numeric_limits<long long>::min() <<
        ", max value: " << numeric_limits<long long>::max() << ".\n";

    cout << "Double -- size: " << sizeof(double) << ", min value: " << numeric_limits<double>::min() <<
        ", max value: " << numeric_limits<double>::max() << ".\n";

    cout << "Float -- size: " << sizeof(float) << ", min value: " << numeric_limits<float>::min() <<
        ", max value: " << numeric_limits<float>::max() << ".\n";

    float fFirst = 111.1111111;
    float fSecond = 111.1111111;
    printf("The sum is %.10f.\n", fFirst + fSecond);

    double dbFirst = 111.11111111111111;
    double dbSecond = 111.11111111111111;
    printf("The sum is %.20f.\n", dbFirst + dbSecond);



    return 0;
}
