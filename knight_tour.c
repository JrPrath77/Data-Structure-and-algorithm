#include <stdio.h>
#include <stdlib.h>

#define N 8

// Structure to represent a cell on the chessboard
struct Cell {
    int x, y, dist;
};

// Function to check if a given position is inside the board
int isInside(int x, int y) {
    return (x >= 0 && x < N && y >= 0 && y < N);
}

// Function to calculate the minimum steps for the knight to reach the target
int minStepsToReachTarget(int knightPos[], int targetPos[]) {
    // Possible moves for the knight
    int dx[] = {-2, -1, 1, 2, -2, -1, 1, 2};
    int dy[] = {-1, -2, -2, -1, 1, 2, 2, 1};

    // Create a queue for BFS
    struct Cell queue[N * N];
    int front = 0, rear = 0;

    // Mark all cells as not visited
    int visited[N][N];
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            visited[i][j] = 0;

    // Enqueue the source cell
    queue[rear++] = (struct Cell){knightPos[0], knightPos[1], 0};
    visited[knightPos[0]][knightPos[1]] = 1;

    // BFS
    while (front != rear) {
        struct Cell current = queue[front++];

        // If this cell is the target cell
        if (current.x == targetPos[0] && current.y == targetPos[1])
            return current.dist;

        // Process all 8 possible moves of the knight
        for (int i = 0; i < 8; i++) {
            int x = current.x + dx[i];
            int y = current.y + dy[i];

            // Check if new position is inside the board and not visited
            if (isInside(x, y) && !visited[x][y]) {
                queue[rear++] = (struct Cell){x, y, current.dist + 1};
                visited[x][y] = 1;
            }
        }
    }

    return -1; // If the target cannot be reached
}

int main() {
    // Take input from the user for source and destination positions with validation
    int knightPos[2], targetPos[2];

    // Input validation for source position
    do {
        printf("Enter source position (x y): ");
        scanf("%d %d", &knightPos[0], &knightPos[1]);
    } while (!isInside(knightPos[0], knightPos[1]));

    // Input validation for destination position
    do {
        printf("Enter destination position (x y): ");
        scanf("%d %d", &targetPos[0], &targetPos[1]);
    } while (!isInside(targetPos[0], targetPos[1]));

    printf("Minimum steps: %d\n", minStepsToReachTarget(knightPos, targetPos));

    return 0;
}