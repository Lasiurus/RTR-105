#include <stdio.h>
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
