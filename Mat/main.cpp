#include <bits/stdc++.h>
#include"Matrix.h"
using namespace std;
template <typename T>
inline ostream &operator<< (ostream &out , Matrix<T> mat){
    for(int i=0;i<mat.getSize();++i){
        if (i%mat.getCol()==0 && i!=0 ) out<<endl;    //endl if its the last element in the row
        out<<mat.getData(i)<<" ";
    }
    return out;
}
template <typename T>
inline istream& operator>> (istream& in, Matrix<T>& mat)
{
    int row,col;
    valarray<int>data;
    cout<<"enter rows number : ";
    cin>>row;
    mat.setRow(row);
    cout<<"enter columns number : ";
    cin>>col;
    mat.setCol(col);
    mat.setSize(row*col);
    data.resize(row*col);
    cout<<"enter your matrix \n";
    for (int i=0;i<mat.getSize();i++)
    {
        in >> data[i];
    }
    mat.setData(data);
    return in;
}

int main()
{
  int data1 [] = {1,2,3,4,5,6,7,18};
  int data2 [] = {13,233,3,4,5,6,7,8};
  int data3 [] = {1,2,3,4,5,6,7,18};
  int data4 [] = {1,0,0,
                  0,1,0,
                  0,0,1};
  float data5[]={1.1,1.2,1.3,1.4,1.5,1.6};
  Matrix<float> m5(2,3,data5);
  cout<<"M5 >>>> "<<m5<<endl;
  Matrix<int> mat1(4,2,data1), mat2(2,4,data2), mat3(2,4,data3) ;
  Matrix<int> mat4;
  mat4.setRow(3);
  mat4.setCol(3);
  mat4.setSize(3*3);
  mat4.setData(data4);
  cout<<"mat1\n"<<mat1<<"\nmat2\n"<<mat2<<"\nmat3\n"<<mat3<<"\nmat4\n"<<mat4<<endl;
  cout<<"3+2\n"<<(mat3+mat2)<<endl;
  mat3+=mat2;
  cout<<"3+=2\n"<<mat3<<endl;
  cout<<"1*2\n"<<mat1*mat2<<endl;
  mat1++;
  cout<<"1++\n"<<mat1<<endl;
  mat1--;
  cout<<"1--\n"<<mat1<<endl;
  cout<<"4 square\n"<<mat4.isSquare()<<endl;
  cout<<"4 identity\n"<<mat4.isIdentity()<<endl;
  cout<<"4 trans\n"<<mat4.transpose()<<endl;
  cout<<"4 symmetric\n"<<mat4.isSymetric()<<endl;

  cout<<"3 square\n"<<mat3.isSquare()<<endl;
  cout<<"3 identity\n"<<mat3.isIdentity()<<endl;
  cout<<"3 trans\n"<<mat3.transpose()<<endl;
  cout<<"3 symmetric\n"<<mat3.isSymetric()<<endl;


  return 0;

}
