#include <stdio.h>

int main() {
    int codigoPeca_1,numeroPeca_1,codigoPeca_2,numeroPeca_2;
    float valorUnitPeca_1,valorUnitPeca_2,total;
    scanf("%d %d %f",&codigoPeca_1,&numeroPeca_1,&valorUnitPeca_1);
    scanf("%d %d %f",&codigoPeca_2,&numeroPeca_2,&valorUnitPeca_2);
    total = numeroPeca_1*valorUnitPeca_1 + numeroPeca_2*valorUnitPeca_2;
    printf("VALOR A PAGAR: R$ %.2f\n",total);
    return 0;
}
