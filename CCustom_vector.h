//
// Created by Leila on 5/12/2022.
//

#ifndef LCHESHMIVECTOR_CCustom_vector_H
#define LCHESHMIVECTOR_CCustom_vector_H

#include <iostream>
#include <algorithm>
#include <stdint.h>
#include <cstring>

#define DOUBLE_SIZE 2

template<typename T>
class CCustom_vector {

private:
    int16_t size_;
    int16_t capacity_;
    T *array_;

public:
    CCustom_vector()
            : size_(0),
              capacity_(5),
              array_(new T[capacity_]) {
    }

    explicit CCustom_vector(const CCustom_vector &rhs)
            : size_{rhs.size_},
              capacity_{rhs.capacity_},
              array_(new T[capacity_]) {
        std::copy(rhs.begin(), rhs.end(), array_);
    }
    CCustom_vector<T> &operator=(const CCustom_vector<T> &rhs) {
        if (rhs.size_ > size_) {
            delete[] array_;
            capacity_ = rhs.capacity_;
            size_ = rhs.size_;
            array_ = new T[capacity_];
        }
        std::copy(rhs.begin(), rhs.end(), array_);
        return *this;
    }
   explicit CCustom_vector(int elements, T value)
            : size_(elements),
              capacity_(elements + 5),
              array_(new T[capacity_]{0}) {
    std::fill(array_, array_ + size_, value);
    }

   explicit CCustom_vector(const std::initializer_list<T> &list)
            : size_(0),
              capacity_(list.size() + 5),
              array_(new T[capacity_]) {
        for (int i: list) {
            push_back(i);
        }
    }

    ~CCustom_vector() {
        delete[] array_;
    }
    int size() const {
        return size_;
    }
    int capacity() const {
        return capacity_;
    }
   const T* begin() const {
        return array_;
}
    const T* end() const{
    return array_ + size_;
    }

    T* begin()  {
        return array_;
    }
    T* end() {
        return array_ +size_;
    }
    bool empty() const {
        return size_ == 0;
    }
    bool operator==(const CCustom_vector &rhs) const {
        if (size() != rhs.size()) {
            return false;
        }
        return true;
    }
    bool operator!=(const CCustom_vector &rhs) const {
        return (!(*this == rhs));
    }
    T &operator[](int index) {
        return array_[index];
    }
    friend std::ostream& operator<<(std::ostream &ostr, const CCustom_vector &rhs)  {
        for (const auto &ref_i: rhs) {
            ostr << ref_i << " ";
        }
        ostr << "||";

        for (int i = rhs.size_; i < rhs.capacity_; ++i) {
            ostr << rhs.array_[i] << " ";
        }
        ostr << std::endl;
        return ostr;
    }
    T &at(size_t index) {
        if (index >= size_) {
            throw std::out_of_range("out of ranger");
        }
        return array_[index];
    }
    T &front() {
        return array_[0];
    }
    T &back() {
        return array_[size_ - 1];
    }
    void insert(int index, T value) {
        if (index < 0 || index >= size_) {
            throw std::exception();
        }
        ++size_;
        if (size_ != capacity_) {
            for (int i = size_ - 1; i >= index; --i) {
                array_[i + 1] = array_[i];
            }
            array_[index] = value;
            ++size_;
        } else {
            capacity_ *= DOUBLE_SIZE;// hard code
            T *newarray = new T[capacity_];
            for (int index = 0; index < size_; ++index) {
                newarray[index] = array_[index];
            }
            delete[] array_;
            array_ = newarray;
            insert(index, value);
        }

    }
    void erase(int index) {
        if (index < 0 || index >= size_) {
            throw std::exception();
        }

        for (int i = index; i < size_ - 1; ++i) {
            array_[i] = array_[i + 1];
        }
        --size_;
    }
    void clear() {
        size_ = 0;
    }
    void push_back(T value) {
        if (size_ < capacity_) {
            array_[size_] = value;
            ++size_;
        }
            //if it is filled
        else {
            capacity_ *= DOUBLE_SIZE;
            T *newarray = new T[capacity_];
//            for (int i = 0; i < size_; ++i) {
//                newarray[i] = array_[i];
//            }
            std::copy(this->begin(), this->end(), newarray);

            newarray[size_] = value;
            ++size_;
            delete[] array_;
            array_ = newarray;
        }
    }
    void pop_back() {
        if (size_ == 0) {
            throw std::exception();
        }
        --size_;
    }
};

//using ccustom_vector_t = CCustom_vector;

#endif //LCHESHMIVECTOR_CCustom_vector_H
