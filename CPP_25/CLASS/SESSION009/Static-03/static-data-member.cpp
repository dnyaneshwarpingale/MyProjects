
#include <iostream>

class Test
{
    private:
        int num,num2;
        double d_num;
        static int s_num;
    public:
        Test()
        {
            num =100;
            d_num = 3.1415;

        }

        void show()
        {
            std::cout<< "num:"<<num<<std::endl
                    <<"d_num:" << d_num <<std::endl
                    <<"s_num:"<<s_num <<std::endl;


        }
};

int Test::s_num = 10; // This is where memory gets allocated.
                      // This syntax is mandatory in C++ 98.
                      // From C++ 11 onwards, this is not necessar

int main(void)
{
    Test t;
    t.show();

    std::cout<<"Sizeof(Test):" <<sizeof(Test)<<std::endl;

    return (0);
}

//Commens:
// Applying static qualifier to data definition statement inside class has
// the following effects
// 1) Time of allocation: static
// 2) section of allocation: Data /BSS
// 3) Frequency of allocation:Once
// 4) Visibility : Static and non-statoc member functions of class.
//    [we are not considering derived classes, friend functions and friend class as of now]
// 5) Lifetime == Lifetime of program

// for non-static data member
// 1) Time of allocation == time of allocation of object
// 2) section of allocation == section of allocation of object
// 3) frequency of allocation == per object
// 4) visibility == non-static member function of class.
//          [static member functions cannot access non-static data members]
//  [we are not considering derived classes, friend functions and friend class as of now]
// 5) Lifetime == Lifetime of object