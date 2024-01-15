#include <cmath>
#include <iostream>

namespace CommonMath {

class Complex
{
public:
    explicit Complex(double real = 0, double imag = 0)
        : R(real), I(imag)
    {}

    double cfabs();

private:
    double R;
    double I;
};

} // namespace CommonMath
