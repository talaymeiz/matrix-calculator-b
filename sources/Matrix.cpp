#include <iostream>
#include <stdexcept>
#include "Matrix.hpp"
#include <vector>
using namespace std;
const int ten=10;


namespace zich{

        Matrix:: Matrix(vector<double> const & vec, int r, int c){

            if(r<=0 || c<=0 ) {
                throw std::invalid_argument("not good input M");
            }
            if((r*c)!=vec.size()) {
                throw std::invalid_argument("not good input x*y!=vec.size()");
            }

            this->row = r;
            this->col = c;
            vector<double> v;
            for (int i=0; i<vec.size(); i++){
                double val=vec[(unsigned long)i];
                v.push_back(val);}
            this->mat = v;
        };
        vector<double> Matrix::getM(){
            return this->mat;
        }

        bool Matrix:: same_size(Matrix const &mat)const{

            bool b= false;
            if(this->col==mat.col && this->row==mat.row){
                b= true;
            }
            return b;
        }
        // bool Matrix:: for_multi(Matrix const mat)const{
//
        //     if(this->col==mat.row){
        //         return true;
        //     }
        //     return false;
        // }

        // Accounting operators
        Matrix Matrix::operator+(Matrix mat){
            
            if(!this->same_size(mat)) {
                throw std::invalid_argument("not same size +");
            }

            vector<double> vec;
            for (int i = 0; i < this->mat.size(); ++i) {
                double val=this->mat[(unsigned long)i]+mat.mat[(unsigned long)i];
                vec.push_back(val);
            }
            Matrix new_mat{vec, this->row, this->col};
            return new_mat;
        }
        void Matrix:: operator+=(const Matrix &mat){

            if(!this->same_size(mat)) {
                throw std::invalid_argument("not same size +=");
            }

            vector<double> vec;
            for (int i = 0; i < this->mat.size(); ++i) {
                double val=this->mat[(unsigned long)i] + mat.mat[(unsigned long)i];
                vec.push_back(val);
            }
            this->mat= vec;
        }
        Matrix operator+(Matrix& mat){
            
            vector<double> vec;
            for (int i = 0; i < mat.mat.size(); ++i) {
                double val=mat.mat[(unsigned long)i];
                vec.push_back(val);
            }
            Matrix new_mat{vec, mat.row, mat.col};
            return new_mat; 
            } //unary
        Matrix Matrix:: operator-(Matrix mat){

            if(!this->same_size(mat)) {
                throw std::invalid_argument("not same size -");
            }

            vector<double> vec;
            for (int i = 0; i < this->mat.size(); ++i) {
                double val=this->mat[(unsigned long)i]-mat.mat[(unsigned long)i];
                vec.push_back(val);
            }
            Matrix new_mat{vec, this->row, this->col};
            return new_mat;
            }
        void Matrix:: operator-=(const Matrix &mat){

            if(!this->same_size(mat)) {
                throw std::invalid_argument("not same size -=");
            }

            vector<double> vec;
            for (int i = 0; i < this->mat.size(); ++i) {
                double val=this->mat[(unsigned long)i] - mat.mat[(unsigned long)i];
                vec.push_back(val);
            }
            this->mat= vec;
        }   
        Matrix operator-(Matrix& mat){
            
            vector<double> vec;
            for (int i = 0; i < mat.mat.size(); ++i) {
                double val= mat.mat[(unsigned long)i]*(-1);
                vec.push_back(val);
            }
            Matrix new_mat{vec, mat.row, mat.col};
            return new_mat;            
            } //unary

        // Comparison operators
        bool Matrix:: operator>(const Matrix &mat) const{

            if(!this->same_size(mat)) {
                throw std::invalid_argument("not same size >");
            }
 
            int sum_M=0; //sum all Matrix
            for(int i=0; i<this->mat.size(); i++){
                sum_M+= this->mat[(unsigned long)i];
            }
            int sum_m=0; //sum all matrix
            for(int i=0; i<this->mat.size(); i++){
                sum_m+= mat.mat[(unsigned long)i];
            }
            if (sum_M>sum_m){
                return (sum_M>sum_m);
            }
            return false;
        }
        bool Matrix:: operator>=(const Matrix &mat) const{
 
            if(!this->same_size(mat)) {
                throw std::invalid_argument("not same size >=");
            }
            
            bool eq1= true;
            for(int i=0; i<this->mat.size(); i++){ //for each element chack if equal
                if (this->mat[(unsigned long)i]!=mat.mat[(unsigned long)i]){
                    eq1= false;
                }
            }
            bool eq2= false;
            int sum_M=0; //sum all Matrix
            for(int i=0; i<this->mat.size(); i++){
                sum_M+= this->mat[(unsigned long)i];
            }
            int sum_m=0; //sum all matrix
            for(int i=0; i<this->mat.size(); i++){
                sum_m+= mat.mat[(unsigned long)i];
            }
            if (sum_M>sum_m){
                eq2= true;
            }

            if (eq2 || eq1){ //cheack bouth = and > 
                return (eq2 || eq1);
            }
            return false; //else
        }
        bool Matrix:: operator<(const Matrix &mat) const{
 
            if(!this->same_size(mat)) {
                throw std::invalid_argument("not same size <");
            }
            
            bool b= false;
            int sum_M=0; //sum all Matrix
            for(int i=0; i<this->mat.size(); i++){
                sum_M+= this->mat[(unsigned long)i];
            }
            int sum_m=0; //sum all matrix
            for(int i=0; i<this->mat.size(); i++){
                sum_m+= mat.mat[(unsigned long)i];
            }
            if (sum_M<sum_m){
                b= true;
            }
            return b;
        }
        bool Matrix:: operator<=(const Matrix &mat) const{

            if(!this->same_size(mat)) {
                throw std::invalid_argument("not same size <=");
            }
            
            bool eq1= true;
            for(int i=0; i<this->mat.size(); i++){ //for each element chack if equal
                if (this->mat[(unsigned long)i]!=mat.mat[(unsigned long)i]){
                    eq1= false;
                }
            }
            bool eq2= false;

            int sum_M=0; //sum all Matrix
            for(int i=0; i<this->mat.size(); i++){
                sum_M+= this->mat[(unsigned long)i];
            }
            int sum_m=0; //sum all matrix
            for(int i=0; i<this->mat.size(); i++){
                sum_m+= mat.mat[(unsigned long)i];
            }
            if (sum_M<sum_m){
                eq2= true;
            }

            if (eq2 || eq1){ //cheack bouth = and > 
                return (eq2 || eq1);
            }
            return false; //else
        }
        bool Matrix:: operator==(const Matrix &mat) const{

            if(!this->same_size(mat)) {
                throw std::invalid_argument("not same size ==");
            }
            
            for(int i=0; i<this->mat.size(); i++){ //for each element chack if equal
                if (this->mat[(unsigned long)i] != mat.mat[(unsigned long)i]){
                    return false;
                }
            }
            return true; //else
        }
        bool Matrix:: operator!=(const Matrix &mat) const{

            if(!this->same_size(mat)) {
                throw std::invalid_argument("not same size !=");
            }
             
            for(int i=0; i<this->mat.size(); i++){ //for each element chack if equal
                if (this->mat[(unsigned long)i]!=mat.mat[(unsigned long)i]){
                    return true;
                }
            }
            return false; //else
        }
        
        // ++ / --
        // const void Matrix:: operator++(){
        Matrix& Matrix:: operator++(){
            
            for (int i = 0; i < this->mat.size(); ++i) {
                this->mat[(unsigned long)i]++;
            }
            return *this;
        }
        Matrix& Matrix:: operator--(){
            
            for (int i = 0; i < this->mat.size(); ++i) {
                this->mat[(unsigned long)i]--;
            }
            return *this;
        }
        Matrix Matrix:: operator++ (int n){
            Matrix m= *this;
            for (int i = 0; i < this->mat.size(); ++i) {
                this->mat[(unsigned long)i]++;
            }
            return m;
        }
        Matrix Matrix:: operator-- (int n){
            Matrix m= *this;
            for (int i = 0; i < this->mat.size(); ++i) {
                this->mat[(unsigned long)i]--;
            }
            return m;
        }

        // scalar multiplication
        Matrix Matrix:: operator*(double scalar) {
            
            vector<double> vec;
            for (int i = 0; i < this->mat.size(); ++i) {
                double val=this->mat[(unsigned long)i]*scalar;
                vec.push_back(val);
            }
            Matrix new_mat{vec, this->row, this->col};
            return new_mat;
        }
        Matrix operator*(double scalar,const Matrix &mat){
            
            vector<double> vec;
            for (int i = 0; i < mat.mat.size(); ++i) {
                double val=mat.mat[(unsigned long)i]*scalar;
                vec.push_back(val);
            }
            Matrix new_mat{vec, mat.row, mat.col};
            return new_mat;
        }
        Matrix& Matrix:: operator*=(double scalar){

            vector<double> vec;
            for (int i = 0; i < this->mat.size(); ++i) {
                double val= this->mat[(unsigned long)i]*scalar;
                vec.push_back(val);
            }
            this->mat= vec;
            return *this;
        }

        // Matrix multiplication
        Matrix Matrix:: operator*(const Matrix &mat){
 
            if(this->col!=mat.row) {
                throw std::invalid_argument("not same size *");
            }
            
            vector<double> vec;
            double x=0;
            for (int i=0; i<this->row; i++){
                for (int j=0; j<mat.col; j++){
                    x=0;
                    for (int n=0; n<this->col; n++){
                        int a= this->col*i+n;//this->col
                        int b= n*mat.col+j;//mat.row
                        x+=(this->mat[(unsigned long)a] * mat.mat[(unsigned long)b]);
                        // cout<<this->mat[(unsigned long)a] * mat.mat[(unsigned long)b]<<","<<endl;
                    }
                    vec.push_back(x);
                    // cout<<"::"<<x<<endl;
                }
            }
            Matrix new_mat{vec, this->row, mat.col};
            return new_mat;
        }
        Matrix& Matrix:: operator*=(Matrix &mat){

            if(this->col!=mat.row) {
                throw std::invalid_argument("not same size *=");
            }
             
            vector<double> vec;
            double x=0;
            for (int j=0; j<this->row; j++){
                for (int i=0; i<mat.col; i++){
                    x=0;
                    for (int n=0; n<this->col; n++){
                        // int n=
                        int i1= (j*this->col+n);
                        int i2= (n*mat.row+i);
                        x+=this->mat[(unsigned long)i1]*mat.mat[(unsigned long)i2];
                    }
                    vec.push_back(x);
                }
            }
            // Matrix new_mat{vec, this->col, mat.row};
            this->mat= vec;
            return *this;
  
        }

        // Input and output operator
        std::ostream &operator<<(std::ostream &o, Matrix const &mat) {
            
            // std::string str="";
            // std::string r="";
            int r=0;
            for(int i=0; i<mat.row; i++){
                // r="[";
                o<<'[';
                for(int j=0; j<mat.col; j++){
                    // r+=to_string((int)mat.mat[(unsigned long)(i*mat.col+j)]);
                    int x=(i*mat.col+j);
                    o<<to_string((int)mat.mat[(unsigned long)x]);
                    if(j!=mat.col-1){
                        // r+= " ";
                        o<< ' ';
                    }
                }
                // r+="]\n";
                if (r<mat.row-1){
                    o<< "]\n";
                    r++;}
                else{
                    o<< "]";}
                
                // str = str+r; 
            }
            return o;
            
            }
        std::istream &operator>>(std::istream &in, Matrix &mat) {
            
            vector<double> v;
            int flag=0;
            int num=0;
            int row=1;

            std::string o;
            char c='-';
            char last='-';
            //"[1 1 1 1], [1 1 1 1], [1 1 1 1]"
            while (c != '\n'){
                last= c;
                c = in.get();
                if (last==','){
                    if (c!=' '){
                        throw std::invalid_argument("bad input cin1");
                    }
                }
                if (last==']' ||last=='['){
                    if (c==' '){
                        throw std::invalid_argument("bad input cin2");
                    }
                }
                // if (last==' '){
                //     if (c!='['|| !(isdigit(c)) ){
                //         throw std::invalid_argument("bad input cin3");
                //     }
                // }
                o += c;
            }

            for (int i=(int)o.length()-1; i>=0; i--){   
                c= o[(unsigned long)i];
                if(c==' ' || c==',' || c=='[' || c==']'){
                    if (flag!=0){
                        v.insert(v.begin(), num);
                    }
                    num=0;
                    flag=0;
                    if(c==','){
                        row++;
                    }
                }
                else{
                    if (flag!=0){
                        num+= flag*ten*int((unsigned char)c);
                    }
                    else{
                        num= int((unsigned char)c);
                    }
                    flag++;
                }
            }
            mat.mat=v;
            // int r=row;
            mat.col= (int)(v.size()/(unsigned long)row);
            mat.row= row;
            return in;
        }       

}