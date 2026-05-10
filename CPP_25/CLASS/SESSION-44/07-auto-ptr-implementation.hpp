#ifndef _CPA_AUTO_PTR
#define _CPA_AUTO_PTR

template <typename T>
class cpa_auto_ptr
{
    private:
        T* ptr;
    public:
        cpa_auto_ptr(T* _ptr) : ptr(_ptr){}
        ~cpa_auto_ptr()
        {
            delete ptr;
            ptr = 0;
        }
        T* operator->()
        {
            return ptr;
        }
};

#endif