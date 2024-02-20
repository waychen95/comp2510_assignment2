#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x;
    int y;
    int vx;
    int vy;
} Particle;

void simulate(char ***arr, int x, int y)
{

  //allocate memory for 
  char **newArr = (char **)malloc(x * y * sizeof(char *));

  for (int i = 0; i < x; i++)
  {
      newArr[i] = (char *)malloc(y * sizeof(char));
  }

  //create the border
  for (int i = 0; i < x; i++)
  {
      for (int j = 0; j < y; j++)
      {
          if (i == 0 || i == x - 1 || j == 0 || j == y- 1)
          {
              newArr[i][j] = '*';
          }
          else
          {
              newArr[i][j] = ' ';
          }
      }
  }

  //free the memory of the border
  for (int i = 0; i < x; i++)
  {
      free((*arr)[i]);
  }
  free(*arr);

  *arr = newArr;
}

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("Usage: %s <input_file> <output_file\n", argv[0]);
        return 1;
    }

    char *inputFileName = argv[1];
    char *outputFileName = argv[2];

    int rows, cols, time;

    FILE *file = fopen(inputFileName, "r");
    if (file == NULL)
    {
        perror("Error opening input file");
        return 1;
    }

    // Read the row value
    fscanf(file, "%d", &rows);
    // Read the column value
    fscanf(file, "%d", &cols);
    // Read the 
    fscanf(file, "%d", &time);

    // Allocate memory for the 2D array
    char **arr = (char **)malloc(rows * sizeof(char *));
    if (arr == NULL)
    {
        printf("Memory allocation failed.\n");
        return 1;
    }
    for (int i = 0; i < rows; i++)
    {
        arr[i] = (char *)malloc(cols * sizeof(char));
        if (arr[i] == NULL)
        {
            printf("Memory allocation failed.\n");
            return 1;
        }
    }

    //the size of the border
    int borderRows = rows + 2;
    int borderCols = cols + 2;

    simulate(&arr, rows, cols);

    FILE *outputFile = fopen(outputFileName, "w");
    if (outputFile == NULL)
    {
        perror("Error opening output file");
        return 1;
    }

    for (int i = 0; i < rows + 2; i++)
    {
        for (int j = 0; j < cols + 2; j++)
        {
            fprintf(outputFile, "%c", arr[i][j]);
        }
        fprintf(outputFile, "\n");
    }

    fclose(outputFile);

    // Free memory
    for (int i = 0; i < rows + 2; i++)
    {
        free(arr[i]);
    }
    free(arr);

    return 0;
}