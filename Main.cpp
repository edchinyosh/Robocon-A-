#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_map>
#include <climits>

using namespace std;

// Structure to hold package details
struct Package {
    string id;
    int urgency;
    int weight;
    string description;
};

// Node structure for pathfinding
struct Node {
    int x, y, cost, priority;
    bool operator<(const Node& other) const {
        return priority > other.priority;  // For min-heap
    }
};

// Directions for moving in the grid
const vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

// Utility function to check if a cell is valid
bool isValidCell(int x, int y, const vector<vector<char>>& grid) {
    int rows = grid.size(), cols = grid[0].size();
    return x >= 0 && y >= 0 && x < rows && y < cols && grid[x][y] == '.';
}

// A* algorithm to find the shortest path from start to end
vector<pair<int, int>> aStarPathfinding(const vector<vector<char>>& grid, pair<int, int> start, pair<int, int> end) {
    priority_queue<Node> openSet;
    unordered_map<int, unordered_map<int, int>> costSoFar;
    openSet.push({start.first, start.second, 0, 0});
    costSoFar[start.first][start.second] = 0;

    unordered_map<int, unordered_map<int, pair<int, int>>> cameFrom;
    cameFrom[start.first][start.second] = {-1, -1};

    while (!openSet.empty()) {
        Node current = openSet.top();
        openSet.pop();

        if (current.x == end.first && current.y == end.second) break;

        for (const auto& dir : directions) {
            int nx = current.x + dir.first;
            int ny = current.y + dir.second;
            if (isValidCell(nx, ny, grid)) {
                int newCost = costSoFar[current.x][current.y] + 1;
                if (!costSoFar[nx].count(ny) || newCost < costSoFar[nx][ny]) {
                    costSoFar[nx][ny] = newCost;
                    int priority = newCost + abs(end.first - nx) + abs(end.second - ny);
                    openSet.push({nx, ny, newCost, priority});
                    cameFrom[nx][ny] = {current.x, current.y};
                }
            }
        }
    }

    // Reconstruct path
    vector<pair<int, int>> path;
    for (pair<int, int> at = end; at != make_pair(-1, -1); at = cameFrom[at.first][at.second]) {
        path.push_back(at);
    }
    reverse(path.begin(), path.end());
    return path;
}

// Function to sort packages based on urgency and weight
void sortPackages(vector<Package>& packages) {
    sort(packages.begin(), packages.end(), [](const Package& a, const Package& b) {
        if (a.urgency == b.urgency) return a.weight < b.weight;
        return a.urgency < b.urgency;
    });
}

// Function to display packages
void displayPackages(const vector<Package>& packages) {
    cout << "Sorted Packages:\n";
    for (const auto& pkg : packages) {
        cout << "ID: " << pkg.id << ", Urgency: " << pkg.urgency << ", Weight: " << pkg.weight << ", Description: " << pkg.description << '\n';
    }
}

// Function to input packages from the user
void inputPackages(vector<Package>& packages, int packageCount) {
    for (int i = 0; i < packageCount; ++i) {
        Package pkg;
        cout << "Enter details for package " << i + 1 << ":\n";
        cout << "ID: ";
        cin >> pkg.id;
        cout << "Urgency (1-5): ";
        cin >> pkg.urgency;
        cout << "Weight (1-10): ";
        cin >> pkg.weight;
        cout << "Description: ";
        cin.ignore();
        getline(cin, pkg.description);
        packages.push_back(pkg);
    }
}

// Predefined grid map
vector<vector<char>> initializeGrid() {
    return {
        {'.', '.', '.', 'X', '.', '.', '.', '.', '.', '.'},
        {'.', 'X', '.', 'X', '.', 'X', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', 'X', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'X', 'X', '.', 'X', '.', 'X', '.', 'X', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'X', 'X', 'X', 'X', 'X', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', 'X', 'X', 'X', 'X', 'X'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'}
    };
}

// Main driver function
int main() {
    int packageCount;
    cout << "Enter the number of packages: ";
    cin >> packageCount;

    vector<Package> packages;
    inputPackages(packages, packageCount);

    vector<vector<char>> grid = initializeGrid();

    cout << "\nInitial Package List:\n";
    displayPackages(packages);

    // Sorting packages by urgency and weight
    sortPackages(packages);
    cout << "\nAfter Sorting:\n";
    displayPackages(packages);

    // Finding path from start to end
    pair<int, int> start, end;
    cout << "Enter start coordinates (row and column): ";
    cin >> start.first >> start.second;
    cout << "Enter end coordinates (row and column): ";
    cin >> end.first >> end.second;
    vector<pair<int, int>> path = aStarPathfinding(grid, start, end);

    cout << "\nPath from Start to End:\n";
    for (const auto& p : path) {
        cout << "(" << p.first << ", " << p.second << ") ";
    }
    cout << '\n';

    return 0;
}
