#include <iostream>
#include <typeinfo>

class Date {

};

Date D;
int a[10];

Date arr[10];

Date* ptrDate;

int* iptr;

int main()
{
    std::cout << "typeid(typeid(int)):" << typeid(typeid(int)).name() << std::endl;
    std::cout << "typeid(int):" << typeid(int).name() << std::endl;
    std::cout << "typeid(D):" << typeid(D).name() << std::endl;
    std::cout << "typeid(arr):" << typeid(arr).name() << std::endl;
    std::cout << "typeid(ptrDate):" << typeid(ptrDate).name() << std::endl;
    std::cout << "type(iPtr):" << typeid(iptr).name() << std::endl;

    int a = 10, b = 20;
    std::cout << "type(a+b):" << typeid(a+b).name() << std::endl;

    return 0;
}