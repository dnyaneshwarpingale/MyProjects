#include <iostream>
#include <stdexcept>

void f1(int n);

class verbose_runtime_error : public std::runtime_error
{
    private:
        char* src_file_name;
        int src_line_number;
    public:
        verbose_runtime_error(
                    char* err_msg,
                    char* file_name = NULL,
                    int line_nr = -1): std::runtime_error(err_msg),
                                        src_file_name(file_name),
                                        src_line_number(line_nr)
                                        {

                                        }
        char* get_src_file_name() const
        {
            return src_file_name;
        }
        
        int get_src_line_number() const
        {
            return src_line_number;
        }
};

int main(void)
{
    try
    {
        f1(-10);
    }
    catch(verbose_runtime_error& ref)
    {
        std::cout << "Error message:" << ref.what() << std::endl;
        std::cout << "Error source file:" << ref.get_src_file_name() << std::endl;
        std::cout << "Line Number" << ref.get_src_line_number() << std::endl;

    }
    return (0);
    
}

void f1(int n)
{
    if(n<0)
    {
        throw verbose_runtime_error("Negative number ka dilas?",__FILE__,__LINE__);
    }
    std::cout << "n:" << std::endl;
    
}