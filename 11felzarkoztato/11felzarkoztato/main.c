#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void valosTombFeltoltese(double *tomb, int meret);
void tombKiir(double *tomb, int meret);
//int limitalattiminindex(double *tomb, int meret double limit);
//int SzazFelettiMinIndex (double *tomb, int meret)
int SzazFelettiMinIndex(double *,int); //igyis lehet
void IntervallumBeolvas(double *alsohatar,double *felsohatar);
double IntervallumAtlag(double *tomb, int meret, double alsohatar, double felsohatar);

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
    double alsohatar, felsohatar;
    double atlag;



    printf("tombos feladat\n");



    valosTombFeltoltese(tomb, meret);

    tombKiir(tomb, meret);

    if(szazFelettiMinIndex != 1)
        szazFelettiMinIndex = SzazFelettiMinIndex(tomb, meret);
    else
        printf("nem volt ilyen");

    IntervallumBeolvas(&alsohatar, &felsohatar);


    printf("%d - %.2lf", szazFelettiMinIndex, tomb[szazFelettiMinIndex]);

    atlag = IntervallumAtlag(tomb, meret, alsohatar, felsohatar);

    if( atlag != -1)
        printf("%.2lf es %.2lf koze eso ertekek atlag: %.2", alsohatar, felsohatar, atlag);
    else
        printf("Nem volt %.2lf es %.2lf  koze eso atlag", alsohatar, felsohatar);



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
//Olvasson be ellen�rz�tt m�don egy intervallumot a 95 �s 105 k�z�tti tartom�nyban. (Pl: 98-100)
void IntervallumBeolvas(double *alsohatar,double *felsohatar)
{

    int jo;

    do
    {
        jo = 1;

        printf("Kerem adja meg az also erteket!\n");
        printf("also [95-105]:\n");
        if (scanf("%lf", alsohatar) !=1 || *alsohatar < 95 && *alsohatar > 105)
        {
            printf("hibas adat\n");
            jo = 0;
        }

        while(getchar() != '\n');
    }
    while (!jo);

    do
    {
        jo = 1;

        printf("Kerem adja meg az felso erteket!\n");
        printf("felso [%.2lf-105]:\n", *alsohatar);
        if (scanf("%lf", felsohatar) !=1 || *felsohatar < *alsohatar || *felsohatar > 105)
        {
            printf("hibas adat\n");
            jo = 0;
        }

        while(getchar() != '\n');
    }
    while (!jo);








    return;
}
//Sz�m�tsa ki a beolvasott intervallumba es� t�mbelemek �tlag�t
double IntervallumAtlag(double *tomb, int meret, double alsohatar, double felsohatar)
{


    int i;
    double szumma = 0;
    double atlag;
    int db;

    for (i = 0; i < meret; i++)
    {
       if(tomb[i] >= alsohatar && tomb[i] <= felsohatar)
        {
          szumma += tomb[i];
          db++;
        }
    }
   if (db != 0)
    atlag = szumma / db;
   else atlag = -1;


   return atlag;
}

