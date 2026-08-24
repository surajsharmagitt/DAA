#include <stdio.h>

int main() {
  int hash[100];
  int size, n, key, index, i;

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

    index = key % size;

    // Linear probing
    while (hash[index] != -1) {
      index = (index + 1) % size;
    }

    hash[index] = key;
  }

  printf("\nHash Table:\n");

  for (i = 0; i < size; i++) {
    printf("Index %d : %d\n", i, hash[i]);
  }

  return 0;
}