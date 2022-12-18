#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

int main(void)
{
    srand(time(NULL));
    system("cls & color A");

    for(;;) printf("%d",rand()%2);

    return 0;
}
