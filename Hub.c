// Locadora: Login e Cadastro

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{

    char nome[100], cpf[11], celular[11], email[40], senha[16];
} data;

data reg(){       //Cadastro

    data a;
/*
    Arquivos
    
    FILE *f = fopen("save.txt", "w");
    if (f == NULL){
        printf ("ERROR: NOT FOUND");
        return;
    }

    data user[50];
    int i = 0, n = 1;
*/
    system("cls");
    printf ("\n| Informe os seguintes dados |\n");
    printf ("\n- Nome completo:\n\n");
    scanf (" %[^\n]", a.nome);

    //arrumar for

    for (int i = 0; a.nome[i]; i++){
        if (((a.nome[i] < 'a') || (a.nome[i] > 'z')) && ((a.nome[i] < 'A') || (a.nome[i] > 'Z')) && (a.nome[i] != ' ')){
            printf ("\n| Apenas letras sao permitidas, tente novamente. |\n\n");
            scanf (" %[^\n]", a.nome);
        }

        if ((a.nome[i] >= 'a') && (a.nome[i] <= 'z')){  // COMO TIRA LETRA GRANDE
            a.nome[i] - 32;
        }
    }

// REMOVER ESPAÇOS DUPLICADOS
/*        for (int i = 1; a.nome[i]; i++){
            if ((a.nome[i] == ' ') && (a.nome[i-1] == ' ')){
                
            }
        }
*/

    printf ("\n- CPF\n\n");
    scanf (" %[^\n]", &a.cpf);

    for (int i = 0; a.cpf[i]; i++){
        if ((a.cpf[i] < '0') || (a.cpf[i] > '9')){
            printf ("\n| Apenas numeros sao permitidos, tente novamente. |\n\n");
            scanf (" %[^\n]", a.cpf);
        }
    }
        
    printf ("\n- Numero de Celular\n\n");
    scanf (" %[^\n]", &a.celular);

    for (int i = 0; a.celular[i]; i++){
        if ((a.celular[i] < '0') || (a.celular[i] > '9')){
            printf ("\n| Apenas numeros sao permitidos, tente novamente. |\n\n");
            scanf (" %[^\n]", a.celular);
        }
    }

    printf ("\n- Email\n\n");
    scanf (" %[^\n]", a.email);

    printf ("\n- Senha\n\n");
    scanf (" %[^\n]", a.senha);

/*    user[i] = a;
    i++;

    for (int i = 0; i < n; i++){
        fprintf(f, "%s\n%s\n%s\n%s\n%s\n", user[i].nome, user[i].cpf, user[i].celular, user[i].email, user[i].senha);
    }
    fclose(f);

    n++;
    */

    return a;
}

data *add_reg(data *save, int *count, data new){    // Alocação Dinâmica

    save = (data*) realloc(save, (*count+1) * sizeof(data)); //aumenta o tamanho do vetor dinamicamente
    
    if (save == 0){
        printf ("ERROR: NO MEMORY\n");
        return;
    }

    save[*count] = new;
    (*count)++;
    system("cls");
    printf("\n| Usuario cadastrado. |\n");

    return save;
}

data *rem(data *a, int *num){       // Remover cadastro

    int j = 0, aux = 0;
    int count = 0;

    char login[40];

    system("cls");
    printf ("\n- Digite o email do cadastro que deseja remover:\n\n");
    
    while(aux == 0){
        scanf (" %[^\n]", login);

        for(int i = 0; i < num; i++){
            if (strcmp(login,a[i].email) == 0){
                aux = 1;
                j = i;
                break;
            }
        }
        
        if (aux == 0){
            printf ("\n| Email nao encontrado, tente novamente. |\n\n");
            count++;
        }

        if (count == 4){
            system("cls");
            printf("\n| Muitas tentativas incorretas, voltando ao menu. |\n");
            return;
        }
    }

    aux = 0;

    a[j] = a[*num-1];
    a = (data*) realloc(a, (*num-1)* sizeof(data));

    if(a == 0){
        printf("ERROR: NOT FOUND.");
        return 0;
    }


    (*num)--;

    printf("\n| Cadastro removido. |\n");

    return a;
}

void login(data *a, int num){       // Login

    int j, aux = 0;
    int count = 0;

    char login[40], ler_senha[16];

    system("cls");
    printf ("\n- Digite seu Login: (Email)\n\n");
    
    while(aux == 0){
        scanf (" %[^\n]", login);

        for(int i = 0; i < num; i++){
            if (strcmp(login,a[i].email) == 0){
                aux = 1;
                j = i;
                break;
            }
        }
        
        if (aux == 0){
        printf ("\n| Email incorreto, tente novamente. |\n\n");
        count++;
        }

        if (count == 4){
            system("cls");
            printf("\n| Muitas tentativas incorretas, voltando ao menu. |\n");
            return;
        }
    }

    aux = 0;
    count = 0;

    system("cls");
    printf ("\n- Digite sua senha:\n\n");

    while(aux == 0){
        scanf (" %[^\n]", ler_senha);

        if (strcmp(ler_senha,a[j].senha) == 0){
            system("cls");
            printf ("\n| Login efetuado. |\n");
            aux = 1;
            break;
        }

        if (aux == 0){
            printf ("\n| Senha incorreta, tente novamente. |\n\n");
            count++;
        }

        if (count == 3){
            system("cls");
            printf("\n| Muitas tentativas incorretas, voltando ao menu. |\n");
            return;
        }
    }
}

int main(){

    data a;
    char op;
    int num = 0;
    data *info = 0;

    system("cls");

    while(1){
    
    printf("\n- Digite uma opcao para continuar:\n");
    printf("\n| 1 | Login\n");
    printf("| 2 | Cadastrar\n");
    printf("| 3 | Descadastrar\n");
    printf("| 4 | Encerrar programa\n\n");
    scanf(" %c", &op);

    switch (op){
    case '1':
        if (num == 0){
            system("cls");
            printf("\n| Nao ha cadastros. |\n");
            break;
        }
        login(info, num);
        break;
    
    case '2':
        data a = reg();
        info = add_reg(info, &num, a);
        break;
    
    case '3':
        if (num == 0){
            system("cls");
            printf("\n| Nao ha cadastros. |\n");
            break;
        }
        rem(info, num);
        break;

    case '4':
        system("cls");
        printf ("\n| Volte sempre! |\n\n");
        exit(1);
        break;

    default:
        system("cls");
        printf("| Opcao invalida, tente novamente. |\n");
    }
    }
    
    return 0;
}