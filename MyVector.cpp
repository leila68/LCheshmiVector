//
// Created by Leila on 5/12/2022.
//

#include "MyVector.h"

MyVector::MyVector()
:vsize(0),
vcapacity(5),
varray(new int[vcapacity])
{

}
MyVector::MyVector(const MyVector& rhs)
 :vsize(rhs.vsize),
  vcapacity(rhs.vcapacity+5),
  varray(new int[vcapacity])
{
    for (int i=0; i<rhs.Size(); i++)
    {
        varray[i] = rhs.varray[i]; //deep copy
    }
}
MyVector::MyVector(int elements, int value)
  :vsize(elements),
   vcapacity(elements+5),
   varray(new int[vcapacity])
{
    for (int i=0; i<vsize; i++)
    {
        varray[i] = value;
    }
}
MyVector::MyVector(const std::initializer_list<int>& list)
:vsize(0),
 vcapacity(list.size()+5),
 varray(new int[vcapacity])
{
    for (int i : list) {
          push_back(i);
    }

}
MyVector::~MyVector(){
    delete[] varray;
}
int MyVector::Size() const{
    return vsize;
}
int MyVector::Capacity() const{
    return vcapacity;
}
bool MyVector::Empty() const{
    return vsize == 0;
}
//int* MyVector::Array(){
//    return 0;
//}

bool MyVector::operator == (const MyVector& rhs) const{
    if(Size() != rhs.Size()){
        return false;
    }
    return true;
}
bool MyVector::operator != (const MyVector& rhs) const{
    return !(*this == rhs);
}

std::ostream& operator << (std::ostream& ostr, const MyVector& rhs){
    for (int i = 0; i < rhs.vsize; ++i) {
        ostr << rhs.varray[i] << " ";
    }
    ostr << "||";
    for (int i = rhs.vsize; i < rhs.vcapacity; ++i) {
        ostr << rhs.varray[i] << " ";
    }
    ostr << std::endl;
    return ostr;
}
MyVector& MyVector::operator=(const MyVector &rhs) {

    if (rhs.vsize > vsize){
        delete[] varray;
        vcapacity = rhs.vsize + 5;
        varray = new int[vcapacity];
    }

    for (int i = 0; i < rhs.Size(); ++i) {
        varray[i] = rhs.varray[i];
    }
    vsize = rhs.vsize;
    return *this;
}

int& MyVector::operator[](int index) {
    return varray[index];
}
int& MyVector::At(int index) {
    if (index == 0 || index>=vsize){
        throw std::exception();
    }
    return varray[index];
}
int& MyVector::Front(){
    return varray[0];
}
int& MyVector::Back() {
    return varray[vsize-1];
}
void MyVector::Insert(int index, int value) {
    if (index < 0 || index >= vsize){
        throw std::exception();
    }
    ++vsize;
    if (vsize != vcapacity){
        for (int i = vsize-1; i >= index ; --i) {
            varray[i+1] = varray[i];
        }
        varray[index] = value;
        ++vsize;
    } else{
        vcapacity *=2;
        int *newarray = new int[vcapacity];
        for (int i = 0; i < vsize; ++i) {
            newarray[i] = varray[i] ;
        }
        delete[] varray;
        varray = newarray;
        Insert(index,value);
    }

}
void MyVector::Erase(int index) {
    if (index < 0 || index >= vsize){
        throw std::exception();
    }

    for (int i = index; i < vsize-1 ; ++i) {
        varray[i] = varray[i+1];
    }
    --vsize;
}
void MyVector::Clear() {
    vsize = 0;
}
void MyVector::push_back(int value){

    if (vsize < vcapacity){
        varray[vsize] = value;
        ++vsize;
    }
    //if it is filled
    else{
        vcapacity *= 2;
        int *newarray = new int[vcapacity];
        for (int i = 0; i < vsize; ++i) {
            newarray[i] = varray[i];
        }
        newarray[vsize] = value;
        ++vsize;
        delete[] varray;
        varray = newarray;
    }
}
void MyVector::pop_back() {
    if (vsize == 0){
        throw std::exception();

    }
    --vsize;
}