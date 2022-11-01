#include<stdlib.h>
#include<stdio.h>
#include<ctype.h>
#include<assert.h>
#include <string>
#pragma warning(disable:4996)

const int nbJoueusesMax = 128;
const int nbTournoisMax = 10;
const char taillemaxMots = 30;
const int nbMatchsMax = 127;
typedef struct {
	char nom[50];
	unsigned int points;
}joueuse;

typedef struct {
	unsigned int idxGagnante;
	unsigned int idxPerdante;

}Match;

typedef struct {
	char nom[30];
	int date;
	Match dataMatch[127];

}Tournoi;



typedef struct {
	Tournoi dataTournois[nbTournoisMax];
	unsigned int nbTournois;
	joueuse dataJoeuses[1280];
	unsigned int idxT;
	unsigned int idxJ;
}TournoiWta;

void enregistrement_tournoi(TournoiWta* tournoiWta) {

	scanf("%s", tournoiWta->dataTournois[0].nom);
	char date[5]; /* variable qui recupere la date car il faut la recuperer en chaine de caractere avant de la transformer en entier ave atoi()*/
	/* 5 caracteres car une date porte maximum 4 chiffres*/
	scanf("%s", date);
	tournoiWta->dataTournois[0].date = atoi(date);
	/*enregistrement des joueuses*/
	for (int i = 0; i < nbJoueusesMax; i++) {
		scanf("%s", tournoiWta->dataJoeuses[i].nom);
	}
	/*enregistrement des 32 prmiers matchs*/
	int point = 0;
	for (int i = 0; i < nbJoueusesMax; i++) {
		tournoiWta->dataTournois[0].dataMatch[point].idxGagnante = i;
		++i;
		tournoiWta->dataTournois[0].dataMatch[point].idxPerdante = i;
		point++;


	}
	int alterne = 0;
	char nomJoueuse[taillemaxMots];

	while (point < nbMatchsMax) {

		scanf("%s", nomJoueuse);
		int i;
		for (i = 0; i < nbJoueusesMax; i++) {
			if (strcmp(tournoiWta->dataJoeuses[i].nom, nomJoueuse) == 0) {

				break;

			}
		}
		if (alterne == 0) {
			tournoiWta->dataTournois[0].dataMatch[point].idxGagnante = i;
			alterne = 1;

		}
		else {
			tournoiWta->dataTournois[0].dataMatch[point].idxPerdante = i;
			alterne = 0;

			point++;
		}
		

	}



}




void affichage_matchs_tournoi(TournoiWta* tournoiWta) {
	char tournoiRecherche[30];
	scanf("%s", tournoiRecherche);
	char anneeRecherche[30];
	scanf("%s", anneeRecherche);
	int i = 0;
	for (i = 0; i < nbTournoisMax; i++) {
		if ((strcmp(tournoiWta->dataTournois[i].nom, tournoiRecherche) == 0) && tournoiWta->dataTournois[i].date == atoi(anneeRecherche)) {
			break;
		}
	}
	printf("%s %d\n", tournoiWta->dataTournois[i].nom, tournoiWta->dataTournois[i].date);
	printf("64emes de finale\n");
	for (int s = 0; s < nbMatchsMax; s++) {
		if (s == nbMatchsMax - (nbMatchsMax / 2)) {
			printf("32emes de finale\n");
		}
		if (s == nbMatchsMax - (nbMatchsMax / 4)) {
			printf("16emes de finale\n");
		}
		if (s == nbMatchsMax - (nbMatchsMax / 8)) {
			printf("8emes de finale\n");
		}
		if (s == nbMatchsMax - (nbMatchsMax / 16)) {
			printf("quarts de finale\n");
		}
		if (s == nbMatchsMax - (nbMatchsMax / 32)) {
			printf("demi-finales\n");
		}
		if (s == nbMatchsMax - (nbMatchsMax / 64)) {
			printf("finale\n");
		}


		printf("%s ", tournoiWta->dataJoeuses[tournoiWta->dataTournois[i].dataMatch[s].idxGagnante].nom);
		printf("%s \n", tournoiWta->dataJoeuses[tournoiWta->dataTournois[i].dataMatch[s].idxPerdante].nom);
	}
}


int  main() {
	TournoiWta tournoiWta;

	while (1) {
		/*Cette partie permet a l'utilisateur de rentrer une commande*/
		char commande[30]; /* 30 correspond a la taille maximum d'une commande */
		scanf("%s", commande);

		if (strcmp(commande, "exit") == 0) { /*strcmp sert a comparer les deyux chaines de caractere entre les parantheses*/
			exit(1);
		}


		if (strcmp(commande, "definir_nombre_tournois") == 0) { /*strcmp sert a comparer les deyux chaines de caractere entre les parantheses*/
			int nbTournois;
			scanf("%d", &tournoiWta.nbTournois);
		}

		if (strcmp(commande, "enregistrement_tournoi") == 0) { /*strcmp sert a comparer les deux chaines de caractere entre les parantheses*/
			enregistrement_tournoi(&tournoiWta);
		}

		if (strcmp(commande, "affichage_matchs_tournoi") == 0) { /*strcmp sert a comparer les deyux chaines de caractere entre les parantheses*/
			affichage_matchs_tournoi(&tournoiWta);
		}

		if (strcmp(commande, "test") == 0) { /*strcmp sert a comparer les deyux chaines de caractere entre les parantheses*/

		}
	}

}