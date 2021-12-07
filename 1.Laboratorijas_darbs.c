#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//1.Laboratorijas darbs
//Aptuvenās funkcijas vērtības noteikšana ar Teilora rindu.

double cosinus_tailors(double, int);
void main(){
    double y,yy;//y=standarta built-in funckija, bet yy=user function ar Teilora rindu
    double x;
    int count;//cik reizes iterēt summu

    printf("Cos no pusargumenta apreekinaashana\n");

    printf("Ievadiet pozitiivu skaitli\n");
    scanf("%le", &x);

    printf("cik preciizu summu, jeb summas lockeklu skaits?(pozitiivu int un vismaz 1)\n");
    scanf("%d",&count);

    yy = cosinus_tailors(x,count);
    printf("Lietotaja funkcija- y=cos(%.6f/2)=%.6f\n",x,yy);

    y=cos(x/2);
    printf("Standarta funkcija cos - y=cos(%.6f/2)=%.6f\n\n",x,y);


    //ASCII māksla
    printf("         sum_part_count\n"
    "         _______\n"
    "         \\             k    2*k\n"
    "          \\        (-1)    x     \n"
    "cos(x/2) = >  _______________________\n"
    "          /                    2*k         \n"
    "         /______     (2*k)! * 2\n"
    "           k=0\n");


    printf("                                  2x\n"
    "                              (-1)\n"
    "rekurences reizinatajs:  ___________________\n"
    "                          2k * (2k-1) * 4\n");
}


double cosinus_tailors(double x,int sum_part_count){
    double a, S;
    int k =0;

    a = (pow(-1,k)*pow(x,2*k))/(1.);
    S = a;
    printf("%.2f\t%8.2f\t%8.2f\n",x,a,S);

    while (k<sum_part_count){
        k++;
        a =a * ((-1)*x*x)/((2*k)*(2*k-1)*4);
        S=S+a;
        printf("%.2f\t%8.2f\t%8.2f\n",x,a,S);
    }
    return S;
}
