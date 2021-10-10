#include <stdio.h>
#include <stdlib.h>

//Vienkārša programma, kas pieprasa keyboard input (stdin) un izdara reizināšanas darbību un izvada atbildi

int main(void){
    long long a,b;

    printf("Reizinasanas operacija, kur starp skaitliem vajag atstarpi: \n pirmais un otrais skaitlis:");fflush(stdout);
    scanf("%lld %lld", &a, &b);

    long long reizinajums = a * b;
    
    printf("\n Atbilde: %lld", reizinajums);
}
