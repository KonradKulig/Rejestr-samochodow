
#include <cstdio>

#define SIZE 4

int main(){


    int x,y,val;

    int pos[2]= {0,0};
    int tab[SIZE][SIZE] = {{1,2,3,4},
                           {4,5,6,7},
                           {8,2,3,1},
                           {10,9,4,2}};

    val = tab[0][0];

    for (x=1;x<SIZE;x++){
        for (y=0;y<SIZE;y++){
            if (tab[x][y]>val){
                val = tab[x][y];
                pos[0]= x;
                pos[1] = y;

            }
        }
    }


    printf("KOLUMNA %d, RZAD %d , WARTOSC %d", pos[0], pos[1], val);





    return 0;
}















