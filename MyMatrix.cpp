#include "MyMatrix.h"
#include<iostream>

using namespace std;

template <class T>
MyMatrix<T>::MyMatrix()
{
    rows = 0;
    cols = 0;
}
template <class T>
MyMatrix<T>::MyMatrix(int rows, int cols) {
    this->rows = rows;
    this->cols = cols;
    m = new T * [this->rows];
    for (int i = 0; i < this->rows; i++)
        m[i] = new T[this->cols];
}
template <class T>
MyMatrix<T> MyMatrix<T>:: operator+(MyMatrix<T>& s)
{
    MyMatrix *result=new MyMatrix(rows, cols);
    if (rows == s.rows && cols == s.cols) {
        cout << "The Addition of The Two Matrices:" << endl;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                result->m[i][j] = m[i][j] + s.m[i][j];
            }
        }
        return *result;
    }
    else {
        cout << "Invalid Addition" << endl;
    }
}
template <class T>
MyMatrix<T> MyMatrix<T>::operator-(const MyMatrix<T>& s)
{
    MyMatrix *result=new MyMatrix(rows, cols);
    if (rows == s.rows && cols == s.cols) {
        cout << "The Subtraction of The Two Matrices:" << endl;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                result->m[i][j] = m[i][j] - s.m[i][j];
            }
        }
        return *result;
    }
    else {
        cout << "Invalid Subtraction" << endl;
    }
}
template <class T>
MyMatrix<T> MyMatrix<T>:: operator*(const MyMatrix<T>& s)
{
    MyMatrix *result=new MyMatrix(rows, s.cols);
    if (cols == s.rows){
        cout << "The Multiplication of The Two Matrices:" << endl;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < s.cols; j++)
            {
                result->m[i][j] =0;
                for (int k = 0; k < cols; k++)
                {
                    result->m[i][j] = result->m[i][j] + (m[i][k] * s.m[k][j]);
                }
            }
        }
        return *result;
    }
    else {
        cout << "Invalid Multiplication" << endl;
    }
}
template <class T>
void MyMatrix<T>::transpose(const MyMatrix<T>& s)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            m[i][j] = s.m[j][i];
        }
    }
}
template <class T>
void MyMatrix<T>::setRows(int r)
{
    rows = r;
}
template <class T>
void MyMatrix<T>::setCols(int c)
{
    cols = c;
}
template <class T>
int MyMatrix<T>::getRows()
{
    return rows;
}
template <class T>
int MyMatrix<T>::getCols()
{
    return cols;
}
template<class T>
istream& operator>>(istream& is, MyMatrix<T>& s)
{
    for (int i = 0; i < s.rows; i++)
    {
        for (int j = 0; j < s.cols; j++)
        {
            is >> s.m[i][j];
        }
    }
    return is;
}
template<class T>
ostream& operator<<(ostream& os, const MyMatrix<T>& s)
{
    for (int i = 0; i < s.rows; i++)
    {
        for (int j = 0; j < s.cols; j++)
        {
            os << s.m[i][j] << " ";
        }
        os << endl;
    }
    return os;
}

template<class T>
MyMatrix<T>::~MyMatrix()
{
    for (int i = 0; i < rows; i++)
    {
        delete[] m[i];
    }
    delete[] m;
}
int main()
{
    bool keepmenu = true;
    while (keepmenu)
    {
        cout << "Welcome to FCI Matrix Calculator" << endl;
        cout << "---------------------------" << endl;
        cout << "1-Perform Matrix Addition" << endl;
        cout << "2-Perform Matrix Subtraction" << endl;
        cout << "3-Perform Matrix Multiplication" << endl;
        cout << "4-Perform Matrix Transpose" << endl;
        cout << "5-Exit" << endl;
        cout << endl;

        int menuchoice;
        cout << "Enter your choice: ";
        cin >> menuchoice;
        switch (menuchoice)
        {
        case 1:
        {
            int noofrows, noofcols;
            cout << "Enter the number of Rows: ";
            cin >> noofrows;
            cout << "Enter the number of Columns: ";
            cin >> noofcols;
            cout << endl;
            MyMatrix<int>m1(noofrows, noofcols);
            cout << "Enter The First Matrix:" << endl;
            cin >> m1;
            cout << endl;
            int noofrows2, noofcols2;
            cout << "Enter the number of Rows: ";
            cin >> noofrows2;
            cout << "Enter the number of Columns: ";
            cin >> noofcols2;
            cout << endl;
            MyMatrix<int>m2(noofrows2, noofcols2);
            cout << "Enter The Second Matrix:" << endl;
            cin >> m2;
            cout << endl;
            cout << m1 + m2;
            cout << endl;
            break;
        }
        case 2:
        {
            int noofrows, noofcols;
            cout << "Enter the number of Rows: ";
            cin >> noofrows;
            cout << "Enter the number of Columns: ";
            cin >> noofcols;
            cout << endl;
            MyMatrix<int>m1(noofrows, noofcols);
            cout << "Enter The First Matrix:" << endl;
            cin >> m1;
            cout << endl;
            int noofrows2, noofcols2;
            cout << "Enter the number of Rows: ";
            cin >> noofrows2;
            cout << "Enter the number of Columns: ";
            cin >> noofcols2;
            cout << endl;
            MyMatrix<int>m2(noofrows2, noofcols2);
            cout << "Enter The Second Matrix:" << endl;
            cin >> m2;
            cout << endl;
            MyMatrix<int>m3;
            cout << m1 - m2;
            cout << endl;
            break;
        }
        case 3:
        {
            int noofrows, noofcols;
            cout << "Enter the number of Rows: ";
            cin >> noofrows;
            cout << "Enter the number of Columns: ";
            cin >> noofcols;
            cout << endl;
            MyMatrix<int>m1(noofrows, noofcols);
            cout << "Enter The First Matrix:" << endl;
            cin >> m1;
            cout << endl;
            int noofrows2, noofcols2;
            cout << "Enter the number of Rows: ";
            cin >> noofrows2;
            cout << "Enter the number of Columns: ";
            cin >> noofcols2;
            cout << endl;
            MyMatrix<int>m2(noofrows2, noofcols2);
            cout << "Enter The Second Matrix:" << endl;
            cin >> m2;
            cout << endl;
            MyMatrix<int>m3;
            cout << m1 * m2;
            cout << endl;
            break;
        }
        case 4:
        {
            int noofrows, noofcols;
            cout << "Enter the number of Rows: ";
            cin >> noofrows;
            cout << "Enter the number of Columns: ";
            cin >> noofcols;
            cout << endl;
            MyMatrix<int>m1(noofrows, noofcols);
            cout << "Enter The Matrix:" << endl;
            cin >> m1;
            cout << endl;
            MyMatrix<int>m2(noofcols, noofrows);
            m2.transpose(m1);
            cout << "The Tranpose of the Matrix:" << endl;
            cout << m2;
            cout << endl;
            break;
        }
        case 5:
            keepmenu = false;
            break;
        default:
            cout << "Invalid input" << endl;
            cout<< endl;
        }
        
    }
}