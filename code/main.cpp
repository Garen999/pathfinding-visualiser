//imports libraries
#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;

//validates neighbouring cells
vector<pair<int,int>> checks_neighbours(int row, int col, int grid_width, int grid_height, vector<vector<int>>& grid) {
    vector <pair<int,int>> neighbours;
    if (row < grid_height && row >= 0) {
        if (col+1 < grid_width && col+1 >= 0 && (grid[row][col+1] == 0 || grid[row][col+1] == 3)) {
            neighbours.push_back({row,col+1});
        }
        if (col-1 < grid_width && col-1 >= 0 && (grid[row][col-1] == 0 || grid[row][col-1] == 3)) {
            neighbours.push_back({row,col-1});
        }
    }
    if (col < grid_width && col >= 0) {
        if (row+1 < grid_height && row+1 >= 0 && (grid[row+1][col] == 0 || grid[row+1][col] == 3)) {
            neighbours.push_back({row+1,col});
        }
        if (row-1 < grid_height && row-1 >= 0 && (grid[row-1][col] == 0 || grid[row-1][col] == 3)) {
            neighbours.push_back({row-1,col});
        }
    }
    return neighbours;
}

//performs breadth first search algorithm
bool bfs(int row, int col, int grid_width, int grid_height, vector<vector<int>>& grid, map<pair<int,int>, bool>& discovered, map<pair<int,int>, bool>& explored, map<pair<int,int>, pair<int,int>>& parent) {
    queue<pair<int,int>> queue;
    bool escape_found = false;
    queue.push({row, col});

    while (!(queue.empty()) && !escape_found) {
        row = queue.front().first;
        col = queue.front().second;
        queue.pop();
        explored[{row,col}] = true;

        if (grid[row][col] == 3) {
            escape_found = true;
            cout << "Escaped the Grid\n";
            break;
        }
            
            for (auto neighbour: checks_neighbours(row, col, grid_width, grid_height, grid)) {
                if (!(discovered[{neighbour.first, neighbour.second}])) {
                    parent[{neighbour.first,neighbour.second}] = {row,col};
                    queue.push(neighbour);
                    discovered[{neighbour.first,neighbour.second}] = true;
                }
            }
    }
    return escape_found;
}

//creates visual representation of grid
void display_grid(int grid_width, int grid_height, vector<vector<int>>& grid, map<pair<int,int>, bool>& explored, vector<pair<int,int>>& path) {
    for (int row = 0; row < grid_height ; row++) {
        for (int col = 0; col < grid_width ; col++) {
            string symbol;
            if (grid[row][col] == 1) {
                symbol = "#";
            } else if (grid[row][col] == 3) {
                symbol = "E";
            } else if (row == 0 && col == 0) {
                symbol = "S";
            } else if (find(path.begin(), path.end(), pair<int,int> {row,col}) != path.end()) {
                symbol = "*";
            } else if (explored[{row,col}]) {
                symbol = "+";
            } else {
                symbol = ".";
            }
            cout << symbol << " ";
        }
        cout << "\n";
    }
}

//main function
int main() {
    //initialises variables
    int current_row = 0;
    int current_col  = 0;
    int grid_width = 10;
    int grid_height = 10;

    //creates random generator
    random_device rd;
    mt19937 gen(rd()); 
    uniform_int_distribution<int> distrib(1,100);

    //creates data structures
    vector<vector<int>> grid(grid_height,vector<int>(grid_width,0));
    map<pair<int,int>, bool> discovered;
    map<pair<int,int>, bool> explored;
    map<pair<int,int>, pair<int,int>> parent;
    vector<pair<int,int>> path;

    //randomly places obstacles in grid
    for (int row = 0; row < grid_height ; row++) {
        for (int col = 0; col < grid_width ; col++) {
            if (distrib(gen) <= 25) {
                grid[row][col] = 1;
            } else {
                grid[row][col] = 0;
            }
            discovered[{row,col}] = false;
            explored[{row,col}] = false;
        }
    }

    //assigns guaranteed grid element states
    grid[grid_height-1][grid_width-1] = 3;
    grid[0][0] = 0;
    discovered[{0,0}] = true;
    cout << "Entered the Grid\n";

    //searches grid
    if (!bfs(current_row, current_col, grid_width, grid_height, grid, discovered, explored, parent)) {
        cout << "Trapped in Grid \n";
    } else {
        int row = grid_height-1;
        int col = grid_width-1;
        bool path_complete = false;

        //finds ideal path
        while (!path_complete) {
            path.push_back({row,col});
            if (row == 0 && col == 0) {
                path_complete = true;
                break;
            }
            auto next = parent[{row,col}];
            row = next.first;
            col = next.second;
        }

        //prints ideal path
        cout << "Path: ";
        for (int i = path.size() - 1; i >= 0; --i) {
            cout << "(" << path[i].first << "," << path[i].second << ")"; 
        }
        cout << "\n";
    }

    //displays grid
    display_grid(grid_width, grid_height, grid, explored, path);
}