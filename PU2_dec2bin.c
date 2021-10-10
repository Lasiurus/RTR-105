#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

int i;
//unsigned char, jo << un >> var tikai pozitīvus skaitllus
unsigned char a[100];  

char str[100];
int n2; 

printf("Ievadiet skaitli, kuru pataisiit par binary: "); 
gets(a);

//unsigned int, jo vajag tikai pozitiivus skaitllus.
unsigned int n = strtof(a, NULL);
unsigned int nKopija = strtof(a, NULL);

for(i=0;n>0;i++)    
{    
  a[i]=n%2;    
  n=n/2;    
}    
printf("\nskaitlis %u uz bin = ", nKopija);

for(i=i-1;i>=0;i--)    
{    
  //izprintēs bināro vērtību skaitlim  
  printf("%d",a[i]);
}

printf("\nCik liels bitshift (vajag veselu skaitli)? : ");
scanf("%d", &n2);

printf( "\n \"left\" vai \"right\" bitshift? :");
scanf("%s", str);

if(strstr(str, "left")){
  printf("%d<<%u = %d\n",nKopija, n2, nKopija<<n2);
  }
else if(strstr(str, "right")){
  printf("%d>>%u = %d\n",nKopija, n2, nKopija>>n2);
}else{return 0;}


return 0;  
}  
