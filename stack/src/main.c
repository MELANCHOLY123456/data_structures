#include <stdio.h>
#include "stack.c"

int main(int argc, char const* argv[]) {
    LinkStack s;
    int e;
    if (InitStack(&s) == OK) {
        for (int j = 1; j <= 10; j++) {
            Push(&s, j);
        }
    }
    StackTraverse(s);
    int length = StackLength(&s);
    printf("%d\n", length);
    Pop(&s, &e);
    printf("e = %d\n", e);
    printf("%d\n", StackEmpty(s));
    GetTop(s, &e);
    printf("e = %d\n", e);
    ClearStack(&s);
    printf("%d", StackEmpty(s));
    return 0;
}
