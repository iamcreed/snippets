#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <cstdlib>
#include <ctime>

const int rows = 11;
const int cols = 11;

enum class Cell { WALL, EMPTY, START, GOAL, PATH };

struct Point {
    int x, y;

    Point(int x, int y) : x(x), y(y) {}
};

// Function to check if a point is within the maze boundaries
bool isValid(Point p) {
    return (p.x >= 0 && p.x < rows && p.y >= 0 && p.y < cols);
}

// Function to generate a random maze
void generateMaze(std::vector<std::vector<Cell>>& maze) {
    std::stack<Point> stack;
    Point start(1, 1);
    maze[start.x][start.y] = Cell::EMPTY;
    stack.push(start);

    while (!stack.empty()) {
        Point current = stack.top();
        int x = current.x;
        int y = current.y;
        std::vector<Point> neighbors;

        // Find unvisited neighbors
        for (int dx = -2; dx <= 2; dx += 2) {
            for (int dy = -2; dy <= 2; dy += 2) {
                Point neighbor(x + dx, y + dy);
                if (isValid(neighbor) && maze[neighbor.x][neighbor.y] == Cell::WALL) {
                    neighbors.push_back(neighbor);
                }
            }
        }

        if (!neighbors.empty()) {
            int randomIndex = rand() % neighbors.size();
            Point randomNeighbor = neighbors[randomIndex];
            int nx = randomNeighbor.x;
            int ny = randomNeighbor.y;
            maze[nx][ny] = Cell::EMPTY;

            int mx = x + (nx - x) / 2;
            int my = y + (ny - y) / 2;
            maze[mx][my] = Cell::EMPTY;

            stack.push(randomNeighbor);
        } else {
            stack.pop();
        }
    }
}

// Function to print the maze
void printMaze(const std::vector<std::vector<Cell>>& maze) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            char symbol;
            switch (maze[i][j]) {
                case Cell::WALL:
                    symbol = '#';
                    break;
                case Cell::EMPTY:
                    symbol = ' ';
                    break;
                case Cell::START:
                    symbol = 'S';
                    break;
                case Cell::GOAL:
                    symbol = 'G';
                    break;
                case Cell::PATH:
                    symbol = '.';
                    break;
                default:
                    symbol = '?';
            }
            std::cout << symbol;
        }
        std::cout << '\n';
    }
}

int main() {
    srand(static_cast<unsigned>(time(nullptr));

    std::vector<std::vector<Cell>> maze(rows, std::vector<Cell>(cols, Cell::WALL));

    generateMaze(maze);

    // Set start and goal
    maze[1][1] = Cell::START;
    maze[rows - 2][cols - 2] = Cell::GOAL;

    std::cout << "Randomly generated maze:\n";
    printMaze(maze);

    // Maze solving algorithms can be implemented here (A* search, Dijkstra, BFS, etc.)

    return 0;
}
