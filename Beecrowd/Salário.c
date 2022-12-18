#include <stdio.h>

int main() {
    int numero,horas;
    float valorPorHora;
    scanf("%d %d %f",&numero,&horas,&valorPorHora);
    printf("NUMBER = %d\n",numero);
    printf("SALARY = U$ %.2f\n",horas*valorPorHora);
    return 0;
}
