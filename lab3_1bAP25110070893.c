#include <stdio.h>

struct Stack {
  int n;
  char source;
  char auxiliary;
  char destination;
};

int main() {
  struct Stack stack[100];
  int top = -1;
  int n;

  printf("Enter number of disks: ");
  scanf("%d", &n);

  stack[++top].n = n;
  stack[top].source = 'A';
  stack[top].auxiliary = 'B';
  stack[top].destination = 'C';

  while (top != -1) {
    int disks = stack[top].n;
    char source = stack[top].source;
    char auxiliary = stack[top].auxiliary;
    char destination = stack[top].destination;

    top--;

    if (disks == 1) {
      printf("Move disk 1 from %c to %c\n", source, destination);
    } else {
      /* Third recursive call */
      top++;
      stack[top].n = disks - 1;
      stack[top].source = auxiliary;
      stack[top].auxiliary = source;
      stack[top].destination = destination;

      /* Move largest disk */
      printf("Move disk %d from %c to %c\n", disks, source, destination);

      /* First recursive call */
      top++;
      stack[top].n = disks - 1;
      stack[top].source = source;
      stack[top].auxiliary = destination;
      stack[top].destination = auxiliary;
    }
  }

  return 0;
}