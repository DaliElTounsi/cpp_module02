#include <iostream>
#include "Fixed.hpp"

int main(void)
{
    Fixed a;
    Fixed const b(Fixed(5.05f) * Fixed(2));

    std::cout << "=== Test original ===" << std::endl;
    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;

    std::cout << b << std::endl;

    std::cout << Fixed::max(a, b) << std::endl;

    std::cout << "\n=== Test comparaisons ===" << std::endl;
    Fixed x(10);
    Fixed y(5);
    Fixed z(10);
    
    std::cout << "x = " << x << ", y = " << y << ", z = " << z << std::endl;
    std::cout << "x == z: " << (x == z) << std::endl;
    std::cout << "x != y: " << (x != y) << std::endl;
    std::cout << "x > y: " << (x > y) << std::endl;
    std::cout << "x < y: " << (x < y) << std::endl;
    std::cout << "x >= z: " << (x >= z) << std::endl;
    std::cout << "x <= y: " << (x <= y) << std::endl;

    std::cout << "\n=== Test arithmetique ===" << std::endl;
    Fixed p(10);
    Fixed q(3);
    std::cout << "p = " << p << ", q = " << q << std::endl;
    std::cout << "p + q = " << (p + q) << std::endl;
    std::cout << "p - q = " << (p - q) << std::endl;
    std::cout << "p * q = " << (p * q) << std::endl;
    std::cout << "p / q = " << (p / q) << std::endl;

    std::cout << "\n=== Test decrementation ===" << std::endl;
    Fixed dec(2);
    std::cout << "dec initial = " << dec << std::endl;
    std::cout << "--dec = " << --dec << std::endl;
    std::cout << "dec-- = " << dec-- << std::endl;
    std::cout << "dec final = " << dec << std::endl;

    std::cout << "\n=== Test min/max ===" << std::endl;
    Fixed m1(15);
    Fixed m2(8);
    std::cout << "m1 = " << m1 << ", m2 = " << m2 << std::endl;
    std::cout << "min(m1, m2) = " << Fixed::min(m1, m2) << std::endl;
    std::cout << "max(m1, m2) = " << Fixed::max(m1, m2) << std::endl;

    return 0;
}
