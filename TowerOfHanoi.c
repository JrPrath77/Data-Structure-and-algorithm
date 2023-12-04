#include <stdio.h>

int moves = 0;
void TowerOfHanoi(int disk_num, char source, char temptower, char destination) {
  if (disk_num == 1) {
    printf("Move disk 1 from %c to %c\n", source, destination);
    moves++;
    return;
  }

  TowerOfHanoi(disk_num - 1, source, destination, temptower);
  printf("Move disk %d from %c to %c\n", disk_num, source, destination);
  moves++;
  TowerOfHanoi(disk_num - 1, temptower, source, destination);
}
int main() {
  int disk_num;
  printf("Enter Number Of Disks\n");
  scanf("%d", &disk_num);

  TowerOfHanoi(disk_num, 'A', 'B', 'C');
  printf("\nTotal Number Of Moves:%d\n", moves);
  return 0;
}
