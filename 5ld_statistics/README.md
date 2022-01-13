# 5.Laboratorijas darbs
'Char array' datu kopas sakārtošana un statistiskā analīze balstoties uz simbolu ASCII vērtībām.

Uzdevums bija no lietotāja iegūt char datu ievades simbolus, kurus pēc tam sakārtos ar izēlētu sorting algoritmu un attiecīgi noteiks datu kopas statistiskos parametrus (lielākā un mazākā vērtība, moda, mediāna u.t.t.).

## Galvenā daļa

### Kods [ld5_statistics](https://github.com/Lasiurus/RTR-105/blob/main/5ld_statistics/ld5_statistics.c)

Kods ir garš, bet tikai modas vērtības aprēķins būtu uzskatāms, kā sarežģīts, jo pārējās darbības, kā datu sakārtošana vai mediānas iegūšana ir matemātiski vienkārši implementājamas C valodā.

Viss notiek *main()* funkcijā. Dažas darbības, kā *bubble sort* vai modas iegūšana varēja būt izveidotas kā atsevišķas funckijas, bet tas visu tikai sarežģītu ar papildus mainīgajiem uzdevumā, kur netiek prasīta koda optimizācija. Kodu var uzlabot, izmantojot daudz mazāk *for* loops, bet tas padarītu kodu daudz sarežģītāku.

#### Programmas darbības secība

  - Lietotājam prasa ievadīt masīva lielumu, kā "int" vērtību mainīgajā *n*.
  - Tiek definēts *char* masīva mainīgais ar *n* kā tā lielumu.
  - Lietotājam tiek pieprasīta simbolu rinda, ko raksta vienā rindā un pēc pabeigšanas, nospiež *Enter*.
  - Nesakārtotie masīva dati tiek ierakstīti *dat* failā priekš GNUPLOT analīzes kā divas kolonas - simboi un to ASCII vērtības.
  - Notiek īsa masīva lieluma *n* pārbaude, lai noteiktu, vai mediāna būs viens ieraksts(nepāra) vai 2 ieraksti (pāra).
  - **Tālāk ir programmas svarīgākā daļa - sorting algoritms. Tika izvēlēts *bubble sort* algoritms**, jo tas ir visvienkāršākais no sorting algoritmiem, kas izmanto divus *for loop*, pārbaudot un, ja vajag, pārbīdot katru masīva locekli, kas ir ļoti neefektīvi un ar lieliem datu apjomiem - laikietilpīgi. Un, lai gan *bubble sort* ir ar Big-O izpildes ātruma proporcionalitāti O(n^2), tam šajā programmā nav lielas nozīmes, ja lietotājs neievada lielus datu apjomus ar *n = 10000* vai vairāk, kas būtiski palielinās algoritma darbības laiku. Protams, varēja arī izmērīt algoritma darbības laiku, bet tas šajā laboratorijas darbā nebija prasīts.
  - Min. un max. vērtības iegūšana. Ļoti vienkārša - izvadīt pirmo un pēdējo sakārtotā masīva locekli.
  - Mediānas iegūšana (balstās uz 5.punkta teiktā). Vidējā masīva vērtība, ja nepāra masīvs un 2 vidus locekļu vidējās vērtības, ka pāra masīvs.
  - **Sarežģītākā programmas daļa - datu modas iegūšana**. C valodā ir ļoti sarežģīti izpildīt šo uzdevumu, dēļ ļoti primitīvām vai pat neeksistējošām masīvu un string apstrādes funkcijām.
  - Simbolu rindas izvade, kurai seko simbolu rindas ASCII vērtību izvade, formatēta divās rindās, kur zem konkrētā datu simbola vajag būt tā atbilstošajai ASCII koda vērtībai.
  - Sakārtoto datu izvade *dat* failā priekš GNUPLOT histogrammas izveides.



```#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void main(){
    
    char kopija;
    float mean = 0;
    int mode = 0, mediana = 0, n = 0;
    int x = 0, i, j, z = 0, w = 1, m = 0; //iterējamie koeficienti
    FILE *fp, *fp2; //priekš Histogrammas failiem

    printf("Input lielums? (skaitlis)\n");
    scanf("%d", &n);

    char stat_sc[n];
    char stat_sc_copy[n]; //priekš datu modas aprēķina

    printf("Ievadiet simbolu rindu\n");
    scanf("%s", stat_sc);

    printf("\n");

    fp2 = fopen("statistics_unsorted.dat", "w");
    for (x = 0; x < n; x++){
        fprintf(fp2,"%c\t %d\n",stat_sc[x],stat_sc[x]);
    }
    fclose(fp2);

    //Pārbaude, vai ir nepāra vai pāra mediāna
    if(n%2 == 0)mediana = (n/2) + 1;
    else if(n%2 != 0)mediana = (n + 1)/2;
    //---------


    //Bubble sort
    for(i = 0; i < n-1; i++){
        for(j=0;j < n-i-1;j++){
            if(stat_sc[j]>stat_sc[j+1]){
                kopija = stat_sc[j];
                stat_sc[j] = stat_sc[j+1];
                stat_sc[j+1] = kopija;
            }
        }
    }
    //-----------


    //Minimālā un maksimālā vērtība
    for (x = 0; x < n; x++){
        if(x == 0)printf("minimaalaa veertiiba: %c = %d\n", stat_sc[x], stat_sc[x]);
        if(x == n-1)printf("maksimaalaa veertiiba: %c = %d\n", stat_sc[x], stat_sc[x]);
    }
    //-----------


    //mediāna
    for (x = 0; x < n; x++){
        mean += stat_sc[x];
        if(x == mediana-1){
            if(n%2 == 0)printf("mediaanas veertiiba(ASCII skaitlis): %.1f\n", ((stat_sc[x-1] + stat_sc[x])/2.0));
            else printf("mediaanas veertiiba(ASCII skaitlis): %d\n", stat_sc[x]);
        }
    }
    //-----------
    printf("videejaa veertiiba(ASCII skaitlis): %g\n", mean/n);


    //datu modas funkcija
    for (i = 0; i < n - 1; i++){
        mode = 0;
        for (j = i + 1; j < n; j++)
        {
            if (stat_sc[i] == stat_sc[j]){
                mode++;
            }
        }
        if ((mode > m) && (mode != 0)){
            z = 0;
            m = mode;
            stat_sc_copy[z] = stat_sc[i];
            z++;
        }
        else if (mode == m) {
            stat_sc_copy[z] = stat_sc[i];
            z++;
        }
    }

    for (i = 0; i < n; i++){
        if(stat_sc[i] == stat_sc_copy[i])w++;
    }

    if(w == n)printf("Datu moda neeksistee!\n");
    else{
        printf("modas veertibas: ");
        for (i = 0; i < z; i++){
            printf("%c = %d;   ",stat_sc_copy[i],stat_sc_copy[i]);
        }
    }
    //----------

    printf("\n");

    //simbolu izvade
    for (x = 0; x < n; x++){
        if(x == n-1){
            printf("%c\n", stat_sc[x]);
            break;
        }
        if(stat_sc[x] > 99)printf("%c,   ", stat_sc[x]);
        else printf("%c,  ", stat_sc[x]);
    }

    //simbolu ASCII vērtību izvade
    for (x = 0; x < n; x++){
        if(x == n-1){
            printf("%d\n", stat_sc[x]);
            break;
        }
        printf("%d, ", stat_sc[x]);
    }

    //rakstīšana failā
    fp = fopen("statistics.dat", "w");
    for (x = 0; x < n; x++){
        fprintf(fp,"%c\t %d\n",stat_sc[x],stat_sc[x]);
    }
    fclose(fp);
}

```

### Koda izvade

Lietotājam arī tiek prasīts ievadīt *int* skaitli, lai noteiktu char masīva lielumu, jo, veicot datu analīzi, rodas traucējoši un "parazītiski" dati, kas ir ASCII vērtības neaizpildītajām ailēm masīvā. Lietotājs, protams, var pēc masīva lieluma noteikšanas ievadīt vairāk vai mazāk ASCII simbolus, bet tas, protams, nav ieteicams, jo nav bijis iespējams izveidot effektīvas "aizsargmehānismu" funkcijas.

Lielas problēmas radīja tas, ka nav iespējams mainīt *char* masīva definēto lielumu, pēc tā inicializācijas. Tas teorētiski ir izdarāms pa tiešo manipulējot ar masīva adresi atmiņā, bet tas šī darba ietvaros ir pārāk sarežģīti un nav pat vajadzīgs.


Šajā izvadē tika izvēlēts masīva lielums **n = 40** un ievadīta random burtu un ciparu rinda - **a81B5fcee8547cE19Pe0d4Xca682fa9Mo8hTH4Qo**.

```Input lielums? (skaitlis)
40
Ievadiet simbolu rindu
a81B5fcee8547cE19Pe0d4Xca682fa9Mo8hTH4Qo

minimaalaa veertiiba: 0 = 48
maksimaalaa veertiiba: o = 111
mediaanas veertiiba(ASCII skaitlis): 74.5
videejaa veertiiba(ASCII skaitlis): 76.075
modas veertibas: 8 = 56;   
0,  1,  1,  2,  4,  4,  4,  5,  5,  6,  7,  8,  8,  8,  8,  9,  9,  B,  E,  H,  M,  P,  Q,  T,  X,  a,  a,  a,  c,  c,  c,  d,   e,   e,   e,   f,   f,   h,   o,   o  
48, 49, 49, 50, 52, 52, 52, 53, 53, 54, 55, 56, 56, 56, 56, 57, 57, 66, 69, 72, 77, 80, 81, 84, 88, 97, 97, 97, 99, 99, 99, 100, 101, 101, 101, 102, 102, 104, 111, 111
```

## Pielikums

### Nesakārtoto masīva datu histogramma izmantojot GNUPLOT - [statistics_histogram_unsorted.png](https://github.com/Lasiurus/RTR-105/blob/main/5ld_statistics/statistics_histogram_unsorted.png)

![image](https://github.com/Lasiurus/RTR-105/blob/main/5ld_statistics/statistics_histogram_unsorted.png)

### Sakārtotu masīva datu histogramma izmantojot GNUPLOT - [statistics_histogram.png](https://github.com/Lasiurus/RTR-105/blob/main/5ld_statistics/statistics_histogram.png)

![image](https://github.com/Lasiurus/RTR-105/blob/main/5ld_statistics/statistics_histogram.png)

### GNUPLOT kods sakārtotajiem datiem - [5ld_statistics_histogram.gnu](https://github.com/Lasiurus/RTR-105/blob/main/5ld_statistics/5ld_statistics_histogram.gnu)

Laboratorijas darbā repo ir arī nesakārtoto darbu kods, kas ir tāds pats, izņemot *color* parametrs un *dat* faila adrese un *png* izvade.

```set terminal png
set output "statistics_histogram.png"

set xlabel "simbols"
set ylabel "ASCII vērtība"
set title "Datu ASCII vērtību histogramma sakārtotiem datiem"
set grid
set yrange [0:200]
set tics nomirror
set style data histograms
set style fill solid
set style histogram clustered gap 0

plot "statistics.dat" using 2:xtic(1) linecolor 'green' title ""
```

