#include <iostream>

class CPA_int
{
    private:
        int n;

    public:
        CPA_int(int _n = 0) : n(_n)
        {

        }

        void show(const char * msg = 0) const
        {
            if(msg)
                std::cout << msg;

            std::cout << n << std::endl;

        }

        // Operator overload function for pre-increment
        CPA_int& operator++()
        {
            this->n = this->n+1;
            return *this;

        }

        // Operator overload function for post-increment
        CPA_int operator++(int)
        {
            CPA_int tmp;
            tmp.n = this->n;
            this->n = this->n+1;
            return tmp;
        }

        // Operator overload function for pre-decrement 

        CPA_int& operator--()
        {
            this->n=  this->n - 1;
            return *this;
        }

        // Operator overload function for post-decrement
        CPA_int operator--(int)
        {
            CPA_int tmp;
            tmp.n = this->n;
            this->n = this->n -1;
            return tmp;
        }

};

void test_pre_increment(void);
void test_pre_decrement(void);
void test_post_increment(void);
void test_post_decrement(void);

int main(void)
{
    test_pre_increment();
    test_pre_decrement();
    test_post_increment();
    test_post_decrement();

    return (0);
}

void test_pre_increment(void)
{
    CPA_int n(10);
    CPA_int m;

    n.show("test_pre_increment:BEFOR:n:");
    m.show("test_pre_increment:BEFORE:m:");

    m = ++n;
    n.show("test_pre_increment:AFTER:n:");
    m.show("test_pre_increment:AFTER:m:");

    // ++n : CPA_int :: operator++(&n)
}

void test_pre_decrement(void)
{
    CPA_int n(10);
    CPA_int m;

    n.show("test_pre_increment:BEFOR:n:");
    m.show("test_pre_increment:BEFORE:m:");

    m = --n;
    n.show("test_pre_increment:AFTER:n:");
    m.show("test_pre_increment:AFTER:m:");

    
}

void test_post_increment(void)
{
    CPA_int n(10);
    CPA_int m;

    n.show("test_pre_increment:BEFOR:n:");
    m.show("test_pre_increment:BEFORE:m:");

    m = n++;
    n.show("test_pre_increment:AFTER:n:");
    m.show("test_pre_increment:AFTER:m:");

}

void  test_post_decrement(void)
{
    CPA_int n(10);
    CPA_int m;

    n.show("test_pre_increment:BEFOR:n:");
    m.show("test_pre_increment:BEFORE:m:");

    m = n--;
    n.show("test_pre_increment:AFTER:n:");
    m.show("test_pre_increment:AFTER:m:");

   
}

