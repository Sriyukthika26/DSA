#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

const int N = 4;

struct Node {
    vector<vector<int>> board;
    int x, y; // blank position
    int cost; // g + h
    int level; // g = number of moves from start
    Node* parent;

    bool operator>(const Node& other) const {
        return cost > other.cost;
    }
};

// Goal state
vector<vector<int>> goal = {
    {1, 2, 3, 4},
    {5, 6, 7, 8},
    {9, 10, 11, 12},
    {13, 14, 15, 0}
};

bool isGoal(const vector<vector<int>>& board) {
    return board == goal;
}

// Heuristic: number of misplaced tiles
int misplacedTiles(const vector<vector<int>>& board) {
    int count = 0;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            if (board[i][j] != 0 && board[i][j] != goal[i][j])
                ++count;
    return count;
}

// Check if position is valid
bool isValid(int x, int y) {
    return x >= 0 && x < N && y >= 0 && y < N;
}

string boardToString(const vector<vector<int>>& board) {
    string s;
    for (auto& row : board)
        for (int val : row)
            s += to_string(val) + ",";
    return s;
}

void printPath(Node* node) {
    if (node == nullptr) return;
    printPath(node->parent);
    for (auto& row : node->board) {
        for (int val : row)
            cout << (val ? to_string(val) : " ") << "\t";
        cout << "\n";
    }
    cout << "---------------------\n";
}

void LCSearch(vector<vector<int>> start) {
    int sx, sy;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            if (start[i][j] == 0) {
                sx = i; sy = j;
            }

    auto cmp = [](Node* a, Node* b) { return *a > *b; };
    priority_queue<Node*, vector<Node*>, decltype(cmp)> pq(cmp);
    set<string> visited;

    Node* root = new Node{start, sx, sy, misplacedTiles(start), 0, nullptr};
    pq.push(root);

    // Movement directions: up, down, left, right
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    while (!pq.empty()) {
        Node* curr = pq.top(); pq.pop();
        string key = boardToString(curr->board);
        if (visited.count(key)) continue;
        visited.insert(key);

        if (isGoal(curr->board)) {
            cout << "Puzzle solved in " << curr->level << " moves:\n";
            printPath(curr);
            return;
        }

        for (int dir = 0; dir < 4; ++dir) {
            int nx = curr->x + dx[dir];
            int ny = curr->y + dy[dir];

            if (isValid(nx, ny)) {
                vector<vector<int>> newBoard = curr->board;
                swap(newBoard[curr->x][curr->y], newBoard[nx][ny]);

                int h = misplacedTiles(newBoard);
                Node* child = new Node{newBoard, nx, ny, curr->level + 1 + h, curr->level + 1, curr};
                pq.push(child);
            }
        }
    }

    cout << "No solution found.\n";
}
int main() {
    vector<vector<int>> start = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9,10,11,12},
        {13,15,14, 0}
    };

    LCSearch(start);
    return 0;
}
