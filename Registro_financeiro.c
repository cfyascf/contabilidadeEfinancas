#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <locale.h>


struct reg{
    int regid ;
    float valor;
    char tipo[50], de[50], para[50] , data[11] ;
    };

void cad_fin (){
    FILE * arq = fopen("arquivo.txt","r+");
    if (arq == NULL){
        printf("não foi possivel ler arquivo");
        return 0;
    };
    struct reg regi;
    printf("\n ###########REGISTRO DE OPERAÇÂO FINANCEIRA############## \n");
    regi.regid=1;
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
    fwrite(&regi,sizeof(struct reg),1,arq);
    fclose(arq);
}
int main(){
    setlocale (LC_ALL,"PORTUGUESE");
    int m;
    while(m == 0){
        printf("\n ###############MENU#################### \n Escreva 1 para cadastrar Operações financeiras \n Escreva 2 para consutar Operações financeiras \n Escreva 0 para sair \n");
        scanf("%i",&m);
        if (m == 1){
            cad_fin();
        }else if(m == 2){

        }else if(m == 0){
            return 0;
        };
    };
    return 0;
 }