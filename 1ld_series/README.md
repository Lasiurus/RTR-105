# 1.Laboratorijas darbs
Diskrētu viena argumenta funkcijas vērtības aprēķins izmantojot Teilora rindas formulas.

Šajā darbā Teilora rinda tiek izmantota, lai noteiktu tuvinātu funkcijas vērtību pie zināmas x vērtības trigonometriskām funkcijām.
Un šo vērtību salīdzināt ar standartfunkciju, kas atrodama *math.h*.

## Galvenā daļa
### Koda apraksts
 **Dotā funkcija - *cos(x/2).***  
Kods sastāv no *main()* funkcijas un lietotāja funkcijas *cosinus_teilors()*.  

```double cosinus_tailors(double, int);```- Rekurenti aprēķina teilora rindas summu ar while loop. Galvenie mainīgie ir *a* un *S*, kur:"
#### Ievade
- *x* : konstante. Izmanto nulles reizinātāja un rekurentā reizinātāja izteiksmēs.
- *sum_part_count* : konstante. Nosaka cik daudz reizes funkcijas loop strādās, jeb, cik precīzu vērtību vajag priekš S (kad salīdzinās ar standartfunkciju;
#### Runtime
- *a* ir Teilora rindas locekļa vērtība indeksācijas while loop pozīcijā *k*;
- *pirmsped_loc* ir *a* vērtība pirmspēdējā izpildāmā cikla iterācijā;
- *ped_loc* ir *a* vērtība pēdējā izpildāmā cikla iterācijā;
#### Izvade
- *S* ir funkcijas izvade, Teilora rindas summa, kas katrā cikla iterācijā tiek atjaunināta ar jaunu *a* vērtību.

```void main();```- Ievades formas priekš user input,ko izmanto funkcijas *cosinus_teilors()* izpildei šeit.
 
 
### Kods - [ld1_series.c](https://github.com/Lasiurus/RTR-105/blob/main/1ld_series/ld1_series.c)

```#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//1.Laboratorijas darbs
//Aptuvenās funkcijas vērtības noteikšana ar Teilora rindu.
//Dotā funkcija - cos(x/2)
//Definīcijas apgabals D pieder (-inf;+inf)
//Grafika .png un source code(.gnu file type) atrodami mapē

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
    printf("\nLietotaja funkcija- y=cos(%.6f/2)=%.6f\n",x,yy);

    y=cos(x/2);
    printf("Standarta funkcija cos - y=cos(%.6f/2)=%.6f\n\n",x,y);


    //ASCII māksla
    printf("       sum_part_count\n"
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
    double pirmsped_loc, ped_loc;

    printf("NPK\tinput\tloceklis\tsumma\n");
    a = (pow(-1,k)*pow(x,2*k))/(1.);
    S = a;
    printf("%d\t%.3f\t%8.6f\t%8.6f\n",k+1,x,a,S);

    while (k<sum_part_count){
        k++;
        a =a * ((-1)*x*x)/((2*k)*(2*k-1)*4);
        S=S+a;
        printf("%d\t%.3f\t%8.6f\t%8.6f\n\n",k+1,x,a,S);
        if(k==sum_part_count-2){
            pirmsped_loc = a;
        }
        if(k==sum_part_count-1){
            ped_loc = a;
        }
    }
    printf("pirmspeedejais loceklis- %.20f\n",pirmsped_loc);
    printf("peedejais loceklis- %.20f\n\n",ped_loc);
    return S;
}
```
 ### Koda izvade  
Šajā gadījumā tiek pieņemtas vērtības *x(x)=4* un *count(sum_part_count)=8*, kas tika ievietotas *cosinus_teilors()*.  
Izvade sastāv no string formatētas tabulas un ASCII fizualizācijas funkcijai un rekurentajam reizinātājam.  

**Tabulas un funkciju izvades precizitāte ir 6 zīmes aiz komata, bet priekš *pirmsped_loc* un *ped_loc*- 20.**  
Lai rezultāti būtu objektīvi uzskatāmi (nevis 0.000000000000), ieteicams ievadīt *x* vērtības logaritmiskā propocionalitātē attiecībā pret *count*.
 
```
Ievadiet pozitiivu skaitli
4
cik preciizu summu, jeb summas lockeklu skaits?(pozitiivu int un vismaz 1)
8
NPK     input   loceklis        summa
1       4.000   1.000000        1.000000       
2       4.000   -2.000000       -1.000000      

3       4.000   0.666667        -0.333333      

4       4.000   -0.088889       -0.422222      

5       4.000   0.006349        -0.415873      

6       4.000   -0.000282       -0.416155      

7       4.000   0.000009        -0.416147      

8       4.000   -0.000000       -0.416147      

9       4.000   0.000000        -0.416147      

pirmspeedejais loceklis- 0.00000855111966223077
peedejais loceklis- -0.00000018793669587320    


Lietotaja funkcija- y=cos(4.000000/2)=-0.416147
Standarta funkcija cos - y=cos(4.000000/2)=-0.416147

       sum_part_count
         _______
         \             k    2*k
          \        (-1)    x
cos(x/2) = >  _______________________
          /                    2*k
         /______     (2*k)! * 2
           k=0
                                  2x
                              (-1)
rekurences reizinatajs:  ___________________
                          2k * (2k-1) * 4
```



## Pielikums  
### Funkcijas grafiks izmantojot gnuplot - [cosxdiv2_teilor.png](https://github.com/Lasiurus/RTR-105/blob/main/1ld_series/cosxdiv2_teilor.png)  
![image](https://github.com/Lasiurus/RTR-105/blob/main/1ld_series/cosxdiv2_teilor.png)

### Funkcijas grafika kods - [1ld_series_graph.gnu](https://github.com/Lasiurus/RTR-105/blob/main/1ld_series/1ld_series_graph.gnu)
```
set terminal png
set output "cosxdiv2_teilor.png"

set xlabel "x"
set ylabel "y"
set title "f(x) = cos(x/2)"
set grid
set tics nomirror
set xrange [-15:15]
set yrange [-2:2]
set xtics ( "-4π" -4*pi, "-3π" -3*pi,"-2π" -2*pi,"-π" (-1)*pi,"0" 0, "π" pi, "2π" 2*pi,"3π" 3*pi,"4π" 4*pi,)

plot cos(x/2)
```
