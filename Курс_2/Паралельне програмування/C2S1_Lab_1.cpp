#include "func.h"
//#include <cmath>



//int xnmrt(int number, int root) {
//    return pow(number, 1.0 / root);
//}

//template <typename n, typename r>
//n xnmrt(n number, r root) {
//    return pow(number, 1.0 / root);
//}

template <typename xreturn, typename n, typename r>
xreturn xnmrt(n number, r root) {
    return pow(number, 1.0 / root);
}


template<typename F, typename S>
void decompose_pair(const pair<F, S>& p, F& first_val, S& second_val) {
    first_val = p.first;
    second_val = p.second;
    //[first_val, second_val] = p;
}