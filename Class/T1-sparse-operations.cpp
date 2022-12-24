#include <iostream>

using namespace std;

#define length 5
#define col 4

int len;

// Read a matrix.
int ReadMatrix(int a[][col], int n, int m)
{
    cout << "Please enter a matrix of size " << n << " * " << m <<endl;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }
    return a[n][m];
}

// Print your matrix.
void PrintMatrix(int a[][col], int n, int m)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }
}

//Array representation of sparse matrix is as follows:
// [][0] represents row
// [][1] represents column
// [][2] represents value
int SparseMatrix(int a[][col], int sparse[length][3], int n, int m)
{
    len = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(a[i][j] != 0)
            {
                //Insert row
                sparse[len][0] = i;

                //Insert col
                sparse[len][1] = j;

                //Insert value
                sparse[len][2] = a[i][j];

                //Increase the length number of non zero elements.
                len++;
            }
        }
    }
    return sparse[len][3];
}

void PrintSparseMatrix(int sparse[length][3], int len)
{
    cout << "Sparse matrix with size of " << len << " * 3" <<endl;
    cout << "Row Column Value" <<endl;

    for(int i = 0; i < len; i++)
    {
        cout << sparse[i][0] << "  " << sparse[i][1] << "  " << sparse[i][2] <<endl;
    }
}

int main()
{
    int a[3][col], sparse[length][3], m, n;

    cout << "Please enter dimension of your matrix: " <<endl;
    cout << "rows: ";
    cin >> n;
    cout << "cols: ";
    cin >> m;

    // Read and then print your matrix.
    ReadMatrix(a, n, m);
    PrintMatrix(a, n, m);

    // Iterate through the matrix and insert every non zero elements in sparse matrix.
    SparseMatrix(a, sparse, n, m);
    PrintSparseMatrix(sparse, len);
    return 0;
}
