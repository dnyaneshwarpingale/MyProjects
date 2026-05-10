#include "complex.hpp"
complex::complex(real_t _re,img_t _im):re(_re),im(_im)
{

}

complex complex ::add(const complex& c2)const
{
    complex summation_result;

    summation_result.re = this->re + c2.re;
    summation_result.im = this->im + c2.im;

    return (summation_result);
}

complex complex::sub(const complex& c2)const
{
    return complex(re-c2.re,im-c2.im);
}

complex complex::mult(const complex& c2)const
{
    complex multiplication_result;
    multiplication_result.re = re*c2.re - im * c2.im;
    multiplication_result.im = re*c2.im + c2.re*im;

    return (multiplication_result);
}

complex complex::div(const complex& c2)const
{
    double div_re, div_im;
    if(c2.re == 0.0 && c2.im == 0.0)
    {
        div_re = INFINITY;
        div_im = INFINITY;

    }
    else
    {
        div_re = (re*c2.re + im*c2.im)/(c2.re*c2.re + c2.im*c2.im);
        div_im = (im*c2.re - re*c2.im)/(c2.re*c2.re + c2.im*c2.im);
    }

    return complex(div_re,div_im);
}

void complex::show(const char* msg)const
{
    if(msg)
        std::cout<<msg;

    std::cout<<"("<<re<<") + i("<<im<<")"<<std::endl;

}