#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <string>

class Matrix
{
private:
    int rows;
    int cols;
    double** values;
public:
    Matrix(); //
    Matrix(double d); //
    Matrix(int r, int c); //
    Matrix(int r, int c, double** v); //
    Matrix(const Matrix& other); //
    Matrix& operator=(const Matrix& right); //
    ~Matrix(); //
    
    int getRows() const; //
    int getCols() const; //
    double get(int r, int c) const; //
    double& operator()(int r, int c) const; //
    std::string str() const; // -- works!
    
    Matrix operator+(const Matrix& right) const; //
    Matrix operator-(const Matrix& right) const; //
    Matrix operator*(const Matrix& right) const; //
    Matrix operator*(double scalar) const; //
    bool operator==(const Matrix& right) const; //--
    bool operator!=(const Matrix& right) const; //--
    
    Matrix& operator+=(const Matrix& right); //--
    Matrix& operator-=(const Matrix& right); //--
    Matrix& operator*=(const Matrix& right); //-- 
    Matrix& operator*=(double scalar); //--
    
    Matrix transpose() const; //
    double determinant() const; //
    Matrix adjoint() const; //
    bool singular() const; // -- 
    bool square() const;  //--
    Matrix inverse() const; //--
    double minorM(int r, int c) const; //
    double cofactor(int r, int c) const; // need to make recursive;//
    Matrix cofactor() const; // need to make recursive;//
    
    static Matrix identity(int size); //--

    class InvalidDimensions { }; //

    class OutOfBounds { };  //
};

std::ostream& operator<<(std::ostream& os, const Matrix& m)
{
    return os << m.str();
}

#endif