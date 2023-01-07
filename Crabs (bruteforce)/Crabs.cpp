#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <map>
#include <climits>

using Map = std::map<int, std::vector<int>>;

struct BoardContainter
{
    std::vector<std::vector<int>> &board;
    std::vector<std::vector<int>> &originalBoard;
};

bool isEmpty(std::vector<int> &result, int k)
{
    for (int i = 0; i < k; i++)
    {
        if (result[i] == result[k] || abs(result[i] - result[k]) == k - i)
        {
            return false;
        }
    }
    return true;
}

int nHetmans(std::vector<int> &result, int k, int n, std::set<std::vector<int>> &solutions,
             std::vector<std::vector<int>> &board)
{
    if (k == n)
    {
        if (solutions.find(result) == solutions.end())
        {
            solutions.insert(result);
        }
        return 0;
    }

    int minScore = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        result[k] = i;
        if (isEmpty(result, k))
        {
            int score = nHetmans(result, k + 1, n, solutions, board);
            minScore = std::min(minScore, score);
        }
    }

    return minScore;
}

void printBoard(std::vector<std::vector<int>> &board, const std::vector<int> &result, Map &map)
{

    int mini = INT_MAX;
    int indexMin = 0;
    int sum = 0;
    std::vector<int> indexes;

    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[i].size(); j++)
        {
            if (mini > board[i][result[i]])
            {
                mini = board[i][result[i]];
                indexMin = result[i];
            }
            board[i][result[i]] = 1000;
        }
        indexes.push_back(indexMin);
        sum += mini;
        mini = INT_MAX;
    }
    map[sum] = indexes;
    indexes.clear();
}

void clearBoard(BoardContainter &bc)
{
    for (int i = 0; i < bc.board.size(); i++)
    {
        for (int j = 0; j < bc.board[i].size(); j++)
        {
            bc.board[i][j] = bc.originalBoard[i][j];
        }
    }
}

void printBoard(BoardContainter &bc,
                std::set<std::vector<int>> &solutions, Map &map)
{
    int i = 1;
    for (const auto &result : solutions)
    {
        printBoard(bc.board, result, map);
        clearBoard(bc);
        i++;
    }
}

void fillBoard(std::vector<std::vector<int>> &board)
{
    for (auto &line : board)
    {
        for (auto &value : line)
        {
            std::cin >> value;
        }
    }
}

void copyBoard(BoardContainter &bc)
{
    bc.originalBoard.assign(bc.board.begin(), bc.board.end());
}

void printMinVector(Map &map)
{
    auto vec = std::min_element(map.begin(), map.end(), [](const auto &a, const auto &b)
                                { return a < b; })
                   ->second;
    for (const int &elem : vec)
    {
        std::cout << elem << " ";
    }
}

int main()
{
    int n;
    std::cin >> n;

    if (n < 4)
    {
        std::cout << "Impossible to create\n";
        return 0;
    }

    std::vector<int> result(n);
    std::vector<std::vector<int>> board(n, std::vector<int>(n));
    std::vector<std::vector<int>> originalBoard(n, std::vector<int>(n));
    Map map;
    BoardContainter bc = {board, originalBoard};
    fillBoard(board);
    copyBoard(bc);

    std::set<std::vector<int>> solutions;

    nHetmans(result, 0, n, solutions, board);

    printBoard(bc, solutions, map);

    printMinVector(map);

    return 0;
}