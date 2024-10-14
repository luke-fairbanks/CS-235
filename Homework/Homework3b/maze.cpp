#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <stdexcept>

#include "Grid.h"

using namespace std;

bool find_maze_path(Grid& maze, int row, int col, int level, vector<string>& solution) {
    string currentIndex = to_string(row)+" "+to_string(col)+" "+to_string(level);
    solution.push_back(currentIndex);

    // base case, if outside of maze
    if (row < 0 || row >= maze.height() || col < 0 || col >= maze.width() || level < 0 || level >= maze.depth()) {
        solution.pop_back(); // remove our solution
        return false;
    }

    // base case, if outside of maze || on invalid path || have been here before
    if ( maze.at(row,col,level)==0 || maze.at(row,col,level)==2){
        solution.pop_back(); // remove our solution
        return false;
    }

    // base case, if at the end of the maze
    if(row == maze.height()-1 && col == maze.width()-1 && level == maze.depth()-1){
        return true;
    }
    maze.at(row,col,level) = 2;
    if( find_maze_path(maze, row-1, col, level, solution)||
        find_maze_path(maze, row+1, col, level, solution)||
        find_maze_path(maze, row, col-1, level, solution)||
        find_maze_path(maze, row, col+1, level, solution)||
        find_maze_path(maze, row, col, level-1, solution)||
        find_maze_path(maze, row, col, level+1, solution))
    {
        return true;
    } else{
        solution.pop_back();
        return false;
    }



}

void maze_helper_function(string fileName, string outPutName){
    ifstream in(fileName);
    if(!in){
        exit(1);
    }
    ofstream o(outPutName);
    if(!o){
        exit(1);
    }
    Grid maze;
    vector<string> solution;
    in >> maze;
    if(find_maze_path(maze, 0, 0, 0, solution)){

        o << "SOLUTION" << endl;

        for (auto it = solution.begin(); it != solution.end(); ++it ){
            o << *it << endl;
        };
    } else {
        o << "NO SOLUTION" << endl;
        exit(0);
    }
}

int main (int argc, char* argv[]) {
    // Write your code here
    maze_helper_function(argv[1], argv[2]);
    return 0;
}
