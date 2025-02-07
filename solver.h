
#ifndef SUKP_SOLVER_H
#define SUKP_SOLVER_H


#include <string>
#include "vector"
#include "unordered_set"

using namespace std;

class solver {
public:
    static vector<int> ranking_by_score(vector<unordered_set<int>> &relation, vector<int> &profit, vector<int> &weight);

    static int calculate_after_ranking_result(vector<int> &rank_by_score, int &c, vector<unordered_set<int>> const &relation, vector<int> const &profit, vector<int> const &weight);

};
#endif //SUKP_SOLVER_H
