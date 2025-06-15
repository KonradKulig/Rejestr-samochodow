#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void pokaz_uzycie(char *nazwa_programu) {
    printf("Użycie: %s <liczba1> <działanie> <liczba2>\n", nazwa_programu);
    exit(1);
}

int main(int argc, char *argv[]) {
    int a, b, wynik;
    char *dzialanie;

    if (argc != 4) {
        pokaz_uzycie(argv[0]);
    }

    a = atoi(argv[1]);
    dzialanie = argv[2];
    b = atoi(argv[3]);

    if (strcmp(dzialanie, "add") == 0) {
        wynik = a + b;
        printf("Suma: %d + %d = %d\n", a, b, wynik);
    } else if (strcmp(dzialanie, "sub") == 0) {
        wynik = a - b;
        printf("Różnica: %d - %d = %d\n", a, b, wynik);
    } else if (strcmp(dzialanie, "mul") == 0) {
        wynik = a * b;
        printf("Iloczyn: %d * %d = %d\n", a, b, wynik);
    } else if (strcmp(dzialanie, "div") == 0) {
        if (b == 0) {
            printf("Błąd: dzielenie przez zero!\n");
            exit(1);
        }
        wynik = a / b;
        printf("Iloraz: %d / %d = %d\n", a, b, wynik);
    } else {
        printf("Nieznane działanie: %s\n", dzialanie);
        pokaz_uzycie(argv[0]);
    }

    return 0;
}