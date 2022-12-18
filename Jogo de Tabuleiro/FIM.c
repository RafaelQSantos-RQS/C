#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

void efeitoMatrix(void){
    srand(time(NULL));
    system("cls & color A");
    for(int i=0;i<100000;i++){
        printf("%d",rand()%2);
        Sleep(0.5);
    }
}

int main(){
    efeitoMatrix();
    system("cls");
    printf("\n");
    printf("##########  ##########  ####            ####\n");
    printf("#               ##      ## ##          ## ##\n");
    printf("#               ##      ##  ##        ##  ##\n");
    printf("#               ##      ##   ##      ##   ##\n");
    printf("#####           ##      ##    ##    ##    ##\n");
    printf("#               ##      ##     ##  ##     ##\n");
    printf("#               ##      ##      ####      ##\n");
    printf("#               ##      ##                ##\n");
    printf("#               ##      ##                ##\n");
    printf("#           ##########  ##                ##\n");
    return 0;
}
