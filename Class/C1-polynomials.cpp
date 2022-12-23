#include <iostream>
#include <cmath>

using namespace std;

void ReadPoly1(int a[], int n)
{
    for(int i = n; i >= 0; i--)
    {
        cout << "enter coefficient of the a["<< i <<"]" << endl;
        cin >> a[i];
    }
}

long int EvaluatePoly1(int a[], int n, int x)
{
    long int sum = 0;
    for(int i = 0; i < n; i++)
    {
        sum += a[i] * pow(x, i);
    }
    return sum;
}

void AddPoly1(int a[], int b[], int s[], int n)
{
    for(int i = 0; i <= n; i++)
    {
        s[i] = b[i] + a[i]; //Adding up two Polynomials.
    }
}

void MultiPoly1(int a[], int b[], int m[], int n1, int n2)
{
    cout<<endl;
    for(int i = 0; i <= n1; i++)
    {
        for(int j = 0; j <= n2; j++)
        {
            m[i+j] = a[i] * b[j]; //Multiplying two Polynomials.
        }
    }
    cout<<endl;
}

void PrintPoly1(int a[], int n)
{
    cout<<endl;
    for(int i = n; i >= 0; i--)
    {
        if(a[i] > 0)
            cout << "+" << a[i] << "x^" << i;
        else
            cout << a[i] << "x^" << i;
    }
    cout<<endl;
}

int main()
{
    int a[21], b[21], s[41], m[41]; //Initializing the arrays.

    cout << "Here we calculate the sum and product of two polynomials!" << endl;
    cout << "Please enter first polynomial: " << endl;
    ReadPoly1(a, 2);
    cout << "Please enter second polynomial: " << endl;
    ReadPoly1(b, 2);

    //Adding up two polynomials.
    AddPoly1(a, b, s, 2);

    //Multiplying two polynomials.
    MultiPoly1(a, b, s, 2, 2);

    //Printing the answers
    cout << "Sum is: ";
    PrintPoly1(s, 2);
    cout << "Product is: ";
    PrintPoly1(m, 6);

    return 0;
}
