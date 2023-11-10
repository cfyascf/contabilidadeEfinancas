#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

// ################################### CODIGO IZA ################################################

typedef struct 
{
    char nome[50];
    int idade; 
    char sexo;
    long long int cpf;
    char endereco[50];
    int rua;
    char  banco[50];
    long long int telefone;
    double renda;
    char ativo;

}clientes;

int tam = 10;
int quant = 0;
clientes listas [10];

typedef struct 
{
    char nome[50];
    int idade;
    char sexo;
    long long int cpf;
    char endereco[50];
    int rua;
    char cargo[50];
    char setor;
    long long int telefone;
    double salario;
    char ativo;

}funcionarios;

int cadastro(){
    if (quant < tam)
    {
        clientes c;

        scanf("%*c");

        printf("digite o nome: ");
        fgets(c.nome, sizeof(c.nome), stdin);
        c.nome[strcspn(c.nome, "\n")] = 0;

        printf("digite idade  e sexo m ou f :");
        scanf("%d %c", &c.idade, &c.sexo);
        getchar();

        printf("digite o cpf :");
        scanf("%lld", &c.cpf);
        getchar(); 

        printf("digite o bairro: ");
        fgets(c.endereco,sizeof(c.endereco), stdin);
        c.endereco[strcspn(c.endereco, "\n")] = 0;

        printf("numero o da casa: ");
        scanf("%d", &c.rua );
        getchar(); 

        printf("digite o banco: ");
        fgets(c.banco, sizeof(c.banco), stdin);
        c.endereco[strcspn(c.endereco, "\n")] = 0;   

        printf("numero de telefone: ");
        scanf("%lld", &c.telefone );
        getchar(); 
        
        printf("renda mensal (liquida): ");
        scanf("%lf", &c.renda);
        getchar(); 
            
        printf("o cliente e ativo ?, responta somente com S OU N:");
        scanf("%c", &c.ativo);
        getchar(); 

        listas [quant] = c;
        quant ++;
        return 1; 
    }
    else{
        printf("ERRO : VETOR CHEIO \n\n");
    }
}

int tama = 10;
funcionarios lista [10];
int quanto = 0;

void imprimir(){
    int i;
    for ( i = 0; i < quant; i++)
    {
        printf("nome :%s\n", listas[i].nome);
        printf ("idade :%d \nsexo : %c \n", listas[i].idade, listas[i].sexo);
        printf("cpf :%lld\n", listas[i].cpf);
        printf("bairro :%s", listas[i].endereco);
        printf(", %d\n", listas[i].rua);
        printf("banco :%s", listas[i].banco);
        printf("telefone :%lld\n", listas[i].telefone);
        printf("renda :%.2lf\n", listas[i].renda);
        printf("ativo: %c", listas[i].ativo);
    }
}

void salvar(){
    FILE *arq = fopen("clientes.txt", "w");
    int i;
    if(arq){
        for ( i = 0; i < quant; i++)
        {
            fprintf(arq, "nome :%s /", listas[i].nome);
            fprintf(arq, "idade :%d /", listas[i].idade);
            fprintf(arq, "sexo :%c /", listas[i].sexo);
            fprintf(arq, "cpf :%lld /", listas[i].cpf);
            fprintf(arq, "endereco :%s", listas[i].endereco);
            fprintf(arq, ", %d /", listas[i].rua);
            fprintf(arq, "banco :%s /", listas[i].banco);
            fprintf(arq, "telefone :%lld /", listas[i].telefone);
            fprintf(arq, "renda mensal :%.2lf /", listas[i].renda);
            fprintf(arq,"id do cliente :%d /", quant);
            fprintf(arq, "ativo: %c\n", listas[i].ativo);
            fprintf(arq, "_____________________________________________________________________");

        }
        fclose(arq);
    }
    else {
        printf("ERRO: NAO FOI POSSIVEL ABRIR O ARQUIVO");
    }
}

int cadastro_main(){
    int op;

    do{
    printf("\n1 - cadastrar cliente\n2 - imprimir cliente\n3 - salvar cliente em arquivo\n---------------------------\n4 - cadastrar funcionario\n5 - imprimir funcionario\n6 - salvar funcionario em arquivo\n 0- sair\n");
    scanf("%d", &op);
    switch (op)
    {
        case 0:
        printf("tchau...\n\n");
        break;

        case 1:
        cadastro();
        break;

        case 2:
        imprimir();
        break;

        case 3:
        salvar();
        printf("salvo em arquivos...\n");
        break;

        case 4:
        cadastrof();
        break;

        case 5:
        imprimirf();
        break;

        case 6:
        salvarf();
        printf("salvo em arquivos...\n");
        break;

    default:
        printf("opcao invalida. \n\n");
    }
    }while (op != 0);

return 0;}

// ################################### CODIGO IZA ################################################

// ################################### CODIGO JUAN ################################################

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
    fprintf(arq,"\nOperação Numero:%i \n Tipo de Opereção Financeira: %s \n Para: %s \n De: %s \n Data: %s \n Valor: %.2f \n",c,regi.tipo,regi.para,regi.de,regi.data,regi.valor);
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

int main_registro(){
    int m=-1,c;
    char linha[100];
    FILE*arq2=fopen("arquivo1.txt","r");
    if (arq2 == NULL){
        c=0;
    }else{
        fgets(linha,100,arq2);
        c=atoi(linha);
    };
    printf("%i",c);
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

// ################################### CODIGO JUAN ################################################



void menu(int *op){
    printf("\n ||| SOFTWARE DE CONTABILIDADE E FINANCAS ||| \n");
    printf("Selecione a opcao desejada!\n");
    printf("\n\n");
    printf("#############################################\n");
    printf("##                                         ##\n");
    printf("## [1] Cadastro de clientes e funcionarios ##\n");
    printf("##                                         ##\n");
    printf("## [2] Listar clientes ou funcionarios     ##\n");
    printf("##                                         ##\n");
    printf("## [3] Consultar clientes ou funcionarios  ##\n");
    printf("##                                         ##\n");
    printf("## [4] Registrar transacao financeira      ##\n");
    printf("##                                         ##\n");
    printf("## [5] Estimar folha de pagamento          ##\n");
    printf("##                                         ##\n");
    printf("## [6] Contas a pagar/receber              ##\n");
    printf("##                                         ##\n");
    printf("## [0] Sair                                ##\n");
    printf("##                                         ##\n");
    printf("#############################################\n");
    *op = _getch();
}

int main(){

    int op;
    menu(&op);

    while(1){
        switch(op){
            case 1:
                cadastro_main();
                break;

            case 2:
                listar();
                break;

            case 3:
                consultar();
                break;

            case 4:
                main_registro();
                break;
            
            case 5:
                folha();
                break;

            case 6:
                contas();
                break;
            
            case 0:
                printf("Encerrando o programa...\n");
                break;

            default:
                printf("Opcao nao registrada!\n");

        } 
    }

    return 0;
}