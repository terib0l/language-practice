#include <stdio.h>
#include <stdlib.h>


typedef struct map {
  char cell[32][32];
} map_t;


void PrintMap(map_t *map) {
  for(int y = 0; y < 32; y++) {
    for(int x = 0; x < 32; x++) {
      putchar(map->cell[y][x] ? '#' : '-');
      putchar(' ');
    }
    putchar('\n');
  }
}


map_t current;
map_t next;


int main(int argc, char *argv[]){
  // Initialization
  for(int i = 0; i < 10; i++) {
    current.cell[16][10+i] = 1;
  }
  for(;;) {
    // Print
    PrintMap(&current);
    // State transition
    for(int y = 0; y < 32; y++){
      for(int x = 0; x < 32; x++){
        int count = 0;
        count += current.cell[(y-1) & 0x1F][(x-1) & 0x1F];
        count += current.cell[(y-1) & 0x1F][(x+0) & 0x1F];
        count += current.cell[(y-1) & 0x1F][(x+1) & 0x1F];

        count += current.cell[(y+0) & 0x1F][(x-1) & 0x1F];
        count += current.cell[(y+0) & 0x1F][(x+1) & 0x1F];

        count += current.cell[(y+1) & 0x1F][(x-1) & 0x1F];
        count += current.cell[(y+1) & 0x1F][(x+0) & 0x1F];
        count += current.cell[(y+1) & 0x1F][(x+1) & 0x1F];

        if(current.cell[y][x]) {
          if(count == 2 || count == 3) {
            next.cell[y][x] = 1;
          } else {
            next.cell[y][x] = 0;
          }
        } else {
          if(count == 3) {
            next.cell[y][x] = 1;
          } else {
            next.cell[y][x] = 0;
          }
        }
      }
    }
    current = next;
    getchar();  // For to stop
  }
  return 0;
}
