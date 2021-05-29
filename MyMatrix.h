#pragma once

#include <iostream>

using namespace std;

template <class T>
class MyMatrix
{
    T** m;
    int rows, cols;
public:
    MyMatrix();
    MyMatrix(int, int);
    MyMatrix operator+(MyMatrix<T>&);
    MyMatrix operator-(const MyMatrix<T>&);
    MyMatrix operator*(const MyMatrix<T>&);
    void transpose(const MyMatrix<T>&);
    void setRows(int r);
    void setCols(int c);
    int getRows();
    int getCols();
    template<class T>
    friend istream& operator>>(istream& is, MyMatrix<T>& s);
    template<class T>
    friend ostream& operator<<(ostream& os, const MyMatrix<T>& s);
    ~MyMatrix();
};