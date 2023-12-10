#include"header.h"

void logo(void){
    printf("\n \n");
    printf("            |||||||||                   |||||||||    \n ");
    printf("          ???      ||||                ???     ??   \n");
    printf("         ???       ||||        |||     ???          \n");
    printf("        |||                    |||       ????       \n");
    printf("        |||    ||||||||        |||          ????    \n ");
    printf("         ???       ||||    |||||||            ???   \n");
    printf("          ???      ||||   ||||||||     ???   ????    \n");
    printf("            |||||||||      |||||||      |||||||||    \n ");
    printf("\n");
}

void menu1(void){ 
   
    printf("    1- Gestion du compte\n");
    printf("    2- Gestion des employers\n");
    printf("    3- Calcul des salaires\n");
    printf("    4- Gestion de paie\n");
    printf("    5- Rappors\n");
    printf("    6- Gestion des horaires de travail\n");
    printf("\n \n");
    printf("0- Se deconnecter\n\n");
}


typedef struct utilisateur utilisateur ;
struct utilisateur {
  char nom[100];
  char matricule[100];
  char mot_de_passe[100];
  char statut[20];
};

int authentification(utilisateur* utilisateurs[10],char* mot_de_passe[] ,char* nom_ou_matricule[], int a ){
    

      top1:
                // Demandez à l'utilisateur son nom ou son matricule
                printf("Veuillez entrer votre nom ou votre matricule : ");

                // Utilisez la fonction fgets pour lire le nom
                fgets(*nom_ou_matricule, sizeof(*nom_ou_matricule), stdin);
                //on remplace \n par \0
                //nom_ou_matricule[strcspn(*nom_ou_matricule, "\n")]='\0';
                    char *nos = memchr(*nom_ou_matricule, '\n', strlen(*nom_ou_matricule));
                              // Si le caractère est trouvé, remplacez-le par 'E'
                       if (nos != NULL) {
                              *nos = '\0';
                          }
        //  int  a =  sizeof((*utilisateurs)) / sizeof(struct utilisateur *); printf("%d",a);
          
          //// Recherchez l'utilisateur dans la liste
          
     for(int i = 0; i<a ; i++) {
                   printf( " %s  %d  %s", (*utilisateurs[i]).nom,i, *nom_ou_matricule);
                     printf("\n");
                    //condition pour comparer nom_ou_matricule avec utilisateur[i].nom et utilisateurs[i].matricule
                    if (strcmp(*nom_ou_matricule, (*utilisateurs[i]).nom) == 0 ||
                        strcmp(*nom_ou_matricule, (*utilisateurs[i]).matricule) == 0) { 
                            printf("Bonjour encore \n");
                            // Si l'utilisateur est trouvé, demandez son mot de passe
                        if (i < a) {
                    top2 :
                            printf("Veuillez entrer votre mot de passe : ");
                            fgets(*mot_de_passe, sizeof(*mot_de_passe), stdin);
                            //mot_de_passe[strcspn(*mot_de_passe, "\n")]= '\0';
                            char *mos = memchr(*mot_de_passe, '\n', strlen(*mot_de_passe));
                              // Si le caractère est trouvé, remplacez-le par 'E'
                       if (mos != NULL) {
                              *mos = '\0';
                          }
                            (*utilisateurs[i]).statut[strcspn((*utilisateurs[i]).statut, "\n")]= '\0';
                            // Si le mot de passe est correct, authentifiez l'utilisateur
                            if (strcmp(*mot_de_passe, (*utilisateurs[i]).mot_de_passe) == 0) {
                                
                            printf("Authentification réussie !\n");
                            //vers le choix des menus
                            goto test ;
                            break;
                            } else {
                            printf("Mot de passe incorrect.\n");
                            goto top2;
                            }
                        } else {
                            printf("Utilisateur non trouvé.\n");
                            goto top1;
                        }
                   // break;
                    }
                //choix des menu 
                    test : 
                 //verifie le statu de l'utilisateur "admin" ou "employer"
                            if(strcmp("admin", (*utilisateurs[i]).statut)==0){
                                printf("%s",(*utilisateurs[i]).statut);
                               return 1;
                            }else { 
                                printf("%s",(*utilisateurs[i]).statut);
                                return 2;
                            }
                }
                return 0;
}
