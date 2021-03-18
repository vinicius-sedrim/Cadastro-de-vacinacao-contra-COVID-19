#include <stdio.h>
#include <stdlib.h>
#define TAMANHO 200 //Quantidade de linhas dos vetores e matrizes

char nome[TAMANHO][TAMANHO]; // Matriz para armazenar 200 nomes
char email[TAMANHO][50]; // Matriz para armazenar 200 e-mails
double cpf[TAMANHO]; // Vetor para armazanear 200 CPFs
double telefone[TAMANHO]; // Vetor utilizado para armazenar 200 telefones
int idade[TAMANHO]; // Vetor utilizado para armazenar 200 valores de idade
char comorbidade[TAMANHO][50]; // Matriz para armazenar possiveis comorbidades do usuario
int opcao; // Variavel utilizada para armazenar as opcoes do usuario


void cadastro(); // Prototipo da funcao cadastro
void pesquisa(); // Prototipo da funcao pesquisa
void lista(); // Prototipo da funcao lista

int main(void){ // Funcao principal - Com a criacao do MENU PRINCIPAL

        // Foi apagada todas as funcoes do Main pois usaremos o Menu principal para direcionar o usuario com mais facilidade

        printf("\n==== PROGRAMA INICIADO ====\n\n");

        do{
        system("cls"); // Criada a funcao System que permite executar codigos do prompt de comando dentro do programa
        printf("\n---- MENU ----\n1 - Cadastrar\n2 - Listar todos\n3 - Pesquisar\n4 - Sair\n\n"); // Cabecario do Menu com todos os itens necessarios
        scanf("%d", &opcao);
        switch(opcao) { // Criada o switch para comparar a opção que o usuario escolheu

        case 1:
            cadastro(); // Caso o usuario escolha a opcao 1, o mesmo sera direcionado para a funcao cadastro na linha 58
            break;

        case 2:         // Caso o usuario escolha a opcao 2, o mesmo sera direcionado para a funcao lista na linha 140
            lista();
            break;

        case 3:         // Caso o usuario escolha a opcao 3, o mesmo sera direcionado para a funcao pesquisa na linha 88
            pesquisa();
            break;

        case 4:          // Caso o usuario escolha a opcao 4, o programa sera fechado.
            printf("\n==== PROGRAMA ENCERRADO ====\n");
            system("exit");
            break;

        default:
            printf("Opcao invalida! Pressione o enter."); // Mensagem para o usuario caso ele digite algum valor diferente do pedido no Menu

            getchar(); // Colocamos a funcao getchar para manter a tela aberta quando o usuario escolher uma outra opcao.
            getchar(); // Dependendo do sistema operacional, compilador e demais fatores, o programa pode funcionar com apenas um getchar, por motivos de precaucao colocamos dois.
            break;
        }
    }while(opcao!=4);

}

void cadastro(){ // Funcao para cadastrar pessoas
    static int linha; //Variavel que estaciona o valor de linha
    printf(" ----------------------------------- \n"); // Inicio do cadastro
    do{
        printf("   CADASTRO DE VACINACAO COVID-19  \n"); // Cabecalho da Funcao cadastro
        printf(" ----------------------------------- \n"); // Inicio do cadastro
        printf("\nDigite o nome: "); // Mensagem para o usuario digitar o nome
        getchar();
        fflush(stdin);
        fgets(nome[linha], 200, stdin);
        printf("\nDigite o e-mail: "); // Mensagem para o usuario digitar o e-mail
        scanf("%s", &email[linha]);
        printf("\nDigite o CPF (somente numeros): ");  // Mensagem para o usuario digitar o CPF
        scanf("%lf", &cpf[linha]);
        printf("\nDigite o telefone (somente numeros): ");  // Mensagem para o usuario digitar o telefone
        scanf("%lf", &telefone[linha]);
        printf("\nDigite a idade (somente numeros): ");  // Mensagem para o usuario digitar a sua idade
        scanf("%d", &idade[linha]);
        printf("\nDigite a(s) comorbidade(s) (digitar '-' se nao tiver. Se tiver mais de uma, separa-las por ','): "); // Mensagem para o usuario digitar sua(s) comorbidades (caso tenha)
        getchar();
        fflush(stdin);
        fgets(comorbidade[linha], 200, stdin);
        printf("\n----------------------------- \n");
        printf("\nDigite 1 para continuar ou outro valor para sair: ");  // Mensagem para o usuario escolher a opcao
        scanf("%d", &opcao);
        linha++; // Acrescentar um ao valor da linha
        printf("\n ----------------------------------- \n"); // Finalizacao do cadastro
    }while(opcao == 1); //Condicao de parada do cadastro

}
void pesquisa(){
    int opcao, contador = 0;
    double cpfPesquisa;
    char emailPesquisa[50];
    int i;
    do{
        printf(" ----------------------------- \n");
        printf("     PESQUISAR CADASTRADOS      \n");
        printf(" ----------------------------- \n");
        printf("\nDigite 1 para pesquisar o CPF ou 2 para pesquisar o e-mail: ");
        scanf("%d", &opcao);
        switch(opcao){
        case 1:
            printf("\nDigite o CPF: ");
            scanf("%lf", &cpfPesquisa);
            for(i = 0; i < TAMANHO; i++){
                if(cpf[i]==cpfPesquisa){
                    printf("\nNome: %s\nEmail: %s\nCPF: %.0lf\nTelefone: %.0lf\nIdade: %d\nComorbidade: %s", nome[i], email[i], cpf[i], telefone[i], idade[i], comorbidade[i]);
                    contador++;
                }
            }
            if (contador == 0){
                printf("\nCPF nao encontrado!\n");
            }
            contador = 0;
            break;
        case 2:
            printf("\nDigite o e-mail: ");
            scanf("%s", &emailPesquisa);
            for(i = 0; i < TAMANHO; i++){
                if(strcmp(email[i], emailPesquisa)==0){
                    printf("\nNome: %s\nEmail: %s\nCPF: %.0lf\nTelefone: %.0lf\nIdade: %d\nComorbidade: %s", nome[i], email[i], cpf[i], telefone[i], idade[i], comorbidade[i]);
                    contador++;
                }
            }
            if (contador == 0){
                printf("\nE-mail nao encontrado!\n");
            }
            contador = 0;
            break;
        default:
            printf("\nOpcao invalida!");
            break;
        }
        printf("\n----------------------------- \n");
        printf("\nDigite 1 para continuar pesquisando ou outro valor para sair: ");
        printf("\n");
        scanf("%d", &opcao);
    }while(opcao == 1);

}


void lista(){
    int i,regs;
    FILE *arq_lista;
    FILE* verifica;


    verifica = fopen("Lista_cadastro.txt", "r");
    if(verifica==NULL){
        arq_lista = fopen("Lista_cadastro.txt","w"); //abrindo para manter a linha head
        fprintf(arq_lista,"Nome ;Email ;CPF ;Telefone ;Idade ;Comorbidade  \n" );
        fclose(arq_lista);
    }



    if(arq_lista == NULL){
        printf("Erro na abertura do arquivo!\n");
        return 1;
    }



    else{
        arq_lista = fopen("Lista_cadastro.txt","a"); //abrindo para gravacao de novos cadastros
        for(i=0; i<TAMANHO; i++){
            if(cpf[i]>0){
                   fprintf(arq_lista,"%s ;%s ;%.0lf ;%.0lf ;%d ;%s \n", nome[i], email[i], cpf[i], telefone[i], idade[i], comorbidade[i]);
                   regs = i+1;
                  }
            else{
                break;
            }
        }
        fclose(arq_lista);
        printf("%i registros salvos!\nPressione o enter.",regs);
    }

    getchar(); // Colocamos a funcao getchar para manter a tela aberta quando o usuario escolher uma outra opcao.
    getchar(); // Dependendo do sistema operacional, compilador e demais fatores, o programa pode funcionar com apenas um getchar, por motivos de precaucao colocamos dois.

}
