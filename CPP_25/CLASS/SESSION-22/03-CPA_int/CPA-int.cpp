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

        CPA_int operator+(const CPA_int& n2)const
        {
                return (this->n + n2.n);
        }
        CPA_int operator-(const CPA_int& n2)const
        {
                return (this->n - n2.n);
        }
        CPA_int operator*(const CPA_int& n2)const
        {
                return (n * n2.n);
        }

        CPA_int operator/(const CPA_int& n2)const
        {
                return (this->n / n2.n);
        }

        CPA_int operator%(const CPA_int& n2)const
        {
            return (n %n2.n);
        }

        bool operator<(const CPA_int& n2)const
        {
            return (n<n2.n);
        }

        bool operator>(const CPA_int& n2)const
        {
            return (n>n2.n);
        }

        bool operator<=(const CPA_int& n2)const
        {
            return (n<n2.n);
        }

        bool operator>=(const CPA_int& n2)const
        {
            return (n<n2.n);
        }

        bool operator==(const CPA_int& n2)const
        {
            return (n<n2.n);
        }

        CPA_int operator&&(const CPA_int& n2)const
        {
            return (n &&n2.n);
        }


        CPA_int operator||(const CPA_int& n2)const
        {
            return (n ||n2.n);
        }

        CPA_int operator&(const CPA_int& n2)const
        {
            return (n & n2.n);
        }

         CPA_int operator^(const CPA_int& n2)const
        {
            return (n ^n2.n);
        }
        
         CPA_int operator<<(const CPA_int& n2)const
        {
            return (n <<n2.n);
        }
         CPA_int operator>>(const CPA_int& n2)const
        {
            return (n >>n2.n);
        }

        CPA_int operator!()const
        {
            return CPA_int(!n);
        }
        CPA_int operator~()const
        {
            return CPA_int(~n);
        }
        

};

int main(void)
{
    CPA_int n1(25);
    CPA_int n2(7);

    n1.show("n1:");
    n2.show("n2:");

    CPA_int result;

    result = n1 + n2;
    result.show("Addition of n1 and n2: ");

    result = n1 - n2;
     result.show("Substraction of n1 and n2: ");

    result = n1 * n2;
     result.show("Multiplication of n1 and n2: ");

    result = n1 / n2;
    result.show("n1/n2:");

    //modulaar

    result =  n1 % n2;
    result.show("n1 %n 2:");

    bool comparisonResult;
    //less than
    comparisonResult = n1 < n2;
    std::cout<< "n1 < n2:"<<comparisonResult << std::endl;

    comparisonResult = n1 > n2;
    std::cout<< "n1 < n2:"<<comparisonResult << std::endl;

    comparisonResult = n1 <= n2;
    std::cout<< "n1 < n2:"<<comparisonResult << std::endl;

    comparisonResult = n1 >= n2;
    std::cout<< "n1 < n2:"<<comparisonResult << std::endl;
    comparisonResult = n1 == n2;
    std::cout<< "n1 < n2:"<<comparisonResult << std::endl;

    //Logical operators
    result = n1 && n2;
    result.show("n1&& n2: "); 

    result = n1 || n2;
    result.show("n1 || n2: "); 

    result = !n1;
    result.show("n1!  n2: "); 

        //BITWISE OPERATOR
    result = n1 & n2;
    result.show("n1& n2: "); 

    result = n1 ^ n2;
   result.show("n1 ^ n2");
    result = ~n1;
   result.show("~n1");

   //shift arithmatic left
    result = n1 << n2;
   result.show("n1 << n2");

    result = n1 >> n2;
   result.show("n1 >>  n2");



    

    return (0);


}