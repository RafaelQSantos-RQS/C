#include <stdio.h>

int main() {
    char nome;
    double salarioFixo,totalDeVendas;
    scanf("%s %lf %lf",&nome,&salarioFixo,&totalDeVendas);
    printf("TOTAL = R$ %.2lf\n",salarioFixo+totalDeVendas*0.15);
    return 0;
}
