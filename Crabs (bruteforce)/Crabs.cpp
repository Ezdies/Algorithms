#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <map>


using Map = std::map<int, std::vector<int>>;

struct BoardContainter {
    std::vector<std::vector<int>> &board;
    std::vector<std::vector<int>> &originalBoard;
};

bool isEmpty(std::vector<int> &result, int k) {
    for (int i = 0; i < k; i++) {
        if (result[i] == result[k] || abs(result[i] - result[k]) == k - i) {
            return false;
        }
    }
    return true;
}

void nHetmans(std::vector<int> &result, int k, int n, std::set<std::vector<int>> &solutions,
              std::vector<std::vector<int>> &board) {
    if (k == n) {
        if (solutions.find(result) == solutions.end()) {
            solutions.insert(result);
        }
        return;
    }

    for (int i = 0; i < n; i++) {
        result[k] = i;
        if (isEmpty(result, k)) {
            nHetmans(result, k + 1, n, solutions, board);
        }
    }
}

void printBoard(std::vector<std::vector<int>> &board, const std::vector<int> &result) {

    int mini = INT_MAX;
    int indexMin = 0;
    int sum = 0;

    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++) {
            if (mini > board[i][result[i]]) {
                mini = board[i][result[i]];
                indexMin = result[i];
            }
            board[i][result[i]] = 99;
            std::cout << board[i][j] << "\t";
        }
        std::cout << "Minimalna w tym wierszu: " << mini << " ";
        std::cout << "Minimalny index w tym wierszu: " << indexMin;
        sum += mini;
        mini = INT_MAX;
        std::cout << std::endl;
    }
    std::cout << "Minimalna suma na tej tablicy to: " << sum << std::endl;
}


void clearBoard(BoardContainter &bc) {
    for (int i = 0; i < bc.board.size(); i++) {
        for (int j = 0; j < bc.board[i].size(); j++) {
            bc.board[i][j] = bc.originalBoard[i][j];
        }
    }
}

void printBoard(BoardContainter &bc,
                std::set<std::vector<int>> &solutions) {
    int i = 1;
    for (const auto &result: solutions) {
        std::cout << "Board nr. " << i << ":" << std::endl;
        printBoard(bc.board, result);
        clearBoard(bc);
        std::cout << std::endl;
        i++;
    }
}


void fillBoard(std::vector<std::vector<int>> &board) {
    for (auto &line: board) {
        for (auto &value: line) {
            std::cin >> value;
        }
    }
}

void copyBoard(BoardContainter &bc) {
    bc.originalBoard.assign(bc.board.begin(), bc.board.end());
}

int main() {
    int n;
    std::cin >> n;

    if (n < 4) {
        std::cout << "Impossible to create\n";
        return 0;
    }

    std::vector<int> result(n);
    std::vector<std::vector<int>> board(n, std::vector<int>(n));
    std::vector<std::vector<int>> originalBoard(n, std::vector<int>(n));
    BoardContainter bc = {board, originalBoard};
    fillBoard(board);
    copyBoard(bc);

    std::set<std::vector<int>> solutions;

    nHetmans(result, 0, n, solutions, board);
    printBoard(bc, solutions);

    return 0;
}