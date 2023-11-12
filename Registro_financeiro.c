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

int cad_fin (int c){
    FILE * arq = fopen("arquivo.txt","a");
    struct reg regi;
    printf("\n ###########REGISTRO DE OPERAÇÂO FINANCEIRA############## \n");
    regi.regid=c+1;
    c++;
    printf("Escreva o tipo de operação financeira ");
    fflush(stdin);
    gets(regi.tipo);
    printf("Escreva quem recebeu a operação financeira ");
    fflush(stdin);
    gets(regi.para);
    printf("Escreva quem pagou a operação financeira ");
    fflush(stdin);
    gets(regi.de);
    printf("Escreva a data da operação financeira ");
    fflush(stdin);
    gets(regi.data);
    printf("Escreva o valor da operação financeira ");
    scanf("%f",&regi.valor);
    fprintf(arq,"\n Operação Numero:%i \n Tipo de Opereção Financeira: %s \n Recebedor: %s \n Pagador: %s \n Data: %s \n Valor: %.2f \n",c,regi.tipo,regi.para,regi.de,regi.data,regi.valor);
    fclose(arq);
    return c;
};
void con_fin(int c){
    printf("############################ CONSULTA DE OPERAÇÔES FINANCEIRA ################## \n");
    char **linha = NULL;
    char line[100];
    int  c_linha=0;
    int  i;

    FILE * arq = fopen("arquivo.txt", "r");
    while( fgets(line,sizeof(line),arq) !=NULL){
        c_linha++;
        linha = realloc (linha, c_linha * sizeof(char*));
        linha[c_linha -1]= malloc (strlen(line)+1);
        strcpy(linha[c_linha-1],line);
    };
    for (i=0 ; i< c_linha ; i++){
        if (i != 0){
            printf("%s",linha[i]);
        }
        free(linha[i]);
    }
    printf("\n O total de consutas é %i \n",c);
    fclose(arq);
    free(linha);
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
    for ( i=1;i < c_linha; i+=7 ){
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

    if (flag==0){
        printf("ID não encontrado");
    };
    fclose(arq);
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
    printf("\n DIGITE O TIPO: ");
    fflush(stdin);
    gets(contd);
    for ( i=2;i < c_linha; i+=7 ){
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
};
void pesq_rece(){
    printf("############################# PESQUISAR POR RECEBEDOR ############################");
    char **linha = NULL,contd[100];
    int c_linha=0,i,flag=0;
    FILE * arq = fopen("arquivo.txt","r");
    while( fgets(contd,sizeof(contd),arq) !=NULL){
        c_linha++;
        linha = realloc (linha, c_linha * sizeof(char*));
        linha[c_linha -1]= malloc (strlen(contd)+1);
        strcpy(linha[c_linha-1],contd);
    };
    printf("\n DIGITE O RECEBEDOR: ");
    fflush(stdin);
    gets(contd);
    for ( i=3;i < c_linha; i+=7 ){
        if (strstr(linha[i],contd) != NULL){
            printf ("%s",linha[i-2]);
            printf ("%s",linha[i-1]);
            printf ("%s",linha[i]);
            printf ("%s",linha[i+1]);
            printf ("%s",linha[i+2]);
            printf ("%s",linha[i+3]);
            flag++;
        };
    };
    fclose(arq);
    if (flag==0){
        printf("Recebedor não encontrado");
    };
};
void pesq_paga(){
    printf("############################# PESQUISAR POR PAGADOR ############################");
    char **linha = NULL,contd[100];
    int c_linha=0,i,flag=0;
    FILE * arq = fopen("arquivo.txt","r");
    while( fgets(contd,sizeof(contd),arq) !=NULL){
        c_linha++;
        linha = realloc (linha, c_linha * sizeof(char*));
        linha[c_linha -1]= malloc (strlen(contd)+1);
        strcpy(linha[c_linha-1],contd);
    };
    printf("\n DIGITE O PAGADOR: ");
    fflush(stdin);
    gets(contd);
    for ( i=4;i < c_linha; i+=7 ){
        if (strstr(linha[i],contd) != NULL){
            printf ("%s",linha[i-3]);
            printf ("%s",linha[i-2]);
            printf ("%s",linha[i-1]);
            printf ("%s",linha[i]);
            printf ("%s",linha[i+1]);
            printf ("%s",linha[i+2]);
            flag++;
        };
    };
    fclose(arq);
    if (flag==0){
        printf("Pagador não encontrado");
    };
};
void pesq_data(){
    printf("############################# PESQUISAR POR DATA ############################");
    char **linha = NULL,contd[100];
    int c_linha=0,i,flag=0;
    FILE * arq = fopen("arquivo.txt","r");
    while( fgets(contd,sizeof(contd),arq) !=NULL){
        c_linha++;
        linha = realloc (linha, c_linha * sizeof(char*));
        linha[c_linha -1]= malloc (strlen(contd)+1);
        strcpy(linha[c_linha-1],contd);
    };
    printf("\n DIGITE A DATA: ");
    fflush(stdin);
    gets(contd);
    for ( i=5;i < c_linha; i+=7 ){
        if (strstr(linha[i],contd) != NULL){
            printf ("%s",linha[i-4]);
            printf ("%s",linha[i-3]);
            printf ("%s",linha[i-2]);
            printf ("%s",linha[i-1]);
            printf ("%s",linha[i]);
            printf ("%s",linha[i+1]);
            flag++;
        };
    };
    fclose(arq);
    if (flag==0){
        printf("Data não encontrado");
    };
};
void pesq_valor(){
    printf("############################# PESQUISAR POR VALOR ############################");
    char **linha = NULL,contd[100];
    int c_linha=0,i,flag=0;
    FILE * arq = fopen("arquivo.txt","r");
    while( fgets(contd,sizeof(contd),arq) !=NULL){
        c_linha++;
        linha = realloc (linha, c_linha * sizeof(char*));
        linha[c_linha -1]= malloc (strlen(contd)+1);
        strcpy(linha[c_linha-1],contd);
    };
    printf("\n DIGITE O VALOR: ");
    fflush(stdin);
    gets(contd);
    for ( i=6;i < c_linha; i+=7 ){
        if (strstr(linha[i],contd) != NULL){
            printf ("%s",linha[i-5]);
            printf ("%s",linha[i-4]);
            printf ("%s",linha[i-3]);
            printf ("%s",linha[i-2]);
            printf ("%s",linha[i-1]);
            printf ("%s",linha[i]);
            flag++;
        };
    };
    fclose(arq);
    if (flag==0){
        printf("Valor não encontrado");
    };
};
int desc_id_r(){
    int c;
    char linha[100];
    FILE*arq=fopen("arquivo.txt","r");
    if (arq == NULL){
        c=0;
    }else{
        fgets(linha,100,arq);
        c=atoi(linha);

    };
    fclose(arq); 
    return c;
};
void salvar_id(int c){
            FILE*arq=fopen("arquivo.txt","r+");
            fprintf(arq,"%i", c);
            fclose(arq); 
};
int main(){
    setlocale (LC_ALL,"PORTUGUESE");
    int m=-1,c;
    c = desc_id_r();          
    while(m != 0){
        printf("\n ############### MENU #################### \n Escreva 1 para cadastrar Operações financeiras \n Escreva 2 para consutar Operações financeiras \n Escreva 3 para pesquisar por ID \n Escreva 4 para pesquisar por tipo \n Escreva 5 para pesquisar por recebedor \n Escreva 6 para pesquisar por pagador \n Escreva 7 para pesquisar por data \n Escreva 8 para pesquisar por valor \n Escreva 0 para sair \n");
        scanf("%i",&m);
        if (m == 1){
            c=cad_fin(c);
        }else if(m == 2){
            con_fin(c);
        }else if(m == 3){
            pesq_id();
        }else if( m == 4){
            pesq_tipo();
        }else if ( m == 5){
            pesq_rece();
        }else if( m == 6){
            pesq_paga();
        }else if (m == 7){
            pesq_data();
        }else if (m == 8){
            pesq_valor();
        }else if(m == 0){    
            salvar_id(c);                     
            return 0;
        };
    };
    return 0;
 }