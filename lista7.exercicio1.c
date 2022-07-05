/* Serã impresso: 
    f1 = 2
    f2 = 2
    f3 = 3
    main = 3
*/

#include <stdio.h>

void f1 (int v) {
    v = v + 1;
    printf ("f1 = %d\n", v);
}

//f2 altera o ponteiro
void f2 (int *v) {
    *v = *v + 1;
    printf ("f2 = %d\n", *v);
}
// f2 + 1
int f3 (int v) {
    v = v + 1;
    printf ("f3 = %d\n", v);
    return v;
}

int main (void) {
    int v = 1;
    f1 (v); //Esta funçao vai imprimir f1 = 2, somando direto na variavel
    f2 (&v); //Esta funçao vai imprimir f2 = 2, somando por meio de ponteiros
    v = f3 (v); //Esta funçao vai imprimir f3 = 3, pois na funçao acima mexemos com ponteiro, apos a conta retornamos o valor 3
    printf ("main = %d", v); //Esta funçao vai imprimir main = 3, valor retornado acima
    return 0;
}