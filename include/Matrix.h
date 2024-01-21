#ifndef MATRIX_H
#define MATRIX_H

#include <vector>

#include "CommonMath/CommonMathExport.h"

namespace CommonMath {

class COMMONMATH_EXPORT Matrix
{
private:
    int _numColumns = 0;                // 矩阵列数
    int _numRows = 0;                   // 矩阵行数
    double _eps = 0.0;                  // 缺省精度
    std::vector<double> _elements = {}; // 矩阵数据缓冲区

    bool init(int nRows, int nCols);
    /**
     * 设置矩阵各元素的值
     *
     * @param elements - 一维数组，长度为numColumns*numRows，存储
     *	              矩阵各元素的值
     */
    void setElements(const std::vector<double>& elements);

public:
    Matrix()
        : _numColumns(1), _numRows(1), _elements{ 0 }
    {}

    /**
     * 指定值构造函数
     *
     * @param value - 二维数组，存储矩阵各元素的值
     */
    explicit Matrix(std::vector<std::vector<double>>& value);
    /**
     * 指定值构造函数
     *
     * @param nRows - 指定的矩阵行数
     * @param nCols - 指定的矩阵列数
     * @param value - 一维数组，长度为nRows*nCols，存储矩阵各元素的值
     */
    Matrix(const std::vector<double>& value, int nRows, int nCols);

    int columns() const;
    int rows() const;
    double getElementAt(int row, int col) const;
    double getEps() const;
    int GetRowVector(int nRow, std::vector<double>& pVector);

    bool setElementAt(int row, int col, double value);
    void setEps(double eps);
    Matrix operator+ (const Matrix& rhs) const;
    Matrix operator- (const Matrix& rhs) const;
    Matrix operator* (const Matrix& rhs) const;
    Matrix operator/ (const Matrix& rhs) const;
    bool makeIdentity(int size);
};
} // namespace CommonMath

#endif // MATRIX_H
