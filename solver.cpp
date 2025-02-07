#include "solver.h"
#include <string>
#include <iostream>
#include "vector"
#include "unordered_set"
using namespace std;

vector<int> solver::ranking_by_score(vector<unordered_set<int>> &relation, vector<int> &profit, vector<int> &weight) {
    int m = profit.size();
    int n = weight.size();
    vector<int> res;
    unordered_set<int> unselected_items;
    unordered_set<int> selected_elements;
    for (int i = 0; i < m; i++) {
        unselected_items.insert(i);
    }
    cout << "check1 " << endl;
    while (!unselected_items.empty()) {
        pair<int, double> next = {m + 1, 0};
        for (int const &item : unselected_items) {
            int sum = 0;
            for (int const &w : relation[item]) {
//                cout << "weight " << weight[w] << endl;
                if (!selected_elements.count(w)) sum += weight[w];
            }
            double current = (double)profit[item] / sum;
            if (current > next.second) {
                next.second = current;
                next.first = item;
            }
        }
        unselected_items.erase(next.first);
        for (auto const &i : relation[next.first]) selected_elements.insert(i);
        res.push_back(next.first);
    }
    return res;
}

int solver::calculate_after_ranking_result(vector<int> &rank_by_score, int &c, vector<unordered_set<int>> const &relation, vector<int> const &profit, vector<int> const &weight) {
    int res = 0;
    int i = 0;
    int wsum = 0;
    unordered_set<int> selected_elements;
    cout << "check2 " << endl;
    while (wsum <= c) {
        for (auto const &j : relation[rank_by_score[i]]) {
            if (!selected_elements.count(j)) {
                selected_elements.insert(j);
                wsum += weight[j];
            }
        }
        if (wsum <= c) res += profit[rank_by_score[i]];
        i++;
    }
    return res;
}



