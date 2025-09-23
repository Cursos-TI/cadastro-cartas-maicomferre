#include <stdio.h>
#include <unistd.h>

struct Carta {
    char estado;
    char cod_carta[10];
    unsigned int populacao;
    char nome[60]; //considerando a cidade Llanfairpwllgwyngyllgogerychwyrndrobwllllantysiliogogogoch(59)
    double area;
    double PIB;
    int pontos_turisticos;
};

void obter_carta(struct Carta *c);
void exibir_cartas(struct Carta *carta1, struct Carta *carta2);

int main(void) {
    struct Carta carta1;
    struct Carta carta2;

    printf("~~~~~~~~~~~~~~ ||  Super Trunfo || ~~~~~~~~~~~~~~\n");

    sleep(1);
    printf("\t\t\tBem vindo ao Jogo.\n");
    sleep(1);
    printf("Para começar cadastre 2 cartas\n");
    sleep(2);
    printf("Começe com a primeira:\n");
    sleep(3);

    obter_carta(&carta1);

    sleep(1);
    printf("\nPerfeito! Agora preencha a segunda carta.\n");
    printf(">----------------- | 2ª CARTA | >>>>\n\n");
    sleep(3);

    obter_carta(&carta2);

    sleep(1);

    printf("Comparação entre as cartas: ");
    exibir_cartas(&carta1,&carta2);
    return 0;
}

void obter_carta(struct Carta *c) {
    printf("1) Informe o estado. Uma letra de 'A' a 'H' (representando um dos oito estados): ");
    scanf(" %c", &c->estado);

    printf("\n2)Codigo da carta: A letra do estado seguida de um número de 01 a 04 (ex: A01, B03).\n");
    printf("\n\to codigo da carta: ");
    scanf(" %s", c->cod_carta);

    printf("\no nome da cidade(Ex: São Paulo): ");
    scanf(" %60[^\n]", c->nome);

    printf("\na população da cidade: ");
    scanf("%u", &c->populacao);

    printf("\na área da cidade(Ex: 17.5): ");

    scanf(" %lf", &c->area);
    printf("\no PIB da cidade(Ex: 17.5): ");

    scanf(" %lf", &c->PIB);

    printf("\nOs pontos turisticos(Ex: 12): ");
    scanf(" %i", &c->pontos_turisticos);
}


void exibir_cartas(struct Carta *carta1, struct Carta *carta2) {
    // Carta 1
    double densidade_populacao = carta1->populacao / carta1->area;
    double PIB_per_capta = (carta1->PIB * 1e9) / (double)carta1->populacao;

    printf("\nCarta 1:\n\n");
    printf("Estado: %c\n", carta1->estado);
    printf("Código: %s\n", carta1->cod_carta);
    printf("Nome da Cidade: %s\n", carta1->nome);
    printf("População: %u\n", carta1->populacao);
    printf("Área: %.2f km²\n", carta1->area);
    printf("PIB: %.2f bilhões de reais\n", carta1->PIB);
    printf("Número de Pontos Turísticos: %d\n", carta1->pontos_turisticos);
    printf("Densidade Populacional: %.2f hab/km²\n", densidade_populacao);
    printf("PIB per Capita: %.2f reais\n", PIB_per_capta);

    // Carta 2
    densidade_populacao = carta2->populacao / (double)carta2->area;
    PIB_per_capta = (carta2->PIB * 1e9) / (double)carta2->populacao;

    printf("\n\nCarta 2:\n\n");
    printf("Estado: %c\n", carta2->estado);
    printf("Código: %s\n", carta2->cod_carta);
    printf("Nome da Cidade: %s\n", carta2->nome);
    printf("População: %u\n", carta2->populacao);
    printf("Área: %.2f km²\n", carta2->area);
    printf("PIB: %.2f bilhões de reais\n", carta2->PIB);
    printf("Número de Pontos Turísticos: %d\n", carta2->pontos_turisticos);
    printf("Densidade Populacional: %.2f hab/km²\n", densidade_populacao);
    printf("PIB per Capita: %.2f reais\n", PIB_per_capta);
}
