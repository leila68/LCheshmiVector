//
// Created by Leila on 5/12/2022.
//

#ifndef LCHESHMIVECTOR_MYVECTOR_H
#define LCHESHMIVECTOR_MYVECTOR_H

#include <iostream>
class MyVector {
    int vsize;
    int vcapacity;
    int *varray;
public:
    MyVector();
    ~MyVector();
    MyVector(const MyVector& rhs); //copy constructor
    MyVector(int elements, int value=0);
    MyVector(const std::initializer_list<int>& list);
    int Size() const;
    int Capacity() const;
    bool Empty() const;
 //   int* Array();

    bool operator == (const MyVector &rhs) const;
    bool operator != (const MyVector &rhs) const;
    friend std::ostream& operator << (std::ostream& ostr, const MyVector& rhs);
    MyVector& operator = (const MyVector &rhs);
    int& operator[](int index);
    int& At(int index);
    int& Front();
    int& Back();
    void Insert(int index, int value);
    void Erase(int index);
    void Clear();

    void push_back(int value);
    void pop_back();
};


#endif //LCHESHMIVECTOR_MYVECTOR_H
