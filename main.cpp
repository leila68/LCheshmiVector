#include <iostream>
#include "CCustom_vector.h"



int main() {

//    CCustom_vector<unsigned int> v(5,2);
//    std::cout << v << std::endl;

    CCustom_vector w{1,2};
    std::cout << w << std::endl;

     w.push_back(12);
    w.push_back(12);
    w.push_back(12);
    w.push_back(12);
    w.push_back(14);
    w.push_back(14);
    std::cout << w << std::endl;
//    v.push_back(20);
//    std::cout << v << std::endl;
//


//  CCustom_vector v;
//    for (int i = 0; i < 22; ++i) {
//        v.push_back(i);
//        std::cout << v ;
//    }

//    while (v.empty() == false){
//        v.pop_back();
//        std::cout<<v;
//    }
// CCustom_vector w;
//    w.push_back(7);
//    w = v;
//    std::cout << w;

    return 0;
}
