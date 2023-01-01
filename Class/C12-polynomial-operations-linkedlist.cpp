#include <iostream>
#include <cstdlib>
#include <math.h>
using namespace std;

struct polynomial
{
    int coef, exp;
    struct polynomial *right, *left;
};

class poly
{
public:
    struct polynomial *start, *last, *temp;

    poly();
    void ReadPoly();
    void PrintPoly();
    long int EvaluatePoly();
    void DeletePoly();
    void AddPoly(poly Poly, poly Result);
    void MultiPoly(poly Poly, poly Result);
};

poly::poly()
{
    start = new struct polynomial;
    start -> right = NULL;
    start -> left = NULL;
    last = start;
}

void poly::ReadPoly()
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

void poly::PrintPoly()
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
long int poly::EvaluatePoly()
{
    int x;
    cout << "Enter x: " << endl;
    cin >> x;

    struct polynomial *temp;
    long int sum = 0;
    for (temp = start -> right; temp != NULL; temp = temp -> right)
    {
        sum += temp -> coef * pow(x, temp -> exp);
    }
    return sum;
}

void poly::DeletePoly()
{
    polynomial *temp;
    while (start != NULL)
    {
        temp = start;
        start = start -> right;
        free(temp);
    }
}

void poly::AddPoly(poly p, poly r)
{
    if (start == NULL && p.start == NULL)
    {return;}

    temp = start -> right;
    p.temp = p.start -> right;

    do
    {
        // create new node for result.
        r.temp = new struct polynomial;
        r.temp -> right = NULL;
        r.temp -> left = r.last;
        
        // insert to end of result.
        r.last -> right = r.temp;
        r.last = r.temp;

        if (temp -> exp == p.temp -> exp)
        {
            r.temp -> coef = temp -> coef + p.temp -> coef;
            r.temp -> exp = temp -> exp;

            // change nodes
            temp = temp -> right;
            p.temp = p.temp -> right;
            r.temp = r.temp -> right;
        }

        else
        {
            if(temp -> exp > p.temp -> exp)
            {
                r.temp -> exp = temp -> exp;
                r.temp -> coef = temp -> coef;
                temp = temp -> right;
                r.temp = r.temp -> right;
            }

            else
            {
                r.temp -> exp = p.temp -> exp;
                r.temp -> coef = p.temp -> coef;
                p.temp = p.temp -> right;
                r.temp = r.temp -> right;
            }
        }
    } while (temp != NULL && p.temp != NULL);
    
}

void poly::MultiPoly(poly p, poly r)
{
    if (start == NULL && p.start == NULL)
    {return;}

    int ex, co;
    struct polynomial *bp, *q;

    for (temp = start -> right; temp != NULL; temp = temp -> right)
    {
        for(p.temp = p.start -> right; p.temp != NULL; p.temp = p.temp -> right)
        {
            ex = (temp -> exp) + (p.temp -> exp);
            co = (temp -> coef) * (p.temp -> coef);

            // iterate for an element with bigger exp to fit ex before it
            for (r.temp = r.start -> right; r.temp != NULL && r.temp -> exp > ex; r.temp = r.temp -> right);

            if (r.temp != NULL) // if found
            {
                if ((r.temp -> left) -> exp == ex)               
                {
                    (r.temp -> left) -> coef += co;
                }

                else // ex is lower so it should be inserted before temp
                {
                    bp = r.temp -> left;

                    q = new struct polynomial;
                    q -> coef = co;
                    q -> exp = ex;
                
                    bp -> right = q;
                    q -> left = bp;

                    q -> right = r.temp;
                    r.temp -> left = q;
                }
            }

            else // if didn't found
            {
                // create new node to add at the end of result
                r.temp = new struct polynomial;
                r.temp -> coef = co;
                r.temp -> exp = ex;

                r.temp -> right = NULL;
                r.temp -> left = r.last;

                r.last -> right = r.temp; 
                r.last = r.temp;
            }
        }
    }
}

int main()
{
    poly poly1 = poly();
    poly poly2 = poly();
    poly sum = poly();
    poly multi = poly();

    cout << "Enter first poly: " << endl;
    poly1.ReadPoly();
    cout << "Enter second poly: " << endl;
    poly2.ReadPoly();

    cout << "Elements of first polynomial is: " << endl;
    poly1.PrintPoly();
    cout << "Elements of second polynomial is: " << endl;
    poly2.PrintPoly();

    poly1.AddPoly(poly2, sum);
    cout << "Elements of sum polynomial is: " << endl; 
    sum.PrintPoly();

    poly1.MultiPoly(poly2, multi);
    cout << "Elements of multi polynomial is: " << endl;
    multi.PrintPoly();

    // free all the polynomials
    poly1.DeletePoly();
    poly2.DeletePoly();
    sum.DeletePoly();
    multi.DeletePoly();

    // to make sure they are free
    // poly1.PrintPoly();
    // poly2.PrintPoly();
    // sum.PrintPoly();
    // multi.PrintPoly();

    return 0;
}