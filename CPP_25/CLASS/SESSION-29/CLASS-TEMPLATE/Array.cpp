#include "Array.hpp"

// ===================== Class Date start ===========
class Date
{
    private:
        int day, month, year;
    public:
        Date(int _day,int _month, int _year):day(_day),month(_month),year(_year)
        {

        }
        Date()
        {

        }

        bool operator>(const Date& other) const
        {
            if(this->year > other.year)
                return true;
            else if(this->month >other.month)
                return true;
            else if(this->month < other.month)
                return false; 

            if(this->day > other.day)
                return true;
            else
                return false;
        }

        bool operator ==(const Date& other)
        {
            return (this->day == other.day && this->month == other.month && this->year == other.year);
        }

        friend std::ostream& operator<<(std::ostream& os, const Date& dateObject);

};

std::ostream& operator<<(std::ostream& os, const Date& dateObject)
{
    os << dateObject.day << "/" << dateObject.month << "/" << dateObject.year << std::endl;
    return os;
}

void test_for_built_in_types(void);
void test_for_user_defined_type(void);

int main(void)
{
    test_for_built_in_types();
    test_for_user_defined_type();
    return (0);
}

void test_for_built_in_types(void)
{
    // Array of integers
    Array<int,5> A_int;
    A_int[0]= 30;
    A_int[1]= 20 ;
    A_int[2]= 15;
    A_int[3]= 50;
    A_int[4]= 5;

    std::cout << "Befor sort:" << std::endl;
    for(std::size_t i = 0; i < A_int.size(); ++i)
        std::cout << "A_int[" << i << "]:" << A_int[i] << std::endl;

    if( A_int.find(20) == true)
        std::cout << "20 is part of array" <<std::endl;

    if(A_int.find(-30) ==false)
        std::cout<<"-30 is not a part of array" << std::endl;

    A_int.sort();

    std::cout << "After Sort:" << std::endl;
    for(std:: size_t i =0; i<A_int.size(); ++i)
        std::cout << "A_int[" << i <<"]:" << A_int[i] << std::endl;

    // Test case for float
    Array<float, 5> A_float;
    A_float[0] = 5.5f;
    A_float[1] = 3.2f;
    A_float[2] = 1.1f;
    A_float[3] = 7.6f;
    A_float[4] = 0.5f;


}

void test_for_user_defined_types(void)
{
    Array<Date,5> dateArray;

    dateArray[0] = Date(4,1,2025);
    dateArray[1] = Date(2,1,2025);
    dateArray[2] = Date(1,1,1970);
    dateArray[3] = Date(2, 1, 1970);
    dateArray[4] = Date(4, 5, 1999);

    std::cout << "DateArray Befor Sort:" <<std::endl;
    for(ssize_t i = 0; i < dateArray.size(); ++i)
        std::cout << " dateArray[" << i <<"]:" << dateArray[i];

    if(dateArray.find(Date(2,1,1970))==true)
        std::cout << "2/1/1970 is a part of array" << std::endl;

    if(dateArray.find(Date(2,3,1997))== false)
        std::cout << "2/3/1997 is not part of array" << std::endl;
        
    dateArray.sort();

    std::cout << "DateArray AFter sort:" << std::endl;
    for(ssize_t i = 0; i<dateArray.size(); ++i)
        std::cout << "dateArray" << i <<"]:" << dateArray[i];

}