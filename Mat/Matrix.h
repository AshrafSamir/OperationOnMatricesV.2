#ifndef MATRIX_H
#define MATRIX_H
#include <bits/stdc++.h>
using namespace std;
template <typename T>
class Matrix
{
    public:
        Matrix(int row, int col, T num[]);
        Matrix();
        void setRow(int row);
        void setCol(int col);
        void setData(T data[]);
        void setData(valarray<T> data);
        int getRow();
        int getCol();
        T getData(T num);
        valarray<T> getData();
        int getSize();
        void setSize(int siz);
        Matrix operator+  (Matrix mat2);
        Matrix operator-  ( Matrix mat2);
        Matrix operator*  ( Matrix mat2);
        Matrix operator+  ( T scalar);
        Matrix operator-  ( T scalar);
        Matrix operator*  ( T scalar);
        Matrix operator+= ( const Matrix &mat2);
        Matrix operator-= (const Matrix& mat2);
        Matrix operator+= (T scalar);
        Matrix operator-= (T scalar);
        Matrix operator++ (int);
        Matrix operator-- (int);
        bool operator== ( Matrix mat2);
        bool operator!= ( Matrix mat2);
        bool isSquare   ();
        bool isSymetric ();
        bool isIdentity ();
        Matrix transpose();
        ~Matrix();

    protected:

    private:
        valarray<T>data;
        int row,col;
};

#endif // MATRIX_H
