#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <Windows.h>

typedef struct {
    char nome[50];
    char sobrenome[50];
    int idade;
    char sexo;
    char cpf[15];
    char estado[50];
    char cidade[50];
    char banco[50];
    char telefone[11];
    double renda;
    char ativo;
} Cliente;

typedef struct
{
    char pagar[50];
    char receber[50];
    float valor;
    char data_vencimento[11];
    char descricao[100];
} Reg;

typedef struct {
    char nome[50];
    char sobrenome[50];
    int idade;
    char sexo;
    char cpf[15];
    char estado[50];
    char cidade[50];
    char cargo[50];
    char setor;
    char telefone[11];
    double salario;
    char ativo;
} Funcionario;

typedef struct {
    int id;
    float valor;
    char tipo[50];
    char de[50];
    char para[50];
    char data[11];
} OperacaoFinanceira;

typedef struct {
    int qtdDependentes;
    float salarioBruto;
    float gratificacao;
    char valeTransporte;
    char planoSaude; 
    float descontoVT;
    float descontoPlanoSaude;
    float FGTS;
    float descontoINSS;
    float salarioFamilia;
    float impostoRenda;
    float salarioLiquido;
} FolhaPagamento;

void main_menu(int *op){
    printf("\n ||| SOFTWARE DE CONTABILIDADE E FINANCAS ||| \n");
    printf("Selecione a opcao desejada!\n");
    printf("\n\n");
    printf("#######################################\n");
    printf("##                                   ##\n");
    printf("## [1] Cadastrar                     ##\n");
    printf("##                                   ##\n");
    printf("## [2] Gerar relatorio               ##\n");
    printf("##                                   ##\n");
    printf("## [3] Consultar                     ##\n");
    printf("##                                   ##\n");
    printf("## [4] Estimar folha de pagamento    ##\n");
    printf("##                                   ##\n");
    printf("## [5] Contas a pagar/receber        ##\n");
    printf("##                                   ##\n");
    printf("## [0] Sair                          ##\n");
    printf("##                                   ##\n");
    printf("#######################################\n");
    scanf("%d", op);
    system("cls");
}

void sec_menu(int *sec_op){
    printf("###############################\n");
    printf("##                           ##\n");
    printf("## [1] Cliente               ##\n");
    printf("##                           ##\n");
    printf("## [2] Funcionario           ##\n");
    printf("##                           ##\n");
    printf("## [3] Operacao financeira   ##\n");
    printf("##                           ##\n");
    printf("## [0] Voltar                ##\n");
    printf("##                           ##\n");
    printf("###############################\n");
    scanf("%d", sec_op);
    system("cls");
}

void cadastroCliente(FILE *file_c) {
    file_c = fopen("registro_clientes.txt", "a+");
    if (file_c == NULL) {
        printf("Erro ao abrir o arquivo de rstro!\n");
        return;
    }

    char line[100];

    Cliente c;
    printf("Insira os dados para cadastrar cliente!\n\n");

    Sleep(3000);
    system("cls");

    printf("Nome: ");
    scanf(" %s", c.nome);

    printf("Sobrenome: ");
    scanf(" %s", c.sobrenome);

    printf("Idade: ");
    scanf("%d", &c.idade);

    printf("Sexo (f, m): ");
    scanf(" %c", &c.sexo);

    printf("CPF: ");
    scanf(" %s", c.cpf);

    printf("UF: ");
    scanf(" %s", c.estado);

    printf("Cidade: ");
    scanf(" %s", c.cidade);

    printf("Banco: ");
    scanf(" %s", c.banco);

    printf("Telefone (99999999999): ");
    scanf(" %s", c.telefone);

    printf("Renda mensal (liquida): ");
    scanf("%lf", &c.renda);

    printf("Cliente ativo? (s, n): ");
    scanf(" %c", &c.ativo);

    system("cls");
    printf("Registrando dados...\n\n");

    while (fgets(line, sizeof(line), file_c)) {
        int size = strlen(line);

        if (size > 0 && line[size - 1] == '\n') {
            line[size - 1] = '\0';
        }

        if (strstr(line, c.cpf) != NULL) {
            printf("Cliente ja cadastrado!\n");
            return;
        }
        else{
            printf("Cliente cadastrado com sucesso!\n");
        }
    }

    fprintf(file_c, "%s %s / %d anos / Sexo: %c / CPF: %s / %s %s/ %s / %s / Renda: %.2lf / Ativo? %c\n", c.nome, c.sobrenome, c.idade, c.sexo, c.cpf, c.estado, c.cidade, c.banco, c.telefone, c.renda, c.ativo);

    Sleep(3000);
    system("cls");

    fclose(file_c);
}

void cadastroFuncionario(FILE *file_f) {
    file_f = fopen("registro_funcionarios.txt", "a+");
    if (file_f == NULL) {
        printf("Erro ao abrir o arquivo de funcionarios!\n");
        return;
    }

    char line[100];

    Funcionario f;

    printf("Insira os dados para cadastrar funcionario!\n\n");

    Sleep(3000);
    system("cls");

    printf("Nome: ");
    scanf(" %s", f.nome);

    printf("Sobrenome: ");
    scanf(" %s", f.sobrenome);

    printf("Idade: ");
    scanf("%d", &f.idade);

    printf("Sexo (f, m): ");
    scanf(" %c", &f.sexo);

    printf("CPF: ");
    scanf(" %s", f.cpf);

    printf("UF: ");
    scanf(" %s", f.estado);

    printf("Cidade: ");
    scanf(" %s", f.cidade);

    printf("Cargo: ");
    scanf(" %s", f.cargo);

    printf("Setor (-a -b -c -d): ");
    scanf(" %c", &f.setor);

    printf("Telefone (99 9 9999-9999): ");
    scanf(" %s", f.telefone);

    printf("Salario: ");
    scanf("%lf", &f.salario);

    printf("Funcionario ativo? (s, n): ");
    scanf(" %c", &f.ativo);

    system("cls");
    printf("Registrando dados...\n\n");

    while (fgets(line, sizeof(line), file_f)) {
        int size = strlen(line);

        if (size > 0 && line[size - 1] == '\n') {
            line[size - 1] = '\0';
        }

        if (strstr(line, f.cpf) != NULL) {
            printf("Funcionario ja cadastrado!\n");
            return 0;
        }
        else{
            printf("Funcionario cadastrado com sucesso!\n");
        }
    }

    fprintf(file_f, "%s %s / %d anos / Sexo: %c / CPF: %s / %s %s / %s / Setor: %c / %s / Salario: %.2lf / Ativo? %c\n", f.nome, f.sobrenome, f.idade, f.sexo, f.cpf, f.estado, f.cidade, f.cargo, f.setor, f.telefone, f.salario, f.ativo);

    Sleep(3000);
    system("cls");

    fclose(file_f);
}



// juan
int cadastroOperacaoFinanceira (FILE * file_r,int c){
    file_r = fopen("registro_transacao_financeira.txt", "a+");

    OperacaoFinanceira r;

    printf("Insira os dados para registrar operacao financeira! \n\n");

    Sleep(3000);
    system("cls");
    c++;
    r.id = c;
 
    printf("Tipo de operacao (receita, despesa ou transferencia): ");
    fflush(stdin);
    gets(r.tipo);
    
    printf("De: ");
    fflush(stdin);
    gets(r.de);

    printf("Para: ");
    fflush(stdin);
    gets(r.para);

    printf("Data: ");
    fflush(stdin);
    gets(r.data);

    printf("Valor: ");
    scanf("%f",&r.valor);

    system("cls");
    printf("Registrando dados...\n\n");

    fprintf(file_r,"\n Operação Numero:%i \n Tipo de Opereção Financeira: %s \n Recebedor: %s \n Pagador: %s \n Data: %s \n Valor: %.2f \n", r.id, r.tipo, r.para, r.de, r.data, r.valor);

    Sleep(3000);

    printf("Operacao cadastrada com sucesso!\n");

    Sleep(3000);
    system("cls");

    fclose(file_r);
    return c;
}
void salvar_id(int c){
            FILE*arq=fopen("registro_transacao_financeira.txt","r+");
            fprintf(arq,"%i",c);
            fclose(arq); 
}
int desc_id_r(){
    int c;
    char linha[100];
    FILE*arq=fopen("registro_transacao_financeira.txt","r");
    if (arq == NULL){
        c=0;
    }else{
        fgets(linha,100,arq);
        c=atoi(linha);

    };
    fclose(arq); 
    return c;
}
void relatorioOperacaoFinanceira (FILE * file_r){
    file_r = fopen("registro_transacao_financeira.txt", "a+");
    
    char **linha = NULL;
    char line[100];
    int  c_linha=0;
    int  i;

    while( fgets(line,sizeof(line),file_r) !=NULL){
        c_linha++;
        linha = realloc (linha, c_linha * sizeof(char*));
        linha[c_linha -1]= malloc (strlen(line)+1);
        strcpy(linha[c_linha-1],line);
    };

    for (i=1 ; i< c_linha ; i++){
            printf("%s",linha[i]);
        free(linha[i]);
    }

    free(linha);
    fclose(file_r);
}
void buscarOperacaoFinanceira(FILE * file_r){
    file_r = fopen("registro_transacao_financeira.txt", "r");

    char **linha = NULL;
    char line[100],contd[100];
    char id[10];
    int c_linha=0,i,flag=0,opc=-1;

    printf("###############################\n");
    printf("##                           ##\n");
    printf("## [1] Buscar por ID         ##\n");
    printf("##                           ##\n");
    printf("## [2] Buscar por tipo       ##\n");
    printf("##                           ##\n");
    printf("## [3] Buscar por recebedor  ##\n");
    printf("##                           ##\n");
    printf("## [4] Buscar por pagador    ##\n");
    printf("##                           ##\n");
    printf("## [5] Buscar por data       ##\n");
    printf("##                           ##\n");
    printf("## [6] Buscar por valor      ##\n");
    printf("##                           ##\n");
    printf("## [0] Voltar                ##\n");
    printf("##                           ##\n");
    printf("###############################\n");
    scanf("%d", &opc);
    system("cls");
    while( fgets(line,sizeof(line),file_r) !=NULL){
        c_linha++;
        linha = realloc (linha, c_linha * sizeof(char*));
        linha[c_linha -1]= malloc (strlen(line)+1);
        strcpy(linha[c_linha-1],line);
    };
    fclose(file_r);

    if (opc == 1){
        printf("Insira o ID da operacao para buscar: ");
        fflush(stdin);
        gets(id);
        flag=0;

        for ( i=1;i < c_linha; i+=7 ){
            if (strstr(linha[i],id) != NULL){
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
            printf("ID nao encontrado");
        };
    }else if(opc == 2){
        flag=0;
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
    if (flag==0){printf("Tipo não encontrado");};
    }else if(opc == 3){
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
    if (flag==0){printf("Recebedor não encontrado");};
    }else if(opc == 4){
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
    if (flag==0){printf("Pagador não encontrado");};
    }else if( opc == 5){
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
    if (flag==0){printf("Data não encontrado");};
    }else if (opc == 6){
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
    if (flag==0){printf("Valor não encontrado");};
    }else if (opc == 0){
        printf("Saindo ...");
        Sleep(2000);
    };
}
// fim juan
// Rafa
void register_payment(Reg *r)
{
    int i, id, qtd;
    FILE*file;
    file = fopen("teste.txt", "a");
    srand(time(NULL));

    printf("\nDigite a quantidade de contas que voce deseja pagar: ");
    scanf("%d", &qtd);

    for (i = 0; i < qtd; i++)
    {
        id = rand() % 1000;
        printf("\n --- Conta %i ---\n\n", id);

        printf("\nDigite o nome do pagador: ");
        scanf("%s", r[i].pagar);

        printf("\nDigite o nome de quem ira receber: ");
        scanf("%s", r[i].receber);

        printf("\nDigite o valor: ");
        scanf("%f", &r[i].valor);

        printf("\nDigite a data de vencimento(dd/mm/aaaa): ");
        scanf("%s", r[i].data_vencimento);

        printf("\nDigite uma descricao da conta: ");
        scanf("%s", r[i].descricao);
        fprintf(file, "--- conta %i ---\nQuem vai pagar: %s\nQuem vai receber: %s\nValor a ser pago: %.2f\nData de vencimento: %s\nDescrição da conta: %s\n", id, r[i].pagar, r[i].receber, r[i].valor, r[i].data_vencimento, r[i].descricao);
        printf("\n --- SEU PAGAMENTO FOI CONCLUIDO COM SUCESSO! --- \n");
    }
    fclose(file);
}

void show_bills()
{
    printf("\n --- Contas a receber --- \n");
    char line[100];
    FILE *file;
    file = fopen("teste.txt", "r");
    while (fgets(line, sizeof(line), file) != NULL)
    {
        printf("%s", line);
    };
    fclose(file);
}
/// fim rafa
int cmp_function(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}

void relatorioCliente (FILE * file_c){
    file_c = fopen("registro_clientes.txt", "a+");
    
    char line[100];
    char *token;
    char **array = NULL;
    int aux = 0;

    while (fgets(line, sizeof(line), file_c)) {
        int size = strlen(line);

        if (size > 0 && line[size - 1] == '\n') {
            line[size - 1] = '\0';
        }

        array = (char **)realloc(array, (aux + 1) * sizeof(char *));
        array[aux] = strdup(line);
        aux++;
        
    }

    qsort(array, aux, sizeof(char *), cmp_function);

    for (int i = 0; i < aux; i++) {
        printf("%s\n\n", array[i]);
        free(array[i]);
    }

    free(array);
    fclose(file_c);
};

void relatorioFuncionario (FILE * file_f){
    file_f = fopen("registro_funcionarios.txt", "a+");
    
    char line[100];
    char *token;
    char **array = NULL;
    int aux = 0;

    while (fgets(line, sizeof(line), file_f)) {
        int size = strlen(line);

        if (size > 0 && line[size - 1] == '\n') {
            line[size - 1] = '\0';
        }

        array = (char **)realloc(array, (aux + 1) * sizeof(char *));
        array[aux] = strdup(line);
        aux++;
        
    }

    qsort(array, aux, sizeof(char *), cmp_function);

    for (int i = 0; i < aux; i++) {
        printf("%s\n\n", array[i]);
        free(array[i]);
    }

    free(array);
    fclose(file_f);
};

void recebeDados(FolhaPagamento *pessoa){

    printf("\n--- SUA FOLHA DE PAGAMENTO ---\n");
    printf("Insira seus dados!\n");

    printf("\nQuantidade de dependentes: ");
    scanf("%d", &pessoa->qtdDependentes);

    printf("Salario bruto: ");
    scanf("%f", &pessoa->salarioBruto);

    printf("Gratificacao: ");
    scanf("%f", &pessoa->gratificacao);

    printf("Utiliza vale transporte? [s, n]: ");
    scanf(" %c", &pessoa->valeTransporte);

    printf("Utiliza plano de saude? [s, n]: ");
    scanf(" %c", &pessoa->planoSaude);

    system("cls");
}

void menu_folha(int *sec_op){
    printf("\n--- CALCULO DA FOLHA ---\n");
    printf("\nInsira a opcao do qual deseja calcular o desconto na folha!\n");
    printf("\n[1] Vale transporte\n");
    printf("[2] Plano de saude\n");
    printf("[3] FGTS\n");
    printf("[4] INSS\n");
    printf("[5] Salario familia\n");
    printf("[6] Imposto de renda\n");
    printf("[7] Salario liquido\n");
    printf("[8] Atualizar dados\n");
    printf("[0] Sair\n");
    printf("\n");
    scanf("%d", sec_op);
    printf("\n");

    system("cls");
}

void valeTransporte(FolhaPagamento *pessoa){
    char option = '0';
    float valorPassagem = 6;
    int qtdPassagens = 0, qtdDiasUteis = 0;

    if(pessoa->valeTransporte == 'n'){
        printf("Voce selecionou a nao utilizacao do vale transporte\n");
        printf("Deseja calcular mesmo assim? [s, n]: ");
        scanf(" %c", &option);

        if(option == 'n'){
            printf("Voce retornara para o menu\n");
            Sleep(5);
            system("cls");
            return;
        }
    }

    printf("Insira a quantidade de passagens utilizadas por dia: ");
    scanf("%d", &qtdPassagens);
    printf("Insira a quantidade de dias uteis do mes atual: ");
    scanf("%d", &qtdDiasUteis);

    float descontoMaximo = 0.06 * pessoa->salarioBruto;
    float descontoVariavel = valorPassagem * (qtdPassagens * qtdDiasUteis);

    if(descontoMaximo < descontoVariavel){
        pessoa->descontoVT = descontoMaximo;
    }
    else if(descontoVariavel < descontoMaximo){
        pessoa->descontoVT = descontoVariavel;
    }

    printf("Desconto correspondente ao vale transporte nesse mes: R$%.2f\n", pessoa->descontoVT);

    Sleep(5);
    system("cls");
}

void planoSaude(FolhaPagamento *pessoa){
    char option = '0'; 
    int tipoPlano = 0;

    if(pessoa->planoSaude == 'n'){
        printf("Voce selecionou a nao utilizacao do plano de saude\n");
        printf("Deseja calcular mesmo assim? [s, n]: ");
        scanf(" %c", &option);

        if(option == 'n'){
            printf("Voce retornara para o menu\n");
            sleep(5);
            system("cls");
            return;
        }

    }

    printf("Insira seu tipo de plano\n");
    printf("Para o tipo 'Enfermaria', digite 1, para o tipo 'Quarto', digite 2: ");
    scanf("%d", &tipoPlano);
    
    if(pessoa->qtdDependentes == 0){
        if(tipoPlano == 1){
            pessoa->descontoPlanoSaude = 89.9;
        }
        else if(tipoPlano == 2){
            pessoa->descontoPlanoSaude= 119.9;
        }
    }

    if(pessoa->qtdDependentes > 0){
        if(tipoPlano == 1){
            pessoa->descontoPlanoSaude = 89.9 * (pessoa->qtdDependentes + 1);
        }
        else if(tipoPlano == 2){
            pessoa->descontoPlanoSaude = 119.9 * (pessoa->qtdDependentes + 1);
        }
    }

    printf("Desconto correspondente ao plano de saude nesse mes: R$%.1f\n", pessoa->descontoPlanoSaude);

    sleep(5);
    system("cls");

}

void fgts(FolhaPagamento *pessoa){
    pessoa->FGTS = 0.08 * pessoa->salarioBruto;

    printf("O FGTS nao eh um valor descontado nem acrescido no seu salario,\n"
            "mas sim um valor depositado pela empresa na sua conta reservada da caixa!\n\n"
            "Valor de FGTS deste mes: R$%.2f\n", pessoa->FGTS);

    sleep(5);
    system("cls");
}

void inss(FolhaPagamento *pessoa){
    float aliquota = 0;

    if(pessoa->salarioBruto <= 1100){
        aliquota = 7.5;
    }
    else if(pessoa->salarioBruto > 1100 && pessoa->salarioBruto <= 2203.48){
        aliquota = 9;
    }
    else if(pessoa->salarioBruto > 2203.48 && pessoa->salarioBruto <= 3305.22){
        aliquota = 12;
    }
    else if(pessoa->salarioBruto > 3305.22 && pessoa->salarioBruto <= 6433.57){
        aliquota = 14;
    }
    else{
        aliquota = 14;
    }

    pessoa->descontoINSS = (pessoa->salarioBruto + pessoa->gratificacao) * (aliquota / 100);

    printf("Desconto correspondente ao INSS nesse mes: R$%.2f\n", pessoa->descontoINSS);

    sleep(5);
    system("cls");
}

void salarioFamilia(FolhaPagamento *pessoa){
  int idadeDependente = 0, cont = 0;
  
  if((pessoa->salarioBruto + pessoa->gratificacao) <= 1503.25){

    if(pessoa->qtdDependentes > 0){
      for(int i = 0; i < pessoa->qtdDependentes; i++){
        printf("Insira a idade do seu dependente %d: ", i + 1);
        scanf("%d", &idadeDependente);
  
        if(idadeDependente <= 14){
          cont++;
        }
        else{
          printf("Dependente maior de 14 anos nao tem direito ao beneficio\n");
        }
      }
      pessoa->salarioFamilia = 51.27 * cont;
    }

    else{
      printf("Voce nao possui dependentes\n");
    }

    printf("Seu acrescimo corresponde a R$%.2f\n", pessoa->salarioFamilia);
  }
  else{
    printf("Voce nao tem direito ao salario familia\n");
  } 

    sleep(5);
    system("cls");
}

void impostoRenda(FolhaPagamento *pessoa){
  float baseCalculo = 0, aliquota = 0, irpf = 0;

  baseCalculo = (pessoa->salarioBruto + pessoa->gratificacao) - pessoa->descontoINSS - (189.59 * pessoa->qtdDependentes);

  if(baseCalculo <= 1903.98){
    printf("Voce esta isento de imposto de renda\n");

    sleep(5);
    system("cls");
    return 0;
  }
  else if(baseCalculo > 1903.98 && baseCalculo <= 2826.65){
    aliquota = 7.5;
    irpf = 142.8;
  }
  else if(baseCalculo > 2826.65 && baseCalculo <= 3751.05){
    aliquota = 15;
    irpf = 354.8;
  }
  else if(baseCalculo > 3751.05 && baseCalculo <= 4664.68){
    aliquota = 22.5;
    irpf = 636.13;
  }
  else if(baseCalculo > 4664.68){
    aliquota = 27.5;
    irpf = 869.36;
  }

  float porc = baseCalculo * (aliquota / 100);
  pessoa->impostoRenda = porc - irpf;

  printf("O valor correspondente ao seu imposto de renda: R$%.2f\n", pessoa->impostoRenda);

  sleep(5);
    system("cls");
}

void salarioLiquido(FolhaPagamento *pessoa){

    pessoa->salarioLiquido = (pessoa->salarioBruto + pessoa->salarioFamilia) - (pessoa->descontoVT + pessoa->descontoINSS + pessoa->descontoPlanoSaude + pessoa->impostoRenda);

    printf("SALARIO BRUTO: R$%.2f\n", pessoa->salarioBruto);
    printf("\nSALARIO LIQUIDO: R$%.2f\n", pessoa->salarioLiquido);
    printf("\nTotal de descontos: R$%.2f\n", pessoa->salarioBruto - pessoa->salarioLiquido);

    sleep(5);
    system("cls");
}

void buscarCliente(FILE * file_c){
    file_c = fopen("registro_clientes.txt", "a+");

    char cpf[13];
    char line[100];

    printf("Insira o CPF do cliente buscar: ");
    scanf(" %s", &cpf); 

    while (fgets(line, sizeof(line), file_c)) {
        int size = strlen(line);

        if (size > 0 && line[size - 1] == '\n') {
            line[size - 1] = '\0';
        }

        if (strstr(line, cpf) != NULL) {
            printf("Cliente encontrado!\n\n");
            printf("%s\n", line);
            Sleep(5000);
            system("cls");
        }
        else{
            printf("Funcionario nao encontrado\n");
        }
    }

    fclose(file_c);
}

void buscarFuncionario(FILE * file_f){
    file_f = fopen("registro_funcionarios.txt", "a+");

    char cpf[13];
    char line[100];

    printf("Insira o CPF do cliente buscar: ");
    scanf(" %s", &cpf); 

    while (fgets(line, sizeof(line), file_f)) {
        int size = strlen(line);

        if (size > 0 && line[size - 1] == '\n') {
            line[size - 1] = '\0';
        }

        if (strstr(line, cpf) != NULL) {
            printf("Funcionario encontrado!\n\n");
            printf("%s\n", line);
            Sleep(5000);
            system("cls");
        }
        else{
            printf("Funcionario nao encontrado\n");
        }
    }

    fclose(file_f);
}

int main() {
    FILE *file_c = NULL;
    FILE *file_f = NULL;
    FILE *file_r = NULL;
   
    Reg r; 
    int opcao;
    int op = 0;
    int sec_op = 0;
    int aux;
    int c;


    while(1){
        main_menu(&op);

        switch(op){
            case 1:
                printf("\n -- CADASTRO -- \n");
                printf("Selecione a opcao que deseja cadastrar!\n");
                printf("\n\n");
                sec_menu(&sec_op);

                switch(sec_op){
                    case 1:
                        cadastroCliente(file_c);
                        break;

                    case 2:
                        cadastroFuncionario(file_f);
                        break;

                    case 3:
                        //juan
                        c = desc_id_r();
                        c = cadastroOperacaoFinanceira(file_r,c);
                        salvar_id(c);
                        break;

                    case 0:
                        system("cls");
                        printf("Voltando para o menu principal...\n");
                        Sleep(1500);
                        system("cls");
                        break;

                    default:
                        printf("Opcao nao disponivel!\n");
                        Sleep(3000);
                        system("cls");
                        break;
                }

                break;

            case 2:
                printf("\n -- RELATORIOS -- \n");
                printf("Selecione a opcao que deseja gerar relatorio!\n");
                printf("\n\n");
                sec_menu(&sec_op);

                switch(sec_op){
                    case 1:
                        relatorioCliente(file_c);
                        printf("Insira '0' para sair\n");
                        scanf("%d", &aux);
                        system("cls");
                        break;

                    case 2:
                        relatorioFuncionario(file_f);
                        printf("Insira '0' para sair\n");
                        scanf("%d", &aux);
                        system("cls");
                        break;

                    case 3:
                        c = desc_id_r();
                        relatorioOperacaoFinanceira(file_r);
                        printf("Insira '0' para sair\n");
                        scanf("%d", &aux);
                        system("cls");
                        Sleep(2000);
                        break;

                    case 0:
                        system("cls");
                        printf("Voltando para o menu principal...\n");
                        Sleep(1500);
                        system("cls");
                        break;

                    default:
                        printf("Opcao nao disponivel!\n");
                        Sleep(3000);
                        system("cls");
                        break;
                }

                break;
            
            case 3:
                printf("\n -- CONSULTA -- \n");
                printf("Selecione a opcao que deseja buscar nos registros!\n");
                printf("\n\n");
                sec_menu(&sec_op);

                switch(sec_op){
                    case 1:
                        buscarCliente(file_c);
                        printf("Insira '0' para sair\n");
                        scanf("%d", &aux);
                        system("cls");
                        break;

                    case 2:
                        buscarFuncionario(file_f);
                        printf("Insira '0' para sair\n");
                        scanf("%d", &aux);
                        system("cls");
                        break;

                    case 3:
                        buscarOperacaoFinanceira(file_r);
                        printf("Insira '0' para sair\n");
                        scanf("%d", &aux);
                        system("cls");
                        break;

                    case 0:
                        system("cls");
                        printf("Voltando para o menu principal...\n");
                        Sleep(1500);
                        system("cls");
                        break;

                    default:
                        printf("Opcao nao disponivel!\n");
                        Sleep(3000);
                        system("cls");
                        break;
                }
                
                break;

            case 4: ;
                FolhaPagamento pessoa;
                recebeDados(&pessoa);

                while(1){
                    menu_folha(&sec_op);

                    switch(sec_op){
                        case 1:
                            valeTransporte(&pessoa);
                            break;
                        case 2:
                            planoSaude(&pessoa);
                            break;
                        case 3:
                            fgts(&pessoa);
                            break;
                        case 4:
                            inss(&pessoa);
                            break;
                        case 5:
                            salarioFamilia(&pessoa);
                            break;
                        case 6:
                            impostoRenda(&pessoa);
                            break;
                        case 7:
                            salarioLiquido(&pessoa);
                            break;
                        case 8:
                            recebeDados(&pessoa);
                            break;
                        case 0:
                            exit(EXIT_SUCCESS);
                    }

                    if(sec_op == 0){
                        break;
                    }
                }
                break;

           case 5:
            do
            {
                    printf("###############################\n");
                    printf("##                           ##\n");
                    printf("## [1] Pagar uma conta       ##\n");
                    printf("##                           ##\n");
                    printf("## [2] Verificar contas      ##\n");
                    printf("##                           ##\n");
                    printf("## [3] Voltar                ##\n");
                    printf("##                           ##\n");
                    printf("###############################\n");
                    scanf("%d", &opcao);
                    system("cls");
                switch(opcao){
                case 1:
                    printf("Opcao escolhida: Pagar uma conta\n");
                    register_payment(&r);
                    break;

                case 2:
                    printf("Opcao escolhida: Verificar contas a receber\n");
                    show_bills();
                    printf("Insira '0' para sair\n");
                    scanf("%d", &aux);
                    system("cls");
                    Sleep(2000);
                    break;

                case 3:
                    printf("Saindo do programa. Ate logo!\n");
                    break;

                default:
                    printf("Opcao invalida. Tente novamente.\n");
                    break;
                };

            } while (opcao != 3);

            case 0:
            
                system("cls");
                printf("Encerrando programa...\n");
                Sleep(2000);                
                system("cls");
                return 0;
                break;
        }
            
    };

    return 0;
}
