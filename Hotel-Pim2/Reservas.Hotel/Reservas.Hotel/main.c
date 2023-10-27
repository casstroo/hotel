//
//  main.c
//  Reservas.Hotel
//
//  Created by Lucas Castro on 27/10/23.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_RESERVAS 31


// Definindo uma estrutura para representar um quarto de hotel
struct Quartos {
    int numero;
    char tipo[50];
    float preco;
    int reserva; // zero para não reservado, 1 para reservado
    struct Reservas {
        int checkin;
        int checkout;
    } reservas[MAX_RESERVAS]; // Estrutura para rastrear as reservas
};

struct Luxo{
    int numero2;
    char tipo2[50];
    float preco2;
    int reserva2;
    struct Reservass {
        int checkin2;
        int checkout2;
    }reservas[MAX_RESERVAS];
};

//Definindo uma estrutura para representar um cliente
struct Cliente {
    char nome[50];
    char email[50];
    char telefone[15];
    int quartoReservado;
    float valorTotal;

};



//funcao para exibir informacoes sobre o quarto do hotel =
void exibirQuarto(struct Quartos quarto){
    printf("NUMERO DO QUARTO: %d\n", quarto.numero);
    printf("TIPO: %s\n", quarto.tipo);
    printf("PRECO POR NOITE: %.2f\n ", quarto.preco);
    if (quarto.reserva){
        printf("STATUS: RESERVADO\n");
    }else{
        printf("STATUS: DISPONIVEL\n");
    }
    printf("\n");
}
void exibirLuxo(struct Luxo luxos){
    printf("NUMERO DO QUARTO: %d\n", luxos.numero2);
    printf("TIPO: %s\n", luxos.tipo2);
    printf("PRECO POR NOITE: %.2f\n ", luxos.preco2);
    if (luxos.reserva2){
        printf("STATUS: RESERVADO\n");
    }else{
        printf("STATUS: DISPONIVEL\n");
    }
    printf("\n");
}



int main() {
    //inicializando quartos
    struct Quartos quarto[10];
    struct Luxo luxos[10];
    
    int opc, esc, numDias;;
    double valorTotalLuxo = 450, valorTotalSimples  = 250, valorcomdesconto = 0;
    float valorcomdesconto2 = 0;
    
    int senha, adm;
    
    int menu, pag;
    
    for (int i = 0; i < 10; i++) {
        quarto[i].numero = i + 1;
        strcpy(quarto[i].tipo, "SIMPLES");
        quarto[i].preco = 250.00;
        quarto[i].reserva = 0; // Inicialmente, nenhum quarto está reservado
        // Inicializando as reservas
        for (int j = 0; j < MAX_RESERVAS; j++) {
            quarto[i].reservas[j].checkin = 0;
            quarto[i].reservas[j].checkout = 0;
        }
            
            luxos[i].numero2 = i + 11;
            strcpy(luxos[i].tipo2, "LUXO");
            luxos[i].preco2 = 450.00;
            luxos[i].reserva2 = 0; // Inicialmente, nenhum quarto está reservado
            // Inicializando as reservas
            for (int j = 0; j < MAX_RESERVAS; j++) {
                luxos[i].reservas[j].checkin2 = 0;
                luxos[i].reservas[j].checkout2 = 0;
        }
    }

    
    
    struct Cliente clientes[99];
    

    do {
        
        printf("\n\n\n");
        printf("----------------------MENU:-------------------------\n");
        printf("----------------------------------------------------\n");
        printf("|1. EXIBIR QUARTOS DISPONIVEIS                     |\n");
        printf("|--------------------------------------------------|\n");
        printf("|2. FAZER UMA RESERVA                              |\n");
        printf("|--------------------------------------------------|\n");
        printf("|3. EXIBIR CLIENTES E RESERVAS                     |\n");
        printf("|--------------------------------------------------|\n");
        printf("|4. ZERAR RESERVAS                                 |\n");
        printf("|--------------------------------------------------|\n");
        printf("|5. PAGAMENTO                                      |\n");
        printf("|--------------------------------------------------|\n");
        printf("|6.ADMINISTRACAO                                   |\n");
        printf("|--------------------------------------------------|\n");
        printf("|7. SAIR                                           |\n");
        printf("|--------------------------------------------------|\n");
        printf("|ESCOLHA UMA OPCAO                                 |: ");
        scanf("%d", &opc);
        
        switch(opc){
                
            case 1:
                printf("\n\n");

                printf("|-----------------------|\n");
                printf("|  QUARTOS DISPONIVEIS  |\n");
                printf("|-----------------------|\n");
                printf("|1. QUARTOS SIMPLES:    |\n");
                printf("|2. QUARTOS DE LUXO     |\n");
                printf("|-----------------------|\n");

                printf("ESCOLHA QUAL TIPO DE QUARTO VOCE DESEJA:");
                scanf("%d", &esc);
                
                switch (esc){
                    case 1:
                        printf("\nQUARTOS SIMPLES DISPONIVEIS:\n\n");
                        for (int i = 0; i < 10; i++){
                            if(!quarto[i].reserva){
                                exibirQuarto(quarto[i]);

                            }
                        }
                        break;
                    case 2:
                        printf("\nQUARTOS DE LUXO DISPONIVEIS:\n\n");
                        for (int i = 0; i <= 10; i++){
                            if(!luxos[i].reserva2){
                                exibirLuxo(luxos[i]);

                            }
                        }
                        break;
                        
                }
                break;
            case 2:
                printf("\nDIGITE O NUMERO DO QUARTO QUE DESEJA RESERVAR:");
                int numeroQuarto;
                scanf("%d", &numeroQuarto);
                
                if (numeroQuarto >= 1 && numeroQuarto <= 10) {
                    int checkin, checkout;
                    int podeReservar = 1; // Variável para controlar se a reserva é possível
                    
                    // Coletar informações do cliente
                    printf("\nDIGITE O SEU NOME PARA COMPLETAR A RESERVA:");
                    scanf("%s", clientes[numeroQuarto - 1].nome);
                    
                    printf("\nDIGITE O SEU TELEFONE PARA COMPLETAR A RESERVA:");
                    scanf("%s", clientes[numeroQuarto - 1].telefone);
                    
                    printf("\nDIGITE SEU EMAIL:");
                    scanf("%s", clientes[numeroQuarto - 1].email);
                    
                    printf("\nDIGITE O DIA DO CHECK IN:");
                    scanf("%d", &checkin);
                    
                    printf("\nDIGITE O DIA DO CHECK OUT:");
                    scanf("%d", &checkout);
                    
                    // Verificar se check-in e check-out são válidos
                    if (checkin < 1 || checkin > 31 || checkout < 1 || checkout > 31 || checkin >= checkout) {
                        printf("\nDATA DE CHECK-IN E CHECK-OUT INVALIDAS\n");
                    } else {
                        // Verificar disponibilidade do quarto para as datas escolhidas
                        for (int i = 0; i < MAX_RESERVAS; i++) {
                            struct Reservas *reserva = &quarto[numeroQuarto - 1].reservas[i];
                            if (reserva->checkin != 0) {
                                // Verificar se a reserva entra em conflito com as datas escolhidas
                                if (!(checkout < reserva->checkin || checkin > reserva->checkout)) {
                                    printf("\nQUARTO JA RESERVADO PARA AS DATAS ESCOLHIDAS\n");
                                    podeReservar = 0;
                                    break;
                                }
                            }
                        }
                        
                        if (podeReservar) {
                            // Encontre um slot vazio para armazenar a nova reserva
                            for (int i = 0; i < MAX_RESERVAS; i++) {
                                struct Reservas *reserva = &quarto[numeroQuarto - 1].reservas[i];
                                if (reserva->checkin == 0) {
                                    reserva->checkin = checkin;
                                    reserva->checkout = checkout;
                                    // Defina um valor total fictício para a reserva (você pode calcular isso com base no preço do quarto)
                                    clientes[numeroQuarto - 1].valorTotal = quarto[numeroQuarto - 1].preco * (checkout - checkin);
                                    quarto[numeroQuarto - 1].reserva = 1; // Marcar o quarto como reservado
                                    printf("\nRESERVA EFETUADA COM SUCESSO!\n");
                                    break;
                                }
                            }
                        }
                    }
                } else if (numeroQuarto >= 11 && numeroQuarto <= 20) {
                    int checkin, checkout;
                    int podeReservar = 1;

                    // Coletar informações do cliente
                    printf("\nDIGITE O SEU NOME PARA COMPLETAR A RESERVA:");
                    scanf("%s", clientes[numeroQuarto - 11].nome);
                    
                    printf("\nDIGITE O SEU TELEFONE PARA COMPLETAR A RESERVA:");
                    scanf("%s", clientes[numeroQuarto - 11].telefone);
                    
                    printf("\nDIGITE SEU EMAIL:");
                    scanf("%s", clientes[numeroQuarto - 11].email);
                    
                    printf("\nDIGITE O DIA DO CHECK IN:");
                    scanf("%d", &checkin);
                    
                    printf("\nDIGITE O DIA DO CHECK OUT:");
                    scanf("%d", &checkout);

                    if (checkin < 1 || checkin > 31 || checkout < 1 || checkout > 31 || checkin >= checkout) {
                        printf("\nDATA DE CHECK-IN E CHECK-OUT INVALIDAS\n");
                    } else {
                        // Verificar disponibilidade do quarto de luxo para as datas escolhidas
                        for (int i = 0; i < MAX_RESERVAS; i++) {
                            struct Reservass *reserva2 = &luxos[numeroQuarto - 11].reservas[i];
                            if (reserva2->checkin2 != 0) {
                                // Verificar se a reserva entra em conflito com as datas escolhidas
                                if (!(checkout < reserva2->checkin2 || checkin > reserva2->checkout2)) {
                                    printf("\nQUARTO JA RESERVADO PARA AS DATAS ESCOLHIDAS\n");
                                    podeReservar = 0;
                                    break;
                                }
                            }
                        }
                        
                        if (podeReservar) {
                            // Encontre um slot vazio para armazenar a nova reserva de luxo
                            for (int i = 0; i < MAX_RESERVAS; i++) {
                                struct Reservass *reserva2 = &luxos[numeroQuarto - 11].reservas[i];
                                if (reserva2->checkin2 == 0) {
                                    reserva2->checkin2 = checkin; // Use as variáveis originais 'checkin' e 'checkout'
                                    reserva2->checkout2 = checkout;
                                    // Defina um valor total fictício para a reserva (você pode calcular isso com base no preço do quarto de luxo)
                                    clientes[numeroQuarto - 11].valorTotal = luxos[numeroQuarto - 11].preco2 * (checkout - checkin);
                                    luxos[numeroQuarto - 11].reserva2 = 1; // Marcar o quarto de luxo como reservado
                                    printf("RESERVA DE QUARTO DE LUXO EFETUADA COM SUCESSO!\n");
                                    break;
                                }
                            }
                        }
                    }
                } else {
                    printf("\nNÚMERO DE QUARTO INVÁLIDO.\n");
                }
                break;
          
                            
            case 3:
                printf("\nQUARTOS RESERVADOS:\n\n");
                int encontrouReservas = 0; // Variável para verificar se encontrou alguma reserva

                // Percorrer todos os quartos padrão
                for (int i = 0; i < 10; i++) {
                    if (quarto[i].reserva) {
                        exibirQuarto(quarto[i]);
                        printf("-------------------------------------\n");


                        // Verificar se há reservas para este quarto
                        for (int j = 0; j < MAX_RESERVAS; j++) {
                            struct Reservas *reserva = &quarto[i].reservas[j];
                            if (reserva->checkin != 0) {
                                printf("RESERVA %d:\n", j + 1);
                                printf("-------------------------------------\n");
                                printf("CHECK-IN: DIA %d\n", reserva->checkin);
                                printf("-------------------------------------\n");
                                printf("CHECK-OUT: DIA %d\n", reserva->checkout);
                                printf("-------------------------------------\n");
                                printf("\n");
                            }
                        }

                        encontrouReservas = 1; // Marcar que pelo menos uma reserva foi encontrada
                    }
                }
                // Percorrer todos os quartos de luxo
                   for (int i = 0; i < 10; i++) {
                       if (luxos[i].reserva2) {
                           exibirLuxo(luxos[i]);
                           printf("-------------------------------------\n");


                           // Verificar se há reservas para este quarto de luxo
                           for (int j = 0; j < MAX_RESERVAS; j++) {
                               struct Reservass *reserva = &luxos[i].reservas[j];
                               if (reserva->checkin2 != 0) {
                                   printf("RESERVA %d:\n", j + 1);
                                   printf("-------------------------------------\n");
                                   printf("CHECK-IN: DIA %d\n", reserva->checkin2);
                                   printf("-------------------------------------\n");
                                   printf("CHECK-OUT: DIA %d\n", reserva->checkout2);
                                   printf("-------------------------------------\n");
                                   printf("\n\n");
                            
                               }
                           }

                           encontrouReservas = 1; // Marcar que pelo menos uma reserva foi encontrada
                       }
                   }

                   if (!encontrouReservas) {
                       printf("\nNENHUM QUARTO RESERVADO.\n\n");
                   }
                   break;
            case 4:
                printf("DIGITE O NUMERO DO QUARTO QUE VOCE DESEJA: ");
                int numQuarto;
                scanf("%d", &numQuarto);

                if (numQuarto >= 1 && numQuarto <= 10) {
                    // Verificar se o quarto está reservado
                    if (quarto[numQuarto - 1].reserva == 1) {
                        printf("A RESERVA ESTA ATIVA PATRA O QUARTO %d (Simples).\n", numQuarto);

                        // Exibir informações sobre as reservas para o quarto
                        for (int i = 0; i < MAX_RESERVAS; i++) {
                            struct Reservas *reserva = &quarto[numQuarto - 1].reservas[i];
                            if (reserva->checkin != 0) {
                                printf("RESERVA %d:\n", i + 1);
                                printf("CHECK-IN: DIA %d\n", reserva->checkin);
                                printf("CHECK-OUT: DIA %d\n", reserva->checkout);
                            }
                        }

                        // Solicitar ao usuário qual reserva deseja excluir
                        int numReserva;
                        printf("DIGITE O NUMERO DA RESERVA QUE DESEJA EXCLUIR: ");
                        scanf("%d", &numReserva);

                        if (numReserva >= 1 && numReserva <= MAX_RESERVAS) {
                            // Verificar se a reserva selecionada existe
                            struct Reservas *reserva = &quarto[numQuarto - 1].reservas[numReserva - 1];
                            if (reserva->checkin != 0) {
                                // Zerar a reserva selecionada
                                reserva->checkin = 0;
                                reserva->checkout = 0;
                                printf("RESERVA %d EXCLUIDA COM SUCESSO.\n", numReserva);
                            } else {
                                printf("RESERVA %d NAO ENCONTRADA.\n", numReserva);
                            }
                        } else {
                            printf("NUMERO DA RESERVA INVALIDO.\n");
                        }
                    } else {
                        printf("O QUARTO %d (SIMPLES) NAO POSSUI RESERVA ATIVA.\n", numQuarto);
                    }
                } else if (numQuarto >= 11 && numQuarto <= 20) {
                    // Verificar se o quarto de luxo está reservado
                    if (luxos[numQuarto - 11].reserva2 == 1) {
                        printf("A RESERVA CONTINUA ATIVA PARA O QUARTO %d (Luxo).\n", numQuarto);

                        // Exibir informações sobre as reservas para o quarto de luxo
                        for (int i = 0; i < MAX_RESERVAS; i++) {
                            struct Reservass *reserva2 = &luxos[numQuarto - 11].reservas[i];
                            if (reserva2->checkin2 != 0) {
                                printf("RESERVA %d:\n", i + 1);
                                printf("CHECK-IN: DIA %d\n", reserva2->checkin2);
                                printf("CHECK-OUT: DIA %d\n", reserva2->checkout2);
                            }
                        }

                        // Solicitar ao usuário qual reserva deseja excluir para o quarto de luxo
                        int numReserva;
                        printf("DIGITE O NUMERO DA RESERVA QUE DESEJA EXCLUIR: ");
                        scanf("%d", &numReserva);

                        if (numReserva >= 1 && numReserva <= MAX_RESERVAS) {
                            // Verificar se a reserva selecionada existe
                            struct Reservass *reserva2 = &luxos[numQuarto - 11].reservas[numReserva - 1];
                            if (reserva2->checkin2 != 0) {
                                // Zerar a reserva selecionada para o quarto de luxo
                                reserva2->checkin2 = 0;
                                reserva2->checkout2 = 0;
                                printf("RESERVA %d EXCLUIDA COM SUCESSO.\n", numReserva);
                            } else {
                                printf("RESERVA %d NAO ENCONTRADA.\n", numReserva);
                            }
                        } else {
                            printf("NUMERO DA RESERVA INVALIDO.\n");
                        }
                    } else {
                        printf("O QUARTO %d (Luxo) NAO POSSUI RESERVA ATIVA\n", numQuarto);
                    }
                } else {
                    printf("NUMERO DO QUARTO INVALIDO.\n");
                }
                break;
                
            case 5:
                printf("\n\n\n");
                printf("|-------FORMAS DE PAGAMENTO-------|\n");
                printf("|---------------------------------|\n");
                printf("|1. DEBITO.                       |\n");
                printf("|---------------------------------|\n");
                printf("|2. CREDITO.                      |\n");
                printf("|---------------------------------|\n");
                printf("|3. PIX.                          |\n");
                printf("|---------------------------------|\n");
                printf("|4. VOLTAR AO MENU PRINCIPAL.     |\n");
                printf("|---------------------------------|\n");
                printf("ESCOLHA UMA FORMA DE PAGAMENTO.");
                scanf("%d", &pag);

                
                switch (pag) {
                        case 1:
                            printf("\nDIGITE O NUMERO DO SEU QUARTO: ");
                            scanf("%d", &numQuarto);

                            if (numQuarto >= 1 && numQuarto <= 10 && quarto[numQuarto - 1].reserva) {
                                // Coletar o número de dias que o cliente ficou
                                printf("\nDIGITE O NUMERO DE DIAS QUE FICOU HOSPEDADO: ");
                                scanf("%d", &numDias);

                                // Calcular o valor total
                                valorTotalSimples = quarto[numQuarto - 1].preco * numDias;
                                valorcomdesconto = valorTotalSimples * 0.10;
                                valorcomdesconto2 = valorTotalSimples - valorcomdesconto;
                            
                                // Processar o pagamento para quarto simples
                                printf("\nPAGAMENTO EFETUADO COM SUCESSO PARA O QUARTO  %d (Simples).\n", numQuarto);
                                printf("\nTOTAL A PAGAR R$ %.2lf\n", valorcomdesconto2);

                                quarto[numQuarto - 1].reserva = 0;  // Zerar a reserva
                            }
                       else if (numQuarto >= 11 && numQuarto <= 20 && luxos[numQuarto - 11].reserva2) {
                            // Coletar o número de dias que o cliente ficou
                            printf("\nDIGITE O NUMERO DE DIAS QUE FICOU HOSPEDADO: ");
                            scanf("%d", &numDias);

                            // Calcular o valor total
                           valorTotalLuxo = luxos[numQuarto - 11].preco2 * numDias;
                           valorcomdesconto = valorTotalLuxo * 0.10;
                           valorcomdesconto2 = valorTotalLuxo - valorcomdesconto;

                            // Processar o pagamento para quarto de luxo
                            printf("\nPAGAMENTO EFETUADO COM SUCESSO PARA O QUARTO %d (Luxo).\n", numQuarto);
                            printf("\nTOTAL A PAGAR: R$ %.2lf\n", valorcomdesconto2);

                            luxos[numQuarto - 11].reserva2 = 0;  // Zerar a reserva
                        } else {
                            printf("QUARTO DE LUXO RESERVADO OU INVALIDO.\n");
                        }
                        break;
                            break;

                    case 2:
                                // Opção: Crédito
                                printf("\nDIGITE O NUMERO DO SEU QUARTO: ");
                                scanf("%d", &numQuarto);

                                if (numQuarto >= 1 && numQuarto <= 10 && quarto[numQuarto - 1].reserva) {
                                    // Coletar o número de dias que o cliente ficou
                                    printf("\nDIGITE O NUMERO DE DIAS QUE FICOU HOSPEDADO: ");
                                    scanf("%d", &numDias);

                                    // Calcular o valor total
                                    valorTotalSimples = quarto[numQuarto - 1].preco * numDias;
                                    // Processar o pagamento para quarto simples

                                    printf("\nTOTAL A PAGAR: R$ %.2lf\n", valorTotalSimples);
                                    quarto[numQuarto - 1].reserva = 0;  // Zerar a reserva
                                    
                                } else if (numQuarto >= 11 && numQuarto <= 20 && luxos[numQuarto - 11].reserva2) {
                                    // Coletar o número de dias que o cliente ficou
                                    printf("\nDIGITE O NUMERO DE DIAS QUE FICOU HOSPEDADO: ");
                                    scanf("%d", &numDias);

                                    // Calcular o valor total
                                    valorTotalLuxo = luxos[numQuarto - 11].preco2 * numDias;
                                    // Processar o pagamento para quarto de luxo

                                    printf("\nTOTAL A PAGAR: R$ %.2lf\n", valorTotalLuxo);
                                    luxos[numQuarto - 11].reserva2 = 0;  // Zerar a reserva
                                } else {
                                    printf("\nQUARTO RESERVADO OU INVALIDO.\n");
                                }
                        
                        int esco;
                        
                        printf("\n\n\n");
                        
                        printf("----------ESCOLHA A FOMAA DE PAGAMENTO:------------\n");
                        printf("|-------------------------------------------------|\n");
                        printf("|1.CREDITO A VISTA                                |\n");
                        printf("|-------------------------------------------------|\n");
                        printf("|2.PARCELAMENTO EM 3 VEZES COM ACRESSIMO DE 5%%    |\n");
                        printf("|-------------------------------------------------|\n");
                        printf("|3.PARCELAMENTO EM 6 VEZES COM ACRESSIMO DE 8%%    |\n");
                        printf("|-------------------------------------------------|\n");
                        printf("|4.PARCELAMENTO EM 12 VEZES COM ACRESSIMO DE 10%% |\n");
                        printf("\n  ESCOLHA UMA OPCAO: ");
                        scanf("%d", &esco);
                        
                        printf("\nDIGITE O NUMERO DO QUARTO NOVAMENTE: ");
                        scanf("%d", &numQuarto);

                        switch (esco) {
                            case 1:
                                printf("\nOPCAO ESCOLHIDA: Crédito à vista\n");
                                
                                if (numQuarto >= 1 && numQuarto <= 10) {
                                    // Calcular o valor com desconto para quarto simples
                                    valorcomdesconto = valorTotalSimples * 0.03;
                                    valorcomdesconto2 = valorTotalSimples + valorcomdesconto;
                                    
                                    printf("\nTOTAL A PAGAR (COM ACRÉSCIMO DE 3%%): R$ %.2lf\n", valorcomdesconto2);
                                    quarto[numQuarto - 1].reserva = 0;  // Zerar a reserva
                                    
                                } else if (numQuarto >= 11 && numQuarto <= 20) {
                                    // Calcular o valor com desconto para quarto de luxo
                                    valorcomdesconto = valorTotalLuxo * 0.03;
                                    valorcomdesconto2 = valorTotalLuxo - valorcomdesconto;
                                    
                                    printf("\nTOTAL A PAGAR (COM ACRÉSCIMO DE 3%%): R$ %.2lf\n", valorcomdesconto2);
                                    luxos[numQuarto - 11].reserva2 = 0;  // Zerar a reserva
                                }
                                break;
                                
                                
                            case 2:
                                // Opção: Parcelamento em 3 vezes com acréscimo de 5%
                                if (numQuarto >= 1 && numQuarto <= 10){
                                    valorcomdesconto = valorTotalSimples * 5/100;
                                    valorcomdesconto2 = valorTotalSimples + valorcomdesconto;
                                    printf("OPÇAO ESCOLHIDA: PARCELAMENTO EM 3 VEZES COM ACRÉSCIMO DE 5%%\n");
                                    printf("TOTAL A PAGAR (COM ACRÉSCIMO DE 5%%):\n");
                                    for (int i = 1; i <= 3; i++){
                                        printf("%dª PARCELA: R$ %.2lf\n", i, (valorTotalSimples + valorcomdesconto) / 3);
                                    }
                                }
                                else if (numQuarto >= 11 && numQuarto <= 20){
                                    valorcomdesconto = valorTotalLuxo * 5/100;
                                    valorcomdesconto2 = valorTotalLuxo + valorcomdesconto;
                                    
                                    printf("OPÇAO ESCOLHIDA: PARCELAMENTO EM 3 VEZES COM ACRÉSCIMO DE 5%%\n");
                                    printf("TOTAL A PAGAR (COM ACRÉSCIMO DE 5%%):\n");
                                    for (int i = 1; i <= 3; i++){
                                        printf("%dª PARCELA: R$ %.2lf\n", i, (valorTotalLuxo + valorcomdesconto) / 3);
                                    }
                                }else{
                                    printf(" NUMERO DO QUARTO INVALIDO");
                                }
                                break;
                                
                            case 3:
                                if (numQuarto >= 1 && numQuarto <= 10){
                                    
                                    valorcomdesconto = valorTotalSimples * 8/100;
                                    
                                    printf("OPÇAO ESCOLHIDA: PARCELAMENTO EM 6 VEZES COM ACRÉSCIMO DE 8%%\n");
                                    printf("TOTAL A PAGAR (COM ACRÉSCIMO DE 8%%):\n");
                                    for (int i = 1; i <= 6; i++){
                                        printf("%dª PARCELA: R$ %.2lf\n", i, (valorTotalSimples + valorcomdesconto) / 6);
                                    }
                                }
                                else if (numQuarto >= 11 && numQuarto <= 20){
                                    // Opção: Parcelamento em 6 vezes com acréscimo de 8%
                                    valorcomdesconto = valorTotalLuxo * 8/100;
                                    
                                    printf("OPÇAO ESCOLHIDA: PARCELAMENTO EM 6 VEZES COM ACRÉSCIMO DE 8%%\n");
                                    printf("TOTAL A PAGAR (COM ACRÉSCIMO DE 8%% ):\n");
                                    for (int i = 1; i <= 6; i++){
                                        printf("%dª PARCELA: R$ %.2lf\n", i, (valorTotalLuxo + valorcomdesconto) / 6);
                                    }
                                }
                                
                                
                                break;
                                
                            case 4:
                                if (numQuarto >= 1 && numQuarto <= 10){
                                valorcomdesconto = valorTotalSimples * 10/100;
                                
                                printf("\nOPCAO: PARCELAMENTO EM 12 VEZES COM ACRESSIMO DE 10%%\n");
                                printf("\nTOTAL A PAGAR (C0M ACRESSIMO DE 10%% NO VALOR TOTAL):\n");
                                for (int i = 1; i <= 12; i++) {
                                    printf("%dª PARCELA: R$ %.2lf\n", i, (valorTotalSimples + valorcomdesconto) / 12);
                                }
                                
                                }  else if (numQuarto >= 11 && numQuarto <= 20){
                                    // Opção: Parcelamento em 12 vezes com acréscimo de 10%
                                    valorcomdesconto = valorTotalLuxo * 10/100;
                                    
                                    printf("\nOPCAO: PARCELAMENTO EM 12 VEZES COM ACRESSIMO DE 10%%\n");
                                    printf("\nTOTAL A PAGAR (C0M ACRESSIMO DE 10%% NO VALOR TOTAL):\n");
                                    for (int i = 1; i <= 12; i++) {
                                        printf("%dª PARCELA: R$ %.2lf\n", i, (valorTotalLuxo + valorcomdesconto) / 12);
                                    }
                                }
                                        break;

                                    default:
                                        printf("\nOPCAO DE PARCELAMENTO INVALIDA.\n");
                                        break;
                                
                            }
                        break;

                    case 3:
                        printf("DIGITE O NUMERO DO SEU QUARTO: ");
                        scanf("%d", &numQuarto);
                        
                        if (numQuarto >= 1 && numQuarto <= 10 && quarto[numQuarto - 1].reserva) {
                            
                            // Coletar o número de dias que o cliente ficou
                            printf("\nDIGITE QUANTOS DIAS VOCE FICOU HOSPEDADO: ");
                            scanf("%d", &numDias);
                            
                            // Calcular o valor total
                            valorTotalSimples = quarto[numQuarto - 1].preco * numDias;
                            valorcomdesconto = valorTotalSimples * 15/100;
                            valorcomdesconto2 = valorTotalSimples - valorcomdesconto;
                            
                            // Processar o pagamento para quartos especiais
                            printf("\nPAGAMENTO EFETUADO PARA O QUARTO %d (SIMPLES).\n", numQuarto);
                            printf("TOTAL A PAGAR (COM DESCONTO DE 15%%): R$ %.2lf\n", valorcomdesconto2);
                            
                            quarto[numQuarto - 1].reserva = 0;  // Zerar a reserva
                        }
                        
                        else if (numQuarto >= 11 && numQuarto <= 20 && luxos[numQuarto - 11].reserva2) {
                            
                            // Coletar o número de dias que o cliente ficou
                            printf("\nDIGITE QUANTOS DIAS VOCE FICOU HOSPEDADO: ");
                            scanf("%d", &numDias);
                            
                            // Calcular o valor total
                            valorTotalLuxo = luxos[numQuarto - 11].preco2 * numDias;
                            valorcomdesconto = valorTotalLuxo * 15/100;
                            valorcomdesconto2 = valorTotalLuxo - valorcomdesconto;
                            
                            // Processar o pagamento para quartos especiais
                            printf("\nPAGAMENTO EFETUADO PARA O QUARTO %d (Luxo).\n", numQuarto);
                            printf("TOTAL A PAGAR (COM DESCONTO DE 15%%): R$ %.2lf\n", valorcomdesconto2);
                            
                            luxos[numQuarto - 11].reserva2 = 0;  // Zerar a reserva
                        }

                        break;


                        case 4:
                            break;

                        default:
                            printf("OPCAO DE PAGAMENTO INVALIDA.\n");
                    }

                    break;
                // ... (seu código existente)

            case 6:
                printf("\nDIGITE SEU LOGIN: ");
                scanf("%d", &adm);
                printf("DIGITE SUA SENHA: ");
                scanf("%d", &senha);

                if (adm == 1234 && senha == 4321) {
                    printf("ACESSO AUTORIZADO.\n");
                    printf("\nRELATÓRIO GERAL DE RESERVAS:\n");
                    int encontrouReservas = 0; // Variável para verificar se encontrou alguma reserva
                    double faturamentoTotal = 0.0; // Variável para acompanhar o faturamento total

                    // Percorrer todos os quartos simples
                    for (int i = 0; i < 10; i++) {
                        if (quarto[i].reserva) {
                            printf("QUARTO SIMPLES - Número: %d\n", quarto[i].numero);
                            printf("NOME DO CLIENTE: %s\n", clientes[i].nome);
                            printf("TELEFONE DO CLIENTE: %s\n", clientes[i].telefone);
                            printf("EMAIL DO CLIENTE: %s\n", clientes[i].email);
                            printf("CHECK-IN: DIA %d\n", quarto[i].reservas[0].checkin);
                            printf("CHECK-OUT: DIA %d\n", quarto[i].reservas[0].checkout); // Suponhamos que um quarto só tenha uma reserva

                            int numDias = quarto[i].reservas[0].checkout - quarto[i].reservas[0].checkin + 1;
                            double valorDiaria = quarto[i].preco;
                            double valorTotal = valorDiaria * numDias;
                            clientes[i].valorTotal = valorTotal;

                            printf("NUMERO DE DIAS: %d\n", numDias);
                            printf("VALOR TOTATO DE RESERVAS: R$ %.2f\n\n", valorTotal);

                            faturamentoTotal += valorTotal;

                            encontrouReservas = 1; // Marcar que pelo menos uma reserva foi encontrada
                        } if(luxos[i].reserva2){
                            printf("QUARTO LUXO - Número: %d\n", luxos[i].numero2);
                            printf("NOME DO CLIENTE: %s\n", clientes[i].nome);
                            printf("TELEFONE DO CLIENTE: %s\n", clientes[i].telefone);
                            printf("EMAIL DO CLIENTE: %s\n", clientes[i].email);
                            printf("CHECK-IN: DIA %d\n", luxos[i].reservas[0].checkin2);
                            printf("CHECK-OUT: DIA %d\n", luxos[i].reservas[0].checkout2); // Suponhamos que um quarto só tenha uma reserva

                            int numDias = luxos[i].reservas[0].checkout2 - luxos[i].reservas[0].checkin2 + 1;
                            double valorDiaria = luxos[i].preco2;
                            double valorTotal = valorDiaria * numDias;
                            clientes[i].valorTotal = valorTotal;

                            printf("NUMERO DE DIASs: %d\n", numDias);
                            printf("VALOR TOTAL DE RESERVAS: R$ %.2f\n\n", valorTotal);

                            faturamentoTotal += valorTotal;
                            
                        }
                    }

                    // Percorrer todos os quartos de luxo
  

                    if (!encontrouReservas) {
                        printf("NENHUMA RESERVA ENCONTRADA.\n");
                    }

                    printf("FATURAMENTO TOTAL DO HOTEL: R$ %.2f\n", faturamentoTotal);
                } else {
                    printf("ACESSO NEGADO. Credenciais de administrador incorretas.\n");
                }

                break;

            case 7:
                printf("saindo....");
                break;
            default:
                printf("opcao invalida");
        }
                
                
        }while (opc != 8);
        
        
        return 0;
    }
