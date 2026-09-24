#include <iostream>
#include <vector>
#include <string>
#include <random>
using namespace std;

int main() {
    int x_pos = 0;
    int y_pos = 0;
    bool escape = false;
    string cell_condition;

    random_device rd;
    mt19937 gen(rd()); 
    uniform_int_distribution<int> distrib(0,1);

    vector<vector<int>> grid(10,vector<int>(10,0));

    cout << "Entered the Grid\n";

    while (escape == false) {
        for (int row = 0; row < 10 ; row++) {
            for (int col = 0; col < 10 ; col++) {

                grid[row][col] = distrib(gen);
                grid[9][9] = 3;

                if (grid[row][col] == 0) {
                    if (row == x_pos++ || row == x_pos--) {
                        x_pos = row;
                    } else if (col == y_pos++ || col == y_pos--) {
                        y_pos = col;
                    }
                    cout << "Current Grid Coordinates: (" << x_pos << "," << y_pos << ")\n";
                }

                if (grid[row][col] == 3) {
                    cout << "Escaped the Grid";
                    escape = true;
                    break;
                }
            }
        }  
    }

    return 0;
}