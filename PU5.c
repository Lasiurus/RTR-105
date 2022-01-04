#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Tas pats kas PU4, tikai ar for loop.


//faktoriāļa darbības funkcija ar for loop ar long long augšējo rezultāta robežu.
long long factorial(int a){
    long long rezFact=1;
    int i, aCopy;
    if(a >= 21){
        printf("Integer overflow.");
        return 0;
    }
    for (i = 2; i <= a; i++){rezFact *= i;}
    aCopy = a;
    printf("Factorial of %d is %lld", aCopy, rezFact);
    return rezFact;
}

int main(){

    char tips[100], skaitlisChar[100];
    int skaitlis;
    long long skaitlisLong;

    printf("Ievadiet pozitiivu decimaalu skaitli: \n ");
    scanf("%d", &skaitlis);

    if(skaitlis < 0){
        printf("tikai pozitiivus skaitlus");
        return 0;
    }
    
    //šī nav faktoriāļa vērtība, tāpēc tā daru.
    if(skaitlis < 0){
        printf("tikai pozitīvus skaitļus");
        return 0;
    }

    printf("char / int / long-long? \n");
    scanf("%s", tips);

    if(strstr(tips,"char")){
        //itoa pārveido int par char
        itoa(skaitlis,skaitlisChar, 10);
        //factorial(skaitlisChar);
        printf("Nevar izpildiit factorial function ar char datu tipu!");
        return 0;
    }
    else if(strstr(tips,"long-long")){
        skaitlisLong = skaitlis;
        factorial(skaitlisLong);
        return 0;
    }
    else if(strstr(tips,"int")){
        factorial(skaitlis);
        return 0;
    }else{
        printf("Nav pareizais datu tips.\n");
        return 0;
    }
}
