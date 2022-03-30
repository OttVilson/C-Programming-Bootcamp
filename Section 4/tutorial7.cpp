#include <cstdlib>
#include <ctime>
#include <cmath>
#include <iostream>

using namespace std;

int main() {

    int height;
    cout << "How tall should the tree be?";
    cin >> height;

    int width = height*2 - 1;
    string row = "#";
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < i; j++) {
            row = "#" + row + "#";
        }
        while (row.length() < width) {
            row = " " + row + " ";
        }
        cout << row << endl;
        row = "#";
    }

    while (row.length() < width) {
        row = " " + row + " ";
    }
    cout << row << endl;

    return 0;
}
/*
    // int j = 0;
    // while (j < 20) {
    //     j++;
    //     if (j % 2 == 0) continue;

    //     cout << j << "\n";
        
    //     if (j == 15) break;
    // }

    // cout << "Out of the loop\n";

    return 0;
}*/