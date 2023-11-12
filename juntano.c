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

    fprintf(file_c, "%s %s / %d anos / Sexo: %c / CPF: %s / %s %s/ %s / %s / Renda: %.2lf / Ativo? %c\n", c.nome, c.sobrenome, c.idade, c.sexo, c.cpf, c.estado, c.cidade, c.banco, c.telefone, c.renda, c.ativo);

    Sleep(3000);

    printf("Cliente cadastrado com sucesso!\n");

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

    fprintf(file_f, "%s %s / %d anos / Sexo: %c / CPF: %s / %s %s / %s / Setor: %c / %s / Salario: %.2lf / Ativo? %c\n", f.nome, f.sobrenome, f.idade, f.sexo, f.cpf, f.estado, f.cidade, f.cargo, f.setor, f.telefone, f.salario, f.ativo);

    Sleep(3000);

    printf("Funcionario cadastrado com sucesso!\n");

    Sleep(3000);
    system("cls");

    fclose(file_f);
}

void cadastroOperacaoFinanceira (FILE * file_r){
    file_r = fopen("registro_transacao_financeira.txt", "a+");
    srand(time(NULL));

    OperacaoFinanceira r;

    printf("Insira os dados para registrar operacao financeira! \n\n");

    Sleep(3000);
    system("cls");

    r.id = rand() % 1000;

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

    fprintf(file_r,"Operação Numero:%i / Tipo: %s / Recebedor: %s / Pagador: %s / Data: %s / Valor: %.2f\n", r.id, r.tipo, r.para, r.de, r.data, r.valor);

    Sleep(3000);

    printf("Operacao cadastrada com sucesso!\n");

    Sleep(3000);
    system("cls");

    fclose(file_r);
};

void relatorioCliente (FILE * file_c){
    file_c = fopen("registro_clientes.txt", "a+");
    
    char linha[100];

    while(fgets(linha, sizeof(linha), file_c) != NULL){
        printf(" %s", linha);
    };

    fclose(file_c);
};

void relatorioFuncionario (FILE * file_f){
    file_f = fopen("registro_funcionario.txt", "a+");
    
    char linha[100];

    while(fgets(linha, sizeof(linha), file_f) != NULL){
        printf(" %s", linha);
    };

    fclose(file_f);
};

void relatorioOperacaoFinanceira (FILE * file_r){
    file_r = fopen("registro_operacao_financeira.txt", "a+");
    
    char linha[100];

    while(fgets(linha, sizeof(linha), file_r) != NULL){
        printf(" %s", linha);
    };

    fclose(file_r);
};

int main() {
    FILE *file_c = NULL;
    FILE *file_f = NULL;
    FILE *file_r = NULL;

    int op = 0;
    int sec_op = 0;
    char aux;

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
                        cadastroOperacaoFinanceira(file_r);
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
                        scanf(" %c", aux);
                        break;

                    case 2:
                        relatorioFuncionario(file_f);
                        printf("Insira '0' para sair\n");
                        scanf(" %c", aux);
                        break;

                    case 3:
                        relatorioOperacaoFinanceira(file_r);
                        printf("Insira '0' para sair\n");
                        scanf(" %c", aux);
                        
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
            
            // case 3:
            //     printf("\n -- CONSULTA -- \n");
            //     printf("Selecione a opcao que deseja buscar nos registros!\n");
            //     printf("\n\n");
            //     sec_menu(&sec_op);

            //     switch(sec_op){
            //         case 1:

            //             break;

            //         case 2:

            //             break;

            //         case 3:

            //             break;

            //         case 0:
            //             system("cls");
            //             printf("Voltando para o menu principal...\n");
            //             Sleep(1500);
            //             system("cls");
            //             break;

            //         default:
            //             printf("Opcao nao disponivel!\n");
            //             Sleep(3000);
            //             system("cls");
            //             break;
            //     }
                
            //     break;

            // case 4:
            //     printf("\n -- FOLHA DE PAGAMENTO -- \n");
            //     break;

            // case 5:
            //     printf("\n -- CONTAS A PAGAR/RECEBER -- \n");
            //     break;

            // case 0:
            //     system("cls");
            //     printf("Encerrando programa...\n");
            //     Sleep(3000);
            //     system("cls");
            //     break;
                }
    }

    return 0;
}
