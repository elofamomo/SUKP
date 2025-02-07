

#ifndef SUKP_LOAD_H
#define SUKP_LOAD_H


#include <string>
#include "vector"
#include "unordered_set"
using namespace std;

class load {
public:
    static void load_all_instances(vector<string> &instance_names, string &instances_direction);
    static void load_instance(vector<string> &instance_names, string &instance_name);
    static void read_input(const string &instance_name, int &m, int &n, int &c, vector<int> &profit, vector<int> &weight,
                    vector<unordered_set<int>> &relation);
};


#endif //SUKP_LOAD_H
