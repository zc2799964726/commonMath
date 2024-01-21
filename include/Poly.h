#ifndef POLY_H
#define POLY_H

#include "CommonMath/CommonMathExport.h"

namespace CommonMath {

class COMMONMATH_EXPORT Poly
{
public:
    Poly(int degree, double* params);
    double polyValue(double) const;
    void polyMultiply(Poly&, Poly&) const;
    void polyDivision(Poly&, Poly&, Poly&) const;

private:
    int _degree;
    double* _params;
};

} // namespace CommonMath


#endif // POLY_H
