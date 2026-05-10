// Excersize sheet -1 , problem -3

//Header files
#include <iostream>

// Class Student definition

class Student
{
    public:
        typedef int age_t;
        typedef const char* name_t;
    private:
        // private non-static i.e per object members
        age_t studentAge;
        name_t studentName;

    public:
        // Parameterized Constructor
        Student(age_t _age, name_t _name): studentAge(_age), studentName(_name)
        {
            if(_age < 0)
            {
                 std::cerr << "Invalid value for age, it must be positive or zero " << std::endl;
                 studentAge = 0;

            }
        }

        // Display Object member function
        void show() const
        {
            std::cout << "Student Name: " << studentName << ", Student Age:" << studentAge << std::endl;

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
    Student newStudent(40, "Dnyaneshwar");

    newStudent.show();

 }

 void test_student_dynamic(void)
 {
    Student* pStudent = 0;
    pStudent = new Student(40, "Dnyaneshwar");

    pStudent->show();

    delete pStudent;
    pStudent = 0;
    
 }
