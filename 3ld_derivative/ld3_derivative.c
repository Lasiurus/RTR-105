#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void main(){
    float a,b,x,delta_x;
    FILE *fp;

    printf("funkcija f(x) = cos(x/2)\n\n");
    printf("Saakuma intervaals (a)?\n");
    scanf("%f",&a);

    printf("Beigu intervaals (b)?\n");
    scanf("%f",&b);

    printf("delta_x veertiba?\n");
    scanf("%f",&delta_x);

    printf("        x  ||       cos(x/2)   ||   cos\'(x/2)      |   cos\'(x/2)     ||    cos\'\'(x/2)    |   cos\'\'(x/2)  \n"
           "           ||                  ||analytical formula|finite difference||analytical formula|finite difference\n"
           "    ========================================================================================================\n");
    x=a;

    fp = fopen("derivative.dat", "w");

    while(x<b){
        fprintf(fp,"%10.3f\t%10.3f\t%10.3f\t%10.3f\t%10.3f\t%10.3f\n",x,cos(x/2),-0.5*sin(x/2),(cos((x+delta_x)/2)-cos(x/2))/delta_x,-0.25*cos(x/2),(-0.5*sin((x+delta_x)/2)-(-0.5*sin(x/2)))/delta_x);
        printf("%10.3f\t%10.3f\t %10.3f\t    %10.3f\t       %10.3f\t    %10.3f\n",x,cos(x/2),-0.5*sin(x/2),(cos((x+delta_x)/2)-cos(x/2))/delta_x,-0.25*cos(x/2),(-0.5*sin((x+delta_x)/2)-(-0.5*sin(x/2)))/delta_x);
        x +=delta_x;
      
    }
    fclose(fp);

    return 0;
}