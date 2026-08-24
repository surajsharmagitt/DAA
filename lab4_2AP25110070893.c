#include <stdio.h>

int main() {
  int hash[100];
  int size, n, key, index;
  int i, j;

  printf("Enter hash table size: ");
  scanf("%d", &size);

  // Initialize hash table
  for (i = 0; i < size; i++) {
    hash[i] = -1;
  }

  printf("Enter number of elements: ");
  scanf("%d", &n);

  for (i = 0; i < n; i++) {
    printf("Enter element: ");
    scanf("%d", &key);

    j = 0;

    while (j < size) {
      index = (key + j * j) % size;

      if (hash[index] == -1) {
        hash[index] = key;
        break;
      }

      j++;
    }
    if (j == size) {
      printf("Hash table is full\n");
    }
  }

  printf("\nHash Table:\n");

  for (i = 0; i < size; i++) {
    printf("Index %d : %d\n", i, hash[i]);
  }

  return 0;
}