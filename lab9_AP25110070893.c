#include <stdio.h>

#define INF 99999

int main() {
  int n, a[10][10];
  int i, j, k;

  printf("Enter number of vertices: ");
  scanf("%d", &n);

  printf("Enter adjacency matrix (-1 for no edge):\n");
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      scanf("%d", &a[i][j]);

      if (a[i][j] == -1)
        a[i][j] = INF;
    }
  }

  for (k = 0; k < n; k++) {
    for (i = 0; i < n; i++) {
      for (j = 0; j < n; j++) {
        if (a[i][k] != INF && a[k][j] != INF && a[i][k] + a[k][j] < a[i][j]) {
          a[i][j] = a[i][k] + a[k][j];
        }
      }
    }
  }

  printf("Shortest distance matrix:\n");
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      if (a[i][j] == INF)
        printf("INF ");
      else
        printf("%d ", a[i][j]);
    }
    printf("\n");
  }

  return 0;
}