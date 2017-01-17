#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    /*Initialisation des constantes et de rand */
    const int MIN = 1;
    int nombreMax = 100; //limite superieur du nombre de l'ordinateur pour le niveau de difficulté
    srand(time(NULL));  //init du random
    int choixDuJoueur = 0;  //entier pour le nombre choisit par la joueur
    int rejoue = 1;  //booleen pour continuer ou non le jeu

    //Explication du Jeu
    printf("\nL'ordinateur a choisit un nombre au hasard !\n");
    printf("Seras tu capable de le retrouver rapidement ?\n\n");

    do {
        //Choix de la difficulte
        int choixDifficulte = 1;
        printf("Quel niveau de difficulte choisis tu ?\n");
        printf("  =============\n");
        printf("  H 1 : 100   H\n");
        printf("  H 2 : 500   H\n");
        printf("  H 3 : 1000  H\n");
        printf("  H 4 : 5000  H\n");
        printf("  =============\n");
        printf("Ton choix : ");
        scanf("%d", &choixDifficulte);
        system("cls");
        switch (choixDifficulte) {
            case 1 :
                printf("Un nombre entre 1 et 100.\n"); // niveau facile
                nombreMax = 100;
                break;
            case 2 :
                printf("Un nombre entre 1 et 500!\n"); // niveau moyen
                nombreMax = 500;
                break;
            case 3 :
                printf("Un nombre entre 1 et 1000 !!\n"); //niveau difficile
                nombreMax = 1000;
                break;
            case 4 :
                printf("Un nombre entre 1 et 5000 !!!\n"); //niveau hardcore
                nombreMax = 5000;
                break;
            default:
                printf("Ce n'est pas un choix correct, la difficulte restera sur facile.\n"); // si le niveau n'est pas choisit correctement alors ca reste facile
                break;
        }


        //Tirage du Nombre mystère
        int nombreMystere = (rand() % (nombreMax - MIN + 1)) + MIN;

        //initialisation compteur
        int compteur = 0;

        //boucle demandant la saisie du choix du joueur, verifiant la concordance et annoncant le resultat
        do {
            //Choix du joueur
            printf("Tape le nombre que tu penses etre celui de l'ordinateur :\n");
            scanf("%d", &choixDuJoueur);
            system("cls");
            //annonce du resultat
            if (choixDuJoueur < nombreMystere && choixDuJoueur > MIN) {
                //annonce que le nombre mystere est superieur au nombre choisit
                printf("C'est plus !\n");
                compteur++;
            }
            else if(choixDuJoueur > nombreMystere && choixDuJoueur < nombreMax){
                //annonce que le nombre mystere est inferieur au nombre choisit
                printf("C'est moins !\n");
                compteur++;
            }
            else if(choixDuJoueur < MIN || choixDuJoueur > nombreMax){
                //le nombre n'est pas dans les limites du niveau de difficulte
                printf("Le nombre que tu as tape n'est pas compris entre 1 et %d !\n", nombreMax);
            }
            else {
                //le nombre esr trouve, annonce du nombre de coups
                compteur++;
                printf("Tu as trouve en %d coups !\n", compteur);
            }
        } while(choixDuJoueur != nombreMystere); // verificaton de la concordance

        //Demande pour rejouer
        char choix = 1;
        printf("Veux tu rejouer (1 : Oui / 2 : Non) ? \n");
        scanf("%d", &choix);
        if(choix == 2) {
            rejoue = 0;
            printf("A bientot ! \n");
        }
        else if(choix == 1) {
            rejoue = 1;
        }
        else {
            printf("tu as tape autre chose que 1 ou 2 ! Nous considerons que tu ne souhaites pas rejouer...\n");
            rejoue = 0;
        }
    } while (rejoue == 1);


    return 0;
}


/*
    - Ajout du suivi des choix (ex : 50 - 25 - 12 -17 ...)

*/
