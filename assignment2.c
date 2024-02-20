#include <stdio.h>

void simulate(char arr, int x, int y, int t) {

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
  char **arr = NULL;

  int rows, cols, time;

  FILE *file = fopen(inputFileName, "r");
  if (file == NULL) {
    perror("Error opening input file");
    return 1;
  }

  // Read the row value
  fscanf(file, "%d", &rows);
  // Read the column value
  fscanf(file, "%d", &cols);
  // Read the zoom factor
  fscanf(file, "%f", &time);

  // Allocate memory for the 2D array
  arr = (char **)malloc(rows * sizeof(char *));
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





}