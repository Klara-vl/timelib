/**
  * Autor: Klara von Lehmden
  *
  * Datum: 17.05.22
  *
  * Programm, welches nach Eingabe des aktuellen Datums berechnet, der wievielte Tag in diesem Jahr es ist.
  **/

#include <stdio.h>
#include <stdlib.h>
#include "zeitBibliothek.h"


int main()
{
    int day = 0;
    int month = 0;
    int year = 0;
    int day_of_year = 0;
    int valid = 0;

    // Eingabe des Datums
    while (valid == 0)
    {
        printf("Geben Sie den Tag ein: ");
        scanf("%i", &day);

        printf("Geben Sie den Monat ein: ");
        scanf("%i", &month);

        printf("Geben Sie das Jahr ein: ");
        scanf("%i", &year);

        // Überprüfung, ob das eingegebene Datum existiert
        if (exists_date(day, month, year) == 1)
        {
            valid = 1;
        }
        else
        {
            printf("Das eingegebene Datum ist ungültig.\n");
        }
    }

    // Berechnung, der wie vielte Tag das Datum im Jahr ist
    day_of_year = day_of_the_year(day, month, year);

    // Ausgabe des Ergebnisses
    printf("Heute ist der %i. Tag des Jahres", day_of_year);

    return 0;
}
