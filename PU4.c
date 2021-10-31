#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//faktoriāļa darbības funkcija ar while loop ar long long augšējo rezultāta robežu.
long long factorial(int a){
    long long rezFact;
    int aCopy;
    aCopy = a;
    //zinu, ka bija aizliegts izmantot int robežu konstantes priekš šī(piemēram,2147483647), 
    //bet šo likumu apgāju izmantojot vērtību pirms faktoriāļa darbības(arguments a), 
    //lai tomēr varētu novērst integer overflow.
    if(a >= 21){
        printf("Integer overflow.");
        return 0;
    }
    rezFact = a;
    a--;
    while(a>=1){
        rezFact = rezFact * a;
        a--;
    }
    printf("Factorial of %d is %lld", aCopy, rezFact);
    return rezFact;
}

int main(){

    char tips[100], skaitlisChar[100];
    int skaitlis;
    long long skaitlisLong;

    printf("Ievadiet decimaalu skaitli: \n ");
    scanf("%d", &skaitlis);

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
