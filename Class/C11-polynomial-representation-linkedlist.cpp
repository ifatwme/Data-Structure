#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <math.h>
using namespace std;

struct polynomial
{
    int coef, exp;
    struct polynomial *right, *left;
}*start, *last;

void ReadPoly()
{
    int co, ex = 0;
    struct polynomial *temp;

    do 
    {
        cout << "Enter coef: ";
        cin >> co;
        cout << "Enter exp: ";
        cin >> ex;

        if (ex >= 0)
        {
            // create node
            temp = new struct polynomial;
            temp -> coef = co;
            temp -> exp = ex;

            // insert node
            temp -> right = NULL;
            temp -> left = last;
            last -> right = temp;
            last = temp;
        }
    } while (ex != 0); // if enter 0 then exit loop.
}

// void writepoly
void PrintPoly()
{
    if (start == NULL)
    {
        cout << "Polynomial does not exist!" << endl;
        return;
    }
    struct polynomial *temp;
    // iterate left to right
    for (temp = start -> right; temp != NULL; temp = temp -> right )
    {
        if (temp -> coef > 0)
        {
            cout << " + " << temp -> coef << " x^ " << temp -> exp;
        }
        else if (temp -> coef < 0)
        {
            cout << " " << temp -> coef << " x^ " << temp -> exp;
        }
    }
    cout << endl;
}

// what if we gave it a real number instead of x...
long int Evaluatepoly(int x)
{
    struct polynomial *temp;
    long int sum = 0;
    for (temp = start -> right; temp != NULL; temp = temp -> right)
    {
        sum += temp -> coef * pow(x, temp -> exp);
    }
    return sum;
}

void DeletePoly()
{
    polynomial *temp;
    while (start != NULL)
    {
        temp = start;
        start = start -> right;
        free(temp);
    }
}

int main()
{
    start = new struct polynomial;
    start -> right = NULL;
    start -> left = NULL;
    last = start;

    ReadPoly();

    cout << "The elements of your polynomial is: " << endl;
    PrintPoly();

    DeletePoly();

    PrintPoly();

    return 0;
}