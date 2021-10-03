#include <stdio.h>
#include <stdlib.h>

//Vienkārša programma, kas pieprasa keyboard input (stdin) un izdara reizināšanas darbību un izvada atbildi

int main(void){
    int a,b;

    printf("Reizinasanas operacija, kur starp skaitliem vajag atstarpi: \n pirmais un otrais skaitlis:");fflush(stdout);
    scanf("%d %d", &a, &b);

    int reizinajums = a * b;
    
    printf("\n Atbilde: %d", reizinajums);
}
