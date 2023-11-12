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
    fprintf(arq,"Operação Numero:%i \n Tipo de Opereção Financeira: %s \n Para: %s \n De: %s \n Data: %s \n Valor: %.2f \n \n",c,regi.tipo,regi.para,regi.de,regi.data,regi.valor);
    fclose(arq);
};
void con_fin(int c){
    printf("############################ CONSULTA DE OPERAÇÔES FINANCEIRA ##################");
    char linha[100];
    FILE * arq = fopen("arquivo.txt", "r");
    while (fgets(linha,sizeof(linha),arq) != NULL){
        printf("%s",linha);
    };
    printf("\n O total de consutas é %i \n",c);
    fclose(arq);
};
void pesq_id(){
    printf("############################# PESQUISAR POR ID ############################");
    char **linha = NULL,contd[100];
    int c_linha=0,i,flag=0;
    FILE * arq = fopen("arquivo.txt","r");
    while( fgets(contd,sizeof(contd),arq) !=NULL){
        c_linha++;
        linha = realloc (linha, c_linha * sizeof(char*));
        linha[c_linha -1]= malloc (strlen(contd)+1);
        strcpy(linha[c_linha-1],contd);
    };
    printf("\n DIGITE O ID DA PESQUISA ");
    fflush(stdin);
    gets(contd);
    for ( i=0;i < c_linha; i+=7 ){
        if (strstr(linha[i],contd) != NULL){
            printf ("%s",linha[i]);
            printf ("%s",linha[i+1]);
            printf ("%s",linha[i+2]);
            printf ("%s",linha[i+3]);
            printf ("%s",linha[i+4]);
            printf ("%s",linha[i+5]);
            flag++;
        };
    };
    fclose(arq);
    if (flag==0){
        printf("ID não encontrado");
    };
};
void pesq_tipo(){
        printf("############################# PESQUISAR POR TIPO ############################");
    char **linha = NULL,contd[100];
    int c_linha=0,i,flag=0;
    FILE * arq = fopen("arquivo.txt","r");
    while( fgets(contd,sizeof(contd),arq) !=NULL){
        c_linha++;
        linha = realloc (linha, c_linha * sizeof(char*));
        linha[c_linha -1]= malloc (strlen(contd)+1);
        strcpy(linha[c_linha-1],contd);
    };
    printf("\n DIGITE O TIPO:");
    fflush(stdin);
    gets(contd);
    for ( i=1;i < c_linha; i+=7 ){
        if (strstr(linha[i],contd) != NULL){
            printf ("%s",linha[i-1]);
            printf ("%s",linha[i]);
            printf ("%s",linha[i+1]);
            printf ("%s",linha[i+2]);
            printf ("%s",linha[i+3]);
            printf ("%s",linha[i+4]);
            flag++;
        };
    };
    fclose(arq);
    if (flag==0){
        printf("Tipo não encontrado");
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
        printf("\n ############### MENU #################### \n Escreva 1 para cadastrar Operações financeiras \n Escreva 2 para consutar Operações financeiras \n Escreva 3 para pesquisar por ID \n Escreva 4 para pesquisar por tipo \n Escreva 0 para sair \n");
        scanf("%i",&m);
        if (m == 1){
            c++;
            cad_fin(c);
        }else if(m == 2){
            con_fin(c);
        }else if(m == 3){
            pesq_id();
        }else if( m == 4){
            pesq_tipo();
        }else if(m == 0){
            FILE*arq2=fopen("arquivo1.txt","w");
            fprintf(arq2," %i ", c);
            fclose(arq2);                          
            return 0;
        };
    };
    return 0;
 }