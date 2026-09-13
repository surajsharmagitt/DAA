#include <stdio.h>

#define MAX 64

void add(int n, int A[MAX][MAX], int B[MAX][MAX], int C[MAX][MAX]) {
  int i, j;

  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++)
      C[i][j] = A[i][j] + B[i][j];
}

void subtract(int n, int A[MAX][MAX], int B[MAX][MAX], int C[MAX][MAX]) {
  int i, j;

  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++)
      C[i][j] = A[i][j] - B[i][j];
}

void strassen(int n, int A[MAX][MAX], int B[MAX][MAX], int C[MAX][MAX]) {
  int i, j, k;

  if (n == 1) {
    C[0][0] = A[0][0] * B[0][0];
    return;
  }

  k = n / 2;

  int A11[MAX][MAX], A12[MAX][MAX], A21[MAX][MAX], A22[MAX][MAX];
  int B11[MAX][MAX], B12[MAX][MAX], B21[MAX][MAX], B22[MAX][MAX];
  int M1[MAX][MAX], M2[MAX][MAX], M3[MAX][MAX], M4[MAX][MAX];
  int M5[MAX][MAX], M6[MAX][MAX], M7[MAX][MAX];
  int C11[MAX][MAX], C12[MAX][MAX], C21[MAX][MAX], C22[MAX][MAX];
  int T1[MAX][MAX], T2[MAX][MAX];

  for (i = 0; i < k; i++) {
    for (j = 0; j < k; j++) {
      A11[i][j] = A[i][j];
      A12[i][j] = A[i][j + k];
      A21[i][j] = A[i + k][j];
      A22[i][j] = A[i + k][j + k];

      B11[i][j] = B[i][j];
      B12[i][j] = B[i][j + k];
      B21[i][j] = B[i + k][j];
      B22[i][j] = B[i + k][j + k];
    }
  }

  add(k, A11, A22, T1);
  add(k, B11, B22, T2);
  strassen(k, T1, T2, M1);

  add(k, A21, A22, T1);
  strassen(k, T1, B11, M2);

  subtract(k, B12, B22, T1);
  strassen(k, A11, T1, M3);

  subtract(k, B21, B11, T1);
  strassen(k, A22, T1, M4);

  add(k, A11, A12, T1);
  strassen(k, T1, B22, M5);

  subtract(k, A21, A11, T1);
  add(k, B11, B12, T2);
  strassen(k, T1, T2, M6);

  subtract(k, A12, A22, T1);
  add(k, B21, B22, T2);
  strassen(k, T1, T2, M7);

  add(k, M1, M4, T1);
  subtract(k, T1, M5, T2);
  add(k, T2, M7, C11);

  add(k, M3, M5, C12);

  add(k, M2, M4, C21);

  add(k, M1, M3, T1);
  subtract(k, T1, M2, T2);
  add(k, T2, M6, C22);

  for (i = 0; i < k; i++) {
    for (j = 0; j < k; j++) {
      C[i][j] = C11[i][j];
      C[i][j + k] = C12[i][j];
      C[i + k][j] = C21[i][j];
      C[i + k][j + k] = C22[i][j];
    }
  }
}

int main() {
  int A[MAX][MAX], B[MAX][MAX], C[MAX][MAX];
  int n, i, j;

  printf("Enter matrix size (power of 2): ");
  scanf("%d", &n);

  printf("Enter matrix A:\n");
  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++)
      scanf("%d", &A[i][j]);

  printf("Enter matrix B:\n");
  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++)
      scanf("%d", &B[i][j]);

  strassen(n, A, B, C);

  printf("Result matrix:\n");
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      printf("%d\t", C[i][j]);
    }
    printf("\n");
  }

  return 0;
}
