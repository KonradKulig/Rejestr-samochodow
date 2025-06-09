#include <stdio.h>
#define MAX 20
void printlist (char name[][50], int year[], char registration[][20], int mileage[], int count) {
    if (count == 0) {
        printf("Brak samochodow do wyswietlenia uzupelnij liste\n\n");
        return;
    }
    for (int i = 0; i < count; i++) {
        printf("[%d.]| %s | %d | %s | %dkm| \n\n",i + 1 , name[i], year [i], registration[i], mileage[i]);
    }
}
void addcar(char name[][50], int year[], char registration[][20], int mileage[], int *count) {
    if (*count >= MAX) {
        printf("Wprowadzona maksymalna liczbe samochodow.\n\n");
        return;
    }
    printf("Marka:");
    scanf("%s", name[*count]);

    printf("Rok produkcji:");
    scanf("%d", &year[*count]);

    printf("Numer rejestracyjny:");
    scanf("%s", registration[*count]);

    printf("Przebieg:");
    scanf("%d", &mileage[*count]);
    (*count)++;
}
FILE *fptr;
 int save(char name[][50], int year[], char registration[][20], int mileage[], int count) {
    fptr = fopen("Samochody.txt","w");
        if (fptr == NULL) {
            return 1;
        }
    for (int i = 0; i < count; i++) {
        fprintf(fptr, "%s;%d;%s;%d\n", name[i], year[i], registration[i], mileage[i]);
    }
    fclose(fptr);
     return 0;
}
int load (char name[][50], int year[], char registration[][20], int mileage[], int *count) {
     FILE *fptr;
     fptr= fopen("Samochody.txt","r");
     if (fptr == NULL) {
         printf("Brak pliku.\n\n");
         return 1;
     }
     *count = 0;
     while (fscanf(fptr,"%49[^;];%d;%19[^;];%d\n", name[*count], &year[*count], registration[*count], &mileage[*count])==4) {
         (*count)++;
         if (*count >= MAX)
             break;
     }
     fclose(fptr);
     printf("Wczytano %d samochodow z pliku.\n", *count);
     return 0;
 }
void menu(void){
    printf("1.Wyswietl liste samochodow\n");
    printf("2.Dodaj Samochod\n");
    printf("3.Zapisz do pliku\n");
    printf("4.Wczytanie z pliku\n");
    printf("0.Wyjscie\n\n");
}
int main(void) {
    int year[MAX];
    int mileage[MAX];
    int count=0;
    int option=0;
    int errorcode=0;
    char name[MAX][50];
    char registration[MAX][20];
    printf("Menu\n");
    do {
        menu();
        scanf("%d",&option);

        switch(option) {
            case 0:
                break;
            case 1:
                printlist(name,year,registration,mileage,count);
            break;
            case 2:
                addcar(name, year,registration, mileage, &count);
            break;
            case 3:
                printf("Zapisywanie do pliku...\n\n");
            errorcode=save(name,year,registration,mileage,count);
            if (!errorcode) {
                printf("Zapisano do pliku\n\n");
            }
            else {
                printf("Blad zapisu do pliku");
            }
                    break;
            case 4:
                printf("Wczytywanie z pliku...\n");
            errorcode=load(name,year,registration,mileage,&count);
            if (!errorcode) {
                printf("Wczytywanie zakonczone pomyslnie\n\n");
            }
            else {
                printf("Blad wczytania z pliku");
            }
            break;
            default:
                printf("Nieprawidlowa opcja\n\n");
        }
    }while (option !=0);
        printf("Koniec programu");
        return 0;
    }




