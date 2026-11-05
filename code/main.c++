#include <iostream>
#include <vector>
#include <string>
#include <random>
using namespace std;

int main() {
    int current_row = 0;
    int current_col  = 0;

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
        cout << "Current Grid Coordinates: (" << current_row << "," << current_col << ")\n";

        if (grid[current_row][current_col] == 3) {
            cout << "Escaped the Grid\n";
            return 0;
        }

        vector<pair<int,int>> valid_moves;

        if (current_col+1 < 10 && (grid[current_row][current_col+1] == 0 || grid[current_row][current_col+1] == 3)) {
            valid_moves.push_back({current_row,current_col+1});
        }
        if (current_col-1 > -1 && (grid[current_row][current_col-1] == 0 || grid[current_row][current_col-1] == 3)) {
            valid_moves.push_back({current_row,current_col-1});
        }
        if (current_row+1 < 10 && (grid[current_row+1][current_col] == 0 || grid[current_row+1][current_col] == 3)) {
            valid_moves.push_back({current_row+1,current_col});
        }
        if (current_row-1 > -1 && (grid[current_row-1][current_col] == 0 || grid[current_row-1][current_col] == 3)) {
            valid_moves.push_back({current_row-1,current_col});
        }
        if (valid_moves.empty()) {
            cout << "Trapped in the Grid\n";
            return 0    ;
        } else {
            //cout << "Valid Moves: " << current_row << "," << current_col << ")\n";
        }
    }
}