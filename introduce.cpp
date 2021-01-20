#include <iostream>
#include <type_traits>

template<typename T, typename std::enable_if<!std::is_integral<T>::value, int>::type = 1> // SFINE tempalte params
bool cmp(T a){
    // call 
    // cmp(1.0)

    // there can not be void typename, and set default value to act as a helper

    std::cout << "typename SFINE value" << std::endl;
    return true;
}

template<typename T>
typename std::enable_if<std::is_integral<T>::value, int>::type cmp(T a){  // SPINE return
    //call
    //cmp(int)

    std::cout << "typename return value" << std::endl;
    return a;
}

template<typename T>
void cmp(T a, typename std::enable_if<std::is_integral<T>::value, T>::type){  // SFINE func params

    // call
    // cmp(int, int) 

    std::cout << "typename func params" << std::endl;
}

bool cmp(float a, float b){         // solo func

    //call
    //cmp(float, float)
    return ::abs(a-b) < 1e-5;
}

int main(){

    cmp(1);
    cmp(2,2);
    cmp(1.0);
    cmp(1,1);
    cmp(1., 1.);


    return 0;
}