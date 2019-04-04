#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
    bool solve(vector<vector<char>>& board)
    {
        for(int i=0; i<9; i++){
            for(int j=0;j<9;j++)
            {
                if(board[i][j]=='.')
                {
                    for(char c='1';c<='9';c++)
                        if(isValid(board,i,j,c))
                        {
                            board[i][j]=c;
                            if(solve(board))
                                return true;
                            else board[i][j]='.';
                        }
                    return false;
                }
            }
            
        }
        return true;
    }
    
    bool isValid(vector<vector<char>>& board, int row, int col, char c)
    {
        for(int i=0;i<9;i++)
        {
            if(board[row][i]==c) return false;
            if(board[i][col]==c) return false;
            if(board[(row/3)*3+i/3][(col/3)*3+i%3]==c) return false;
        }
        return true;
    }
};

//vector<vector<int>> rows_, cols_, boxes_;
//
//bool fill(vector<vector<char>>& board, int x, int y) {
//    if (y == 9)
//        return true;
//
//    int nx = (x + 1) % 9;
//    int ny = (nx == 0) ? y + 1 : y;
//
//    if (board[y][x] != '.') return fill(board, nx, ny);
//
//    for (int i = 1; i <= 9; i++) {
//        int bx = x / 3;
//        int by = y / 3;
//        int box_key = by * 3 + bx;
//        if (!rows_[y][i] && !cols_[x][i] && !boxes_[box_key][i]) {
//            rows_[y][i] = 1;
//            cols_[x][i] = 1;
//            boxes_[box_key][i] = 1;
//            board[y][x] = i + '0';
//            if (fill(board, nx, ny)) return true;
//            board[y][x] = '.';
//            boxes_[box_key][i] = 0;
//            cols_[x][i] = 0;
//            rows_[y][i] = 0;
//        }
//    }
//    return false;
//}
//void printVec(vector<vector <char> > v)
//{
//    for(int i=0;i<9;i++)
//    {
//        for(int j=0;j<10;j++)
//            cout<<v[i][j]<<" ";
//        cout<<endl;
//    }
//    cout<<endl;
//
//}
//
//void printVec(vector<vector <int> > v)
//{
//    for(int i=0;i<9;i++)
//    {
//        for(int j=0;j<10;j++)
//            cout<<v[i][j]<<" ";
//        cout<<endl;
//    }
//    cout<<endl;
//
//}
//
//void solveSudoku(vector<vector<char>>& board) {
//    rows_ = vector<vector<int>>(9, vector<int>(10));
//    cols_ = vector<vector<int>>(9, vector<int>(10));
//    boxes_ = vector<vector<int>>(9, vector<int>(10));
//
//    for(int i = 0; i < 9; i++)
//        for(int j = 0; j < 9; j++) {
//            const char c = board[i][j];
//            if ( c != '.') {
//                int n = c - '0';
//                int bx = j / 3;
//                int by = i / 3;
//                rows_[i][n] = 1;
//                cols_[j][n] = 1;
//                boxes_[by * 3 + bx][n] = 1;
//            }
//        }
//
//    fill(board, 0, 0);
//}
//
//
//int main()
//{
//    vector<vector<char> > board = {
//        {'.', '5', '3', '.', '.', '7', '.', '.', '.', '.'},
//        {'.', '6', '.', '.', '1', '9', '5', '.', '.', '.'},
//        {'.', '.', '9', '8', '.', '.', '.', '.', '6', '.'},
//        {'.', '8', '.', '.', '.', '6', '.', '.', '.', '3'},
//        {'.', '4', '.', '.', '8', '.', '3', '.', '.', '1'},
//        {'.', '7', '.', '.', '.', '2', '.', '.', '.', '6'},
//        {'.', '.', '6', '.', '.', '.', '.', '2', '8', '.'},
//        {'.', '.', '.', '.', '4', '1', '9', '.', '.', '5'},
//        {'.', '.', '.', '.', '.', '8', '.', '.', '7', '9'}
//    };
//    rows_ = vector<vector<int>>(9, vector<int>(10));
//    cols_ = vector<vector<int>>(9, vector<int>(10));
//    boxes_ = vector<vector<int>>(9, vector<int>(10));
//
//    for(int i = 0; i < 9; i++)
//        for(int j = 0; j < 9; j++) {
//            const char c = board[i][j];
//            if ( c != '.') {
//                int n = c - '0';
//                cout<<endl<<n<<endl;
//                int bx = j / 3;
//                int by = i / 3;
//                rows_[i][n] = 1;
//                cols_[j][n] = 1;
//                boxes_[by * 3 + bx][n] = 1;
//                printVec(board);
//                printVec(rows_);
//                printVec(cols_);
//                printVec(boxes_);
//            }
//        }
//
//    fill(board, 0, 0);
//}
//
