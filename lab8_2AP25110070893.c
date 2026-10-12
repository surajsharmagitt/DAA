#include <stdio.h>

struct Node {
    char name[10];
    int freq, left, right, used;
};

struct Node h[40];
long long bits = 0;

void codes(int r, char code[], int d) {
    if (h[r].left == -1 && h[r].right == -1) {
        code[d] = '\0';

        printf("%s\t%s\t%d\n", h[r].name, code, d);
        bits += (long long)h[r].freq * d;
        return;
    }

    code[d] = '0';
    codes(h[r].left, code, d + 1);

    code[d] = '1';
    codes(h[r].right, code, d + 1);
}

int main() {
    int n, i, j, count, root = -1;

    printf("Enter number of characters: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter character %d and frequency: ", i + 1);
        char c;
        int f;
        scanf(" %c %d", &c, &f);
        sprintf(h[i].name, "%c", c);
        h[i].freq = f;
        h[i].left = h[i].right = -1;
        h[i].used = 0;
    }

    count = n;

    printf("\nMerging Steps:\n");

    for (i = 1; i < n; i++) {
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

        printf("Step %d: %s(%d) + %s(%d) = %d\n", i,
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

    printf("\nTotal bits = %lld\n", bits);

    return 0;
}
