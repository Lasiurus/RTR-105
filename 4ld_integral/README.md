# 4.Laboratorijas darbs
Viena argumenta funkcijas aptuvenā integrāļa vērtības aprēķināšana izmantojot 3 metodes:
    
    1.Viduspunktu, jeb taisnstūru metode;
    
    2.Trapeču metode;
    
    3.Simpsona metode.

Uzdevums ir iegūt laukumu noteiktā intervālā, ar noteiktu precizitāti, izmantojot šīs metodes.

## Galvenā daļa

### Kods [ld4_integral.c](https://github.com/Lasiurus/RTR-105/blob/main/4ld_integral/ld4_integral.c)

Kods nav pārāk sarežģīts. Katrai metodei ir iedota sava atsevišķā funkcija, kur *main()* funkcijā tiek iegūti vajadzīgie dati no lietotāji un izpildītas visu 3 metožu funkcijas ar šiem datiem.

```#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float Midpoint_integral(float, float, int);
float Trapezoid_integral(float, float, int);
float Simpsons_integral(float, float, int);

void main(){


    float a,b,delta_x, Integ_mid;
    int n;

    printf("funkcija f(x) = cos(x/2)\n\n");
    printf("Saakuma intervaals (a)?\n");
    scanf("%f",&a);

    printf("Beigu intervaals (b)?\n");
    scanf("%f",&b);

    printf("Intervaalu skaits (precizitaate)? (n)\n");
    scanf("%d",&n);

    printf("\nLaukums zeme grafika ar:\n");

    Midpoint_integral(a, b, n);

    Trapezoid_integral(a, b, n);

    Simpsons_integral(a, b, n);

}

float Midpoint_integral(float a, float b, int n){
    float Integral_mid, delta_x, midpoint;
    int k;

    Integral_mid = 0;
    delta_x = (b-a)/n;

    b = a + delta_x;

    for(k=1;k<=n;k++){
        midpoint = (b + a)/2;
        Integral_mid += cos(midpoint/2);
        b += delta_x;
        a += delta_x;
    }

    Integral_mid = Integral_mid*delta_x;

    printf("\tViduspunktu, jeb taisnstuuru metodi = %.12f\n", Integral_mid);
    return Integral_mid;
}

float Trapezoid_integral(float a, float b, int n){
    float Integral_trapez, delta_x;
    int k;

    Integral_trapez = 0;
    delta_x = (b-a)/n;

    for(k=1;k<=n;k++){
        if(k==1){
            Integral_trapez += cos(a/2);
            a += delta_x;
        }
        else{
            Integral_trapez += (cos(a/2))*2;
            a += delta_x;
        }
    }
    Integral_trapez += cos(a/2);
    Integral_trapez = (delta_x/2)*Integral_trapez;

    printf("\tTrapeces metodi = %.12f\n", Integral_trapez);
    return Integral_trapez;
}

float Simpsons_integral(float a, float b, int n){
    float Integral_simp, delta_x;
    int k;

    Integral_simp = 0;
    delta_x = (b-a)/n;

    for(k=1;k<=(n-1);k++){
        if(k==1){
            Integral_simp += cos(a/2);
            a += delta_x;
        }
        else if(k==2){
            Integral_simp += 4*cos(a/2);
            a += delta_x;
        }
        else{
            if(k%2 == 0){
            Integral_simp += (cos(a/2))*4;
            a += delta_x;
            }
            else{
                Integral_simp += (cos(a/2))*2;
            a += delta_x;
            }
        }
    }
    Integral_simp += 4*cos(a/2);
    Integral_simp += cos(a/2);
    Integral_simp = (delta_x/3)*Integral_simp;

    printf("\tSimpsona metodi = %.12f\n", Integral_simp);
    return Integral_simp;
}
```

### Koda izvade
Tika izvēlētas robežas vērtības a=0, b=8 un precizitāte, jeb *n* vērtības 5, 10, 50, 100.
Tika mēģinātas arī negatīvu skaitļu robežas, un tika pārbaudīts, ka viss funkcionē optimāli.

**Wolfram Alpha kalkulatora rezultāts = -1.51360499061586**, mājaslapā https://www.wolframalpha.com/input/?i2d=true&i=Integrate%5Bcos%5C%2840%29Divide%5Bx%2C2%5D%5C%2841%29%2C%7Bx%2C0%2C8%7D%5D

#### *n = 5*

```funkcija f(x) = cos(x/2)

Saakuma intervaals (a)?
0
Beigu intervaals (b)?
8
Intervaalu skaits (precizitaate)? (n)
5

Laukums zeme grafika ar:
        Viduspunktu, jeb taisnstuuru metodi = -1.554734468460
        Trapeces metodi = -1.432005286217
        Simpsona metodi = -2.246731519699
```


Pie *n = 5* redzams, ka visprecīzākā metode taisnstūru metode, bet visneprecīzākā - simpsona metode.

#### *n = 10*

```funkcija f(x) = cos(x/2)

Saakuma intervaals (a)?
0
Beigu intervaals (b)?
8
Intervaalu skaits (precizitaate)? (n)
10

Laukums zeme grafika ar:
        Viduspunktu, jeb taisnstuuru metodi = -1.523742914200
        Trapeces metodi = -1.493369460106
        Simpsona metodi = -1.578654885292
```

#### *n = 50*

```funkcija f(x) = cos(x/2)

Saakuma intervaals (a)?
0
Beigu intervaals (b)?
8
Intervaalu skaits (precizitaate)? (n)
50

Laukums zeme grafika ar:
        Viduspunktu, jeb taisnstuuru metodi = -1.514009356499
        Trapeces metodi = -1.512798428535
        Simpsona metodi = -1.516720294952
```


#### *n = 100*

```funkcija f(x) = cos(x/2)

Saakuma intervaals (a)?
0
Beigu intervaals (b)?
8
Intervaalu skaits (precizitaate)? (n)
100

Laukums zeme grafika ar:
        Viduspunktu, jeb taisnstuuru metodi = -1.513705253601
        Trapeces metodi = -1.513402581215
        Simpsona metodi = -1.514397263527
```

Visos šajos precizitātes gadījumos var secināt, ka labākā metode ir **taisnstūru metode**, otrā labākā ir **trapeces metode**, bet vissliktākā ir **Simpsona metode**.


## Pielikums

### Funkcijas grafiks ar iekrāsotu laukumu zem grafika, kad x ir [0;8] - [cosxdiv2_integral.png](https://github.com/Lasiurus/RTR-105/blob/main/4ld_integral/cosxdiv2_integral.png)

![image](https://github.com/Lasiurus/RTR-105/blob/main/4ld_integral/cosxdiv2_integral.png)

### Laukuma aprēķins un grafiks ar Wolfram Alpha palīdzību (attēls) - [4ld_integral_Wolfram_alpha.png](https://github.com/Lasiurus/RTR-105/blob/main/4ld_integral/4ld_integral_Wolfram_alpha.png)

![image](https://github.com/Lasiurus/RTR-105/blob/main/4ld_integral/4ld_integral_Wolfram_alpha.png)
