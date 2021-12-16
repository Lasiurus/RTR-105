#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float cos_sakne(float,float,float);
void main(){
    float delta_x;
    float a,b,c;
    printf("funkcija f(x) = cos(x/2)\n\n");
    printf("Saakuma intervaals (a)?\n");
    scanf("%f",&a);

    printf("Beigu intervaals (b)?\n");
    scanf("%f",&b);

    printf("delta_x veertiba?\n");
    scanf("%f",&delta_x);

    cos_sakne(a,b,delta_x);

}

float cos_sakne(float a,float b,float delta_x){
    float c,f_a,f_b;
    int k=0; //while loop iterējamais
    
    f_a = cos(a/2);
    f_b = cos(b/2);

    if(f_a*f_b>0){
        printf("Interevalaa [%.2f;%.2f] cos(x/2) funkcijai saknju nav vai ir paara skaits\n\n",a,b);
        return 1;
    }

    printf("cos(a/2)=cos(%g)=%7.3f\t\t\t\t cos(b/2)=cos(%g)=%7.3f\n\n",a,cos(a/2),b,cos(b/2));
    printf("\niteraacija(k)\t\ta\t\tb\t\tf(c)\n");
    while((b-a)>delta_x){
        k++;
        c=(a+b)/2;
        if(f_a*cos(c/2)>0){
            a=c;
            printf("\t%d\t\t%g\t\t%g\t\t%g\n",k,a,b,c);
            }
        else{
            b=c;
            printf("\t%d\t\t%g\t\t%g\t\t%g\n",k,a,b,c);
        }
    }
    printf("\n\nSakne atrodas pie x=%g, jo cos(x/2) ir %10f\n",c,cos(c/2));
    return c;
}
