// Craciunoiu Cezar 324CA
#include "./algo.h"

#define PRECISION 100000000

// Radix sort pentru numere intregi pozitive
void sort(std::vector<int>& input, const bool reverse) {
    std::stack<int> stacks[10];
    unsigned short cifraPutere = 0;
    int maxSize = 0;

    // Se calculeaza lungimea maxima a numerelor
    int elementMax = -1;
    for (int element : input) {
        if (elementMax < element)
            elementMax = element;
    }

    while (elementMax != 0) {
        maxSize++;
        elementMax /= 10;
    }

    while (maxSize--) {
        // Se calculeaza cifra ce urmeaza sa fie modificata
        unsigned int cifraCurenta = 1;
        if (cifraPutere != 0) {
            for (int i = 0; i < cifraPutere; ++i) {
                cifraCurenta *= 10;
            }
        }

        // Elementele sunt luate in ordine inversa si puse in stive
        for (auto element = input.rbegin(); element != input.rend(); ++element) {
            stacks[(*element) / cifraCurenta % 10].push(*element);
        }

        // Se scot elementele din stive, in ordine si se pun la loc
        int j = 0;
        for (int i = 0; i < 10; ++i) {
            while(!stacks[i].empty()) {
                input[j] = stacks[i].top();
                stacks[i].pop();
                j++;
            }
        }
        cifraPutere++;
    }

    // Daca se doreste la final se inverseaza vectorul
    if (reverse) {
        std::reverse(input.begin(), input.end());
    }
    return;
}
