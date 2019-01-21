// Craciunoiu Cezar 324CA
#include "./algo.h"

// ShellSort - interschimba elementele pe o distanta mai mare ca restul pentru
// a realiza mai putine interschimbari. Pentru un gap foarte mic(1) acesta
// functioneaza ca un insertion sort.
void sort(std::vector<int>& input, const bool reverse) {
    for (unsigned int gap = input.size()/2; gap > 0; gap /= 2) {
        for (unsigned int i = gap; i < input.size(); ++i) {
            for(unsigned int j = i; j >= gap; j -= gap){
                if(input[j] < input[j - gap]){
                    std::swap(input[j], input[j - gap]);
                }
                else{
                    break;
                }
            }
        } 
    } 
    if (reverse) {
        std::reverse(input.begin(), input.end());
    }
    return;
}

// Adaugata desi nu este implementata, pentru a evita erorile de compilare
void sort(std::vector<double>& input, const bool reverse){
    if (reverse)
        input[0] = 0;
}
