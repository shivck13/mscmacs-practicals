#include <stdio.h>
#include <limits.h>

#define ROW 3
#define COL 3

void northWestCorner(int cost[ROW][COL], int supply[], int demand[]) {
    int allocation[ROW][COL] = {0};
    int i = 0, j = 0;
    int s[ROW], d[COL];

    // Make local copies to preserve original
    for (int k = 0; k < ROW; k++) s[k] = supply[k];
    for (int k = 0; k < COL; k++) d[k] = demand[k];

    printf("\nNorth-West Corner Method Allocation:\n");
    while (i < ROW && j < COL) {
        int alloc = s[i] < d[j] ? s[i] : d[j];
        allocation[i][j] = alloc;
        s[i] -= alloc;
        d[j] -= alloc;

        if (s[i] == 0) i++;
        if (d[j] == 0) j++;
    }

    int totalCost = 0;
    for (i = 0; i < ROW; i++) {
        for (j = 0; j < COL; j++) {
            if (allocation[i][j] > 0) {
                printf("O%d → D%d: %d units @ cost %d\n", i + 1, j + 1, allocation[i][j], cost[i][j]);
                totalCost += allocation[i][j] * cost[i][j];
            }
        }
    }
    printf("Total Transportation Cost: %d\n", totalCost);
}

void matrixMinMethod(int cost[ROW][COL], int supply[], int demand[]) {
    int allocation[ROW][COL] = {0};
    int s[ROW], d[COL], used[ROW][COL] = {0};

    for (int k = 0; k < ROW; k++) s[k] = supply[k];
    for (int k = 0; k < COL; k++) d[k] = demand[k];

    printf("\nMatrix Minimum Cost Method Allocation:\n");
    while (1) {
        int minCost = INT_MAX, minI = -1, minJ = -1;
        for (int i = 0; i < ROW; i++) {
            for (int j = 0; j < COL; j++) {
                if (!used[i][j] && cost[i][j] < minCost && s[i] > 0 && d[j] > 0) {
                    minCost = cost[i][j];
                    minI = i;
                    minJ = j;
                }
            }
        }
        if (minI == -1 || minJ == -1) break;

        int alloc = s[minI] < d[minJ] ? s[minI] : d[minJ];
        allocation[minI][minJ] = alloc;
        s[minI] -= alloc;
        d[minJ] -= alloc;
        used[minI][minJ] = 1;
    }

    int totalCost = 0;
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            if (allocation[i][j] > 0) {
                printf("O%d → D%d: %d units @ cost %d\n", i + 1, j + 1, allocation[i][j], cost[i][j]);
                totalCost += allocation[i][j] * cost[i][j];
            }
        }
    }
    printf("Total Transportation Cost: %d\n", totalCost);
}

int main() {
    int cost[ROW][COL] = {
        {7, 3, 4},
        {2, 1, 3},
        {3, 4, 6}
    };
    int supply[ROW] = {2, 3, 5};
    int demand[COL] = {4, 1, 5};

    northWestCorner(cost, supply, demand);
    matrixMinMethod(cost, supply, demand);

    return 0;
}
