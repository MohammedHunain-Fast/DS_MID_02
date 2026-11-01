#include <iostream>
#include <vector>

using namespace std;

void backtrack(vector<vector<int>>& maze, int row, int col, vector<string>& ans, string path, bool key) {
    int n = maze.size();
    if(row < 0 || col < 0 || row >= n || col >= n || maze[row][col] == 0 || maze[row][col] == -1) return;
    if(maze[row][col] == 2) key = true; 
    if(row == n - 1 && col == n - 1) {
        if(key) {
            ans.push_back(path);
        }
        return;
    }
    int ogVal = maze[row][col];
    maze[row][col] = -1;
    backtrack(maze, row + 1, col, ans, path + 'D', key);
    backtrack(maze, row - 1, col, ans, path + 'U', key);
    backtrack(maze, row, col - 1, ans, path + 'L', key);
    backtrack(maze, row, col + 1, ans, path + 'R', key);
    maze[row][col] = ogVal;
}

vector<string> solveMaze(vector<vector<int>>& maze) {
    vector<string> ans;
    string path = "";
    bool key = false;
    backtrack(maze, 0, 0, ans, path, key);
    
    return ans;
}

int main() {
    vector<vector<int>> maze = {{1, 0, 0, 0}, 
                                {1, 2, 0, 1},
                                {1, 1, 0, 0},
                                {0, 1, 1, 1}};

    vector<string> ans = solveMaze(maze);
    for(string path : ans) {
        cout << path << endl;
    }
    return 0;
}