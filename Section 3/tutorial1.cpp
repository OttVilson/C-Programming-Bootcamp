#include <cstdlib>
#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {
    cout << "Hello world!" << endl;

    if (argc != 1) {
        cout << "You entered " << argc << " arguments\n";
        for (int i = 0; i < argc; i++) {
            cout << argv[i] << "\n";
        }
    }

    return 0;
} 