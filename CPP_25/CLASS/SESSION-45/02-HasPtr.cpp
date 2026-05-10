#include <iostream>

class HasPtr
{
    private:
        int n;
        int * ptr;
    public:
        HasPtr(int _n, int _m) : n(_n), ptr(new int(_m))
        {

        }

        int getn() const{
            return n;
        }

        void setn(int new_n)
        {
            n = new_n;
        }

        int get_ptr_val() const
        {
            return *ptr;
        }

        void set_ptr_val(int new_val)
        {
            *ptr = new_val;
        }

        ~HasPtr()
        {
            delete ptr;
        }
};

void memory_leak_scenario();
void segfault_scenario();

int main()
{
    memory_leak_scenario();
    segfault_scenario();

    // control flow will not reach here

    std::cout << "main(): Application terminated successfully" << std::endl;
    return 0;
}

void memory_leak_scenario()
{
    std::cout << "-----Entered Memory leak scenario-------" <<std::endl;
    HasPtr hp1(100, 200);
    HasPtr hp2(400, 500);

    hp1 = hp2;

    /*
        hp1 = hp2;
         will be internally converted to a synthesized copy assignment operator call
         HasPtr::operator=(&hp1, hp2);

         And Synthesized assignment operator does memberwise assignment.
         In effect the following will happen
         hp1.n = hp2.n; // It will happen through this pointer and other reference variable
          hp1.ptr = hp2.ptr // Lo' behold -> the memory leak !


    */
  std::cout << "-----Leaving Memory leak scenario-------" <<std::endl;
}

void segfault_scenario()
{
    std::cout << "-----Entered segfault_scenario scenario-------" <<std::endl;
    HasPtr* p_hp1 = new HasPtr(100, 200);
    HasPtr* p_hp2 = new HasPtr(*p_hp1);

    delete p_hp1; /* Object of class HasPtr pointed by p_hp1 will be freed but  
                   
    */
    
    std::cout << "Ye Antim, Behoshi Antim, Saki Antim Pyala hai, Pathik Pyar se Pina Isko , Phir Na Milegi Madhushala" << std::endl;
    // std::cout.flush();

    p_hp2->set_ptr_val(500); // !! Segmentaion Fault
    delete p_hp2;

    std:: cout << "Segfault Scenario: " << std::endl;
     std::cout << "-----Leaving  segfault_scenario leak scenario-------" <<std::endl;
}