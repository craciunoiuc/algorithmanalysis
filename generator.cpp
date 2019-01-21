// Craciunoiu Cezar 324CA
#include <iostream>
#include <random>
#include <time.h>

// Returneaza un numar cu virgula intre limitele date.
double fRand(double fMin, double fMax) {
    double f = (double)rand() / RAND_MAX;
    return fMin + f * (fMax - fMin);
}

// Genereaza 200000 de numere naturale.
void generateInt() {
    srand(time(NULL));
    int size = 200000;
    std::cout << size << "\n";
    for (int i = 0; i < size; ++i) {
        srand(rand() * i);
        std::cout << rand() << " ";
    }
    std::cout << "\n";
    return;
}

// Genereaza 200000 de numere cu virgula cu 15 zecimale.
void generateDouble() {
     srand(time(NULL));
    int size = 200000;
    std::cout << size << "\n";
    for (int i = 0; i < size; ++i) {
        srand(rand() * i);
        printf("%0.15f ", fRand(0, 10000));
    }
    std::cout << "\n";
    return;
}

int main() {
    std::string x;
    std::cin >> x;
    if (x == "int") {
        generateInt();
    } else {
        generateDouble();
    }
    return 0;
}
