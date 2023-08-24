#include <stdio.h>
int main()
{
    int rows, col;
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &col);
    int matrix[rows][col];
    printf("Enter the matrix elements:\n");
    for (int i = 0; i < rows; i++)
	{
        for (int j = 0; j < col; j++)
		{
            scanf("%d", &matrix[i][j]);
        }
    }
    int largest = matrix[0][0];
    for (int i = 0; i < rows; i++)
	{
        for (int j = 0; j < col; j++)
		{
            if (matrix[i][j] > largest)
			{
                largest = matrix[i][j];
            }
        }
    }
    printf("The largest element in the matrix is: %d\n", largest);
    return 0;
}
