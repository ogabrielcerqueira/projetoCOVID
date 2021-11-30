#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Endereco {
    char logradouro[50];
    int numero;
    char complemento[50];
    char bairro[50];
    char cidade[50];
    char estado[50];
    char pais[50];
    int cep;
};

struct Data {
    int dia;
    int mes;
    int ano;
};

struct Usuario {
    char usuario[50]; // Usuario de login
    char senha[50]; // Senha de login
};

struct Paciente {
    char nome[50]; // Nome do paciente
    char cpf[16]; // Cpf do paciente
    char telefone[50]; // Telefone do paciente
    char email[50]; // Email do paciente
    struct Data dtDiagnostico; // obj de data de nascimento
    struct Endereco endereco; // obj de endereço
    struct Data dtNasc; // obj de data de nascimento
    int temComorbidade; // 1 = Sim || 0 = Não
    char comorbidade[50]; // Qual comorbidade em caso de 'Sim'
};

struct Usuario usuarios[2]; // Limitado a 2 usuarios (Gabriel e William)
struct Paciente pacs[2]; // Limitado a 100 pacientes
int POSICAO = 0; // Posição em que o paciente será inserido no array de pacientes

int main(void){

    int logar = login();
    cadastrarPacienteTeste();

    if(logar == 0){
        menu();
    } else {
        printf("Erro inesperado!");
    }

    return 0;
}

void menu(){
    int opcao = 0;
    do {
        system("cls");
        printf("-----------------------------------------\n");
        printf("|\t    [Menu do Usuario]    \t|\n");
        printf("| * 1 - Inserir paciente\t\t|\n");
        printf("| * 2 - Pesquisar paciente\t\t|\n");
        printf("| * 3 - Sair\t\t\t\t|\n");
        printf("-----------------------------------------\n");
        printf("*Digite a opcao desejada: ");
		scanf("%d", &opcao);
		system("cls");

        switch(opcao){
        case 1:
            cadastrarPaciente();
            break;
        case 2:
            pesquisarPaciente();
            break;
        case 3:
            printf("Volte sempre!");
            opcao = 3;
            break;
        }

    }while(opcao != 3);

}

int login(){

    struct Usuario gabriel = {.usuario = "gabriel", .senha = "123"};
    struct Usuario william = {.usuario = "william", .senha = "321"};

    char usuario[15];
    char senha[15];
    int run = 1;

    while(run){
        printf("Usuario: ");
        scanf("%s", usuario);
        printf("Senha: ");
        scanf("%s", senha);

        if((strcmp(usuario,gabriel.usuario) == 0 && strcmp(senha,gabriel.senha)) == 0 || (strcmp(usuario,william.usuario) == 0 && strcmp(senha,william.senha))){
            printf("Sucesso ao entrar no sistema\n");
            run = 0;
        } else {
            system("cls");
            printf("Falha ao logar! Usuário e/ou senha incorreto(s)\n");
        }
    }

    return 0;
}

void cadastrarPaciente(){
    struct Paciente pac;

    printf("Nome: ");
    scanf("%s", &pac.nome);
    printf("CPF: ");
    scanf("%s", &pac.cpf);
    fflush(stdin);
    printf("Telefone: ");
    scanf("%d", &pac.telefone);
    fflush(stdin);

    printf("Endereco: \n");
    struct Endereco endereco;
    printf("- Logradouro: ");
    scanf("%s", &endereco.logradouro);
    fflush(stdin);

    printf("- Numero: ");
    scanf("%d", &endereco.numero);
    fflush(stdin);

    printf("- Complemento: ");
    scanf("%s", &endereco.complemento);
    fflush(stdin);

    printf("- Bairro: ");
    scanf("%s", &endereco.bairro);
    fflush(stdin);

    printf("- Cidade: ");
    scanf("%s", &endereco.cidade);
    fflush(stdin);

    printf("- Estado: ");
    scanf("%s", &endereco.estado);
    fflush(stdin);

    printf("- Pais: ");
    scanf("%s", &endereco.pais);
    fflush(stdin);

    printf("- CEP: ");
    scanf("%s", &endereco.cep);
    fflush(stdin);

    pac.endereco = endereco;

    printf("Data de Nascimento: \n");
    struct Data dtNasc;
    printf("- Dia: ");
    scanf("%d", &dtNasc.dia);
    fflush(stdin);
    printf("- Mes: ");
    scanf("%d", &dtNasc.mes);
    fflush(stdin);
    printf("- Ano: ");
    scanf("%d", &dtNasc.ano);
    fflush(stdin);

    pac.dtNasc = dtNasc;

    printf("E-mail: ");
    scanf("%s", &pac.email);
    fflush(stdin);

    printf("Data do diagnostico: \n");
    struct Data dtDiag;
    printf("- Dia: ");
    scanf("%d", &dtDiag.dia);
    fflush(stdin);
    printf("- Mes: ");
    scanf("%d", &dtDiag.mes);
    fflush(stdin);
    printf("- Ano: ");
    scanf("%d", &dtDiag.ano);
    fflush(stdin);

    pac.dtDiagnostico = dtDiag;

    printf("Possui comorbidade? (0 = Nao / 1 = Sim): ");
    scanf("%d", &pac.temComorbidade);
    fflush(stdin);

    if(pac.temComorbidade == 1){
        printf("- Descreva: ");
        scanf("%s", &pac.comorbidade);
        fflush(stdin);
    }

    fflush(stdin);
    system("cls");

    pacs[POSICAO] = pac;
    POSICAO++;
    printf("Cadastrado com sucesso!");
    delay(3);
}

void cadastrarPacienteTeste(){
    struct Paciente pac = {
        .nome = "Lucas",
        .cpf = "123",
        .telefone = "33012865",
        .email = "lucas@email.com",
        .dtDiagnostico = {.ano = 2021, .mes = 11, .dia = 15},
        .endereco = {.logradouro = "Av. Afonso Pena", .numero = 128, .complemento = "24", .bairro = "Boqueirao", .cidade = "Santos", .estado = "SP", .pais = "Brasil", .cep = 11020000},
        .dtNasc = {.ano = 1998, .mes = 11, .dia = 14},
        .temComorbidade = 1,
        .comorbidade = "Pressao alta"
    };

    pacs[POSICAO] = pac;
    POSICAO++;
}

void pesquisarPaciente(){
    char identificacao[50];

    system("cls");
    printf("Identificacao(Email ou CPF): ");
    scanf("%s", &identificacao);
    system("cls");

    int encontrou = 0;
    for(int i = 0; i < POSICAO+1; i++){
        if(strcmp(identificacao,pacs[i].email) == 0 ||
           strcmp(identificacao,pacs[i].cpf) == 0){
            printf("Paciente encontrado:\nNome: %s", pacs[i].nome);
            printf("\nCPF: %s", pacs[i].cpf);
            printf("\nIdade: %d", calcularIdade(pacs[i].dtNasc));
            printf("\nTelefone: %d", pacs[i].telefone);
            printf("\nEmail: %s", pacs[i].email);
            printf("\nEndereco: %s n%d, apto/bloco %s - %s - %s/%s - %d", pacs[i].endereco.logradouro, pacs[i].endereco.numero, pacs[i].endereco.complemento, pacs[i].endereco.bairro, pacs[i].endereco.cidade, pacs[i].endereco.estado, pacs[i].endereco.cep);
            printf("\nDt. Nascimento: %d/%d/%d", pacs[i].dtNasc.dia, pacs[i].dtNasc.mes, pacs[i].dtNasc.ano);
            printf("\nDt. Diagnostico: %d/%d/%d\n", pacs[i].dtDiagnostico.dia, pacs[i].dtDiagnostico.mes, pacs[i].dtDiagnostico.ano);
            if(pacs[i].temComorbidade == 1){
                printf("Comorbidade: %s\n", pacs[i].comorbidade);
            }
            encontrou = 1;
            system("pause");
            break;
        }
    }
    system("cls");
    if(encontrou == 0){
        printf("Paciente nao encontrado!!\n");
        system("pause");
    }
    menu();
}

int calcularIdade(struct Data dat){
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    int anoAtual = tm->tm_year + 1900;
    int mesAtual = tm->tm_mon + 1;
    int diaAtual = tm->tm_mday;

    int ano = anoAtual - dat.ano;
    int mes = mesAtual - dat.mes;
    int dia = diaAtual - dat.dia;
    int idade;

    if(mes >= 0 && dia >= 0){
        idade = ano;
    } else {
        idade = ano - 1;
    }

    //struct Data nascimento = {.dia = 26, .mes = 11, .ano = 1998};

    return idade;
}

void delay(int segundos){
    int milli_segundos = 1000 * segundos;
    clock_t start = clock();

    while(clock() < start + milli_segundos);
}
