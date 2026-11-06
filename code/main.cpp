//imports modules
#include <iostream>
#include <vector>
#include <string>
#include <random>
using namespace std;

//determines which moves are valid
void determines_valid_moves(int row, int col, vector<vector<int>>& grid, vector <pair<int,int>>& valid_moves) {
    if (col < 10 && row < 10 && col >= 0 && row >= 0) {
        if (col < 10 && (grid[row][col] == 0 || grid[row][col] == 3)) {
            valid_moves.push_back({row,col});
        }
    }
}

//main function
int main() {
    //initialises variables
    int current_row = 0;
    int current_col  = 0;
    int valid_move_index;

    //creates random generator
    random_device rd;
    mt19937 gen(rd()); 
    uniform_int_distribution<int> distrib(0,1);

    //creates grid
    vector<vector<int>> grid(10,vector<int>(10,0));

    //randomly places walls in grid
    for (int row = 0; row < 10 ; row++) {
        for (int col = 0; col < 10 ; col++) {
            grid[row][col] = distrib(gen);
        }
    }

    //assigns guaranteed grid element states
    grid[9][9] = 3;
    grid[0][0] = 0;

    cout << "Entered the Grid\n";

    //searches through grid
    while (true) {
        cout << "Current Coordinates: (" << current_row << "," << current_col << ")\n";
        
        //Ends program when the exit is found
        if (grid[current_row][current_col] == 3) {
            cout << "Escaped the Grid\n";
            return 0;
        } else {
            grid[current_row][current_col] = 2;
        }

        //determines if moves are valid
        vector<pair<int,int>> valid_moves;
        determines_valid_moves(current_row, current_col + 1, grid, valid_moves);
        determines_valid_moves(current_row, current_col - 1, grid, valid_moves);
        determines_valid_moves(current_row + 1, current_col, grid, valid_moves);
        determines_valid_moves(current_row - 1, current_col, grid, valid_moves);

        //ends program if there are no valid moves
        if (valid_moves.empty()) {
            cout << "Trapped in Grid\n";
            return 0    ;
        } else {
            //shows user all valid moves
            cout << "Valid Cells: ";
            for (auto valid_move: valid_moves) {
                cout << "(" << valid_move.first << "," << valid_move.second << ")";
    
                current_row = valid_moves[0].first;
                current_col = valid_moves[0].second;

            }
            cout << "\n";
        }

    }
}