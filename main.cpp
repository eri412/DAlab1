#include <iostream>

#include "record.h"
#include "vector.h"
#include "radix.h"

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    TVector<TRecord> vec;
    TRecord tempRecord;
    while (std::cin >> tempRecord) {
        vec.Push(tempRecord);
    }
    RadixSort(vec);
    for (int i = 0; i < (int) vec.Size(); ++i) {
        std::cout << vec[i] << std::endl;
    }

    return 0;
}