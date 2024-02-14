#include <bits/stdc++.h>
#include <iostream>
#include <queue>
#include <set>
#include <vector>

void insert(std::vector<std::set<int>> &friendships, int x, int y) {
    friendships[x].insert(y);
    friendships[y].insert(x);
}

void del(std::vector<std::set<int>> &friendships, int x, int y) {
    friendships[x].erase(y);
    friendships[y].erase(x);
}

int numFriends(std::vector<std::set<int>> &friendships, int x) {
    return friendships[x].size();
}

int friendOfFriends(std::vector<std::set<int>> &friendships, int x) {
    std::set<int> found;
    for (int i : friendships[x]) {
        for (int j : friendships[i]) {
            if (j != x && !friendships[x].contains(j)) {
                found.insert(j);
            }
        }
    }
    return found.size();
}

bool bfs(std::vector<std::set<int>> &friendships, int start, int target,
         std::vector<int> &distances) {
    std::queue<int>   q;
    std::vector<bool> visited(21, false);
    std::vector<int>  prevs(21, -1);

    visited[start]   = true;
    distances[start] = 0;
    q.push(start);

    while (!q.empty()) {
        int top = q.front();
        q.pop();
        for (int i : friendships[top]) {
            if (!visited[i]) {
                visited[i]   = true;
                distances[i] = distances[top] + 1;
                prevs[i]     = top;
                q.push(i);

                if (i == target) {
                    return true;
                }
            }
        }
    }

    return false;
}

int degSep(std::vector<std::set<int>> &friendships, int x, int y) {
    std::vector<int> distances(21, INT_MAX);
    bfs(friendships, x, y, distances);
    return distances[y];
}

int main() {
    std::cin.sync_with_stdio(0);
    std::cin.tie(0);

    std::vector<std::set<int>> friendships = {
        {},
        {6},
        {6},
        {4, 5, 6, 15},
        {3, 5, 6},
        {3, 4, 6},
        {1, 2, 3, 4, 5, 7},
        {6, 8},
        {7, 9},
        {8, 10, 12},
        {9, 11},
        {10, 12},
        {9, 11, 13},
        {12, 14, 15},
        {13},
        {3, 13},
        {17, 18},
        {16, 18},
        {16, 17},
        {},
        {},
    };

    char letter;
    while (true) {
        std::cin >> letter;
        if (letter == 'i') {
            int x, y;
            std::cin >> x >> y;
            insert(friendships, x, y);
        } else if (letter == 'd') {
            int x, y;
            std::cin >> x >> y;
            del(friendships, x, y);
        } else if (letter == 'n') {
            int x;
            std::cin >> x;
            std::cout << numFriends(friendships, x) << '\n';
        } else if (letter == 'f') {
            int x;
            std::cin >> x;
            std::cout << friendOfFriends(friendships, x) << '\n';
        } else if (letter == 's') {
            int x, y;
            std::cin >> x >> y;
            int result = degSep(friendships, x, y);
            if (result == INT_MAX) {
                std::cout << "Not connected\n";
            } else {
                std::cout << result << '\n';
            }
        } else if (letter == 'q') {
            break;
        }
    }

    return 0;
}
