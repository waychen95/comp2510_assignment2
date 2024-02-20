#include <stdio.h>
#include <stdlib.h>

#define MAX_PARTICLES 1000

typedef struct {
    int x;
    int y;
    int vx;
    int vy;
} Particle;

void simulate() {

}

int main(int argc, char *argv[]) {

  if (argc != 3) {
    printf("Usage: %s <input_file> <output_file\n", argv[0]);
    return 1;
  }

  char *inputFileName = argv[1];
  char *outputFileName = argv[2];

  int width, height, simulation_time;

  simulate();

  return 0;
}