#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void valosTombFeltoltese(double *tomb, int meret);
void tombKiir(double *tomb, int meret);
//int limitalattiminindex(double *tomb, int meret double limit);
//int SzazFelettiMinIndex (double *tomb, int meret)
int SzazFelettiMinIndex(double *,int); //igyis lehet

/*
1. Írjon C programot, amely 10 adat tárolására alkalmas egydimenziós tömbben nyilvántartja egy
csokigyárban az elkészült 100 grammos csokoládé táblák valós tömegét. Az alábbi részfeladatokat
külön függvényben valósítsa meg:
- Töltse fel a tömböt 95 és 105 közé esõ véletlen valós értékekkel 2 tizedesjegy pontossággal.
- Írja ki a tömb elemeit.
- Válassza ki a 100 grammot meghaladó értékek közül a legkisebbet.
- Olvasson be ellenõrzött módon egy intervallumot a 95 és 105 közötti tartományban. (Pl: 98-100)
- Számítsa ki a beolvasott intervallumba esõ tömbelemek átlagát

*/


int main()
{

    int meret = 10;
    double tomb[meret];
    int szazFelettiMinIndex;
    printf("tombos feladat\n");
    valosTombFeltoltese(tomb, meret);
    tombKiir(tomb, meret);
    szazFelettiMinIndex = SzazFelettiMinIndex(tomb, meret);

    printf("%d - %.2lf", szazFelettiMinIndex, tomb[szazFelettiMinIndex]);

    return 0;
}
//Töltse fel a tömböt 95 és 105 közé esõ véletlen valós értékekkel 2 tizedesjegy pontossággal.
void valosTombFeltoltese(double *tomb, int meret)
{
    int i;
    int tmp;
    srand(time(NULL));

    tmp = 10500 - 9500 + 1;

    for(i = 0; i < meret; i++)
    {
        tomb[i] = (rand() % tmp + 9500) / 100.0;
    }
    return;
}
//Írja ki a tömb elemeit.
void tombKiir(double *tomb, int meret)
{
    int i;

    //ha fordítva kéne for(i = meret - 1; i > 0; i--)
    for(i = 0; i < meret; i++)
    {

        printf("%2d. ertek: %6.2lf\n", i + 1, tomb[i]);
    }

    return;
}
//Válassza ki a 100 grammot meghaladó értékek közül a legkisebbet.
int SzazFelettiMinIndex (double *tomb,int meret)
{
    int i;
    int minimalisIndex = -1;

    for(i = 0; i < meret; i++)
    {
        if(tomb[i] > 100 && minimalisIndex == -1)
            minimalisIndex = i;
        if(minimalisIndex != -1 && tomb[i] > 100 && tomb[minimalisIndex] > tomb[i] )
            minimalisIndex = i;


    }
    return minimalisIndex;

}

/* ez kb mindig kell
int i;

    for(i = 0; i < meret; i++)
    {



    }
*/


