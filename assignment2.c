#include <stdio.h>

typedef struct {
    int x;
    int y;
    int vx;
    int vy;
} Particle;

void simulate(char **arr, int rows, int cols, int t) {

  char **newArr = (char **)malloc(rows * cols * sizeof(char *));
  
  for (int i = 0; i < rows; i++) {
      newArr[i] = (char *)malloc(cols * sizeof(char));
  }

  for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
          if (i == 0 || i == -1 || j == 0 || j == -1) {
              newArr[i][j] = '*';
          }
      }
  }


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

  rows += 2;
  cols += 2;

  simulate();



}