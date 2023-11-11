#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <locale.h>
#include <string.h>

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
    fprintf(arq," %i / %s / %s / %s / %s / %.2f \n",c,regi.tipo,regi.para,regi.de,regi.data,regi.valor);
    fclose(arq);
};
void con_fin(int c){
    printf("############################ CONSULTA DE OPERAÇÔES FINANCEIRA ##################");
    char linha[100];
    FILE * arq = fopen("arquivo.txt", "r");
    while (fgets(linha,sizeof(linha),arq) != NULL){
        printf("\n %s",linha);
    };
    printf("\n O total de consutas é %i \n",c);
    fclose(arq);
};
void pesq_id(){
    char peq[100],linha[100];
    FILE * arq = fopen("arquivo.txt","r");
    printf("##################### PESQUISA POR ID ##########################");
    printf("\nDIGITE O ID PARA PESQUISAR: ");
    fflush(stdin);
    gets(peq);
    while (fgets(linha,sizeof(linha),arq) != NULL){
        if (strstr(linha,peq) != NULL){
            printf("\n %s",linha);
        }
    };

}
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
        printf("\n ############### MENU #################### \n Escreva 1 para cadastrar Operações financeiras \n Escreva 2 para consutar Operações financeiras \n Escreva 3 para pesquisar Operações financeiras por ID \n Escreva 0 para sair \n");
        scanf("%i",&m);
        if (m == 1){
            c++;
            cad_fin(c);
        }else if(m == 2){
            con_fin(c);
        }else if(m == 3){   
            pesq_id();
        }else if(m == 0){
            FILE*arq2=fopen("arquivo1.txt","w");
            fprintf(arq2," %i ", c);
            fclose(arq2);                          
            return 0;
        };
    };
    return 0;
 }