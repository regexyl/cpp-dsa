#include <vector>

class Solution {
public:
    const int MAX_KEYS = 6;
    const int MAX_KEYS_POSSIBLE = 1 << MAX_KEYS; // different combinations of 000001, 100101 etc. from 000001 to 111111

    bool isStart(char ch) { return ch == '@'; }
    bool isWall(char ch) { return ch == '#'; }
    bool isEmptyCell(char ch) { return ch == '.'; }
    bool isKey(char ch) { return (ch >= 'a' && ch < ('a' + MAX_KEYS)); }
    bool isDoor(char ch) { return (ch >= 'A' && ch < ('A' + MAX_KEYS)); }

    int shortestPathAllKeys(vector<string>& grid) {
        pair<int, int> startCoords;
        int tRows = grid.size();
        int tCols = grid[0].size();
        vector<vector<vector<bool>>> visited(tRows,
                         vector<vector<bool>>(tCols, vector<bool>(MAX_KEYS_POSSIBLE, false)));

        int keyMask = 0;
        for (int i = 0; i < tRows; i++) {
            for (int j = 0; j < tCols; j++) {
                char ch = grid[i][j];
                if (isStart(ch)) {
                    startCoords = {i, j};
                } else if (isKey(ch)) {
                    keyMask |= 1 << (ch - 'a');
                }
            }
        }

        queue<pair<pair<int, int>, int>> q; // {row, col}, currKeyMask (i.e. keys already picked up)
        q.push({{startCoords.first, startCoords.second}, 0});
        visited[startCoords.first][startCoords.second][0] = true;

        vector<pair<int, int>> coordsToExplore = {{0,1}, {1,0}, {-1,0}, {0, -1}};

        int totalMoves = 0;
        while (!q.empty()) {
            int lvlSize = q.size();

            while (lvlSize--) { // ?
                auto coords = q.front();
                q.pop();
                int currRow = coords.first.first;
                int currCol = coords.first.second;
                int currKey = coords.second;

                if (currKey == keyMask) return totalMoves;

                for (auto coordToExplore: coordsToExplore) {
                    int newRow = coordToExplore.first + currRow;
                    int newCol = coordToExplore.second + currCol;

                    if (newRow < 0 || newRow >= tRows || newCol < 0 || newCol >= tCols) {
                        continue;
                    }

                    char ch = grid[newRow][newCol];
                    if (isWall(ch)) continue;

                    if (isStart(ch) || isEmptyCell(ch)) {
                        if (!visited[newRow][newCol][currKey]) {
                            q.push({{newRow, newCol}, currKey});
                            visited[newRow][newCol][currKey] = true;
                        }
                    } else if (isKey(ch)) {
                        int newKey = currKey | 1 << (ch - 'a');
                        if (!visited[newRow][newCol][newKey]) {
                            q.push({{newRow, newCol}, newKey});
                            visited[newRow][newCol][newKey] = true;
                        }
                    } else if (isDoor(ch)) {
                        // Check if we can pass through the door and its not visited yet
                        bool canPassDoor = (currKey >> (ch - 'A')) & 1;
                        if (canPassDoor && !visited[newRow][newCol][currKey]) {
                            q.push({{newRow, newCol}, currKey});
                            visited[newRow][newCol][currKey] = true;
                        }
                    }
                }

            }
            totalMoves++;
        }
        return -1;
    }
};