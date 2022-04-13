#include <string>
#include <iostream>
#include<bits/stdc++.h> 
#include <vector>

#ifndef MY_HHEDER
#define MY_HHEDER

using namespace std;

namespace zich{

    class Matrix{
    
    private:
        int row;
        int col;
        vector<double> mat;
    public:

        //constractor
        Matrix(vector<double> const & vec, int r, int c);//: mat(vec), row(x), col(y){}//{
        vector<double> getM();

        bool same_size(const Matrix &mat)const;
        // bool for_multi(const Matrix mat)const;

        // Accounting operators
        Matrix operator+(Matrix mat) ;
        void operator+=(const Matrix &mat);
        friend Matrix operator+(Matrix& mat); //unary
        Matrix operator-(Matrix mat);
        void operator-=(const Matrix &mat);
        friend Matrix operator-(Matrix& mat); //unary
        // Comparison operators
        bool operator>(const Matrix &mat) const;
        bool operator>=(const Matrix &mat) const;
        bool operator<(const Matrix &mat) const;
        bool operator<=(const Matrix &mat) const;
        bool operator==(const Matrix &mat) const;
        bool operator!=(const Matrix &mat) const;
        
        // ++ / --
        Matrix& operator++();
        Matrix& operator--();
        Matrix operator--(int);
        Matrix operator++(int);
        
        // scalar multiplication
        Matrix operator*(double scalar);
        friend Matrix operator*(double scalar,const Matrix &mat);
        Matrix& operator*=(double scalar);
        // Matrix multiplication
        Matrix operator*(const Matrix &mat);// const;
        Matrix& operator*=(Matrix &mat);

        // Input and output operator

        friend std::ostream &operator<<(std::ostream &o, Matrix const &mat);
        friend std::istream &operator>>(std::istream &in, Matrix &mat);

    };
}

#endif