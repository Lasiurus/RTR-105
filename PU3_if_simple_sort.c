#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//bubble sort, kas pieņem tikai 3 skaitļus.

int main(){

    int masivs[100], x, y, masivsTemp;
    char seciba[100];

    printf("Ievadiet 3 skaitlus jauktaa seciibaa, piemeeram, \"5 42 3\" \n: ");


    for (x = 0; x < 3; x++)
        scanf("%d", &masivs[x]);


    printf( "\n \"ascending\" vai \"descending\" order? :");
    scanf("%s", seciba);

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

    if(strstr(seciba, "ascending")){
        printf("Sakartots ascending seciiba:\n");
    }
    else if(strstr(seciba, "descending")){
        printf("Sakartots descending seciiba:\n");
    }else{return 0;}

    
    
    for (x = 0; x < 3; x++)
     printf("%d\n", masivs[x]);
    
    return 0;
}
