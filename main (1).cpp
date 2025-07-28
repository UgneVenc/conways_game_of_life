#include <iostream>
using namespace std;
void neighbor_check(int i, int j, bool grid[10][10]){
    int x=0;

    if (j > 0 && grid[i][j-1] == 1) x++;
    if (j < 9 && grid[i][j+1] == 1) x++;
    if (i > 0 && grid[i-1][j] == 1) x++;
    if (i < 9 && grid[i+1][j] == 1) x++;

    if (grid[i][j]==0 && x==3){
            grid[i][j]=1;
    }
    else if(x<2 || x>3) {
            grid[i][j]=0;
    }
}
int main() {
    bool grid[10][10];

    for (int i=0; i<10; i++) {
        for (int j=0; j<10; j++) {
            grid[i][j]=1;
            if (i==0 && j==2) {
                grid[i][j]=0;
            }
            cout<<grid[i][j];
        }
        cout<<endl;
    }

    for (int gen=1; gen<=50; gen++) {
        cout<<endl<<"--- GEN: "<<gen<<" ---"<<endl;
        for (int i=0; i<10; i++) {
            for (int j=0; j<10; j++) {
                neighbor_check(i,j, grid);
                cout<<grid[i][j];
            }
            cout<<endl;
        }
    }


    return 0;
}
//Living with less than 2 neighbors dies
//Living with more than 3 neighbors dies
//Dead with 3 neighbors lives