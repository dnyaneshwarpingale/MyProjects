#include <iostream>

class HasPtr
{
    private:
        int n;
        int* ptr;
    public:
        // parameterized constructor
        HasPtr(int _n, int _m) : n(_n), ptr(new int(_m))
        {

        }

        // copy constructor -> for imolementing deep copying
        HasPtr(const HasPtr& other) : n(other.n), ptr(new int(*other.ptr))
        {

        }

        // Copy Assignment operator -> for implementing deep copying
        HasPtr& operator=(const HasPtr& other)
        {
            if(this != &other)
            {
                this->n = other.n;
                *this->ptr = *other.ptr;
            }
            return *this;
        }

        int getn()const{
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

        void print_ptr_addr(const char* msg = 0)const
        {
            if(msg)
                std::cout << msg;
            std::cout << "Address of object:" << this << std::endl;
            std::cout << "Address of ptr:" << ptr << std::endl;
        }
};

void test();

int main()
{
    test();
    return 0;
}

void test()
{
    HasPtr * p_hp1 = new HasPtr(100, 200);
    HasPtr * p_hp2 = new HasPtr(*p_hp1);

    std::cout << "P_hp1-> getn():" << p_hp1->getn() << std::endl;
    std::cout << "p_hp2-> getn():" << p_hp2->getn() << std::endl;

    p_hp1->print_ptr_addr("Address of p_hp1->ptr:");
    p_hp2->print_ptr_addr("Address of p_hp2->ptr:");

    if(p_hp1->get_ptr_val() == p_hp2->get_ptr_val())
        std::cout << "p_hp1->ptr and p_hp2->ptr are different but *p_hp1->ptr == *p_hp2->ptr" << std::endl;

    HasPtr* p_hp3 = new HasPtr(400, 500);
    HasPtr* p_hp4 = new HasPtr(600, 700);

    std::cout << "P_hp3-> getn():" << p_hp3->getn() << std::endl;
    std::cout << "p_hp4-> getn():" << p_hp4->getn() << std::endl;
    
    std::cout << "p_hp3->get_ptr_val():" << p_hp3->get_ptr_val() << std::endl; 
    std::cout << "p_hp4->get_ptr_val():" << p_hp4->get_ptr_val() << std::endl;

    p_hp3->print_ptr_addr("Address of p_hp3->ptr:");
    p_hp4->print_ptr_addr("Address of p_hp4->ptr:");

    *p_hp3 = *p_hp4;

       std::cout << "P_hp3-> getn():" << p_hp3->getn() << std::endl;
    std::cout << "p_hp4-> getn():" << p_hp4->getn() << std::endl;
    
    std::cout << "p_hp3->get_ptr_val():" << p_hp3->get_ptr_val() << std::endl; 
    std::cout << "p_hp4->get_ptr_val():" << p_hp4->get_ptr_val() << std::endl;

    p_hp3->print_ptr_addr("Address of p_hp3->ptr:");
    p_hp4->print_ptr_addr("Address of p_hp4->ptr:");

    std::cout << "Deep Copying : successfully Done -> Yach Sathi Kela Hota Attahas " << std::endl;

}


