#include<stdio.h>
int main() {

    int a, b, aux, i, n;

    a = 0;
    b = 1;

    scanf("%d", &n);
    printf("\nSerie de Fibonacci: ");
    printf("%d ", b);

    for(i = 0; i < n; i++) {

        aux = a + b;
        a = b;
        b = a#include<stdio.h>
int main() {

    int a, b, aux, i, n;

    a = 0;
    b = 1;

    scanf("%d", &n);
    printf("\nSerie de Fibonacci: ");
    printf("%d ", b);

    for(i = 0; i < n; i++) {

        aux = a + b;
        a = b;
        b = aux;

        printf("%d ", aux);
    }
    return 0;
}
