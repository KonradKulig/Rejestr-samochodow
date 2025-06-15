

#include <stdio.h>
#define Size 10

void printArray(int *array)
{
    for (int i = 0; i < Size; i++) {
        printf("Tablica[%d]= %d\n",i, *(array +i));
    }
}
int findminimum(int *array) {
    int minimum= *array;
    for (int i = 1; i < Size; i++) {
        if (*(array +i) < minimum) {
            minimum = *(array +i);
        }
    }
    return minimum;
}
int findmaximum(int *array) {
    int maximum = *array;
    for (int i = 0; i < Size; i++) {
        if (*(array +i) > maximum) {
            maximum =*(array +i);
        }
    }
    return maximum;
}

float findaverage(int *array) {
    int sum=0;
    for (int i = 0; i < Size; i++) {
        sum+=*(array+i);
    }
    float average=(float) sum / Size;
    return average;
}
FILE *fptr;
int save(int *array)
{
    fptr = fopen("tablica.txt", "w");
    if (fptr ==0){
        return 1;
    }
    for (int i=0; i < Size; i++){
        fprintf(fptr,"\n %d \n", array[i]);
    }
    fclose(fptr);
    return 0;
}
int load(int *array) {
    FILE *fptr;
    fptr = fopen("tablica.txt", "r");
    if (fptr == NULL) {
        printf("Brak pliku.\n\n");
        return 1;
    }
    int i = 0;
    while (fscanf(fptr, "%d", &array[i]) == 1) {
        i++;
        if (i >= Size)
            break;
    }
    fclose(fptr);
    printf("Wczytano tablice z pliku.\n\n");
    return 0;
}
void menu(void){
    printf("1.Wyswietl tabele\n");
    printf("2.Wprowadz wartosci do tabeli\n");
    printf("3.Zdefiniuj najmniejsza wartosc\n");
    printf("4.Zdefiniuj majwieksza warotsc\n");
    printf("5.Zdefiniuj srednia wartosc\n");
    printf("6.Zapisz do pliku\n");
    printf("7.Wczytaj z pliku\n");
    printf("0.Wyjscie\n");
    printf("wybierz wlasciowa opcje\n\n");
}
int main() {
    int array[Size]= {1,2,3,4,5,6,7,8,9,10};
    int i=array[0];
    int option= 0;
    int errorCode=0;
    printf("Tabela\n");
    do{
        menu();
        scanf("%d",&option);

        switch(option){
            case 0:
                break;
            case 1:
                printArray(array);
                break;
            case 2:
                for (int i = 0; i < Size; i++) {
                    printf("%d:",i);
                    scanf("%d", &array[i]);
                }
                break;
            case 3:
                findminimum(array);
                printf("Najmniejsza wartosc %d\n\n", findminimum(array));
                break;
            case 4:
                findmaximum(array);
                printf("Najwieksza wartosc %d\n\n", findmaximum(array));
                break;
            case 5:
                findaverage(array);
                printf("Srednia wartosc %f\n\n", findaverage(array));
                break;
            case 6:
                printf("Zapisaywanie do pliku\n\n");
                errorCode= save(array);
                if(!errorCode){
                    printf("Zapisano do pliku \n\n");
                }
                break;
            case 7:
                errorCode = load(array);
                if (!errorCode)
                    printf("Dane wczytane poprawnie z pliku.\n");
                break;
            default:
                printf("Wprowadz poprawna wartosc\n");
        }
    }
    while (option !=0);

    printf("Koniec programu");

    return 0;
}