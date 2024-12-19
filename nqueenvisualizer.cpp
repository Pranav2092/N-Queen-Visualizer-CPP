#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <unistd.h>

using namespace std;

class NQueensVisualizer
{
private:
    vector<vector<int>> board;
    int n;
    int total_no_of_solutions = 0;
    int solution_no = 0;
    string state = "Solving";
    int nextSol = -1;

    /**
     * @brief Prints the current state of the board.
     *
     * The 'state' variable determines whether to print the board in the "Solving" or "Solved" format.
     * In the "Solving" format, the board is displayed with queens represented by " ⇯ " and empty squares represented by " ▣ "
     * In the "Solved" format, the board is displayed with queens represented by " ⇯ " and empty squares represented by " ▢ "
     */
    void display()
    {
        vector<string> temp;
        string s;
        if (state == "Solved")
        {
            for (int i = 0; i < n; i++)
            {
                s = "";
                for (int j = 0; j < n; j++)
                {
                    if (board[i][j] == 1)
                    {
                        s += " ⇯    ";
                    }
                    else
                    {
                        s += "▢     ";
                    }
                }
                temp.push_back(s);
            }
        }
        else
        {
            for (int i = 0; i < n; i++)
            {
                s = "";
                for (int j = 0; j < n; j++)
                {
                    if (board[i][j] == 1)
                    {
                        s += " ⇯    ";
                    }
                    else if (board[i][j] < 0)
                    {
                        s += " ▣    ";
                    }
                    else
                    {
                        s += " ▢     ";
                    }
                }
                temp.push_back(s);
            }
        }

        for (int i = 0; i < n; i++)
        {
            cout << temp[i] << endl;
            cout << endl;
        }
    }

    /**
     * Checks if the position (i, j) on the board is safe for placing a queen.
     * A position is considered safe if there are no conflicts with previously
     * placed queens in the same column, row, or diagonals.
     *
     * @param row The row index to check.
     * @param col The column index to check.
     * @return True if the position is safe; otherwise, false.
     */
    bool isSafe(int row, int col)
    {
        return (board[row][col] == 0);
    }

    /**
     * Attempts to solve the N-Queens problem starting from a given row.
     * Uses a backtracking approach to place queens on the board such that
     * no two queens threaten each other.
     *
     * @param row The current row to attempt placing a queen.
     * @return True if a solution is found; otherwise, false.
     */
    bool solve(int row)
    {
        if (row == n)
        {
            sleep(1);
            state = "Solved";
            cout << "\033[2J\033[H";
            cout << "Solution: " << endl
                 << endl;
            display();
            solution_no++;
            nextSol = -1;
            return true;
        }
        for (int j = 0; j < n; j++)
        {
            if (isSafe(row, j))
            {
                board[row][j] = 1;
                for (int k = row + 1; k < n; k++)
                {
                    board[k][j] += -1;
                }
                for (int i = 0; i < n; i++)
                {
                    if (board[row][i] == 1)
                    {
                        continue;
                    }
                    board[row][i] += -1;
                }
                int i = row + 1;
                int k = j + 1;
                while (k < n && i < n)
                {
                    board[i][k] += -1;
                    i++;
                    k++;
                }
                i = row + 1;
                k = j - 1;
                while (i < n && k >= 0)
                {
                    board[i][k] += -1;
                    i++;
                    k--;
                }
                state = "Solving";
                sleep(1);
                cout << "\033[2J\033[H";
                cout << "Solving..." << endl
                     << endl;
                display();
                if (solve(row + 1))
                {
                    if (solution_no < total_no_of_solutions)
                    {
                        if (nextSol == -1)
                        {
                            cout << "Press 1 to get next solution or 0 to stop: ";
                            cin >> nextSol;
                        }
                        if (nextSol == 0)
                        {
                            return true;
                        }
                    }
                    else
                    {
                        return true;
                    }
                }
                for (int k = row + 1; k < n; k++)
                {
                    board[k][j] += 1;
                }
                for (int i = 0; i < n; i++)
                {
                    if (board[row][i] == 1)
                    {
                        continue;
                    }
                    board[row][i] += 1;
                }
                i = row + 1;
                k = j + 1;
                while (k < n && i < n)
                {
                    board[i][k] += 1;
                    i++;
                    k++;
                }
                i = row + 1;
                k = j - 1;
                while (i < n && k >= 0)
                {
                    board[i][k] += 1;
                    i++;
                    k--;
                }
                board[row][j] = 0;
                state = "Solving";
                sleep(1);
                cout << "\033[2J\033[H";
                cout << "Solving..." << endl
                     << endl;
                display();
            }
        }
        return false;
    }

    /**
     * @brief Recursively counts the number of solutions of the N-Queens problem.
     * @param row The current row to attempt placing a queen.
     * @return True if a solution is found; otherwise, false.
     */
    void countSolutions(int row)
    {
        if (row == n)
        {
            total_no_of_solutions++;
            return;
        }
        for (int j = 0; j < n; j++)
        {
            if (isSafe(row, j))
            {
                board[row][j] = 1;

                for (int k = row + 1; k < n; k++)
                {
                    board[k][j] += -1;
                }

                for (int i = 0; i < n; i++)
                {
                    if (board[row][i] == 1)
                    {
                        continue;
                    }
                    board[row][i] += -1;
                }

                int i = row + 1;
                int k = j + 1;

                while (k < n && i < n)
                {
                    board[i][k] += -1;
                    i++;
                    k++;
                }

                i = row + 1;
                k = j - 1;

                while (i < n && k >= 0)
                {
                    board[i][k] += -1;
                    i++;
                    k--;
                }

                countSolutions(row + 1);

                for (int k = row + 1; k < n; k++)
                {
                    board[k][j] += 1;
                }

                for (int i = 0; i < n; i++)
                {
                    if (board[row][i] == 1)
                    {
                        continue;
                    }
                    board[row][i] += 1;
                }

                i = row + 1;
                k = j + 1;

                while (k < n && i < n)
                {
                    board[i][k] += 1;
                    i++;
                    k++;
                }

                i = row + 1;
                k = j - 1;

                while (i < n && k >= 0)
                {
                    board[i][k] += 1;
                    i++;
                    k--;
                }

                board[row][j] = 0;
            }
        }
        return;
    }

public:
    /**
     * @brief Solves the NQueens problem with backtracking and prints the solution
     * @param n the size of the board
     *
     * This function reads the number of queens from the user, initializes an instance of the NQueensVisualizer
     * class, and calls the solveNQueens method to find and display the solution to the N-Queens problem.
     */
    void solveNQueens(int n)
    {
        board.clear();
        board = vector<vector<int>>(n, vector<int>(n, 0));
        this->n = n;
        total_no_of_solutions = 0;
        solution_no = 0;
        state = "Solving";
        nextSol = -1;
        countSolutions(0);
        if (solve(0) == false)
        {
            cout << "No solution exists" << endl;
        }
        else
        {
            cout << "\033[2J\033[H";
            cout << "Solution: " << endl
                 << endl;
            display();
        }
        nextSol = -1;
        state = "Solving";
        total_no_of_solutions = 0;
        solution_no = 0;
        this->n = 0;
        board.clear();
    }
};

/**
 * @brief Main function that prompts the user for the number of queens and solves the N-Queens problem.
 *
 * This function reads the number of queens from the user, initializes an instance of the NQueensVisualizer
 * class, and calls the solveNQueens method to find and display the solution to the N-Queens problem.
 */

int main()
{
    int n;
    cout << "Enter the number of queens: ";
    cin >> n;
    NQueensVisualizer nqv;
    nqv.solveNQueens(n);
    return 0;
}
