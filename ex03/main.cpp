#include <iostream>
#include "Point.hpp"

bool bsp(Point const& a, Point const& b, Point const& c, Point const& p);

int main()
{
    Point a(0.0f, 0.0f);
    Point b(10.0f, 0.0f);
    Point c(0.0f, 10.0f);

    Point p_inside(2.0f, 2.0f);
    Point p_outside(10.0f, 10.0f);
    Point p_on_edge(5.0f, 0.0f);
    Point p_on_vertex(0.0f, 0.0f);

    std::cout << "inside  (2,2)   : " << (bsp(a, b, c, p_inside) ? "true" : "false") << std::endl;
    std::cout << "outside (10,10) : " << (bsp(a, b, c, p_outside) ? "true" : "false") << std::endl;
    std::cout << "on edge (5,0)   : " << (bsp(a, b, c, p_on_edge) ? "true" : "false") << std::endl;
    std::cout << "on vertex (0,0) : " << (bsp(a, b, c, p_on_vertex) ? "true" : "false") << std::endl;

    return 0;
}
