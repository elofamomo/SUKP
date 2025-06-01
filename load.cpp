#include <fstream>
#include "load.h"
#include "filesystem"
#include "iostream"
#include "unordered_set"

using namespace std;
namespace fs = std::filesystem;

void load::load_all_instances(vector<string> &instance_names, string &instance_directory) {
    try {
        for (const auto &entry: fs::directory_iterator(instance_directory)) {
            if (fs::is_regular_file(entry)) {
                string name = entry.path().stem().string();
                string extension = entry.path().extension().string();
                if (extension == ".txt") {
                    instance_names.push_back(instance_directory + '/' + name + extension);
                }
            }
        }
    } catch (fs::filesystem_error &e) {
        cerr << e.what() << endl;
    }

}

void load::load_instance(vector<string> &instance_names, std::string &instance_name) {
    vector<string> directories = {"SUKP_instances_60/Instances of Set I", "SUKP_instances_60/Instances of Set II"};
    for (auto const &directory: directories) {
        try {
            for (const auto &entry: fs::directory_iterator(directory)) {
                if (fs::is_regular_file(entry)) {
                    string name = entry.path().stem().string();
                    string extension = entry.path().extension().string();
                    stringstream ss(name);
                    string lname;
                    ss >> lname;
                    ss >> lname;
                    if (extension == ".txt" && lname == instance_name) {
                        instance_names.push_back(directory + '/' + name + extension);
                    }
                }
            }
        } catch (fs::filesystem_error &e) {
            cerr << e.what() << endl;
        }
    }
}

void
load::read_input(const std::string &instance_name, int &m, int &n, int &c, vector<int> &profit, vector<int> &weight,
                 vector<unordered_set<int>> &relation) {
    ifstream ifs(instance_name);
    constexpr size_t buffer_size = 512 * 1024;
    unique_ptr<char[]> buffer(new char[buffer_size]);
    if (!ifs.is_open()) {
        cerr << "Error: Unable to open file " << instance_name << endl;
        return;
    }
    string word;
    // get m, n, c
    while (ifs >> word && (!m || !n || !c)) {
        if (word.substr(0, 2) == "m=") {
            stringstream ss(word.substr(2));
            ss >> m;
            cout << "m=" << m << endl;
        } else if (word.substr(0, 2) == "n=") {
            stringstream ss(word.substr(2));
            ss >> n;
            cout << "n=" << n << endl;
        } else if (word.substr(0, 5) == "size=") {
            stringstream ss(word.substr(5));
            ss >> c;
            cout << "c=" << c << endl;
        }
    }
    relation.assign(m, unordered_set<int>());
    profit.assign(m, 0);
    weight.assign(n, 0);
    // get items
    while (ifs >> word) {
        if (word == "items") break;
    }
    for (int i = 0; i < m; i++) {
        ifs >> word;
        profit[i] = stoi(word);
    }
    //get elements
    while (ifs >> word) {
        if (word == "elements") break;
    }
    for (int i = 0; i < n; i++) {
        ifs >> word;
        weight[i] = stoi(word);
    }
    // get relation matrix
    while (ifs >> word) {
        if (word == "matrix") break;
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            ifs >> word;
            if (word == "1") relation[i].insert(j);
        }
    }

    ifs.close();
}
