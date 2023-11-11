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
    printf("Escreva o tipo de operação financeira ");
    fflush(stdin);
    gets(regi.tipo);
    printf("Escreva o para quem foi operação financeira ");
    fflush(stdin);
    gets(regi.para);
    printf("Escreva de quem foi a operação financeira ");
    fflush(stdin);
    gets(regi.de);
    printf("Escreva a data da operação financeira ");
    fflush(stdin);
    gets(regi.data);
    printf("Escreva o valor da operação financeira ");
    scanf("%f",&regi.valor);
    fprintf(arq,"/ %i / %s / %s / %s / %s / %.2f \n",c,regi.tipo,regi.para,regi.de,regi.data,regi.valor);
    fclose(arq);
};
void con_fin(int c){
    printf("############################ CONSULTA DE OPERAÇÔES FINANCEIRA ##################");
    struct reg regi;
    int j;
    char linha[100];
    FILE * arq = fopen("arquivo.txt", "r");
    while (fgets(linha,sizeof(linha),arq) != NULL){
        fscanf(arq,"/ %i / %d / %d / %d / %d / %f ",&j,&regi.tipo,&regi.para,&regi.de,&regi.data,&regi.valor);
        printf("%s",linha);
        printf("/ %i / %d / %d / %d / %d / %f",j,regi.tipo,regi.para,regi.de,regi.data,regi.valor);
    };
    printf("\n O total de consutas é %i \n",c);
    fclose(arq);
};
int main(){
    setlocale (LC_ALL,"PORTUGUESE");
    int m=-1,c;
    char linha[100];
    FILE*arq2=fopen("arquivo1.txt","r");
    if (arq2 == NULL){
        c=0;
    }else{
        fgets(linha,100,arq2);
        c=atoi(linha);
    };
    fclose(arq2);            
    while(m != 0){
        printf("\n ############### MENU #################### \n Escreva 1 para cadastrar Operações financeiras \n Escreva 2 para consutar Operações financeiras \n Escreva 0 para sair \n");
        scanf("%i",&m);
        if (m == 1){
            c++;
            cad_fin(c);
        }else if(m == 2){
            con_fin(c);
        }else if(m == 0){
            FILE*arq2=fopen("arquivo1.txt","w");
            fprintf(arq2," %i ", c);
            fclose(arq2);                          
            return 0;
        };
    };
    return 0;
 }