#include <iostream>


class Student 
{
    private:
        typedef std::string s_name_t;
        typedef int age_t;
        
    
        s_name_t sname;
        age_t age;
    public:
        Student()
        {
            this->sname = "Unknown";
            this->age = 0;

        }

        s_name_t get_sname() const
        {
            return this->sname;

        }

        age_t get_age() const
        {
           return this->age;
        }
        
        void set_sname(s_name_t _sname)
        {
            this->sname = _sname;

        }

        void set_age(age_t _age)
        {
            this->age = _age;
        }



};