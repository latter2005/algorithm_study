#include <stdlib.h>
#include <stdio.h>
#include <string.h>
 
int main() {
    char ary[1000][242];
    int n, k;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d ", &k);
        fgets(ary[i], 241, stdin);
    }
    qsort(ary, n, sizeof(ary[0]), [](const void *a, const void *b) -> int {
        return strcmp((char*)a, (char*)b);
    });
 
    char *stack[15];
    char *cur;
    int count = 0;
    ary[0][strlen(ary[0]) - 1] = '\0';
    for (cur = strtok(ary[0], " "); cur ; cur = strtok(0, " ")) {
        stack[count] = cur;
        for (int i = 0; i < count; i++)
            printf("--");
        printf("%s\n", cur);
        count++;
    }
 
    for (int i = 1; i < n; i++) {
        ary[i][strlen(ary[i]) - 1] = '\0';
        count = 0;
        for (cur = strtok(ary[i], " "); strcmp(cur, stack[count]) == 0; cur = strtok(0, " "))
            count++;
        for (; cur; cur = strtok(0, " ")) {
            stack[count] = cur;
            for (int i = 0; i < count; i++)
                printf("--");
            printf("%s\n", cur);
            count++;
        }
    }
 
    return 0;
}