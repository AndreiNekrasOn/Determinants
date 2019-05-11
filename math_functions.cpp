#include <math_functions.h>
#include<math.h>

int **convertQTableToMatrix(QTableWidget *qtable)
{
    int **matrix = new int*[qtable->rowCount()];
    for(int i = 0; i < qtable->rowCount(); i++)
        matrix[i] = new int[qtable->columnCount()];
    for(int i = 0; i < qtable->rowCount(); i++)
    {
        for(int j = 0; j < qtable->columnCount(); j++)
        {
            matrix[i][j] = qtable->item(i, j)->text().toInt();
        }
    }
    return matrix;
}

int determinant(int **matrix, int n) {
   if (n == 2)
      return ((matrix[0][0] * matrix[1][1]) - (matrix[1][0] * matrix[0][1]));
   int det = 0;
   int **submatrix = new int*[n];
   for(int i = 0; i < n; i++)
       submatrix[i] = new int[n];

   for (int x = 0; x < n; x++)
   {
       int subi = 0;
       for (int i = 1; i < n; i++)
       {
          int subj = 0;
          for (int j = 0; j < n; j++)
          {
             if (j == x)  continue;
             submatrix[subi][subj] = matrix[i][j];
             subj++;
          }
          subi++;
       }
       det = det + int((pow(-1, x) * matrix[0][x] * determinant( submatrix, n - 1 ))); //added int() to stop ide warning me

   }

   for(int i = 0; i < n; i++)
       delete submatrix[i];
   delete[] submatrix;
   return det;
}


