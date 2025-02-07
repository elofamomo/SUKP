#include <bits/stdc++.h>
#include "load.h"
#include "solver.h"

using namespace std;
// change directory here
string instance_direction = "SUKP_instances_60/";
void solve(vector<string> &instance_names) {
    for (auto const &instance_name : instance_names) {
        int m = 0, n = 0, c = 0;
        vector<unordered_set<int>> relation;
        vector<int> profit, weight;
        load::read_input(instance_name, m, n, c, profit, weight, relation);
        vector<int> rank_by_score = solver::ranking_by_score(relation, profit, weight);
        cout << instance_name << " : " << solver::calculate_after_ranking_result(rank_by_score, c, relation, profit, weight) << endl;
    }
}

int main(int argc, char *argv[]) {
    assert(argc >= 2);
    vector<string> instance_names;
    if (argv[1][0] == '1') {
        instance_direction += "Instances of Set I";
        load::load_all_instances(instance_names, instance_direction);
    } else if (argv[1][0] == '2') {
        instance_direction += "Instances of Set II";
        load::load_all_instances(instance_names, instance_direction);
    } else if (argv[1][0] == '3') {
        string instance_direction1 = instance_direction + "Instances of Set I";
        string instance_direction2 = instance_direction + "Instances of Set II";
        load::load_all_instances(instance_names, instance_direction1);
        load::load_all_instances(instance_names, instance_direction2);
    } else {
        assert(argc >= 3);
        int no_name = argc - 2;
        string fname = argv[2];
        load::load_instance(instance_names, fname);
    }
    solve(instance_names);
    return 0;

}
