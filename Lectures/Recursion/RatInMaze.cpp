#include <bits/stdc++.h>
using namespace std;

bool canVisit(vector<vector<int>> m, int n, int x, int y, vector<vector<int>> visited){
    // ? following are the cases for mouse can not visit 
    // ? 1. it is out of the maze
    // ? 2. the position is already visited
    // ? 3. the position is cannot be visited in the maze
    if(x >= 0 && y >= 0 && x < n && y < n && visited[x][y] == 0 && m[x][y] == 1){
        return true;
    }else{
        return false;
    }
}

void pather(vector<vector<int>> &m, int n, vector<string> &ans, vector<vector<int>> &visited, int x, int y, string &path){
    // base case
    // when you reach your destination 
    // which is coordinates (n-1,n-1)
    if(x == n-1 && y == n-1){
        ans.push_back(path);
        return;
    }
    // mark the place you are at currently as visited
    visited[x][y] = 1;
    // 4 choice --> UP, DOWN, RIGHT, LEFT
    // ? UP
    int newX = x-1;
    int newY = y;
    if(canVisit(m, n, newX, newY, visited)){
        path.push_back('U');
        // check on going path
        pather(m, n, ans, visited, newX, newY, path);
        path.pop_back();
    }
    // ? DOWN
    newX = x+1;
    newY = y;
    if(canVisit(m, n, newX, newY, visited)){
        path.push_back('D');
        // check on going path
        pather(m, n, ans, visited, newX, newY, path);
        path.pop_back();
    }
    // ? LEFT
    newX = x;
    newY = y-1;
    if(canVisit(m, n, newX, newY, visited)){
        path.push_back('L');
        // check on going path
        pather(m, n, ans, visited, newX, newY, path);
        path.pop_back();
    }
    // ? RIGHT
    newX = x;
    newY = y+1;
    if(canVisit(m, n, newX, newY, visited)){
        path.push_back('R');
        // check on going path
        pather(m, n, ans, visited, newX, newY, path);
        path.pop_back();
    }
    
    // reset the visited vector
    visited[x][y] = 0;

}

vector<string> findPath(vector<vector<int>> &m, int n){
    vector<string> ans;
    // when the origin(source) is 0 in the maze
    if(m[0][0] == 0){
        return ans;
    }
    vector<vector<int>> visited = m;
    // initiating the visited vector with 0
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            visited[i][j] = 0;
        }
    }
    string path = "";
    int src_x = 0;
    int src_y = 0;
    pather(m, n, ans, visited, src_x, src_y, path);
    
    sort(ans.begin(), ans.end());
    return ans;
}

int main(){
    vector<vector<int>> maze = {
        {1,0,0,0},
        {1,1,0,1},
        {1,1,0,0},
        {0,1,1,1},
    };
    int n = 4;
    vector<string> res = findPath(maze, n);
    // print path
    for(string item : res){
        cout<<item<<endl;
    }
}