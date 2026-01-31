#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"


class Point
{
public :
    Point();
    Point(Point const &src);
    Point& operator=(Point const& src);
     Point(float x, float y);
    ~Point();

   

    Fixed const& getX() const;
    Fixed const& getY() const;






private :

    Fixed const m_x;
    Fixed const m_y;


};

#endif