#include "pch.h"

using namespace System;

void generateMatr(array<int, 2>^ p, int n, int m, Random^ generator)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            p[i, j] = generator->Next(1, 100);
        }

    }
};

array<int >^ creatArrayMin(array<int, 2>^ p, int n, int m) {

    array<int >^ r = gcnew array<int>(n);

    for (int i = 0; i < n; i++)
    {
        int min = 1000000;
        for (int j = 0; j < m; j++)
        {
            if (p[i, j] < min)
                min = p[i, j];
        }
        r[i] = min;
    }
    return r;
};

void printArr(array<int >^ r)
{
    for (int i = 0; i < r->Length; i++)
        Console::Write(L"{0} ", r[i]);
};

void printMatr(array<int, 2>^ p, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            Console::Write("{0,3} ", p[i, j]);
        }
        Console::WriteLine();
    }
};

void interfase()
{

    int n = 3;
    int m = 6;
    array<int, 2>^ p = gcnew array<int, 2>(n, m);
    array<int, 2>^ q = gcnew array<int, 2>(n, m);

    Random^ generator = gcnew  Random();

    generateMatr(p, n, m, generator);
    generateMatr(q, n, m, generator);

    array<int >^ r = creatArrayMin(p, n, m);
    array<int >^ t = creatArrayMin(q, n, m);

    Console::WriteLine("Массив r");
    printArr(r);
    Console::WriteLine();
    Console::WriteLine("Массив t");
    printArr(t);

    Console::WriteLine();
    Console::WriteLine();

    Console::WriteLine("Матрица p");
    printMatr(p, n, m);
    Console::WriteLine();
    Console::WriteLine("Матрица p");
    printMatr(q, n, m);
};


int main(array<System::String^>^ args)
{
    interfase();

    return 0;
}