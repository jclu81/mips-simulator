#include <iostream>
#include <fstream>
#include <vector>
#include <thread>
#include "Solution.h"
//#include "tester.cpp"

using namespace std;

int main(int argc, char *argv[]) {

    bool DEBUG = 0;
    int clck = 100;
    //Makeing sure the file is supplied
    if (argc < 2) {
        cout << "File not supplied" << endl;
//        return 1;
        argv[1]="/Users/jclu/Documents/assembly.txt";

    }
    if (argc >= 3) {
        clck = stoi(argv[2]);
    }

    if (argc >= 4) {
        DEBUG = true;
    }

    ifstream infile(argv[1]);
    if (!infile) {
        cout << "assembly file cannot be open!!ERROR" << endl;
        return 1;
    }
    string answer;
    getline(infile, answer);
    cout << "answer is : " << answer << endl;
    Solution mips(infile, clck, DEBUG);
    cout << "after init" << endl;
    vector<int> *t_vars = mips.alu();

    cout << "your answer is : " << endl;
    int i = 0;
    for (; i < t_vars->size() - 1; i++) {
        cout << t_vars->at(i) << ",";
    }
    cout << t_vars->at(i) << endl;
    delete t_vars;
}

