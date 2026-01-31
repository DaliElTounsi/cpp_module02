#include "Point.hpp"
#include "Fixed.hpp"

static Fixed orientation(Point const& a, Point const& b, Point const& p)
{
    Fixed dx1 = b.getX() - a.getX();
    Fixed dy1 = b.getY() - a.getY();
    Fixed dx2 = p.getX() - a.getX();
    Fixed dy2 = p.getY() - a.getY();

    return (dx1 * dy2) - (dy1 * dx2);
}



bool bsp(Point const& a, Point const& b, Point const& c, Point const& p)
{
    Fixed zero(0);

    Fixed s1 = orientation(a, b, p), s2 = orientation(b, c, p), s3 = orientation(c, a, p);

    if (s1 == zero || s2 == zero || s3 == zero)
        return false;
    else if (s1 > zero && s2 > zero && s3 > zero)
        return true;
    else if (s1 < zero && s2 < zero && s3 < zero)
        return true;
    else
        return false;

}

