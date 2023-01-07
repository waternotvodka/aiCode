#include <stdio.h>
#include <stdlib.h>

#define N_ROWS 10
#define N_COLS 10
#define N_GENS 10

// Function prototypes
void init_grid(int grid[N_ROWS][N_COLS]);
void print_grid(int grid[N_ROWS][N_COLS]);
void update_grid(int grid[N_ROWS][N_COLS]);
int get_neighbor_count(int grid[N_ROWS][N_COLS], int row, int col);

int main(int argc, char** argv) {
  int grid[N_ROWS][N_COLS];
  init_grid(grid);

  for (int g = 0; g < N_GENS; g++) {
    printf("Generation %d:\n", g + 1);
    print_grid(grid);
    update_grid(grid);
  }

  return 0;
}

// Initializes the grid with random values
void init_grid(int grid[N_ROWS][N_COLS]) {
  for (int row = 0; row < N_ROWS; row++) {
    for (int col = 0; col < N_COLS; col++) {
      grid[row][col] = rand() % 2;
    }
  }
}

// Prints the grid to the console
void print_grid(int grid[N_ROWS][N_COLS]) {
  for (int row = 0; row < N_ROWS; row++) {
    for (int col = 0; col < N_COLS; col++) {
      printf("%c", (grid[row][col]) ? '#': ' ');
    }
    printf("\n");
  }
  printf("\n");
}

// Updates the grid based on the rules of the Game of Life
void update_grid(int grid[N_ROWS][N_COLS]) {
  int new_grid[N_ROWS][N_COLS];

  for (int row = 0; row < N_ROWS; row++) {
    for (int col = 0; col < N_COLS; col++) {
      int neighbors = get_neighbor_count(grid, row, col);

      if (grid[row][col] == 1) {
        // Live cell
        if (neighbors == 2 || neighbors == 3) {
          // Live on to the next generation
          new_grid[row][col] = 1;
        } else {
          // Die
          new_grid[row][col] = 0;
        }
      } else {
        // Dead cell
        if (neighbors == 3) {
          // Come to life
          new_grid[row][col] = 1;
        } else {
          // Stay dead
          new_grid[row][col] = 0;
        }
      }
    }
  }

  // Copy the new grid over the old grid
  for (int row = 0; row < N_ROWS; row++) {
    for (int col = 0; col < N_COLS; col++) {
      grid[row][col]
      = new_grid[row][col];
          }
        }
      }

      // Returns the number of live neighbors for the cell at (row, col)
      int get_neighbor_count(int grid[N_ROWS][N_COLS], int row, int col) {
        int count = 0;

        // Check the cell to the left
        if (col > 0) {
          count += grid[row][col - 1];
        }

        // Check the cell to the right
        if (col < N_COLS - 1) {
          count += grid[row][col + 1];
        }

        // Check the cell above
        if (row > 0) {
          count += grid[row - 1][col];
        }

        // Check the cell below
        if (row < N_ROWS - 1) {
          count += grid[row + 1][col];
        }

        // Check the top-left cell
        if (row > 0 && col > 0) {
          count += grid[row - 1][col - 1];
        }

        // Check the top-right cell
        if (row > 0 && col < N_COLS - 1) {
          count += grid[row - 1][col + 1];
        }

        // Check the bottom-left cell
        if (row < N_ROWS - 1 && col > 0) {
          count += grid[row + 1][col - 1];
        }

        // Check the bottom-right cell
        if (row < N_ROWS - 1 && col < N_COLS - 1) {
          count += grid[row + 1][col + 1];
        }

        return count;
      }
