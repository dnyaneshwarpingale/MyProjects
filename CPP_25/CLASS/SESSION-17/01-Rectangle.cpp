// Excersize sheet -1 , problem -1

#include <iostream>

class Rectangle
{   
    public:
        typedef double width_t;
        typedef double height_t;
    private:

        typedef double area_t;

        // private non-static i.e per object data members
        width_t width;
        height_t height;

    public:
        // Parameterized constructor
        Rectangle(width_t _width, height_t _height)
        {
            if(_width <=0.0 || _height <= 0.0)
            {
                std:: cerr << "Bad value for width or height "<< std::endl;

            }

            width = _width > 0.0 ? _width : 1.0f;
            height = _height > 0.0 ? _height :1.0f;

        }

        width_t get_width() const
        {
            return this ->width;
        }

        height_t get_height() const
        {
            return this->height;
        }

        void set_width(width_t new_width)
        {
            if(new_width <= 0.0)
            {
                std::cerr << "Invalid value for new width , not setting width"<< std::endl;
                return;
            }

            this-> width =new_width;
        }

        void set_height(height_t new_height)
        {
            if(new_height <= 0.0)
               {
                std:: cerr << " Invalid value for new , not setting height" << std::endl;
                return;
               }

               this-> height =new_height;
        }

        area_t get_area() const
        {
            return (this->width * this->height);
        }
        void show(const char* msg = 0) const
        {
            if(msg)
                std::cout<< msg << std::endl;
            std::cout<<"Width:" << width << ", Height:" << height << std::endl;

        }

};

void test_rectangle_1(void);
void test_rectangle_2(void);

int main(void)
{
    test_rectangle_1();
    test_rectangle_2();

    return EXIT_SUCCESS;

}

void test_rectangle_1(void)
{
    static const Rectangle::width_t rect_width = 5.0;
    static const Rectangle::height_t rect_height = 2.0;
    static const Rectangle::width_t new_rect_width = 15.0;
    static const Rectangle::height_t new_rect_height = 7.5;

    Rectangle R(rect_width , rect_height);
    
    R.show("Showing width and Height of Rectangle R:");
    R.set_width(new_rect_width);
    R.set_height(new_rect_height);

    std::cout << "Area of modified rect:" << R.get_area()<< std::endl;

    Rectangle::width_t current_width = R.get_width();
    Rectangle::height_t current_height = R.get_height();

    std::cout << "current width of  R: " << current_width << std::endl
                <<"Current Height of R: "<< current_height << std::endl;
}

void test_rectangle_2(void)
{
    static const Rectangle::width_t rect_width = 5.0;
    static const Rectangle::height_t rect_height = 2.0;
    static const Rectangle::width_t new_rect_width = 15.0;
    static const Rectangle::height_t new_rect_height = 7.5;

    Rectangle* pRect = new Rectangle(rect_width, rect_height);

    pRect ->show("Showing width and Height of Rectangle R:");
    pRect->set_width(new_rect_width);
    pRect->set_height(new_rect_height);

    std::cout << "Area of modified rect:" << pRect->get_area() << std::endl;

    Rectangle::width_t current_width = pRect->get_width();
    Rectangle::height_t current_height = pRect->get_height();

    std::cout << "Current width of pRect:" << current_width << std::endl
                << "Current height of pRect:"<<current_height << std::endl;

    delete pRect;
    pRect = 0;

}