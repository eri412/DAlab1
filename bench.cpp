#include <iostream>
#include <ctime>
#include <algorithm>

#include "record.h"
#include "vector.h"
#include "radix.h"

void RadixDecorator(TVector<TRecord>& vec) {
    std::clock_t start = std::clock();
    RadixSort(vec);
    std::clock_t end = std::clock();
    std::cout << "Radix time: " << ((double) (end - start))/CLOCKS_PER_SEC << std::endl;
}

void StableDecorator(TVector<TRecord>& vec) {
    std::clock_t start = std::clock();
    std::stable_sort(vec.Begin(), vec.End());
    std::clock_t end = std::clock();
    std::cout << "Stable time: "<< ((double) (end - start))/CLOCKS_PER_SEC << std::endl;
}

int main() {
    TVector<TRecord> vecRadix;
    TRecord tempRecord;
    while (std::cin >> tempRecord) {
        vecRadix.Push(tempRecord);
    }
    TVector<TRecord> vecStable(vecRadix);
    RadixDecorator(vecRadix);
    StableDecorator(vecStable);

    return 0;
}