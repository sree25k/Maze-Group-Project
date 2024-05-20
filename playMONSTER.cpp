#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <sstream>
#include <string>
#include "game_functions.h"

using namespace std;

namespace MONSTER {

// Open Map
    vector<vector<string> > read_maze(const string &filename) {
        vector<vector<string> > grid;
        ifstream file(filename);
        string line;

        if (!file) {
            cout << "Error in file opening!" << endl;
            exit(1);
        }

        while (getline(file, line)) {
            vector<string> row;
            stringstream ss(line);
            string element;

            // Read each quoted element
            while (getline(ss, element, '"')) {
                // Skip empty parts and spaces
                if (!element.empty() && element != " ") {
                    row.push_back(element);
                }
            }
            grid.push_back(row);
        }

        file.close();
        return grid;
    }

// Structure to represent a point in the maze
    struct Point {
        int x;
        int y;
    };

// Size of the maze, 21 by 21
    const int SIZE = 21;
    Point pos;
    int MoveCount = 0;

// Calculate the Manhattan distance between two points
    int calculateDistance(const Point &p1, const Point &p2) {
        return abs(p1.x - p2.x) + abs(p1.y - p2.y);
    }

// Monster class
    class Monster {
    public:
        Point position;

        Monster(int x, int y);

        Monster(const Point &initialPos) : position(initialPos) {}

        // Declare getNextMove function
        Point getNextMove(const Point &pos, Monster monster, vector<vector<string> > &grid);
    };

// Calculate the next move for the monster based on the player's position
    Point Monster::getNextMove(const Point &pos, Monster monster, vector<vector<string> > &grid) {
        bool Valid = false;

        // All possible moves for the monster (it can jump over blocks)
        Point moves[8] = {{monster.position.x - 2, monster.position.y},
                          {monster.position.x + 2, monster.position.y},
                          {monster.position.x,     monster.position.y - 2},
                          {monster.position.x,     monster.position.y + 2},
                          {monster.position.x + 1, monster.position.y + 1},
                          {monster.position.x + 1, monster.position.y - 1},
                          {monster.position.x - 1, monster.position.y + 1},
                          {monster.position.x - 1, monster.position.y - 1}};

        Point nextMove = moves[0];

        // Find moves with shortest distance to player
        for (int i = 0; i < 8; ++i) {
            int distance = calculateDistance(moves[i], pos);
            if (distance < calculateDistance(nextMove, pos)) {
                nextMove = moves[i];
                string monstercellContent = grid[nextMove.x][nextMove.y];
                if (monstercellContent == "   ") {
                    Valid = true;
                    position = nextMove;
                }
            }
        }
        return position;
    }

// Constructor for Monster class
    Monster::Monster(int x, int y) {
        position.x = x;
        position.y = y;
    }

// Player Moves
    void move(char input, Point &pos, vector<vector<string> > &grid) {
        switch (input) {
            case 'w':
                pos.x--;
                break;  // Move up
            case 's':
                pos.x++;
                break;  // Move down
            case 'a':
                pos.y--;
                break;  // Move left
            case 'd':
                pos.y++;
                break;  // Move right
            default:
                return;  // Invalid input
        }

        string cellContent = grid[pos.x][pos.y];

        // Check if it is a block or whitespace
        if (cellContent != "   ") {
            switch (input) {
                case 'w':
                    pos.x++;
                    break;  // Move up
                case 's':
                    pos.x--;
                    break;  // Move down
                case 'a':
                    pos.y++;
                    break;  // Move left
                case 'd':
                    pos.y--;
                    break;  // Move right
                default:
                    return;  // Invalid input
            }
        }

        // Check boundaries
        if (pos.x < 0 || pos.y < 0 || pos.x >= SIZE || pos.y >= SIZE) {
            return; // Out of bounds move
        }
    }

    int playMONSTER() {
        vector<vector<string> > grid = read_maze("map3.txt");
        Point pos;
        pos.x = 0;
        pos.y = 0;

        // Monster location
        Monster monster(0, 10);

        // Print Map
        while (pos.x < SIZE && pos.y < SIZE) {
            vector<vector<string> > copy = grid;
            copy[pos.x][pos.y] = " ♀ ";
            copy[monster.position.x][monster.position.y] = " ☿ ";

            // Print the modified map
            for (const auto &row: copy) {
                for (const auto &cell: row) {
                    cout << cell;
                }
                cout << endl;
            }
            cout << "Move Count:" << MoveCount << endl;
            MoveCount++;

            // Read the player's position - WASD
            char input;
            cout << "What's your input (wasd)? ";
            cin >> input;

            // Press q to exit game
            if (input == 'q') {
                exit(0);
            }

            // Press r to restart game
            if (input == 'r') {
                monster.position.x = 0;
                monster.position.y = 10;
                pos.x = 0;
                pos.y = 0;
                MoveCount = 0;
            }

            // Call function to move player
            move(input, pos, grid);

            // Monster only starts moving when player gets to depth of 10
            Point monsterMove;
            if (pos.x >= 10) {
                monsterMove = monster.getNextMove(pos, monster, grid);
            }

            // If monster catches up to player
            if (pos.x == monster.position.x && pos.y == monster.position.y) {
                cout << "Oh no, you died!";
                exit(0);
            }

            // If player reaches the end – bottom right
            if (pos.x == 20 && pos.y == 20) {
                cout << "Congratulations, you won!";
                exit(0);
            }
        }
        return 0;
    }
}
