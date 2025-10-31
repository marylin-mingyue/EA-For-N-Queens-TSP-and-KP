#include <bits/stdc++.h>
using namespace std;
// Time Complexity : O(N!)
// Space Complexity : O(1)
// We raised the solutions by Combination
int n;
/*
 for loop 2: col[1] = 1
 // Just for idea generating
 b = i - j
 b = -1

 left [-3 -2 -1 0 1 2 3] + (n-1) = [0,1,2,3,4,5,6]
                                    0 0 1 0 0 0 0


 {(n-1) - j} - i
 y = b - x
 b = y + x
   = (n-1) - j + i
                        right    = [0 1 2 3 4 5 6]
                                    0 0 0 0 1 0 0
         0 1 2 3
 pos = 0 0 - * - -
 pos = 1 - - - *
 pos = 2 * - - -
 pos = 3 - - * -
//
 *
 */
void solve(int row,vector <int> col,vector <int> left, vector <int> right,vector <vector <int>> board) {
    if (row == n) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j]) {
                    cout << '*' << " ";
                }
                else cout << '-' << " ";
            }
            cout << endl;
        }
        cout << "--------------------------"<<endl;
        return;
    }

    for (int i = 0; i < n; i++) {
        if (!col[i] && !left[row - i + n - 1] && !right[row + i]) {
            left[row - i + n - 1] = 1;
            right[row + i] = 1;
            col[i] = 1;
            board[row][i] = 1;
            solve(row+1,col,left,right,board);
            left[row - i + n - 1] = 0;
            right[row + i] = 0;
            col[i] = 0;
            board[row][i] = 0;
        }

    }

}

int main() {
    cout << "Enter the number of the queens:";
    cin >> n;
    vector <vector <int>> board (n, vector <int> (n,0));
    vector <int> left (2*n-1,0);
    vector <int> right (2*n-1,0);
    vector <int> col (n,0);
    solve(0,col,left,right,board);
}
