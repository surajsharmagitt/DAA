#include <stdio.h>

int parent[20];

int find(int i) {
  while (parent[i] != i)
    i = parent[i];
  return i;
}

void unionSet(int i, int j) {
  int a = find(i);
  int b = find(j);
  parent[a] = b;
}

int main() {
  int n, e;
  int u[20], v[20], w[20];
  int i, j, count = 0, total = 0;

  printf("Enter number of vertices: ");
  scanf("%d", &n);

  printf("Enter number of edges: ");
  scanf("%d", &e);

  printf("Enter edges (u v weight):\n");
  for (i = 0; i < e; i++)
    scanf("%d%d%d", &u[i], &v[i], &w[i]);

  for (i = 0; i < n; i++)
    parent[i] = i;

  /* Sort edges by weight */
  for (i = 0; i < e - 1; i++) {
    for (j = 0; j < e - i - 1; j++) {
      if (w[j] > w[j + 1]) {
        int temp;

        temp = w[j];
        w[j] = w[j + 1];
        w[j + 1] = temp;

        temp = u[j];
        u[j] = u[j + 1];
        u[j + 1] = temp;

        temp = v[j];
        v[j] = v[j + 1];
        v[j + 1] = temp;
      }
    }
  }

  printf("\nEdges in MST:\n");

  for (i = 0; i < e && count < n - 1; i++) {
    if (find(u[i]) != find(v[i])) {
      printf("%d - %d = %d\n", u[i], v[i], w[i]);
      total += w[i];
      unionSet(u[i], v[i]);
      count++;
    }
  }

  printf("Minimum Cost = %d\n", total);

  return 0;
}
