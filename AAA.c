#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

typedef struct empregado {
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
} empregado_t;

void recebeDados(empregado_t *pessoa){

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

void menu(int *opcao){
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
    scanf("%d", opcao);
    printf("\n");

    system("cls");

}

void valeTransporte(empregado_t *pessoa){
    char option = '0';
    float valorPassagem = 6;
    int qtdPassagens = 0, qtdDiasUteis = 0;

    if(pessoa->valeTransporte == 'n'){
        printf("Voce selecionou a nao utilizacao do vale transporte\n");
        printf("Deseja calcular mesmo assim? [s, n]: ");
        scanf(" %c", &option);

        if(option == 'n'){
            printf("Voce retornara para o menu\n");
            sleep(5);
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

    sleep(5);
    system("cls");
}

void planoSaude(empregado_t *pessoa){
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

void fgts(empregado_t *pessoa){
    pessoa->FGTS = 0.08 * pessoa->salarioBruto;

    printf("O FGTS nao eh um valor descontado nem acrescido no seu salario,\n"
            "mas sim um valor depositado pela empresa na sua conta reservada da caixa!\n\n"
            "Valor de FGTS deste mes: R$%.2f\n", pessoa->FGTS);

    sleep(5);
    system("cls");
}

void inss(empregado_t *pessoa){
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

void salarioFamilia(empregado_t *pessoa){
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

void impostoRenda(empregado_t *pessoa){
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

void salarioLiquido(empregado_t *pessoa){

    pessoa->salarioLiquido = (pessoa->salarioBruto + pessoa->salarioFamilia) - (pessoa->descontoVT + pessoa->descontoINSS + pessoa->descontoPlanoSaude + pessoa->impostoRenda);

    printf("SALARIO BRUTO: R$%.2f\n", pessoa->salarioBruto);
    printf("\nSALARIO LIQUIDO: R$%.2f\n", pessoa->salarioLiquido);
    printf("\nTotal de descontos: R$%.2f\n", pessoa->salarioBruto - pessoa->salarioLiquido);

    sleep(5);
    system("cls");
}


int main(){

    int opcao = 0;

    empregado_t pessoa;

    recebeDados(&pessoa);

    while(1){
        menu(&opcao);
        switch(opcao){
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

        if(opcao == 0){
            break;
        }
    }


    return 0;
}