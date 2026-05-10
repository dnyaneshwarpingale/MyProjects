#include <iostream>

struct IntPtr
{
    int* p;
    unsigned int reference_count;
};

class HasPtr
{
    private:
        int n;
        struct IntPtr* pIntPtr;
    
    public:
        HasPtr(int _n, int _m) : n(_n)
        {
            this->pIntPtr = new IntPtr;
            this->pIntPtr->p = new int(_m);
            this->pIntPtr->reference_count = 1;

        }

        HasPtr(const HasPtr& other)
        {
            this->n = other.n;
            this->pIntPtr = other.pIntPtr;
            this->pIntPtr->reference_count +=1;

        }

        HasPtr& operator=(const HasPtr& other)
        {
            if(this != &other)
            {
                this->n = other.n;
                this->pIntPtr->reference_count = this->pIntPtr->reference_count -1;
                if(this->pIntPtr->reference_count == 0)
                {
                    delete this->pIntPtr->p;
                    delete this->pIntPtr;
                }

                this->pIntPtr = other.pIntPtr;
                this->pIntPtr->reference_count = this->pIntPtr->reference_count + 1;

            }
            return *this;

        }

        ~HasPtr()
        {
            std::cout << "In HasPtr:: ~HasPtr()" << std::endl;
            this->pIntPtr->reference_count = this->pIntPtr->reference_count -1;
            if(this->pIntPtr->reference_count == 0)
            {
                std::cout << "Deleting shared pIntPtr" << std::endl;
                delete this-> pIntPtr->p;
                delete this-> pIntPtr;

            }
        }

        unsigned int getrefcount() const
        {
            return this->pIntPtr->reference_count;
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
    HasPtr* php1 = new HasPtr(100, 200);
    std::cout << "php1->getrefecount():" << php1->getrefcount() << std::endl;
    HasPtr* php2 = new HasPtr(*php1);
    std::cout << "php1->getrefcount():" << php1->getrefcount() << std::endl;
    HasPtr* php3 = new HasPtr(*php2);
    std::cout << "php1->getrefcount():" << php1->getrefcount() << std::endl;

    HasPtr* php4 = new HasPtr(300, 400);
    std::cout << "php4-> getrefcount():" << php4->getrefcount() << std::endl;
    HasPtr* php5 = new HasPtr(*php4);
    std::cout << "php4->getrefcount():" << php4->getrefcount() << std::endl;

    delete php3;
    php3 = 0;

    std::cout << "php1->getrefcount():" << php1->getrefcount() << std::endl;
    delete php2;
    php2 =0;
    std::cout << "php1-> getrefcount():" << php1->getrefcount() << std::endl;
    delete php1;
    php1 =0;

    delete php5;
    php5 = 0;

    std::cout << "php->getrefcount():" << php4->getrefcount() << std::endl;
    delete php4;
    php4 = 0;


}