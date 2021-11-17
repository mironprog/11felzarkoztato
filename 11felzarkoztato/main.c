#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void valosTombFeltoltese(double *tomb, int meret);
void tombKiir(double *tomb, int meret);
//int limitalattiminindex(double *tomb, int meret double limit);
//int SzazFelettiMinIndex (double *tomb, int meret)
int SzazFelettiMinIndex(double *,int); //igyis lehet

/*
1. �rjon C programot, amely 10 adat t�rol�s�ra alkalmas egydimenzi�s t�mbben nyilv�ntartja egy
csokigy�rban az elk�sz�lt 100 grammos csokol�d� t�bl�k val�s t�meg�t. Az al�bbi r�szfeladatokat
k�l�n f�ggv�nyben val�s�tsa meg:
- T�ltse fel a t�mb�t 95 �s 105 k�z� es� v�letlen val�s �rt�kekkel 2 tizedesjegy pontoss�ggal.
- �rja ki a t�mb elemeit.
- V�lassza ki a 100 grammot meghalad� �rt�kek k�z�l a legkisebbet.
- Olvasson be ellen�rz�tt m�don egy intervallumot a 95 �s 105 k�z�tti tartom�nyban. (Pl: 98-100)
- Sz�m�tsa ki a beolvasott intervallumba es� t�mbelemek �tlag�t

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
//T�ltse fel a t�mb�t 95 �s 105 k�z� es� v�letlen val�s �rt�kekkel 2 tizedesjegy pontoss�ggal.
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
//�rja ki a t�mb elemeit.
void tombKiir(double *tomb, int meret)
{
    int i;

    //ha ford�tva k�ne for(i = meret - 1; i > 0; i--)
    for(i = 0; i < meret; i++)
    {

        printf("%2d. ertek: %6.2lf\n", i + 1, tomb[i]);
    }

    return;
}
//V�lassza ki a 100 grammot meghalad� �rt�kek k�z�l a legkisebbet.
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


