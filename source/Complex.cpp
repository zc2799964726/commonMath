#include <cmath>

#include <Complex.h>

namespace CommonMath {

double Complex::cfabs()
{
    return std::sqrt(R * R + I * I);

}
} // namespace CommonMath
