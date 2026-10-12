#include <stdio.h>

#define N 9

struct Node {
    char name[10];
    int freq, left, right, used;
};

struct Node h[2 * N];
long long bits = 0;

void codes(int r, char code[], int d) {
    if (h[r].left == -1 && h[r].right == -1) {
        code[d] = '\0';

        printf("%s\t%s\t%d\n", h[r].name, code, d);
        bits += (long long)h[r].freq * 100 * d;
        return;
    }

    code[d] = '0';
    codes(h[r].left, code, d + 1);

    code[d] = '1';
    codes(h[r].right, code, d + 1);
}

int main() {
    char ch[] = {'a','c','d','e','o','m','s','t','u'};
    int f[] = {20,11,2,10,15,8,10,22,2};
    int i, j, count = N, root = -1;

    for (i = 0; i < N; i++) {
        sprintf(h[i].name, "%c", ch[i]);
        h[i].freq = f[i];
        h[i].left = h[i].right = -1;
        h[i].used = 0;
    }

    printf("Merging Steps:\n");

    for (i = 1; i < N; i++) {
        int a = -1, b = -1;

        for (j = 0; j < count; j++) {
            if (h[j].used) continue;

            if (a == -1 || h[j].freq < h[a].freq) {
                b = a;
                a = j;
            } else if (b == -1 || h[j].freq < h[b].freq) {
                b = j;
            }
        }

        printf("%s(%d) + %s(%d) = %d\n",
               h[a].name, h[a].freq,
               h[b].name, h[b].freq,
               h[a].freq + h[b].freq);

        h[count].freq = h[a].freq + h[b].freq;
        h[count].left = a;
        h[count].right = b;
        h[count].used = 0;
        sprintf(h[count].name, "N%d", i);

        h[a].used = h[b].used = 1;
        root = count++;
    }

    char code[20];

    printf("\nLetter\tCode\tLength\n");
    codes(root, code, 0);

    printf("\nTotal Memory = %lld bits\n", bits);
    printf("Total Memory = %lld bytes\n", bits / 8);

    return 0;
}
