#ifndef _RADIX_H_
#define _RADIX_H_

#include <cstring>

#include "record.h"
#include "vector.h"

const std::size_t DIGIT_SIZE = 128;

void CountingSort(TVector<TRecord>& vec, const std::size_t digit) {
    TVector<TRecord> temp(vec);
    std::size_t count[DIGIT_SIZE];
    std::memset(count, 0, DIGIT_SIZE * sizeof(std::size_t));
    for (int i = 0; i < (int) vec.Size(); ++i) {
        count[(unsigned char) vec[i].key[digit]]++;
    }
    for (int i = 1; i < (int) DIGIT_SIZE; ++i) {
        count[i] += count[i-1];
    }
    for (int i = (int) temp.Size() - 1; i >= 0; --i) {
        vec[count[(unsigned char) temp[i].key[digit]] - 1] = temp[i];
        count[(unsigned char) temp[i].key[digit]]--;
    }
}

void RadixSort(TVector<TRecord>& vec) {
    if (vec.Size() <= 1) {
        return;
    }
    for (int digit = FIRST_LEN + MIDDLE_LEN + LAST_LEN - 1; digit >= 0; --digit) {
        CountingSort(vec, digit);
    }
}

#endif