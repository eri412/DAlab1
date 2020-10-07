#ifndef _VECTOR_H_
#define _VECTOR_H_

#include <cstring>

template <typename T>
class TVector {
public:
    TVector() {
        size = 0;
        capacity = DEFAULT_CAPACITY;
        buff = new T[DEFAULT_CAPACITY];
    }
    TVector(const TVector& other) {
        size = other.size;
        capacity = other.capacity;
        buff = new T[capacity];
        std::memcpy((void *) buff, (void *) other.buff, size * sizeof(T));
    }
    ~TVector() {
        delete[] buff;
    }
    T& operator[](std::size_t index) const {
        return buff[index];
    }
    void Push(T value) {
        if (size == capacity) {
            Grow();
        }
        buff[size++] = value;
    }
    std::size_t Size() const {
        return size;
    }   
    T* Begin() const {
        return buff;
    }
    T* End() const {
        return buff + size;
    }
private:
    void Grow() {
        capacity *= CAPACITY_MULTIPLIER;
        T *temp = buff;
        buff = new T[capacity];
        std::memcpy((void *) buff, (void *) temp, size * sizeof(T));
        delete[] temp;
    }
private:
    std::size_t size;
    std::size_t capacity;
    T *buff;
    static const size_t DEFAULT_CAPACITY = 8;
    static const size_t CAPACITY_MULTIPLIER = 2;
};

#endif