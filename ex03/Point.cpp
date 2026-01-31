
#include "Fixed.hpp"
#include "Point.hpp"


Point::Point()
    : m_x(0), m_y(0)
{

}

Point::Point(Point const &src)
    : m_x(src.m_x), m_y(src.m_y)
{
   
}

Point& Point::operator=(Point const& src) 
{
    (void)src;
    return *this;
}

Point::Point(float x, float y)
    :m_x(x), m_y(y)
{

}

Point::~Point()
{

}

Fixed const& Point::getX() const
{
    return m_x;
}

Fixed const& Point::getY() const
{
    return m_y;
}
