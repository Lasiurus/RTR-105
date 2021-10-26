#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*  Sort funkcija ar bubble sort algoritmu.
    Izmantoju "if" un "else if" statement, kā programmas pamatu, lai mainīgajam "masivs[100]" tiktu pareizi iedots int vai char datu tips.
    ŠIS IR NEEFEKTĪVI, JO MAN DIVAS REIZES VAJAG VIENU UN TO PAŠU DARĪT, KUR VIENĪGĀ ATŠĶIRĪBA IR APSTRĀDĀJAMAIS DATU TIPS.
    Es ilgi mēģināju dabūt, lai izmanto pareizo datu tipu, atkarībā no "burti" vai "cipari", lai man vajadzētu izmantot bubble sort tikai
        vienreiz, bet tāds nekas nesanāca.
        
    ŠIS KODS IR GARŠ, TOMĒR STRĀDĀ.

*/
int main(){

    int x, y;
    char seciba[100],datu_tips[100];


    printf("\"burti\" vai \"cipari\"?\n");fflush(stdout);
    scanf("%s", datu_tips);


    if(strstr(datu_tips, "burti")){
        char masivs[100],masivsTemp;

        printf("Ievadiet 3 latinu alfabeeta burtus, piemeeram \"U A M\" (nevar, piemeeram \"U AB M\", jo AB -> A, jo char output) \n");fflush(stdout);
        for (x = 0; x < 3; x++)scanf("%s", &masivs[x]);

        printf( "\n \"ascending\" vai \"descending\" order? :");
        scanf("%s", seciba);
        
        //--------------BUBBLE SORT--------------
        for (x = 0 ; x < 3 - 1; x++)
        {
            for (y = 0 ; y < 3 - x - 1; y++)
            {
                if (masivs[y] > masivs[y+1] && strstr(seciba, "ascending"))
                {
                    masivsTemp = masivs[y];
                    masivs[y] = masivs[y+1];
                    masivs[y+1] = masivsTemp;
                }
                else if(masivs[y] < masivs[y+1] && strstr(seciba, "descending"))
                {
                    masivsTemp = masivs[y];
                    masivs[y] = masivs[y+1];
                    masivs[y+1] = masivsTemp;
                }
            }
        }
        //------------------------------------------

        if(strstr(seciba, "ascending")){
            printf("Sakartots ascending seciiba:\n");
        }
        else if(strstr(seciba, "descending")){
            printf("Sakartots descending seciiba:\n");
        }else{return 0;}

        for (x = 0; x < 3; x++)printf("%c\n", masivs[x]);

        return 0;
    }
    else if(strstr(datu_tips, "cipari")){
        int masivs[100],masivsTemp;

        printf("Ievadiet 3 skaitlus jauktaa seciibaa, piemeeram, \"5 42 3\" \n: ");fflush(stdout);
        for (x = 0; x < 3; x++)scanf("%d", &masivs[x]);


        printf( "\n \"ascending\" vai \"descending\" order? :");
        scanf("%s", seciba);
        
        //--------------BUBBLE SORT--------------
        for (x = 0 ; x < 3 - 1; x++)
        {
            for (y = 0 ; y < 3 - x - 1; y++)
            {
                if (masivs[y] > masivs[y+1] && strstr(seciba, "ascending"))
                {
                    masivsTemp = masivs[y];
                    masivs[y] = masivs[y+1];
                    masivs[y+1] = masivsTemp;
                }
                else if(masivs[y] < masivs[y+1] && strstr(seciba, "descending"))
                {
                    masivsTemp = masivs[y];
                    masivs[y] = masivs[y+1];
                    masivs[y+1] = masivsTemp;
                }
            }
        }
        //------------------------------------------
        
        if(strstr(seciba, "ascending")){
            printf("Sakartots ascending seciiba:\n");
        }
        else if(strstr(seciba, "descending")){
            printf("Sakartots descending seciiba:\n");
        }else{return 0;}

        for (x = 0; x < 3; x++)printf("%d\n", masivs[x]);

        return 0;

    }else{return 0;}
}
