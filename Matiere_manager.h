
#include <stdlib.h>

matiere ecriremat(){
	

	FILE *e;
	e=fopen("matiere.txt","a");
	if(e==NULL)
	  printf("erreur d'ouverture");
	else
	  {
	  
	  	fprintf(e,"%s\t%s\t%s\t%d\t%s\t%d\t%s\t%d\n",(*m).relationedmat.nom,(*m).relationedmat.prenom,(*m).relationedmat.filiere,(*m).idmat,(*m).nomat,(*m).coef,(*m).nomod,(*m).note);
	  	fclose(e);
	  }
	  
	
	return (*m);
}


matiere liremat(){
	
    
    
	m=(matiere*)malloc(sizeof(matiere));
	e=(etudiant*)malloc(sizeof(etudiant));
	int trouve;
	printf("       Filiere : ");
	scanf("%s",(*m).relationedmat.filiere);
	int idmat;
    do
      {
      	trouve = 0;
      	printf("       idMatiere : ");
	    scanf("%d",&idmat);
	    FILE *b;
        b=fopen("matiere.txt","r");
        if(b==NULL)
           printf("erreur d'ouverture");
        else
          {
		  
	      while(fscanf(b,"%s\t%s\t%s\t%d\t%s\t%d\t%s\t%d\n", (*m).relationedmat.nom,(*m).relationedmat.prenom,(*m).relationedmat.filiere,&(*m).idmat,(*m).nomat,&(*m).coef,(*m).nomod,&(*m).note) != EOF)
             {
              if((*m).idmat==idmat)
                {
                	trouve = 1;
				}
              
             }
          }
             if(trouve == 1)
              {
				
                printf("\n       le code matiere saisi existe deja ");
                do
                  {
				  printf("\n       Tapez 1 pour saisir une nouvelle fois le code ou 0 pour sortir du terminal : ");
			      scanf("%d",&trouve);
			      }while(trouve != 1 && trouve != 0);
			    if(trouve==0)
			    {
			      exit(1);
			     }
			 }
             if(trouve == 0)
                (*m).idmat=idmat;
                
	  }while(trouve!=0);
	printf("       Nom Matiere : ");
	scanf("%s",(*m).nomat);
	printf("       coefficient : ");
	scanf("%d",&(*m).coef);
	printf("       Module : ");
	scanf("%s",(*m).nomod);
	printf("       Note : ");
	scanf("%d",&(*m).note);
    do
      {
      trouve =0;
	  printf("       Nom : ");
      scanf("%s",(*m).relationedmat.nom);
	  printf("       Prenom : ");
	  scanf("%s",(*m).relationedmat.prenom);
      FILE *b;
      b=fopen("etudiant.txt","r");
      if(b==NULL)
         printf("       Erreur d'ouverture du fichier");
      else
       {
       	 
       	  
			   
       	   	 while(fscanf(b,"%d\t%s\t%s\t%d %s %d\t%s\t%d\t%s\n",&(*e).idetudiant,(*e).nom,(*e).prenom,&(*e).datenaiss.jour,(*e).datenaiss.mois,&(*e).datenaiss.annee,(*e).mail,&(*e).numtel,(*e).filiere)!=EOF)
	 	      {
	 	     	if(strcmp((*m).relationedmat.nom,(*e).nom)==0 && strcmp((*m).relationedmat.prenom,(*e).prenom)==0)
	 	     	   {
	 	     	   	  trouve = 1;
	 	     	   	  ecriremat();
					 }
			  }
			  if(trouve == 0)
			     {
			     	 printf("\n       Le nom et le prenom  saisi n'existe pas dans le fichier etudiant\n\n");
			     	 do
			     	  {
					   printf("       Tapez 0 pour saisir une nouvelle fois le nom et le prenom ou 1 pour sortir du terminal : ");
			     	   scanf("%d",&trouve);
			           }while(trouve != 1 && trouve != 0);
			     	 if(trouve==1)
			     	   {
			     	   	 exit(1);
						}
			      }
			     
		
	   }
      }while(trouve!=1);
	
	
	return (*m);
	
}


matiere affichermat(){
	
	
	m=(matiere*)malloc(sizeof(matiere));
	FILE *e;
	e=fopen("matiere.txt","r");
	if(e==NULL)
	  printf("erreur d'ouverture");
	else
	 {
	 	while(fscanf(e,"%s\t%s\t%s\t%d\t%s\t%d\t%s\t%d\n",(*m).relationedmat.nom,(*m).relationedmat.prenom,(*m).relationedmat.filiere,&(*m).idmat,(*m).nomat,&(*m).coef,(*m).nomod,&(*m).note)!=EOF)
	 	   {
	 	   	printf("       Nom : %s\tPrenom : %s\tFiliere : %s\tIdentifiant Matiere : %d\tNom Matiere: %s\tCoeficient : %d\tNom Module : %s\t Note : %d\n",(*m).relationedmat.nom,(*m).relationedmat.prenom,(*m).relationedmat.filiere,(*m).idmat,(*m).nomat,(*m).coef,(*m).nomod,(*m).note);
			}
		fclose(e);
	 }
	 
	 return (*m);
	
	
}

matiere supprimermat()
  {
  	m=(matiere*)malloc(sizeof(matiere));
    e=(etudiant*)malloc(sizeof(etudiant));
    FILE * y = fopen("matiere.txt", "r");
    FILE * z = fopen("modmatiere.txt", "w");
    int idmat;
    int trouve = 0;
    if(y == NULL)
        printf("       Erreur lors de l'ouverture du fichier \n");
    else
    {
        printf("\n       Entrer le code de matiere : ");
        scanf("%d", &idmat);
        while(fscanf(y,"%s\t%s\t%s\t%d\t%s\t%d\t%s\t%d\n",(*m).relationedmat.nom,(*m).relationedmat.prenom,(*m).relationedmat.filiere,&(*m).idmat,(*m).nomat,&(*m).coef,(*m).nomod,&(*m).note) != EOF)
            {
             if((*m).idmat!=idmat)
             {
               fprintf(z, "%s\t%s\t%s\t%d\t%s\t%d\t%s\t%d\n",(*m).relationedmat.nom,(*m).relationedmat.prenom,(*m).relationedmat.filiere,(*m).idmat,(*m).nomat,(*m).coef,(*m).nomod,(*m).note);
              }
             else
             {
               trouve = 1;
             }
            }
            if(trouve == 0)
                {
                	printf("       le code saisi n'a pas ete trouve ");
				}
            else
                {
                	printf("\n       la matiere a ete supprime \n\n");
                	
				}
			    
            
    }
    fclose(y);
    fclose(z);
	y = fopen("matiere.txt", "w");
    z = fopen("modmatiere.txt", "r");
   if( y != NULL && z != NULL)
       {
           while(fscanf(z,"%s\t%s\t%s\t%d\t%s\t%d\t%s\t%d\n", (*m).relationedmat.nom,(*m).relationedmat.prenom,(*m).relationedmat.filiere,&(*m).idmat,(*m).nomat,&(*m).coef,(*m).nomod,&(*m).note) != EOF)
                {
                   fprintf(y,"%s\t%s\t%s\t%d\t%s\t%d\t%s\t%d\n", (*m).relationedmat.nom,(*m).relationedmat.prenom,(*m).relationedmat.filiere,(*m).idmat,(*m).nomat,(*m).coef,(*m).nomod,(*m).note);
	               }
	    }
   else
        {
            printf("       une erreur s est produite..!\n");
	      }
	    fclose(y);
        fclose(z);
        remove("modmatiere.txt");
    
    return (*m);
    
  }

matiere modifiernomrelationedmat(){
	
	m=(matiere*)malloc(sizeof(matiere));
    FILE *b= fopen("matiere.txt", "r");
    FILE *c= fopen("modmatiere.txt", "w");
    char nom[25];
    int trouve = 0;
    int idmat;

    if( b == NULL)
        printf("              Erreur lors de l'ouverture du fichier \n");
    else
     {
     	printf("\n              Donner l'identifiant de la matiere : ");
        scanf("%d",&idmat);
       /* printf("\nDonner le nom de l'etudiant que vous voulez modifier : ");
        scanf("%s",nom);*/
        while(fscanf(b,"%s\t%s\t%s\t%d\t%s\t%d\t%s\t%d\n", (*m).relationedmat.nom,(*m).relationedmat.prenom,(*m).relationedmat.filiere,&(*m).idmat,(*m).nomat,&(*m).coef,(*m).nomod,&(*m).note) != EOF)
            {
             if(/*strcmp((*m).relationedmat.nom,nom)==0*/(*m).idmat==idmat)
             {
               trouve = 1;
               printf("              Donner le nouveau nom de l'etudiant : ");
               scanf("%s", (*m).relationedmat.nom);
               fprintf(c,"%s\t%s\t%s\t%d\t%s\t%d\t%s\t%d\n",(*m).relationedmat.nom,(*m).relationedmat.prenom,(*m).relationedmat.filiere,(*m).idmat,(*m).nomat,(*m).coef,(*m).nomod,(*m).note);
             }
             else
             {
               fprintf(c, "%s\t%s\t%s\t%d\t%s\t%d\t%s\t%d\n", (*m).relationedmat.nom,(*m).relationedmat.prenom,(*m).relationedmat.filiere,(*m).idmat,(*m).nomat,(*m).coef,(*m).nomod,(*m).note);
             }
            }
            if(trouve == 0)
             {
             	printf("              Le code saisi n'a pas ete trouve\n");
			 }
			fclose(b);
            fclose(c);
            b = fopen("matiere.txt", "w"); 
            c = fopen("modmatiere.txt", "r"); 
            if(c != NULL && b != NULL)
             {
             	while(fscanf(c,"%s\t%s\t%s\t%d\t%s\t%d\t%s\t%d\n", (*m).relationedmat.nom,(*m).relationedmat.prenom,(*m).relationedmat.filiere,&(*m).idmat,(*m).nomat,&(*m).coef,(*m).nomod,&(*m).note) != EOF)
                    {
                    	fprintf(b,"%s\t%s\t%s\t%d\t%s\t%d\t%s\t%d\n", (*m).relationedmat.nom,(*m).relationedmat.prenom,(*m).relationedmat.filiere,(*m).idmat,(*m).nomat,(*m).coef,(*m).nomod,(*m).note);
					}
			 }
                
            else
             {
             	printf("              une erreur s est produite..!\n");
			 }
               fclose(b);
               fclose(c);
               remove("modmatiere.txt");
	
	
	
    }
    
    return (*m);
}

matiere modifierprenomrelationedmat(){
	
	m=(matiere*)malloc(sizeof(matiere));
    FILE *b= fopen("matiere.txt", "r");
    FILE *c= fopen("modmatiere.txt", "w");
    char prenom[25];
    int trouve = 0;
    int idmat;

    if( b == NULL)
        printf("              Erreur lors de l'ouverture du fichier \n");
    else
     {
     	printf("\n              Donner l'identifiant de la matiere : ");
        scanf("%d",&idmat);
        /*printf("\nDonner le prenom de l'etudiant que vous voulez modifier : ");
        scanf("%s", prenom);*/
        while(fscanf(b,"%s\t%s\t%s\t%d\t%s\t%d\t%s\t%d\n", (*m).relationedmat.nom,(*m).relationedmat.prenom,(*m).relationedmat.filiere,&(*m).idmat,(*m).nomat,&(*m).coef,(*m).nomod,&(*m).note) != EOF)
            {
             if(/*strcmp((*m).relationedmat.prenom,prenom)==0*/(*m).idmat==idmat)
             {
               trouve = 1;
               printf("              Donner le nouveau prenom de l'etudiant : ");
               scanf("%s", (*m).relationedmat.prenom);
               fprintf(c,"%s\t%s\t%s\t%d\t%s\t%d\t%s\t%d\n",(*m).relationedmat.nom,(*m).relationedmat.prenom,(*m).relationedmat.filiere,(*m).idmat,(*m).nomat,(*m).coef,(*m).nomod,(*m).note);
             }
             else
             {
               fprintf(c, "%s\t%s\t%s\t%d\t%s\t%d\t%s\t%d\n", (*m).relationedmat.nom,(*m).relationedmat.prenom,(*m).relationedmat.filiere,(*m).idmat,(*m).nomat,(*m).coef,(*m).nomod,(*m).note);
             }
            }
            if(trouve == 0)
             {
             	printf("              Le code saisi n'a pas ete trouve\n");
			 }
			fclose(b);
            fclose(c);
            b = fopen("matiere.txt", "w"); 
            c = fopen("modmatiere.txt", "r"); 
            if(c != NULL && b != NULL)
             {
             	while(fscanf(c,"%s\t%s\t%s\t%d\t%s\t%d\t%s\t%d\n", (*m).relationedmat.nom,(*m).relationedmat.prenom,(*m).relationedmat.filiere,&(*m).idmat,(*m).nomat,&(*m).coef,(*m).nomod,&(*m).note) != EOF)
                    {
                    	fprintf(b,"%s\t%s\t%s\t%d\t%s\t%d\t%s\t%d\n", (*m).relationedmat.nom,(*m).relationedmat.prenom,(*m).relationedmat.filiere,(*m).idmat,(*m).nomat,(*m).coef,(*m).nomod,(*m).note);
					}
			 }
                
            else
             {
             	printf("              une erreur s est produite..!\n");
			 }
               fclose(b);
               fclose(c);
               remove("modmatiere.txt");
	
	
	
    }
    
    return (*m);
}

matiere modifierfiliererelationedmat(){
	
	m=(matiere*)malloc(sizeof(matiere));
    FILE *b= fopen("matiere.txt", "r");
    FILE *c= fopen("modmatiere.txt", "w");
    char filiere[25];
    int idmat;
    int trouve = 0;

    if( b == NULL)
        printf("              Erreur lors de l'ouverture du fichier \n");
    else
     {
     	printf("\n              Donner l'identifiant de la matiere : ");
        scanf("%d",&idmat);
        /*printf("\nDonner la filiere de l'etudiant que vous voulez modifier : ");
        scanf("%s", filiere);*/
        while(fscanf(b,"%s\t%s\t%s\t%d\t%s\t%d\t%s\t%d\n", (*m).relationedmat.nom,(*m).relationedmat.prenom,(*m).relationedmat.filiere,&(*m).idmat,(*m).nomat,&(*m).coef,(*m).nomod,&(*m).note) != EOF)
            {
             if(/*strcmp((*m).relationedmat.filiere,filiere)==0*/(*m).idmat==idmat)
             {
               trouve = 1;
               printf("              Donner la nouvelle filiere de l'etudiant : ");
               scanf("%s", (*m).relationedmat.filiere);
               fprintf(c,"%s\t%s\t%s\t%d\t%s\t%d\t%s\t%d\n",(*m).relationedmat.nom,(*m).relationedmat.prenom,(*m).relationedmat.filiere,(*m).idmat,(*m).nomat,(*m).coef,(*m).nomod,(*m).note);
             }
             else
             {
               fprintf(c, "%s\t%s\t%s\t%d\t%s\t%d\t%s\t%d\n", (*m).relationedmat.nom,(*m).relationedmat.prenom,(*m).relationedmat.filiere,(*m).idmat,(*m).nomat,(*m).coef,(*m).nomod,(*m).note);
             }
            }
            if(trouve == 0)
             {
             	printf("              Le code saisi n'a pas ete trouve\n");
			 }
			fclose(b);
            fclose(c);
            b = fopen("matiere.txt", "w"); 
            c = fopen("modmatiere.txt", "r"); 
            if(c != NULL && b != NULL)
             {
             	while(fscanf(c,"%s\t%s\t%s\t%d\t%s\t%d\t%s\t%d\n", (*m).relationedmat.nom,(*m).relationedmat.prenom,(*m).relationedmat.filiere,&(*m).idmat,(*m).nomat,&(*m).coef,(*m).nomod,&(*m).note) != EOF)
                    {
                    	fprintf(b,"%s\t%s\t%s\t%d\t%s\t%d\t%s\t%d\n", (*m).relationedmat.nom,(*m).relationedmat.prenom,(*m).relationedmat.filiere,(*m).idmat,(*m).nomat,(*m).coef,(*m).nomod,(*m).note);
					}
			 }
                
            else
             {
             	printf("              une erreur s est produite..!\n");
			 }
               fclose(b);
               fclose(c);
               remove("modmatiere.txt");
	
	
	
    }
    
    return (*m);
}

matiere modifiernote(){
	
	m=(matiere*)malloc(sizeof(matiere));
    FILE *b= fopen("matiere.txt", "r");
    FILE *c= fopen("modmatiere.txt", "w");
    int note;
    int idmat;
    int trouve = 0;

    if( b == NULL)
        printf("              Erreur lors de l'ouverture du fichier \n");
    else
     {
     	printf("\n              Donner l'identifiant de la matiere : ");
        scanf("%d",&idmat);
       /* printf("\nEntrer la note que vous voulez modifier : ");
        scanf("%d",&note);*/
        while(fscanf(b,"%s\t%s\t%s\t%d\t%s\t%d\t%s\t%d\n", (*m).relationedmat.nom,(*m).relationedmat.prenom,(*m).relationedmat.filiere,&(*m).idmat,(*m).nomat,&(*m).coef,(*m).nomod,&(*m).note) != EOF)
            {
             if(/*(*m).note==note*/(*m).idmat==idmat)
             {
               trouve = 1;
               printf("              Entrer la nouvelle note de l'etudiant : ");
               scanf("%d", &(*m).note);
               fprintf(c,"%s\t%s\t%s\t%d\t%s\t%d\t%s\t%d\n",(*m).relationedmat.nom,(*m).relationedmat.prenom,(*m).relationedmat.filiere,(*m).idmat,(*m).nomat,(*m).coef,(*m).nomod,(*m).note);
             }
             else
             {
               fprintf(c, "%s\t%s\t%s\t%d\t%s\t%d\t%s\t%d\n", (*m).relationedmat.nom,(*m).relationedmat.prenom,(*m).relationedmat.filiere,(*m).idmat,(*m).nomat,(*m).coef,(*m).nomod,(*m).note);
             }
            }
            if(trouve == 0)
             {
             	printf("              Le code saisi n'a pas ete trouve\n");
			 }
			fclose(b);
            fclose(c);
            b = fopen("matiere.txt", "w"); 
            c = fopen("modmatiere.txt", "r"); 
            if(c != NULL && b != NULL)
             {
             	while(fscanf(c,"%s\t%s\t%s\t%d\t%s\t%d\t%s\t%d\n", (*m).relationedmat.nom,(*m).relationedmat.prenom,(*m).relationedmat.filiere,&(*m).idmat,(*m).nomat,&(*m).coef,(*m).nomod,&(*m).note) != EOF)
                    {
                    	fprintf(b,"%s\t%s\t%s\t%d\t%s\t%d\t%s\t%d\n", (*m).relationedmat.nom,(*m).relationedmat.prenom,(*m).relationedmat.filiere,(*m).idmat,(*m).nomat,(*m).coef,(*m).nomod,(*m).note);
					}
			 }
                
            else
             {
             	printf("              une erreur s est produite..!\n");
			 }
               fclose(b);
               fclose(c);
               remove("modmatiere.txt");
	
	
	
    }
    
    return (*m);
}

matiere recherchernomrelationedmat()
{
	m=(matiere*)malloc(sizeof(matiere));
    int trouve=0;
    FILE * f = fopen("matiere.txt", "r");
    char nomrech[25];
    printf("       Donner le nom a recherche : ");
    scanf("%s", nomrech);
    if(f == NULL)
        printf("Erreur lors de l'ouverture du fichier \n");
    else
    {
        while(fscanf(f,"%s\t%s\t%s\t%d\t%s\t%d\t%s\t%d\n", (*m).relationedmat.nom,(*m).relationedmat.prenom,(*m).relationedmat.filiere,&(*m).idmat,(*m).nomat,&(*m).coef,(*m).nomod,&(*m).note)!= EOF )
              {
              	if(strcmp((*m).relationedmat.nom, nomrech)==0)
              	  {
              	  	trouve= 1;
              	  	printf("       Nom : %s\tPrenom : %s\tFiliere : %s\tIdentifiant Matiere : %d\tNom Matiere: %s\tCoeficient : %d\tNom Module : %s\t Note : %d\n",(*m).relationedmat.nom,(*m).relationedmat.prenom,(*m).relationedmat.filiere,(*m).idmat,(*m).nomat,(*m).coef,(*m).nomod,(*m).note);
		            }
              }
              
        
        fclose(f);
    }

    if(trouve == 0)
      {
      	printf("       le nom n'existe pas \n");
	  }
        
        
        return (*m);
}

matiere modifieridmat(){
	
	m=(matiere*)malloc(sizeof(matiere));
    FILE *b= fopen("matiere.txt", "r");
    FILE *c= fopen("modmatiere.txt", "w");
    int idmat;
    int trouve = 0;

    if( b == NULL)
        printf("              Erreur lors de l'ouverture du fichier \n");
    else
     {
        printf("\n              Donner l'identifiant de la matiere que vous souhaitez modifier : ");
        scanf("%d",&idmat);
        while(fscanf(b,"%s\t%s\t%s\t%d\t%s\t%d\t%s\t%d\n", (*m).relationedmat.nom,(*m).relationedmat.prenom,(*m).relationedmat.filiere,&(*m).idmat,(*m).nomat,&(*m).coef,(*m).nomod,&(*m).note) != EOF)
            {
             if((*m).idmat==idmat)
             {
               trouve = 1;
               printf("              Donner le nouvel identifiant de la matiere : ");
               scanf("%d", &idmat);
               (*m).idmat=idmat;
               fprintf(c,"%s\t%s\t%s\t%d\t%s\t%d\t%s\t%d\n",(*m).relationedmat.nom,(*m).relationedmat.prenom,(*m).relationedmat.filiere,(*m).idmat,(*m).nomat,(*m).coef,(*m).nomod,(*m).note);
             }
             else
             {
               fprintf(c, "%s\t%s\t%s\t%d\t%s\t%d\t%s\t%d\n", (*m).relationedmat.nom,(*m).relationedmat.prenom,(*m).relationedmat.filiere,(*m).idmat,(*m).nomat,(*m).coef,(*m).nomod,(*m).note);
             }
            }
            if(trouve == 0)
             {
             	printf("              L'identifiant matiere saisi n'a pas ete trouve\n");
			 }
			fclose(b);
            fclose(c);
            b = fopen("matiere.txt", "w"); 
            c = fopen("modmatiere.txt", "r"); 
            if(c != NULL && b != NULL)
             {
             	while(fscanf(c,"%s\t%s\t%s\t%d\t%s\t%d\t%s\t%d\n", (*m).relationedmat.nom,(*m).relationedmat.prenom,(*m).relationedmat.filiere,&(*m).idmat,(*m).nomat,&(*m).coef,(*m).nomod,&(*m).note) != EOF)
                    {
                    	fprintf(b,"%s\t%s\t%s\t%d\t%s\t%d\t%s\t%d\n", (*m).relationedmat.nom,(*m).relationedmat.prenom,(*m).relationedmat.filiere,(*m).idmat,(*m).nomat,(*m).coef,(*m).nomod,(*m).note);
					}
			 }
                
            else
             {
             	printf("              une erreur s est produite..!\n");
			 }
               fclose(b);
               fclose(c);
               remove("modmatiere.txt");
	
	
	
    }
    
    return (*m);
}

matiere modifiercoef(){
	
	m=(matiere*)malloc(sizeof(matiere));
    FILE *b= fopen("matiere.txt", "r");
    FILE *c= fopen("modmatiere.txt", "w");
    int coef;
    int idmat;
    int trouve = 0;

    if( b == NULL)
        printf("              Erreur lors de l'ouverture du fichier \n");
    else
     {
     	printf("\n              Donner l'identifiant de la matiere : ");
        scanf("%d",&idmat);
       /* printf("\nDonner le coefficient de la matiere que vous souhaitez modifier : ");
        scanf("%d",&coef);*/
        while(fscanf(b,"%s\t%s\t%s\t%d\t%s\t%d\t%s\t%d\n",(*m).relationedmat.nom,(*m).relationedmat.prenom,(*m).relationedmat.filiere,&(*m).idmat,(*m).nomat,&(*m).coef,(*m).nomod,&(*m).note) != EOF)
            {
             if(/*(*m).coef==coef*/(*m).idmat==idmat)
             {
               trouve = 1;
               printf("              Donner le nouveau coefficient de la matiere : ");
               scanf("%d", &coef);
               (*m).coef=coef;
               fprintf(c,"%s\t%s\t%s\t%d\t%s\t%d\t%s\t%d\n",(*m).relationedmat.nom,(*m).relationedmat.prenom,(*m).relationedmat.filiere,(*m).idmat,(*m).nomat,(*m).coef,(*m).nomod,(*m).note);
             }
             else
             {
               fprintf(c, "%s\t%s\t%s\t%d\t%s\t%d\t%s\t%d\n", (*m).relationedmat.nom,(*m).relationedmat.prenom,(*m).relationedmat.filiere,(*m).idmat,(*m).nomat,(*m).coef,(*m).nomod,(*m).note);
             }
            }
            if(trouve == 0)
             {
             	printf("              le code saisi n'a pas ete trouve\n");
			 }
			fclose(b);
            fclose(c);
            b = fopen("matiere.txt", "w"); 
            c = fopen("modmatiere.txt", "r"); 
            if(c != NULL && b != NULL)
             {
             	while(fscanf(c,"%s\t%s\t%s\t%d\t%s\t%d\t%s\t%d\n", (*m).relationedmat.nom,(*m).relationedmat.prenom,(*m).relationedmat.filiere,&(*m).idmat,(*m).nomat,&(*m).coef,(*m).nomod,&(*m).note) != EOF)
                    {
                    	fprintf(b,"%s\t%s\t%s\t%d\t%s\t%d\t%s\t%d\n", (*m).relationedmat.nom,(*m).relationedmat.prenom,(*m).relationedmat.filiere,(*m).idmat,(*m).nomat,(*m).coef,(*m).nomod,(*m).note);
					}
			 }
                
            else
             {
             	printf("              une erreur s est produite..!\n");
			 }
               fclose(b);
               fclose(c);
               remove("modmatiere.txt");
	
	
	
    }
    
    return (*m);
}

matiere modifiernomat(){
	
	m=(matiere*)malloc(sizeof(matiere));
    FILE *y= fopen("matiere.txt", "r");
    FILE *z= fopen("modmatiere.txt", "w");
    char nomat[15];
    int idmat;
    int trouve = 0;

    if( y == NULL)
        printf("              Erreur lors de l'ouverture du fichier \n");
    else
     {
     	printf("\n              Donner l'identifiant de la matiere : ");
        scanf("%d",&idmat);
        /*printf("\nDonner le nom de la matiere que vous souhaitez modifier : ");
        scanf("%s",nomat);*/
        while(fscanf(y,"%s\t%s\t%s\t%d\t%s\t%d\t%s\t%d\n", (*m).relationedmat.nom,(*m).relationedmat.prenom,(*m).relationedmat.filiere,&(*m).idmat,(*m).nomat,&(*m).coef,(*m).nomod,&(*m).note) != EOF)
            {
             if(/*strcmp((*m).nomat,nomat)==0*/(*m).idmat==idmat)
             {
               trouve = 1;
               printf("              Donner le nouveau nom de la matiere : ");
               scanf("%s", (*m).nomat);
               fprintf(z,"%s\t%s\t%s\t%d\t%s\t%d\t%s\t%d\n",(*m).relationedmat.nom,(*m).relationedmat.prenom,(*m).relationedmat.filiere,(*m).idmat,(*m).nomat,(*m).coef,(*m).nomod,(*m).note);
             }
             else
             {
               fprintf(z, "%s\t%s\t%s\t%d\t%s\t%d\t%s\t%d\n", (*m).relationedmat.nom,(*m).relationedmat.prenom,(*m).relationedmat.filiere,(*m).idmat,(*m).nomat,(*m).coef,(*m).nomod,(*m).note);
             }
            }
            if(trouve == 0)
             {
             	printf("              le code de la matiere saisi n'a pas ete trouve\n");
			 }
			fclose(y);
            fclose(z);
            y = fopen("matiere.txt", "w"); 
            z = fopen("modmatiere.txt", "r"); 
            if(z != NULL && y != NULL)
             {
             	while(fscanf(z,"%s\t%s\t%s\t%d\t%s\t%d\t%s\t%d\n", (*m).relationedmat.nom,(*m).relationedmat.prenom,(*m).relationedmat.filiere,&(*m).idmat,(*m).nomat,&(*m).coef,(*m).nomod,&(*m).note) != EOF)
                    {
                    	fprintf(y,"%s\t%s\t%s\t%d\t%s\t%d\t%s\t%d\n", (*m).relationedmat.nom,(*m).relationedmat.prenom,(*m).relationedmat.filiere,(*m).idmat,(*m).nomat,(*m).coef,(*m).nomod,(*m).note);
					}
			 }
                
            else
             {
             	printf("              une erreur s est produite..!\n");
			 }
               fclose(y);
               fclose(z);
               remove("modmatiere.txt");
	
	       
	
    }
    
    return (*m);
}

matiere modifiernomod(){
	
	m=(matiere*)malloc(sizeof(matiere));
    FILE *y= fopen("matiere.txt", "r");
    FILE *z= fopen("modmatiere.txt", "w");
    char nomod[15];
    int idmat;
    int trouve = 0;

    if( y == NULL)
        printf("              Erreur lors de l'ouverture du fichier \n");
    else
     {
     	printf("\n              Donner l'identifiant de la matiere : ");
        scanf("%d",&idmat);
        /*printf("\nDonner le nom du module que vous souhaitez modifier : ");
        scanf("%s",nomod);*/
        while(fscanf(y,"%s\t%s\t%s\t%d\t%s\t%d\t%s\t%d\n", (*m).relationedmat.nom,(*m).relationedmat.prenom,(*m).relationedmat.filiere,&(*m).idmat,(*m).nomat,&(*m).coef,(*m).nomod,&(*m).note) != EOF)
            {
             if(/*strcmp((*m).nomod,nomod)==0*/(*m).idmat==idmat)
             {
               trouve = 1;
               printf("              Donner le nouveau nom du module : ");
               scanf("%s", (*m).nomod);
               fprintf(z,"%s\t%s\t%s\t%d\t%s\t%d\t%s\t%d\n",(*m).relationedmat.nom,(*m).relationedmat.prenom,(*m).relationedmat.filiere,(*m).idmat,(*m).nomat,(*m).coef,(*m).nomod,(*m).note);
             }
             else
             {
               fprintf(z, "%s\t%s\t%s\t%d\t%s\t%d\t%s\t%d\n", (*m).relationedmat.nom,(*m).relationedmat.prenom,(*m).relationedmat.filiere,(*m).idmat,(*m).nomat,(*m).coef,(*m).nomod,(*m).note);
             }
            }
            if(trouve == 0)
             {
             	printf("              le code saisi n'a pas ete trouve\n");
			 }
			fclose(y);
            fclose(z);
            y = fopen("matiere.txt", "w"); 
            z = fopen("modmatiere.txt", "r"); 
            if(z != NULL && y != NULL)
             {
             	while(fscanf(z,"%s\t%s\t%s\t%d\t%s\t%d\t%s\t%d\n", (*m).relationedmat.nom,(*m).relationedmat.prenom,(*m).relationedmat.filiere,&(*m).idmat,(*m).nomat,&(*m).coef,(*m).nomod,&(*m).note) != EOF)
                    {
                    	fprintf(y,"%s\t%s\t%s\t%d\t%s\t%d\t%s\t%d\n", (*m).relationedmat.nom,(*m).relationedmat.prenom,(*m).relationedmat.filiere,(*m).idmat,(*m).nomat,(*m).coef,(*m).nomod,(*m).note);
					}
			 }
                
            else
             {
             	printf("              une erreur s est produite..!\n");
			 }
               fclose(y);
               fclose(z);
               remove("modmatiere.txt");
	
	       
	
    }
    
    return (*m);
}
   


