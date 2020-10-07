#include <iostream>

#include "record.h"
#include "vector.h"
#include "radix.h"

int main() {
    TVector<TRecord> vec;
    TRecord temp_record;
    while (std::cin >> temp_record) {
        vec.Push(temp_record);
    }
    RadixSort(vec);
    for (int i = 0; i < (int) vec.Size(); ++i) {
        std::cout << vec[i] << std::endl;
    }

    return 0;
}