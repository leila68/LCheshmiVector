#include <iostream>
#include "MyVector.h"



int main() {

//    MyVector v(5);
//    std::cout << v << std::endl;
//    v.push_back(10);
//    std::cout << v << std::endl;
//    v.push_back(20);
//    std::cout << v << std::endl;
//
//    MyVector w{1,2,3,4,5};
//    std::cout << w << std::endl;

  MyVector v;
    for (int i = 0; i < 22; ++i) {
        v.push_back(i);
        std::cout << v ;
    }

//    while (v.Empty() == false){
//        v.pop_back();
//        std::cout<<v;
//    }
 MyVector w;
    w.push_back(7);
    w = v;
    std::cout << w;

    return 0;
}
