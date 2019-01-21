// Craciunoiu Cezar 324CA
#include <iostream>
#include <fstream>
#include "./algo.h"

template <class T>
void sortExec(char* argv[]) {
    std::vector<T> toSort;
    std::ifstream fin;
    fin.open(argv[1], std::ifstream::in);
    int size;
    T x;
    fin >> size;
    for (int i = 0; i < size; ++i) {
        fin >> x;
        toSort.push_back(x);
    }
    
    sort(toSort, false);
    for (auto print : toSort) {
        std::cout << print << " ";
    }
    std::cout << "\n";
    fin.close();
}

int main(int argc, char* argv[]) {
    if (argc != 3)
        return -1;
    std::string inputType = "int";
    if (argv[2] == inputType)
        sortExec<int>(argv);
    else
        sortExec<double>(argv);
    return 0;
}