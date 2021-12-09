#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//1.funkcija - bez arg. , bez return
void printHello(){
    printf("Hello! \n");fflush(stdout);
}

//2.funkcija - ar arg. , bez return
int pyramid(int a){
    int x;
    for (x = 1; x <= a; x++) {
        int y;
        for (y = 0; y < x; y++) {
            putchar('*');
        }
        putchar('\n');
    }
}

//3.funkcija - bez arg. , ar return
float goldenRationumber(){
    float phi;
    phi = (1 + sqrt(5))/2;
    return phi;
}

//4.funkcija - ar arg. , ar return
float pitagoraTeorema(int a,int b){
    
    float c;
    c = a*a + b*b;
    c = sqrt(c);
    return c;
}

int main(){

    printHello();

    pyramid(6);

    printf("phi=%f\n", goldenRationumber());
    
    float hipotenuza = pitagoraTeorema(1,4);
    printf("c = %f", hipotenuza);

    return 0;
}

