#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x;
    int y;
    int vx;
    int vy;
    int colided;
} Particle;

void updateGrid(char ***arr, int x, int y, Particle *parr, int count)
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
          if (i == 0 || i == x - 1 || j == 0 || j == y - 1)
          {
              newArr[i][j] = '*';
          }
          else
          {
              newArr[i][j] = ' ';
          }
      }
  }

  for (int p = 0; p < count && parr[p].colided != 1; p++) {
    newArr[parr[p].y + 3][parr[p].x + 1] = '+';
  }

  *arr = newArr;
}

// call this function in a for loop for each second the simulation runs.
void moveParticles(Particle *arr, int length, int gridLengthx, int gridLengthy) {
  // Move particles
  for (int j = 0; j < length && arr[j].x != -1; j++) {
      arr[j].x += arr[j].vx;
      arr[j].y += arr[j].vy;

      // Handle border bouncing
      if (arr[j].x <= 0 || arr[j].x >= gridLengthx - 1) {
          arr[j].vx *= -1;
      }
      if (arr[j].y <= 0 || arr[j].y >= gridLengthy - 1) {
          arr[j].vy *= -1;
      }
  }

  // Check for collisions
  for (int j = 0; j < length && arr[j].x != -1; j++) {
      for (int k = j + 1; k < length && arr[k].x != -1; k++) {
          if (arr[j].x == arr[k].x && arr[j].y == arr[k].y) {
              arr[j].x = arr[k].x = -1;
              break;
          }
      }
  }
}

Particle makeParticle(int x, int y, int vx, int vy){
  Particle temp;
  temp.x = x;
  temp.y = y;
  temp.vx = vx;
  temp.vy = vy;
  temp.colided = 0;
  return temp;
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
    Particle particles[1000];

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

    int particle_count = 0;
    while (fgetc(file) != 'E' && fscanf(file, "%d, %d, %d, %d", &particles[particle_count].x, &particles[particle_count].y, &particles[particle_count].vx, &particles[particle_count].vy) == 4) { 
      particles[particle_count].colided = 0;
      particle_count++;
    }

    for (int i = 0; i < particle_count; i++) {
      printf("%d", particles[i].x);
      printf("%d", particles[i].y);
      printf("%d", particles[i].vx);
      printf("%d\n", particles[i].vy);
    }

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

    for (int i = time; i > 0; i--) {
      moveParticles(particles, particle_count, cols, rows);
    }

    updateGrid(&arr, borderRows, borderCols, particles, particle_count);

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