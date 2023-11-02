#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <locale.h>

struct reg{
    int regid ;
    float valor;
    char tipo[50], de[50], para[50] , data[11] ;
    };

void cad_fin (int c){
    FILE * arq = fopen("arquivo.txt","a");
    struct reg regi;
    printf("\n ###########REGISTRO DE OPERAÇÂO FINANCEIRA############## \n");
    regi.regid=c;
    printf("Escreva o tipo de operação financeira");
    fflush(stdin);
    gets(regi.tipo);
    printf("Escreva o para quem foi operação financeira");
    fflush(stdin);
    gets(regi.para);
    printf("Escreva de quem foi a operação financeira");
    fflush(stdin);
    gets(regi.de);
    printf("Escreva a data da operação financeira");
    fflush(stdin);
    gets(regi.data);
    printf("Escreva o valor da operação financeira");
    scanf("%f",&regi.valor);
    // fwrite(&regi,sizeof(struct reg),1,arq);       // não consegui fazer funcionar assim 
    fprintf(arq,"\n Operação Numero:%i \n Tipo de Opereção Financeira: %s \n Para: %s \n De: %s \n Data: %s \n Valor: %.2f",c,regi.tipo,regi.para,regi.de,regi.data,regi.valor);
    fclose(arq);
};
void con_fin(int c){
    printf("############################ CONSULTA DE OPERAÇÔES FINANCEIRA ##################");
    char linha[100];
    FILE * arq = fopen("arquivo.txt", "r");
    printf("\n O total de consutas é %i \n",c);
    while (fgets(linha,sizeof(linha),arq) != NULL){
        printf("%s",linha);
    };
    fclose(arq);
};
int main(){
    setlocale (LC_ALL,"PORTUGUESE");
    int m,c=0;
    FILE*arq=fopen("arquivo.txt","w");  // pra resetar e a id funcionar tentar arrumar depois
    fclose(arq);
    
    while(m != 0){
        printf("\n ###############MENU#################### \n Escreva 1 para cadastrar Operações financeiras \n Escreva 2 para consutar Operações financeiras \n Escreva 0 para sair \n");
        scanf("%i",&m);
        if (m == 1){
            c++;
            cad_fin(c);
        }else if(m == 2){
            con_fin(c);
        }else if(m == 0){
            return 0;
        };
    };

    return 0;
 }