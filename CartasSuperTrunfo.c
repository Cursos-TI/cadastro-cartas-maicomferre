#include <stdio.h>
#include <unistd.h>

struct Carta {
    char estado;
    char cod_carta[4];
    char nome[60];
    float area;
    float PIB;
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
    printf("\nPerfeito! Agora preencha a segunda carta.\n>----------------- | 2ª CARTA | >>>>\n\n");
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

    printf("\no nome da cidade: ");
    scanf(" %60[^\n]", c->nome);
    printf("\na área da cidade(Ex: 17.5): ");

    scanf(" %f", &c->area);
    printf("\no PIB da cidade(Ex: 17.5): ");

    scanf(" %f", &c->PIB);

    printf("\nOs pontos turisticos(Ex: 12): ");
    scanf(" %i", &c->pontos_turisticos);
}


void exibir_cartas(struct Carta *carta1, struct Carta *carta2) {
    printf("\n~~~~~~~~~~~~~~ ||  Super Trunfo  || ~~~~~~~~~~~~~~\n");
    printf("~~~~~~~~~~~~~~ || CARTAS EM JOGO || ~~~~~~~~~~~~~~\n");
    printf("                     CARTA 1 \n");

    printf("Letra do Estado: %c\n",carta1->estado);
    printf("Codigo da Carta: %s\n",carta1->cod_carta);
    printf("Nome da Cidade: %s\n", carta1->nome);
    printf("Área da Cidade: %f km²\n", carta1->area);
    printf("PIB da Cidade: %f bilhões de reais\n", carta1->PIB);
    printf("Pontos turísticos: %i\n", carta1->pontos_turisticos);


    printf("                     CARTA 2 \n");

    printf("Letra do Estado: %c\n",carta2->estado);
    printf("Codigo da Carta: %s\n",carta2->cod_carta);
    printf("Nome da Cidade: %s\n", carta2->nome);
    printf("Área da Cidade: %f  km²\n", carta2->area);
    printf("PIB da Cidade: %f bilhões de reais\n", carta2->PIB);
    printf("Pontos turísticos: %i\n", carta2->pontos_turisticos);

    printf("~~~~~~~~~~~~~~ || CARTAS EM JOGO || ~~~~~~~~~~~~~~\n");
    printf("~~~~~~~~~~~~~~ ||  Super Trunfo || ~~~~~~~~~~~~~~\n");

}