#include <iostream>

class Test
{
    private:
        int num1, num2;
        double d_num;
        static int s_num;
    public:
        Test()
        {
            num1 = 100;
            num2 =200;
            d_num =3.1415;

        }

       void show()
        {
            std::cout<< "num:"<<num1<<", num2:" << num2 <<std::endl
                    <<"d_num:" << d_num <<std::endl
                    <<"s_num:"<<s_num <<std::endl;


        }

        static void test_function(float x, float y)
        {
            std::cout  <<"s_num:" << s_num << std::endl
                        <<"x:" << x << std::endl
                        <<"y:" << y << std::endl;

        //std::cout<< "num:"<<num1<<", num2:" << num2 <<std::endl
           //         <<"d_num:" << d_num <<std::endl //compile time error
               //     <<"s_num:"<<s_num <<std::endl;  // non-static data cannot be accessed in static functions

        }
};

int Test::s_num = 100;

int main(void)
{
    Test t;

    t.show();
    //static functions can be invoked using object name qualification
    t.test_function(1.1f,2.2f);
    //static functions can be invoked using class name qualification
    Test::test_function(3.3f, 4.4f);

    return (0);
}

// comments:
// If you want to define  function which is functionally related to 
// a class but does not require an object of class for its definition
// should be defined in the class and made static 

// In our terminology: static member fuctions do not require context
// of calling object for their definitions

// As static member functions do not require a calling object's context,
// they can be invoked using only the class name qualification

// C++ syntax allows object name qualification as well but with a crucial 
// difference vis-a-vis non-static member function
// An address of object used for the qualification is Not Passed as a
// first actual parameter to the static member functions

// Therefore, as a consequence we have a rule that static -member functions
// cannot access non-static data members of class (because non-static data 
// members of class are qualified by the 'this' pointer which is absent here)