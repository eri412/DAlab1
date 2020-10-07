#ifndef _RECORD_H_
#define _RECORD_H_

#include <cstdint>
#include <cstring>
#include <iostream>

const unsigned int FIRST_LEN = 1;
const unsigned int MIDDLE_LEN = 3;
const unsigned int LAST_LEN = 2;

class TRecord {
public:
    bool operator<(const TRecord& other) const {
        if (std::strcmp(key, other.key) == -1) {
            return 1;
        }
        else {
            return 0;
        }
    }
public:
    char key[FIRST_LEN + MIDDLE_LEN + LAST_LEN + 1];
    std::uint64_t value;
};

std::ostream& operator<<(std::ostream& output, const TRecord& record) {
    unsigned char first[FIRST_LEN + 1], middle[MIDDLE_LEN + 1], last[LAST_LEN + 1];
    std::memcpy(first, record.key, FIRST_LEN);
    first[FIRST_LEN] = '\0';
    std::memcpy(middle, record.key + FIRST_LEN, MIDDLE_LEN);
    middle[MIDDLE_LEN] = '\0';
    std::memcpy(last, record.key + FIRST_LEN + MIDDLE_LEN, LAST_LEN);
    last[LAST_LEN] = '\0';
    output << first << ' ' << middle << ' ' << last << '\t' << record.value;
    return output;
}

std::istream& operator>>(std::istream& input, TRecord& record) {
    unsigned char first[FIRST_LEN + 1], middle[MIDDLE_LEN + 1], last[LAST_LEN + 1];
    input >> first >> middle >> last >> record.value;
    std::memcpy(record.key, first, FIRST_LEN);
    std::memcpy(record.key + FIRST_LEN, middle, MIDDLE_LEN);
    std::memcpy(record.key + FIRST_LEN + MIDDLE_LEN, last, LAST_LEN);
    record.key[6] = '\0';
    return input;
}

#endif