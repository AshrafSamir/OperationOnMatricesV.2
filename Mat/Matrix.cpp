#include "Matrix.h"

template <typename T>
Matrix<T>::Matrix(int row, int col, T num[])
{
    this->row = row;
    this->col = col;
    this->data.resize (row * col);
    for (int i = 0; i < row * col; i++)
    this->data [i] = num [i];
}
template <typename T>
Matrix<T>::Matrix()
{

}
template <typename T>
void Matrix<T>::setRow(int row){
    this->row=row;
}
template <typename T>
void Matrix<T>::setCol(int col){
    this->col=col;
}
template <typename T>
void Matrix<T>::setData(T data[]){
    this->data.resize(row*col);
    for(int i=0;i<this->data.size();++i){
        this->data[i]=data[i];
    }
}
template <typename T>
void Matrix<T>::setData(valarray<T> data){
    this->data.resize(data.size());
    this->data=data;
}
template <typename T>
int Matrix<T>::getRow(){
    return row;
}
template <typename T>
int Matrix<T>::getCol(){
    return col;
}
template <typename T>
T Matrix<T>::getData(T num){
    return data[num];
}
template <typename T>
valarray<T> Matrix<T>::getData(){
    return data;
}
template <typename T>
int Matrix<T>::getSize(){
    return data.size();
}
template <typename T>
void Matrix<T>::setSize(int siz){
    data.resize(siz);
}
template <typename T>
Matrix<T> Matrix<T>::operator+  (Matrix mat2){
        Matrix tmp;
    if (row==mat2.row && col==mat2.col){
        tmp.col=col;
        tmp.row=row;
        tmp.data.resize(data.size());
        for(int i=0;i< row * col ;++i){
            tmp.data[i]=data[i]+mat2.data[i]; // put the addition in the tmp Matrix
        }
    }
    else{
        cout<<"the dimensions of tow matrices are not equal\n";     // if the tow dimensions not equal return Matrix with
        tmp.col=1,tmp.row=1;                                        // 1 element equal to 0
        tmp.data.resize(1);
        tmp.data[0]=0;
    }
    return tmp;
}

//subtract every element of the first Matrix from the other one in the second Matrix
template <typename T>
Matrix<T> Matrix<T>::operator-  ( Matrix mat2){
        Matrix tmp;
    if (row==mat2.row && col==mat2.col){
        tmp.col=col;
        tmp.row=row;
        tmp.data.resize(data.size());
        for(int i=0;i< row * col ;++i){
            tmp.data[i]=data[i]-mat2.data[i];  //put the subtract in the tmp Matrix
        }
    }
    else{
        cout<<"the dimensions of tow matrices are not equal\n";     // if the tow dimensions not equal return Matrix with
        tmp.col=1,tmp.row=1;                                        // 1 element equal to 0
        tmp.data.resize(1);
        tmp.data[0]=0;
    }
    return tmp;
}

//multiple tow matrices if the 1st column = the second row
template <typename T>
Matrix<T> Matrix<T>::operator*  ( Matrix mat2){
        Matrix tmp;
    if(col==mat2.row){
        tmp.col=mat2.col,tmp.row=row;
        tmp.data.resize(row*mat2.col);
        for(int i=0;i<tmp.data.size();++i){             // loop over the tmp Matrix
            int tmp2=0;
                for(int k=(i/tmp.col)*col;k<(i/tmp.col)*col+col;++k){ //loop over every row in the 1st Matrix
                    tmp2+=data[k]*mat2.data[i%tmp.col+(k%mat2.row)*mat2.col];  //equation to multiple matrices
                }                                                                  //i%col to determine the column in the 2nd Matrix
                                                                                  //(k%row)*col to determine the row in the 2bd Matrix
            tmp.data[i]=tmp2;               //put the value in the Matrix
        }
    return tmp;
    }
   else{
        cout<<"can't multiple matrices\n";                  // if the tow dimensions not equal return Matrix with
        tmp.col=1,tmp.row=1;                                // 1 element equal to 0
        tmp.data.resize(1);
        tmp.data[0]=0;
    }
    return tmp;
}

//add number to every element of the Matrix
template <typename T>
Matrix<T> Matrix<T>::operator+  ( T scalar){
    Matrix tmp;
    tmp.col=col;
    tmp.row=row;
    tmp.data.resize(data.size());
    for(int i=0;i<row * col;++i){
        tmp.data [i]+=scalar;           // add each element to the scalar
    }
    return tmp;
}

//subtract number from all the Matrix elements
template <typename T>
Matrix<T> Matrix<T>::operator-  ( T scalar){
    Matrix tmp;
    tmp.col=col;
    tmp.row=row;
    tmp.data.resize(data.size());
    for(int i=0;i<row * col;++i){
        tmp.data [i]-=scalar;       //subtract each element from the scalar
    }
    return tmp;
}

//multiple number with each number of the Matrix
template <typename T>
Matrix<T> Matrix<T>::operator*  ( T scalar){
    Matrix tmp;
    tmp.col=col;
    tmp.row=row;
    tmp.data.resize(data.size());
    for(int i=0;i<row * col;++i){
        tmp.data [i]*=scalar;           // multiple each element in the scalar
    }
    return tmp;
}

//____________________________________

// Printing out an array of data


// Taking 2 Matrix and adding the second one to the first keeping in mind
// that the change would be in the first Matrix
template <typename T>
Matrix<T> Matrix<T>::operator+= ( const Matrix &mat2)
{
    if (row==mat2.row && col ==mat2.col ){
            Matrix tmp;
        for (int i=0;i<mat2.row*mat2.col;i++)
        {
            data[i] += mat2.data[i];
        }
    tmp.row=row;
    tmp.col=col;
    tmp.data.resize(data.size());
    tmp.data=data;
    return tmp;
    }
    else {
        cout << "Can't be added Because the size of two array isn't equal each others." << endl;

    }

}

// Taking 2 Matrix and subtract the first one to the second keeping in mind
// that the change would be in the first Matrix
template <typename T>
Matrix<T> Matrix<T>::operator-= (const Matrix& mat2)
{
    if (row*col == mat2.row*mat2.col ){
            Matrix tmp;
        for (int i=0;i<mat2.row*mat2.col;i++)
        {
            data[i] -= mat2.data[i];
        }
    tmp.row=row;
    tmp.col=col;
    tmp.data.resize(data.size());
    tmp.data=data;
    return tmp;
    }
    else {
        cout << "Can't be added Because the size of two array isn't equal each others." << endl;

    }
}

// Taking 1 Matrix and adding a number to it
template <typename T>
Matrix<T> Matrix<T>::operator+= (T scalar)
{
    Matrix tmp;
    data+=scalar;
    tmp.row=row;
    tmp.col=col;
    tmp.data.resize(data.size());
    tmp.data=data;
    return tmp;
}

// Taking 1 Matrix and subtract a number from it
template <typename T>
Matrix<T> Matrix<T>::operator-= (T scalar)
{
    Matrix tmp;
    data-=scalar;
    tmp.row=row;
    tmp.col=col;
    tmp.data.resize(data.size());
    tmp.data=data;
    return tmp;
}
template <typename T>
Matrix<T> Matrix<T>::operator++ (int)
{
    for(int i=0;i<this->data.size();++i)
        this->data[i]++;
    return *this;

}

// Subtract one from the elements of the Matrix
template <typename T>
Matrix<T> Matrix<T>::operator-- (int)
{
    for(int i=0;i<this->data.size();++i)
        this->data[i]--;
    return *this;
}



//______________________________________________
template <typename T>
bool Matrix<T>::operator== ( Matrix<T> mat2){
    if((row==mat2.row) && (col==mat2.col)){
          for (int i = 0; i < data.size(); i++)
                if(data[i]!=mat2.data[i]) return 0; //compare between every element of the 2 matrices return 0 if not equal
    }
    else return 0;
    return 1;
}
template <typename T>
bool Matrix<T>::operator!= ( Matrix<T> mat2){
    if((row==mat2.row) && (col==mat2.col)){
          for (int i = 0; i < row * col; i++)
                if(data[i]==mat2.data[i]) return 0;//compare between every element of the 2 matrices return 0 if equal
    }
    return 1;
}
template <typename T>
bool Matrix<T>::isSquare   (){
    if(row==col) return 1;  // check if column = row or not
    else return 0;
}
template <typename T>
bool Matrix<T>::isSymetric (){
    if(row==col){
        int counter = 0;
        for (int i =0; i<row; i++)
        {
            for (int j=0; j<col; j++)
            {
                if(j <= i){             //skip the visited element
                    counter++;
                    continue;
                }
                if(data[counter]!=data[row*j+i]) return 0;  //compare between element and its symmetric
                counter++;                                              // if not equal return 0
            }
        }
    }
    else return 0;
    return 1;
}
template <typename T>
bool Matrix<T>::isIdentity (){
    int counter=0;
    if(row==col){
        if(data[0]!=1) return 0;
        for(int i=1;i<data.size();++i){
            if(i==col+1+counter){           //check if the main diameter equal to 1 or no
                if(data[i]!=1)
                    return 0;
                counter+=col+1;
            }
            else if(data[i]!=0) return 0;   // check the other elements if equal to 0 or no

        }
    }
    else return 0;
    return 1;
}
template <typename T>
Matrix<T> Matrix<T>::transpose()
{
    Matrix tmp;
    tmp.col=row;
    tmp.row=col;
    tmp.data.resize(data.size());
    int counter = 0;

    for (int i =0; i<col; i++)
    {
        for (int j=0; j<row; j++)
        {
            tmp.data[counter]=data[col*j+i];    //transpose the Matrix counter is the element in the transposed Matrix
            counter++;
        }
    }
    return tmp;
}
template <typename T>
Matrix<T>::~Matrix()
{
    //dtor
}
template class Matrix<int>;
template class Matrix<double>;
template class Matrix<float>;
