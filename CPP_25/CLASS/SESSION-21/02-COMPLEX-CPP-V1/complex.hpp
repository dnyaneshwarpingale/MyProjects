 #ifndef _COMPLEX_HPP
 #define _COMPLEX_HPP

 typedef double real_t;
 typedef double img_t;

 class complex 
 {
    private:
        real_t re;
        img_t im;

    public:
        //Default + Parameterized constructor
        complex(real_t _re = 0.0, img_t _im = 0.0);

        // Definitions of arithmetic operators
        complex add(const complex& c2) const;
        complex sub(const complex& c2) const;
        complex mult(const complex& c2) const;
        complex div(const complex& c2) const;

        // Display function
        void show(const char* msg) const;
 };

 #endif // _COMPLEX_HPP