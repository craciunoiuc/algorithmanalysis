// Craciunoiu Cezar 324CA
#include "./algo.h"

int min (int a, int b) {
    return (a < b)? a : b;
}

// Functia merge a fost implementata cu cozi, deoarece se fac mai mult
// introduceri si scoateri din acestea, nu accesari.
void merge(std::vector<int>& input, int left, int middle, int right) {

    int vector1Length = middle - left + 1; // elementele din stanga mijlocului
    int vector2Length = right - middle; // elementele din dreapta mijocului
    std::queue<int> leftQ;
    std::queue<int> rightQ;

    // Se adauga in cele doua cozi elementele din cele 2 bucati sortate
    for (int i = 0; i < vector1Length; ++i)
        leftQ.push(input[left + i]);
    for (int i = 0; i < vector2Length; ++i)
        rightQ.push(input[middle + 1 + i]);

    // Se face merge la cele doua adaugandu-se in vectorul de input
    int i = left;
    while (!leftQ.empty() && !rightQ.empty()) {
        if (leftQ.front() <= rightQ.front()) {
            input[i] = leftQ.front();
            leftQ.pop();
        } else {
            input[i] = rightQ.front();
            rightQ.pop();
        }
        i++;
    }

    // Se adauga restul elementelor ramase din stanga
    while (!leftQ.empty()) {
        input[i] = leftQ.front();
        leftQ.pop();
        i++;
    }

    // Se adauga restul elementelor din dreapta
    while (!rightQ.empty()) {
        input[i] = rightQ.front();
        rightQ.pop();
        i++;
    }
}

// TimSort
void sort(std::vector<int>& input, const bool reverse) {
    const int RUN = 8;
    // Se sorteaza cu insertion sort blocurile de date
    for (int i = 0; i < (int)input.size(); i += RUN) {

        // Se parcurge un bloc de date, se alege cate un pivot pe rand si apoi
        // se pun toate elementele mai mari in dreapta lui
        int blockSize = min((i+RUN), input.size());
        for (int j = i; j < blockSize; ++j) {
            int pivot = input[j];
            int k = j-1;
            while (k >= i && input[k] > pivot) {
                input[k+1] = input[k];
                k--;
            }
            input[k+1] = pivot;
        }
    }

    // Functie de merge face mai intai merge dintre toate blocurile de 32 de
    // elemente, facand blocuri de 64. Apoi din acestea face blocuri de 128 si
    // tot asa pana cand au s-a facut merge la tot vectorul.
    for (unsigned int runSize = RUN; runSize < input.size(); runSize = 2 * runSize) { 
        
        // Al doilea for itereaza prin fiecare bloc de dimensiune runSize 
        for (unsigned int left = 0; left < input.size(); left += 2 * runSize) {
            int right = min(left + 2 * runSize - 1, input.size() - 1);
            merge(input, left, left + runSize - 1, right);
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
