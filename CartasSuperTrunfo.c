#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>

struct Carta {
    char estado;
    char cod_carta[10];
    unsigned long int populacao;
    char nome[60]; //considerando a cidade Llanfairpwllgwyngyllgogerychwyrndrobwllllantysiliogogogoch(59) + '\0'
    double area;
    double PIB;
    int pontos_turisticos;
    double super_poder;
    double pib_per_capta;
    double densidade_populacional;
};

void obter_carta(struct Carta *c);
void exibir_carta(struct Carta *carta);
void exibir_vencedor(const struct Carta *carta1, const struct Carta *carta2);

int main(void) {
    struct Carta carta1;
    struct Carta carta2;

    printf("~~~~~~~~~~~~~~ ||  Super Trunfo || ~~~~~~~~~~~~~~\n");

    sleep(1);
    printf("\t\t\t\tBem vindo ao Jogo.\n");
    sleep(1);
    printf("Para começar cadastre 2 cartas\n");
    sleep(2);
    printf("Começe com a primeira:\n");
    sleep(2);

    obter_carta(&carta1);

    sleep(1);
    printf("\nPerfeito! Agora preencha a segunda carta.\n");
    printf(">----------------- | 2ª CARTA | >>>>\n\n");
    sleep(1);

    //Faz a coleta do stdin para a carta
    obter_carta(&carta2);

    sleep(1);

    printf("Comparação entre as cartas: ");

    printf("\n\nCarta 1:\n\n");
    exibir_carta(&carta1);
    printf("\n\nCarta 2:\n\n");
    exibir_carta(&carta2);

    sleep(5);
    exibir_vencedor(&carta1, &carta2);
    return 0;
}

void obter_carta(struct Carta *c) {
    printf("1) Informe o estado. Uma letra de 'A' a 'H' (representando um dos oito estados): ");
    scanf(" %c", &c->estado);

    printf("\n2)Codigo da carta: A letra do estado seguida de um número de 01 a 04 (ex: A01, B03).\n");
    printf("\n\to codigo da carta: ");
    scanf(" %s", c->cod_carta);

    printf("\no nome da cidade(Ex: São Paulo): ");
    scanf(" %59[^\n]", c->nome);

    printf("\na população da cidade: ");
    scanf("%lu", &c->populacao);

    printf("\na área da cidade(Ex: 17.5): ");

    scanf(" %lf", &c->area);
    printf("\no PIB da cidade(Ex: 17.5): ");

    scanf(" %lf", &c->PIB);

    printf("\nOs pontos turisticos(Ex: 12): ");
    scanf(" %i", &c->pontos_turisticos);


}


void exibir_carta(struct Carta *carta) {
    carta->densidade_populacional = (double)carta->populacao / carta->area;
    carta->pib_per_capta = (carta->PIB * 1e9) / (double)carta->populacao;

    carta->super_poder = (double)carta->populacao +
             carta->area +
             carta->PIB +
             (double)carta->pontos_turisticos +
             carta->pib_per_capta +
             (1.0 / carta->densidade_populacional);

    printf("%-30s %c\n", "Estado:", carta->estado);
    printf("%-30s %s\n", "Código:", carta->cod_carta);
    printf("%-30s %s\n", "Nome da Cidade:", carta->nome);
    printf("%-30s %lu\n", "População:", carta->populacao);
    printf("%-30s %.2f km²\n","Área:", carta->area);
    printf("%-30s %.2f bilhões de reais\n","PIB:", carta->PIB);
    printf("%-30s %d\n", "Número de Pontos Turísticos:", carta->pontos_turisticos);
    printf("%-30s %.2f hab/km²\n","Densidade Populacional:", carta->densidade_populacional);
    printf("%-30s %.2f reais\n","PIB per Capita: ", carta->pib_per_capta);
}

void exibir_vencedor(const struct Carta *carta1, const struct Carta *carta2) {
    printf("Comparação de Cartas:\n");

    //População:
    bool venceu = (carta1->populacao > carta2->populacao);

    printf("População: Carta %d venceu (%d)\n",(venceu ? 1 : 2), venceu);

    //Área
    venceu = (carta1->area > carta2->area);
    printf("Área: Carta %d venceu (%d)\n",(venceu ? 1 : 2), venceu);

    //PIB
    venceu = (carta1->PIB > carta2->PIB);
    printf("PIB: Carta %d venceu (%d)\n",(venceu ? 1 : 2), venceu);

    //Pontos turísticos
    venceu = (carta1->pontos_turisticos > carta2->pontos_turisticos);
    printf("Pontos Turísticos: Carta %d venceu (%d)\n",(venceu ? 1 : 2), venceu);

    //Densidade Populacional
    venceu = (carta1->densidade_populacional < carta2->densidade_populacional);
    printf("Densidade Populacional: Carta %d venceu (%d)\n",(venceu ? 1 : 2), venceu);

    venceu = (carta1->pib_per_capta > carta2->pib_per_capta);
    printf("PIB per Capita: Carta %d venceu (%d)\n",(venceu ? 1 : 2), venceu);

    venceu = (carta1->super_poder > carta2->super_poder);
    printf("Super Poder: Carta %d venceu (%d)\n",(venceu ? 1 : 2), venceu);

    printf(">>>>>> fim de jogo.");
}