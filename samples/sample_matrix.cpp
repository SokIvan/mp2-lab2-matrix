// ННГУ, ИИТММ, Курс "Алгоритмы и структуры данных"
//
// Copyright (c) Сысоев А.В.
//
// Тестирование матриц

#include <iostream>
#include "tmatrix.h"
//---------------------------------------------------------------------------



void create_random_matrix(TDynamicMatrix<double> &M,int ran)
{
    srand(ran);
    for(size_t i = 0;i<M.size();i++)
        for (size_t j = 0; j < M.size(); j++)
        {
            M[i][j] = 100 + (rand() % 10000) / 10.0;
        }
}

void standart_test(TDynamicMatrix<double>& M1, TDynamicMatrix<double>& M2)
{
    
    int i, j;

    setlocale(LC_ALL, "Russian");
    cout << "Тестирование класс работы с матрицами"
        << endl;

    cout << "Matrix a = " << endl << M1 << endl;
    cout << "Matrix b = " << endl << M2 << endl;
    M2 = M1 + M2;
    cout << "Matrix c = a + b" << endl << M2 << endl;
}

void special_test(TDynamicMatrix<double> &M1, TDynamicMatrix<double> &M2)
{
    cout << "Matrix A\n" << M1 << "\nMatrix B\n" << M2 << endl;
    cout << "1)test A*B\n\nMatrix A*B\n" << M1 * M2 << endl;
    cout << "2)test A+B\n\nMatrix A+B\n" << M1 + M2 << endl;
    cout << "3)test A-B\n\nMatrix A-B\n" << M1 - M2 << endl;
}

void choice_test(const int &ch, TDynamicMatrix<double>& M1, TDynamicMatrix<double>& M2)
{
    if (ch == 1)
    {
        standart_test(M1, M2);
    }
    else if (ch == 2)
    {
        special_test(M1, M2);
    }
}

void choice_matrix(const int& ch, TDynamicMatrix<double>& M,int ran)
{
    if (ch == 1)
    {
        cout << "\nSet matrix:\n";
        cin >> M;
    }
    else if (ch == 2)
    {
        create_random_matrix(M,ran);
    }
}
void choice_matrix_and_test(const int& ch1, const int& ch2, const int& ch3,int n)
{
    TDynamicMatrix<double> M1(n),M2(n);
    choice_matrix(ch1, M1,5326);
    choice_matrix(ch2, M2,9083);
    cout << "\nSTARTING TEST:\n\n";
    choice_test(ch3, M1, M2);
}










void main()
{
    int ch1, ch2, ch3,size;
    cout << "Change size of Matrixs:\n\n1)Your size(input '1')\n2)Random size(input '2')\n";
    cin >> size;
    if (size == 1)
    {
        cout << "\nInput size: ";
        cin >> size;
    }
    else if (size == 2)
    {
        srand(204);
        size = 3+rand() % 98;
    }
    cout << "Choice matrix1:\n\n1)Your Matrix(input '1')\n2)Random Matrix(input '2')\n\n";
    cin >> ch1;
    cout << "Choice matrix2:\n\n1)Your Matrix(input '1')\n2)Random Matrix(input '2')\n\n";
    cin >> ch2;
    cout << "Choice test method:\n\n1)Standart test(input '1')\n2)Special test(input '2')\n\n";
    cin >> ch3;
    
    choice_matrix_and_test(ch1, ch2, ch3,size);
}
//---------------------------------------------------------------------------
