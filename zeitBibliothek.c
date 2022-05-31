
#include <stdio.h>
#include <stdlib.h>

/**
  * Die Funktion �berpr�ft, ob ein eingegebenes Datum g�ltig ist. Daten vor dem 1.1.1582 sind ung�ltig, genauso
  * wie alle Daten nach dem 31.12.2400.
  **/
int exists_date(int day, int month, int year)
{
    if (year < 1582 || year > 2400)     //Jahr �berpr�fen
    {
        return 0;
    }

    if (month <= 0 || month >= 13)      // Monat �berpr�fen
    {
       return 0;
    }

    if (day <= 0 || day > get_days_for_month(month, year))  // Tag �berpr�fen
    {
       return 0;
    }

    return 1;
}


/**
  * Die Funktion bestimmt f�r einen gegebenen Monat eines gegebenen Jahres, wie viele Tage der Monat hat. Der
  * Wert des Monats muss zwischen 1 und 12 liegen. Schaltjahre werden ber�cksichtigt.
  **/
int get_days_for_month(int month, int year)
{
    int day_permonth[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

    //wenn es Schaltjahr ist, dann den Februar �ndern
    if (is_leapyear(year) == 1)
    {
        day_permonth[1] = 29;
    }

    // Abfragen, ob es den Monat �berhaupt gibt
    if (month > 0 && month < 13)
    {
        return day_permonth[month - 1];
    }
    else
    {
        return -1;
    }
}


/**
  * Die Funktion �berpr�ft, ob ein gegebenes Jahr nach den Regeln des gregorianischen Kalender ein Schaltjahr
  * ist. Bei Jahreszahlen vor dem Jahr 1582 wird ein Fehler zur�ckgegeben.
  **/

int is_leapyear(int year)
{
    // ist das Jahr g�ltig?
    if (year < 1582 || year > 2400)
    {
        return -1;
    }

    //
    //Berechnungen
    //
    if (year % 4 == 0)       //ohne rest durch 4 Teilbar?
    {
        if (year % 100 == 0)    //ohne rest durch 100 Teilbar?
        {
            if (year % 400 == 0)    //ohne rest durch 400 Teilbar?
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        else
        {
            return 1;
        }
    }
    else
    {
        return 0;
    }
}


/**
  *Die Funktion berechnet f�r ein gegebenes Datum des gregorianischen Kalenders bestehend aus Tag, Monat
  *und Jahr die Nummer des Tages, gez�hlt von Jahresbeginn (1. Januar) an. Schaltjahre werden bei der
  *Berechnung ber�cksichtigt. Ist das �bergebene Datum ung�ltig, betr�gt der R�ckgabewert -1.
  **/

int day_of_the_year(int day, int month, int year)
{
    // Hinzuf�gen des aktuellen Tages
    int day_of_year = day;

    // aufsummieren der restlichen Monate
    for(int i = 1; i < month; i++)
    {
        day_of_year = day_of_year + get_days_for_month(i, year);
    }

    return day_of_year;
}
