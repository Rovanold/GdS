#include"header.h"
#include"fonction.c"



int main(){ 

    //declaration des variables 
    int i=0;
    char* nom_ou_matricule[100];
    char* mot_de_passe[50];
    FILE *fichier;
    int choix=0;

    start :
    logo();
    printf("        GESTION DES SALAIRES    \n");
    printf("\n");
    printf("    Se connecter en tant que :\n");
    printf("\n");

 // Ouvrez le fichier en mode lecture et écriture
    fichier = fopen("utilisateurs.csv", "r+");

// Si le fichier n'existe pas, créez-le
     if (fichier == NULL) {
                    printf("Le fichier d'authentification n'est pas disponible.\n");
                     goto end;
               }

    /// declaration de la structure utilisateur  
     utilisateur* utilisateurs[10] ;
    for (int i = 0; i < 10; i++) {
            (utilisateurs[i]) = (struct utilisateur * ) malloc(sizeof(struct utilisateur));
        }
    
    while (!feof(fichier)) {
                
        struct utilisateur* user = malloc(sizeof(struct utilisateur));
         fscanf(fichier, "%s %s %s %s \n", 
         user->matricule, user->nom, 
         user->statut, user->mot_de_passe);
         utilisateurs[i] = user;
         //retirer le \n sur les variables lues
        char *pos = memchr((utilisateurs[i])->nom, '\n', strlen((utilisateurs[i])->nom));
                    char *dos = memchr((utilisateurs[i])->matricule, '\n', strlen((utilisateurs[i])->matricule));
                    // Si le caractère est trouvé, remplacez-le par 'E'
                if (pos != NULL || dos != NULL) {
                         *pos = '\0';
                         *dos = '\0';
                    } 
         printf( " %s  %d", (*utilisateurs[i]).nom,i);
         printf("\n");
           i++;
        
                }
        int  a = (sizeof((*utilisateurs)) / sizeof(struct utilisateur *));      

       choix = authentification(utilisateurs ,mot_de_passe, nom_ou_matricule, a );

              if(choix==1){
                goto Menu1;
              } else if(choix==2){
                goto Menu2;
              }else{
                goto start;
                }

                // Fermez le fichier
                fclose(fichier);
                
 Menu1: 
    printf("\n");     
      logo();
    printf("                 BIENVENU    \n");
    printf("\n");
    printf("    Vous etes connecter en tant que %s  \n",(utilisateurs[i])->nom);
    printf("\n");
      menu1();
      printf("Votre choix :");
      scanf("%d",&choix);
    switch(choix){
        case 0:
                printf("Deconnexion reussie\n");
                free(*utilisateurs);
                for(int i = 0; i < 50; i++){
                    free(utilisateurs[i]);
                }
            
            goto start;
        case 1:

        goto Menu1;
        case 2:

            goto Menu1;
        case 3:

            goto Menu1;
        case 4:

            goto Menu1;
        case 5:

            goto Menu1;
        case 6:

            goto Menu1;
        default:
            printf("Entrer un choix valide\n");
            goto Menu1;
    }

Menu2 :
             logo();
            printf("                 BIENVENU    \n");
            printf("\n");
            printf("    Vous etes connecter en tant que %s\n",(utilisateurs[i])->nom);
            printf("\n");
            printf("    1- Gestion du compte\n");
            printf("    2- Historique de salaire\n");
            printf("    3- Fiche de paie\n");
            printf("\n \n");
            printf(" 0- Se deconnecter\n");
            scanf("%d",&choix);
            switch(choix){
                case 1:

                goto Menu1;
                break;
                case 2:

                    goto Menu1;
                case 3:

                    goto Menu1;
                case 0:
                    printf("Deconnexion reussie\n");
                    for(int i = 0; i < 50; i++){
                    free(utilisateurs[i]);
                }
                    free(*utilisateurs);
                    goto start;
                
                default:
                    printf("Entrer un choix valide\n");
                    
                    goto Menu1;
            }

            goto end;
    
    

    end :
    return 0;

                }

              
