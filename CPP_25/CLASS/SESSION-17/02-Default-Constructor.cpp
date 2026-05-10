//Excersize sheet 1 -Problem 2

#include <iostream>

class Student
{
    public:
        typedef int age_t;
        typedef const char* name_t;

    private:
        age_t studentAge;
        name_t studentName;

    public:
        Student():studentAge(0),studentName("Unknown")
        {

        }

        void show() const
        {
            std::cout <<"Age:"<< studentAge << ", Name:"<< studentName << std::endl;


        }
};

void test_student_dds(void);
void test_student_dynamic(void);

int main(void)
{
    test_student_dds();
    test_student_dynamic();

    return EXIT_SUCCESS;
}

void test_student_dds(void)
{
    Student newStudent;

    newStudent.show();

}

void test_student_dynamic(void)
{
    Student* pStudent = 0;
    pStudent = new Student;

    pStudent->show();

    delete pStudent;
    pStudent = 0;

}