#ifndef COMPLEXPOLY_H
#define COMPLEXPOLY_H

#include <Complex.h>
#include <CommonMath/CommonMathExport.h>

namespace CommonMath {

class COMMONMATH_EXPORT ComplexPoly : public Complex // 声明com_poly是基类complex类的派生类
{
private:
    int N;      // 复系数多项式次数
    Complex* p; // 复系数多项式存储空间首地址

public:
    explicit ComplexPoly(int nn = 0, Complex* pp = NULL)
        : N(nn), p(pp) // 构造函数
    {}

    void input();                // 由键盘输入多项式复系数
    Complex polyValue(Complex); // 复系数多项式求值

    //   void ComplexPoly operator + (ComplexPoly&,ComplexPoly&);  //复系数多项式相加
    //   void ComplexPoly operator - (ComplexPoly&,ComplexPoly&);  //复系数多项式相减

    void comPolyMul(ComplexPoly&, ComplexPoly&);               // 复系数多项式相乘
    void comPolyDiv(ComplexPoly&, ComplexPoly&, ComplexPoly&); // 复系数多项式相除
};

} // namespace CommonMath
#endif // COMPLEXPOLY_H
