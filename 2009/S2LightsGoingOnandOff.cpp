#include <bits/stdc++.h>
#include <iostream>
#include <set>

int combinations(std::vector<std::vector<int>> lights) {
    std::set<std::vector<int>> combs;
    combs.insert(lights.back());

    std::vector<std::vector<int>> copy = lights;
    for (int start = 1; start < copy.size(); start++) {
        for (int i = start; i < copy.size(); i++) {
            for (int j = 0; j < copy[i].size(); j++) {
                copy[i][j] ^= copy[i - 1][j];
            }
        }
        combs.insert(copy.back());
        copy = lights;
    }

    return combs.size();
}

int main() {
    std::cin.sync_with_stdio(0);
    std::cin.tie(0);

    int r, l;
    std::cin >> r;
    std::cin >> l;

    std::vector<std::vector<int>> lights(r, std::vector<int>(l));
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < l; j++) {
            std::cin >> lights[i][j];
        }
    }

    std::cout << combinations(lights) << '\n';

    return 0;
}
