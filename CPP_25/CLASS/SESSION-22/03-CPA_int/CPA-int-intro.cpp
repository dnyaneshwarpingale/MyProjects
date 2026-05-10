#include <iostream>
#include<typeinfo>

class CPA_int
{
    private:
        int n;

    public:
        CPA_int(int _n = 0):n(_n)
        {
               
        }

        void show(const char* msg =0)const
        {
            if(msg)
                std::cout<<msg;

            std::cout<< n << std::endl;

        }
};

int main(void)
{
    CPA_int n1(25);
    CPA_int n2(7);

    std::cout<< "type(n1): " <<typeid(n1).name() <<std::endl;
    std::cout<< "type(n2): " <<typeid(n2).name() <<std::endl;

    n1.show("n1:");
    n2.show("n2:");

    

    return (0);


}