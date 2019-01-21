#ifndef ALGO_H
#define ALGO_H

#include <vector>
#include <stack>
#include <algorithm> // Reverse
#include <queue>

/**
 * Sorts the elements from the input container in-place.
 *
 * By default, the container is sorted in ascending order, unless the reverse parameter reverse
 * is set to true.
 *
 */
void sort(std::vector<int>& input, const bool reverse);

void sort(std::vector<double>& input, const bool reverse);

#endif