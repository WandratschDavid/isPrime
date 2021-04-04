#include <stdio.h>
#include <stdbool.h>
#include <math.h>

int main()
{
    // Variablen anlegen
    int input;
    double wurzelAusInput;

    // Userabfrage nach der Obergrenze
    printf("Bitte geben Sie die gewollte Obergrenze ein: ");
    scanf("%i", &input);

    // Überprüfung ob Obergrenze nicht < 2 oder > 100000 ist, da eine höhere Zahl keinen Sinn machen würde bzw. lange zur Berechnung braucht
    while ((input < 2) || (input > 100000))
    {
        printf("Es ist ein Fehler aufgetreten!\n");
        printf("Die Obergrenze muss zwischen 2 und 100000 liegen!\n");

        // erneute Abfrage der Obergrenze bis der Input valide ist
        printf("Bitte geben Sie die gewollte Obergrenze ein:");
        scanf("%i", &input);
    }

    // Array anlegen & initialisieren
    bool isPrim[input + 1];

    for (int i = 0; i < input + 1; i++)
    {
        isPrim[i] = true;
    }

    // einmalige Berechnung für die Grenze beim Durchlauf der Primzahlüberprüfung
    wurzelAusInput = sqrt(input);

    // Ausgabe der Primzahlen
    printf("Primzahlen von 2 - %i:\n", input);

    // Zahlen von 2 bis zur angegebenen Obergrenze durchgehen und prüfen
    for (int i = 2; i < input + 1; i++)
    {
        if (isPrim[i])
        {
            // Prüfung ob der Index kleiner als die Wurzel aus der Obergrenze ist, da ein längerer Durchlauf keinen Sinn macht
            if (i <= wurzelAusInput)
            {
                // alle Vielfachen der Nicht-Primzahlen streichen
                for (int j = 2; j <= (input / i); j++)
                {
                    isPrim[i * j] = false;
                }
            }

            // Ausgabe der übrig gebliebenen Primzahlen
            printf("%i, ", i);
        }
    }
}