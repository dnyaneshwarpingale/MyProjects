// @author: Dnyaneshwar Pingale
// @date: 15th Nov 2025
// @version: 0.2
// @goal: To iplement date class with validation check.
// This is a single file implementation

//--------------header files-----------
#include <iostream>
#include <cstring>

//-----------Definition of class Date-----------
class Date
{
    private:
        //-----------Typedefs------------------
        typedef int day_t;
        typedef int month_t;
        typedef int year_t;

        //-----------------non-static private data members-------------
        day_t day;
        month_t month;
        year_t year;

        //-------------------------private static constants-------------
        static const day_t VALID_START_DAY ;
        static const day_t VALID_END_DAY_FOR_LEAP_FEBRUARY;
        static const day_t VALID_END_DAY_FOR_NONLEAP_FEBRUARY;
        static const day_t VALID_END_DAY_FOR_THIRTY_DAY_MONTH;
        static const day_t VALID_END_DAY_FOR_THIRTY_ONE_DAY_MONTH;
        static const int FOUR;
        static const int HUNDRED;
        static const int FOUR_HUNDRED;
        static const int ZERO;
        static const int ONE;
        static const year_t NINTEEN_SEVENTY;
        
        //-----------------Enums------------

        enum MONTH{
            JANUARY = 1,
            FEBRUARY,
            MARCH,
            APRIL,
            MAY,
            JUNE,
            JULY,
            AUGUST,
            SEPTEMBER,
            OCTOBER,
            NOVEMBER,
            DECEMBER
        };


        //-----------------------------private static member functions------------------
        static bool is_year_leap(year_t year)
        {
            return (
                        (year % FOUR == ZERO && year % HUNDRED != ZERO)
                        ||
                        (year % FOUR_HUNDRED == ZERO )

            );
        }

        static bool is_date_valid(day_t day, month_t month, year_t year)
        {
           return ( (month == FEBRUARY && is_year_leap(year) && (day >= VALID_START_DAY && day <= VALID_END_DAY_FOR_LEAP_FEBRUARY)) || 
                    (month == FEBRUARY && !is_year_leap(year) && (day >= VALID_START_DAY && day <= VALID_END_DAY_FOR_NONLEAP_FEBRUARY)) 
                     ||
                    (
                         (month == JANUARY || month == MARCH || month == MAY || month == JULY 
                         || month == AUGUST || month == OCTOBER || month == DECEMBER ) && 
                        (day >= VALID_START_DAY && day <= VALID_END_DAY_FOR_THIRTY_ONE_DAY_MONTH)
                     )
                    ||
                    (
                        (month == APRIL || month == JUNE || month == SEPTEMBER || month == NOVEMBER ) &&
                        (day >= VALID_START_DAY && day <= VALID_END_DAY_FOR_THIRTY_DAY_MONTH)
                    )
         );
        }

    public:
        //----------------------Constructors --------------------
        //Default constructor
        Date() : day(ONE), month(ONE), year(NINTEEN_SEVENTY)
        {

        }
        
        //parameterized constructor
        Date(day_t _day, month_t _month, year_t _year)
        {
            bool date_validation_flag ;
            date_validation_flag = is_date_valid(_day, _month, _year);
            if(date_validation_flag == false)
            {
                std::cerr << "Invalid Date values, setting day, month, year to epoch date" << std::endl;
                this->day = ONE;
                this -> month = ONE;
                this -> year = NINTEEN_SEVENTY;

            }

            this->day = date_validation_flag != false ? _day : ONE;
            this->month = date_validation_flag != false ? _month : ONE;
            this->year = date_validation_flag != false ? _year : NINTEEN_SEVENTY;
             
        }



       //-----------------getter functions-----------------
       
       day_t get_day()const
       {
            return this ->day;
       }

       month_t get_month() const 
        {
            return this->month;
        }

        year_t get_year() const
        {
            return this->year;
        }

        //------------------setter functions-----------------

        void set_date(day_t new_day)
        {
            //validation check
            if(is_date_valid(new_day, this->month, this->year) == false)
            {
                std::cerr << "Invalid value for new_day, not changing anything"<< std::endl;
                return;
            }

            this->day = new_day;

        }

        void set_month(month_t new_month) 
        {
            if(is_date_valid(this->day, new_month, this->year)== false)
            {
                std:: cerr << "Bad value for new month or existing day not compatible with new_month" << std::endl;
                return;
            }
            this->month = new_month;
        }

        void set_year(year_t new_year)
        {
            this->year =new_year;
        }
        
        //----------------Miscallaneous functions------------------

        void show() const
        {
            std::cout<<this->day << "/" <<this->month <<"/" << this->year << std::endl;
        }

};

        const Date::day_t Date:: VALID_START_DAY                        = 1;
        const Date::day_t Date:: VALID_END_DAY_FOR_LEAP_FEBRUARY        = 29;
        const Date::day_t Date:: VALID_END_DAY_FOR_NONLEAP_FEBRUARY     = 28 ;
        const Date::day_t Date:: VALID_END_DAY_FOR_THIRTY_DAY_MONTH     = 30;
        const Date::day_t Date:: VALID_END_DAY_FOR_THIRTY_ONE_DAY_MONTH = 31;
        const Date::year_t Date:: NINTEEN_SEVENTY                       = 1970;
        const int Date:: FOUR           = 4;
        const int Date:: HUNDRED        = 100;
        const int Date:: FOUR_HUNDRED   = 400;
        const int Date:: ZERO           = 0;
        const int Date:: ONE            = 1;

//------------------------------------------------------END OF SERVER SIDE------------------------------------------------------

// ------------------------------------------------------CLIENT SIDE ---------------------------------------------------------

void test_date(void);

int main(void)
{
    test_date();
    return EXIT_SUCCESS;

}
 
void test_date(void)
{
    Date myDate;

    std::cout << "Showing myDate:";
    myDate.show();

    Date today(15, 11, 2025);
    std::cout << "showing today:";
    today.show();

    //---------------Invalid initilizers-----------
    Date myDateOne(34,2,1900);
    Date myDateTwo(2,56,2025);
    Date myDateThree(31,9,2025);
    Date myDateFour(29,2,2025);

    std::cout << "showing myDateOne, myDateTwo, myDateThree, myDateFour respectively" << std::endl;
    // all are 1/1/1970
    myDateOne.show();
    myDateTwo.show();
    myDateThree.show();
    myDateFour.show();

    Date testDate(15, 11,2025);

    int day = testDate.get_day();
    int month = testDate.get_month();
    int year = testDate.get_year();

    std::cout << "Showing testDate:" << day << "/" << month << "/" << year << std::endl;

    testDate.set_date(24);
    testDate.set_month(3);
    testDate.set_year(2026);

    std::cout << "Showing modified testDate:";
    testDate.show();

    Date* pDate =new Date(25,11,2025);
    std::cout << "Showing pDate";
    pDate->show();

    day = pDate->get_day();
    month = pDate -> get_month();
    year = pDate -> get_year();

    std::cout << "Showing pDate by obtaining values from getters():" << day << "/" <<month <<"/" <<year<< std::endl; 

    pDate->set_date(26);
    pDate-> set_month(3);
    pDate->set_year(2026);

    std::cout<<"showing modified pDate:";
    pDate->show();

    const Date* cpDate =new Date(15, 11, 2025);
    //only getters can be called from cpDate

    day = cpDate->get_day();
    month =cpDate->get_month();
    year = cpDate-> get_year();
   std::cout<< " showing cpDate by otaining values from getters: "<< day << "/" << month << "/" << year<< std::endl;
   std::cout<< "Showing cpDate by show() function:";
   cpDate->show();

   //cpDate ->set_day(24);   //CTE
   //cpDate ->set_month(3);    //CTE
   //cpDate ->set_year(2026);   //CTE

   delete cpDate;
   cpDate = 0;




}