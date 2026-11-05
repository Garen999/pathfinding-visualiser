#include <iostream>
#include <vector>
#include <string>
#include <random>
using namespace std;

int main() {
    int x_pos = 0;
    int y_pos = 0;

    random_device rd;
    mt19937 gen(rd()); 
    uniform_int_distribution<int> distrib(0,1);

    vector<vector<int>> grid(10,vector<int>(10,0));

    for (int row = 0; row < 10 ; row++) {
        for (int col = 0; col < 10 ; col++) {
            grid[row][col] = distrib(gen);
        }
    }

    grid[9][9] = 3;
    grid[0][0] = 0;

    cout << "Entered the Grid\n";

    while (true) {
        cout << "Current Grid Coordinates: (" << x_pos << "," << y_pos << ")\n";

        if (grid[x_pos][y_pos] == 3) {
            cout << "Escaped the Grid\n";
            return 0;
        }

        if (y_pos + 1 < 10 && (grid[x_pos][y_pos + 1] == 0 || grid[x_pos][y_pos + 1] == 3)) {
            y_pos++;
        } else if (x_pos + 1 < 10 && (grid[x_pos + 1][y_pos] == 0 || grid[x_pos + 1][y_pos] == 3)) {
            x_pos++;
        } else {
            cout << "Trapped in the Grid\n";
            return 0;
        }
    }
}