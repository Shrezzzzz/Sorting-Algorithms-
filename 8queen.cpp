#include <iostream>
#include <vector>
using namespace std;

// Function to print the board
void printSolution(const vector<vector<int> >& board) {
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++) {
            cout << (board[i][j] ? "Q " : ". ");
        }
        cout << endl;
    }
    cout << endl;
}

// Check if placing a queen at board[row][col] is safe
bool isSafe(const vector<vector<int> >& board, int row, int col) {
    // Check this column on the upper side
    for (int i = 0; i < row; i++) {
        if (board[i][col]) return false;
    }

    // Check the upper left diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j]) return false;
    }

    // Check the upper right diagonal
    for (int i = row, j = col; i >= 0 && j < board.size(); i--, j++) {
        if (board[i][j]) return false;
    }

    return true;
}

// Recursive utility function to solve the N-Queens problem
bool solveNQueensUtil(vector<vector<int> >& board, int row, int& solutionCount) {
    if (row == board.size()) {
        // If all queens are placed, print the solution and increment the solution count
        solutionCount++;
        printSolution(board);
        return true;
    }

    bool res = false;
    for (int col = 0; col < board.size(); col++) {
        if (isSafe(board, row, col)) {
            // Place the queen
            board[row][col] = 1;

            // Recur to place the next queen
            res = solveNQueensUtil(board, row + 1, solutionCount) || res;

            // Backtrack: remove the queen
            board[row][col] = 0;
        }
    }

    return res;
}

// Function to solve the N-Queens problem
void solveNQueens(int N) {
    vector<vector<int> > board(N, vector<int>(N, 0));
    int solutionCount = 0;

    if (!solveNQueensUtil(board, 0, solutionCount)) {
        cout << "No solutions exist.\n";
        return;
    }

    // Output the number of solutions
    cout << "Total number of solutions: " << solutionCount << "\n";
}

int main() {
    int N;
    cout << "Enter the size of the chessboard (N x N): ";
    cin >> N;
    
    cout << "Solving the " << N << " Queens problem...\n";
    solveNQueens(N);
    
    return 0;
}


