#include <stdio.h>
#include <stdlib.h>


absence ecrireabs(){
	
	
	FILE *b;
	b=fopen("absence.txt","a");
	if(b==NULL)
	  printf("erreur d'ouverture");
	else
	  {
	    fprintf(b,"%d\t%s\t%s\t%d %s %d\t%d\t%s\n",(*a).codeabs,(*a).relationedabs.nom,(*a).relationedabs.prenom,(*a).dateabs.jour,(*a).dateabs.mois,(*a).dateabs.annee,(*a).heurabs,(*a).relationedabs.filiere);
	  	fclose(b);
	  }
	  
    return (*a);
	
 }

absence lireabs(){
	
	a=(absence*)malloc(sizeof(absence));
	e=(etudiant*)malloc(sizeof(etudiant));
	int codeabs;
	int trouve;
    do
      {
      	trouve = 0;
      	printf("Code absence: ");
	    scanf("%d",&codeabs);
	    FILE *b;
        b=fopen("absence.txt","r");
        if(b==NULL)
           printf("erreur d'ouverture");
        else
          {
		  
	      while(fscanf(b,"%d\t%s\t%s\t%d %s %d\t%d\t%s\n", &(*a).codeabs,(*a).relationedabs.nom,(*a).relationedabs.prenom,&(*a).dateabs.jour,(*a).dateabs.mois,&(*a).dateabs.annee,&(*a).heurabs,(*a).relationedabs.filiere) != EOF)
             {
              if((*a).codeabs==codeabs)
                {
                	trouve = 1;
				}
              
             }
          }
             if(trouve == 1)
              {
				
                printf("\nle code absence saisi existe deja ");
                do
                 {
				 printf("\nTapez 1 pour saisir une nouvelle fois le code ou 0 pour sortir du terminal : ");
			     scanf("%d",&trouve);
			     }while(trouve != 1 && trouve != 0);
			    if(trouve==0)
			    {
			      exit(1);
			     }
			 }
             if(trouve == 0)
                {
                	(*a).codeabs=codeabs;
				}
                
                
	  }while(trouve!=0);
	  
	printf("\nJour : ");
	scanf("%d",&(*a).dateabs.jour);
	printf("\nMois : ");
	scanf("%s",(*a).dateabs.mois);
	printf("\nannee: ");
	scanf("%d",&(*a).dateabs.annee);
	printf("\nFiliere : ");
	scanf("%s",(*a).relationedabs.filiere);
	printf("\nHeure Absence : ");
	scanf("%d",&(*a).heurabs);
    do
      {
	  
      trouve = 0;
	  printf("Nom : ");
	  scanf("%s",(*a).relationedabs.nom);
	  printf("Prenom : ");
   	  scanf("%s",(*a).relationedabs.prenom);
      FILE *b;
      b=fopen("etudiant.txt","r");
      if(b==NULL)
         printf("Erreur d'ouverture du fichier");
      else
       {
       	 
       	  
			   
       	   	 while(fscanf(b,"%d\t%s\t%s\t%d %s %d\t%s\t%d\t%s\n",&(*e).idetudiant,(*e).nom,(*e).prenom,&(*e).datenaiss.jour,(*e).datenaiss.mois,&(*e).datenaiss.annee,(*e).mail,&(*e).numtel,(*e).filiere)!=EOF)
	 	      {
	 	     	if(strcmp((*a).relationedabs.nom,(*e).nom)==0 && strcmp((*a).relationedabs.prenom,(*e).prenom)==0)
	 	     	   {
	 	     	   	  trouve = 1;
	 	     	   	  ecrireabs();
					 }
			  }
			  fclose(b);
			  if(trouve == 0)
			     {
			     	 printf("\nLe nom et/ou le prenom  saisi n'existe pas dans le fichier etudiant\n\n");
			     	 do
			     	   {
			     	   	printf("Tapez 0 pour saisir une nouvelle fois le nom et le prenom ou 1 pour sortir du terminal : ");
			     	    scanf("%d",&trouve);
						}while(trouve!= 1 && trouve!= 0);
			     	 if(trouve==1)
			     	   {
			     	   	 exit(1);
						}
			      }
			     
		
	   }
      }while(trouve!=1);
    
    
	return (*a);
	
}

absence afficheabs()
  {
	
	
	
	a=(absence*)malloc(sizeof(absence)); 
    FILE *b;
	b=fopen("absence.txt","r"); 
    while(fscanf(b,"%d\t%s\t%s\t%d %s %d\t%d\t%s\n",&(*a).codeabs,(*a).relationedabs.nom,(*a).relationedabs.prenom,&(*a).dateabs.jour,(*a).dateabs.mois,&(*a).dateabs.annee,&(*a).heurabs,(*a).relationedabs.filiere)!=EOF)
	 	  {
             printf("Code : %d\tNom : %s\tPrenom : %s\tDate Absence : %d %s %d\tHeure Absence : %d\tFiliere : %s\n",(*a).codeabs,(*a).relationedabs.nom,(*a).relationedabs.prenom,(*a).dateabs.jour,(*a).dateabs.mois,(*a).dateabs.annee,(*a).heurabs,(*a).relationedabs.filiere);
		    }
	       fclose(b);
	
	 	   return (*a);
	
	
   }
   
absence supprimerabs()
  {
    a=(absence*)malloc(sizeof(absence));
    FILE * y = fopen("absence.txt", "r");
    FILE * z = fopen("modabsence.txt", "w");
    int codeabs;
    int trouve = 0;
    if(y == NULL)
        printf("Erreur lors de l'ouverture du fichier \n");
    else
    {
        printf("\nEntrer le code de l'absence : ");
        scanf("%d", &codeabs);
        while(fscanf(y,"%d\t%s\t%s\t%d %s %d\t%d\t%s\n",&(*a).codeabs,(*a).relationedabs.nom,(*a).relationedabs.prenom,&(*a).dateabs.jour,(*a).dateabs.mois,&(*a).dateabs.annee,&(*a).heurabs,(*a).relationedabs.filiere) != EOF)
            {
             if((*a).codeabs!=codeabs)
             {
               fprintf(z, "%d\t%s\t%s\t%d %s %d\t%d\t%s\n",(*a).codeabs,(*a).relationedabs.nom,(*a).relationedabs.prenom,(*a).dateabs.jour,(*a).dateabs.mois,(*a).dateabs.annee,(*a).heurabs,(*a).relationedabs.filiere);
              }
             else
             {
               trouve = 1;
             }
            }
            if(trouve == 0)
                {
                	printf("le code saisi n'a pas ete trouve ");
				}
            else
                {
                	printf("\nl'absence de l'etudiant a ete supprime \n\n");
                	
				}
			    
            
    }
    fclose(y);
    fclose(z);
	y = fopen("absence.txt", "w");
    z = fopen("modabsence.txt", "r");
   if( y != NULL && z != NULL)
       {
           while(fscanf(z,"%d\t%s\t%s\t%d %s %d\t%d\t%s\n", &(*a).codeabs,(*a).relationedabs.nom,(*a).relationedabs.prenom,&(*a).dateabs.jour,(*a).dateabs.mois,&(*a).dateabs.annee,&(*a).heurabs,(*a).relationedabs.filiere) != EOF)
                {
                   fprintf(y,"%d\t%s\t%s\t%d %s %d\t%d\t%s\n", (*a).codeabs,(*a).relationedabs.nom,(*a).relationedabs.prenom,(*a).dateabs.jour,(*a).dateabs.mois,(*a).dateabs.annee,(*a).heurabs,(*a).relationedabs.filiere);
	               }
	    }
   else
        {
            printf("une erreur s est produite..!\n");
	      }
	    fclose(y);
        fclose(z);
        remove("modabsence.txt");
    
    return (*a);
    
  }

absence modifiercodeabs(){
	
	
    FILE *b= fopen("absence.txt", "r");
    FILE *c= fopen("modabsence.txt", "w");
    a=(absence*)malloc(sizeof(absence));
    int codeabs;
    int trouve = 0;

    if( b == NULL)
        printf("              Erreur lors de l'ouverture du fichier \n");
    else
     {
        printf("\n              Donner le code d'absence de l'etudiant que vous voulez modifier : ");
        scanf("%d",&codeabs);
        while(fscanf(b,"%d\t%s\t%s\t%d %s %d\t%d\t%s\n", &(*a).codeabs,(*a).relationedabs.nom,(*a).relationedabs.prenom,&(*a).dateabs.jour,(*a).dateabs.mois,&(*a).dateabs.annee,&(*a).heurabs,(*a).relationedabs.filiere) != EOF)
            {
             if((*a).codeabs==codeabs)
             {
               trouve = 1;
               printf("              donner le nouveau code d'absence : ");
               scanf("%d", &codeabs);
               (*a).codeabs=codeabs;
               fprintf(c,"%d\t%s\t%s\t%d %s %d\t%d\t%s\n",(*a).codeabs,(*a).relationedabs.nom,(*a).relationedabs.prenom,(*a).dateabs.jour,(*a).dateabs.mois,(*a).dateabs.annee,(*a).heurabs,(*a).relationedabs.filiere);
             }
             else
             {
               fprintf(c, "%d\t%s\t%s\t%d %s %d\t%d\t%s\n", (*a).codeabs,(*a).relationedabs.nom,(*a).relationedabs.prenom,(*a).dateabs.jour,(*a).dateabs.mois,(*a).dateabs.annee,(*a).heurabs,(*a).relationedabs.filiere);
             }
            }
            if(trouve == 0)
             {
             	printf("              Le code d'absence trouve n'a pas ete trouve\n");
			 }
			fclose(b);
            fclose(c);
            b = fopen("absence.txt", "w"); 
            c = fopen("modabsence.txt", "r"); 
            if(c != NULL && b != NULL)
             {
             	while(fscanf(c,"%d\t%s\t%s\t%d %s %d\t%d\t%s\n", &(*a).codeabs,(*a).relationedabs.nom,(*a).relationedabs.prenom,&(*a).dateabs.jour,(*a).dateabs.mois,&(*a).dateabs.annee,&(*a).heurabs,(*a).relationedabs.filiere) != EOF)
                    {
                    	fprintf(b,"%d\t%s\t%s\t%d %s %d\t%d\t%s\n", (*a).codeabs,(*a).relationedabs.nom,(*a).relationedabs.prenom,(*a).dateabs.jour,(*a).dateabs.mois,(*a).dateabs.annee,(*a).heurabs,(*a).relationedabs.filiere);
					}
			 }
                
            else
             {
             	printf("              une erreur s est produite..!\n");
			 }
               fclose(b);
               fclose(c);
               remove("modabsence.txt");
	
	
	
    }
    
    return (*a);
}


absence modifierheurabs(){
	
	
	a=(absence*)malloc(sizeof(absence));
    FILE *b= fopen("absence.txt", "r");
    FILE *c= fopen("modabsence.txt", "w");
    int codeabs;
	int heurabs;
    int trouve = 0;

    if( b == NULL)
        printf("              Erreur lors de l'ouverture du fichier \n");
    else
     {
     	printf("\n              Donner le code d'absence de l'etudiant : ");
        scanf("%d",&codeabs);
        /*printf("\nDonner le nombre d'heure d'absence de l'etudiant que vous voulez modifier : ");
        scanf("%d",&heurabs);*/
        while(fscanf(b,"%d\t%s\t%s\t%d %s %d\t%d\t%s\n", &(*a).codeabs,(*a).relationedabs.nom,(*a).relationedabs.prenom,&(*a).dateabs.jour,(*a).dateabs.mois,&(*a).dateabs.annee,&(*a).heurabs,(*a).relationedabs.filiere) != EOF)
            {
             if(/*(*a).heurabs==heurabs && */(*a).codeabs==codeabs)
             {
               trouve = 1;
               printf("              Donner la nouvelle heure d'absence : ");
               scanf("%d", &heurabs);
               (*a).heurabs=heurabs;
               fprintf(c,"%d\t%s\t%s\t%d %s %d\t%d\t%s\n",(*a).codeabs,(*a).relationedabs.nom,(*a).relationedabs.prenom,(*a).dateabs.jour,(*a).dateabs.mois,(*a).dateabs.annee,(*a).heurabs,(*a).relationedabs.filiere);
             }
             else
             {
               fprintf(c, "%d\t%s\t%s\t%d %s %d\t%d\t%s\n", (*a).codeabs,(*a).relationedabs.nom,(*a).relationedabs.prenom,(*a).dateabs.jour,(*a).dateabs.mois,(*a).dateabs.annee,(*a).heurabs,(*a).relationedabs.filiere);
             }
            }
            if(trouve == 0)
             {
             	printf("              Le code n'a pas ete trouve\n");
			 }
			fclose(b);
            fclose(c);
            b = fopen("absence.txt", "w"); 
            c = fopen("modabsence.txt", "r"); 
            if(c != NULL && b != NULL)
             {
             	while(fscanf(c,"%d\t%s\t%s\t%d %s %d\t%d\t%s\n", &(*a).codeabs,(*a).relationedabs.nom,(*a).relationedabs.prenom,&(*a).dateabs.jour,(*a).dateabs.mois,&(*a).dateabs.annee,&(*a).heurabs,(*a).relationedabs.filiere) != EOF)
                    {
                    	fprintf(b,"%d\t%s\t%s\t%d %s %d\t%d\t%s\n", (*a).codeabs,(*a).relationedabs.nom,(*a).relationedabs.prenom,(*a).dateabs.jour,(*a).dateabs.mois,(*a).dateabs.annee,(*a).heurabs,(*a).relationedabs.filiere);
					}
			 }
                
            else
             {
             	printf("              une erreur s est produite..!\n");
			 }
               fclose(b);
               fclose(c);
               remove("modabsence.txt");
	
	
	
    }
    
    return (*a);
}
 
 
absence modifierdateabs(){
	
	a=(absence*)malloc(sizeof(absence));
    FILE *b= fopen("absence.txt", "r");
    FILE *c= fopen("modabsence.txt", "w");
    int jour,annee;
    int codeabs;
    char mois[10];
    int trouve = 0;

    if( b == NULL)
        printf("              Erreur lors de l'ouverture du fichier \n");
    else
     {
     	printf("\n              Donner le code d'absence de l'etudiant : ");
        scanf("%d",&codeabs);
       /* printf("\nDonner le Jour d'absence que vous souhaitez modifiez : ");
        scanf("%d",&jour);
        printf("\nDonner le mois d'absence que vous souhaitez modifiez : ");
        scanf("%s",mois);
        printf("\nDonner l'annee d'absence que vous souhaitez modifiez : ");
        scanf("%d",&annee);*/
        while(fscanf(b,"%d\t%s\t%s\t%d %s %d\t%d\t%s\n", &(*a).codeabs,(*a).relationedabs.nom,(*a).relationedabs.prenom,&(*a).dateabs.jour,(*a).dateabs.mois,&(*a).dateabs.annee,&(*a).heurabs,(*a).relationedabs.filiere) != EOF)
            {
             if(/*(*a).dateabs.jour==jour && strcmp((*a).dateabs.mois,mois)==0 && (*a).dateabs.annee==annee*/(*a).codeabs==codeabs)
             {
               trouve = 1;
               printf("              Donner le nouveau jour : ");
               scanf("%d", &jour);
               printf("              Donner le nouveau mois : ");
               scanf("%s", (*a).dateabs.mois);
               printf("              Donner la nouvelle annee : ");
               scanf("%d", &annee);
               (*a).dateabs.jour=jour;
               (*a).dateabs.annee=annee;
               fprintf(c,"%d\t%s\t%s\t%d %s %d\t%d\t%s\n", (*a).codeabs,(*a).relationedabs.nom,(*a).relationedabs.prenom,(*a).dateabs.jour,(*a).dateabs.mois,(*a).dateabs.annee,(*a).heurabs,(*a).relationedabs.filiere);
             }
             else
             {
               fprintf(c, "%d\t%s\t%s\t%d %s %d\t%d\t%s\n",  (*a).codeabs,(*a).relationedabs.nom,(*a).relationedabs.prenom,(*a).dateabs.jour,(*a).dateabs.mois,(*a).dateabs.annee,(*a).heurabs,(*a).relationedabs.filiere);
		     	 }
            
             }
            }
            if(trouve == 0)
             {
             	printf("              Le code d'absence n'a pas ete trouve\n");
			 }
			   fclose(b);
               fclose(c);
               b = fopen("absence.txt", "w"); 
               c = fopen("modabsence.txt", "r"); 
               if(c != NULL && b != NULL)
                 {
             	   while(fscanf(c,"%d\t%s\t%s\t%d %s %d\t%d\t%s\n", &(*a).codeabs,(*a).relationedabs.nom,(*a).relationedabs.prenom,&(*a).dateabs.jour,(*a).dateabs.mois,&(*a).dateabs.annee,&(*a).heurabs,(*a).relationedabs.filiere) != EOF)
                    {
                    	fprintf(b,"%d\t%s\t%s\t%d %s %d\t%d\t%s\n", (*a).codeabs,(*a).relationedabs.nom,(*a).relationedabs.prenom,(*a).dateabs.jour,(*a).dateabs.mois,(*a).dateabs.annee,(*a).heurabs,(*a).relationedabs.filiere);
					}
	
	
                 }
                 return (*a);
    }
      
absence recherchernomrelationedabs()
{
	a=(absence*)malloc(sizeof(absence)); 
    int trouve=0;
    int compte=0;
    FILE * f = fopen("absence.txt", "r");
    char nomrech[25];
    printf("       Donner le nom a recherche : ");
    scanf("%s", nomrech);
    if(f == NULL)
        printf("Erreur lors de l'ouverture du fichier \n");
    else
    {
        while(fscanf(f,"%d\t%s\t%s\t%d %s %d\t%d\t%s\n", &(*a).codeabs,(*a).relationedabs.nom,(*a).relationedabs.prenom,&(*a).dateabs.jour,(*a).dateabs.mois,&(*a).dateabs.annee,&(*a).heurabs,(*a).relationedabs.filiere)!= EOF )
              {
              	if(strcmp((*a).relationedabs.nom, nomrech)==0)
              	  {
              	  	trouve= 1;
              	  	compte++;
              	  	printf("\n       Code : %d\tNom : %s\tPrenom : %s\tDate Absence : %d %s %d\tHeure Absence : %d\tFiliere : %s\n",(*a).codeabs,(*a).relationedabs.nom,(*a).relationedabs.prenom,(*a).dateabs.jour,(*a).dateabs.mois,(*a).dateabs.annee,(*a).heurabs,(*a).relationedabs.filiere);
		            }
              }
              
        printf("\n\n       Nombre d'absence : %d",compte);
        fclose(f);
    }
  if(trouve==0)
        printf("\n\n       le nom n'existe pas \n");
        
        return (*a);
}

absence modifierprenomrelationedabs(){
	
	a=(absence*)malloc(sizeof(absence));
    FILE *b= fopen("absence.txt", "r");
    FILE *c= fopen("modabsence.txt", "w");
    char prenom[25];
    int trouve = 0;
    int codeabs;

    if( b == NULL)
        printf("              Erreur lors de l'ouverture du fichier \n");
    else
     {
     	printf("\n              Donner le code d'absence de l'etudiant : ");
        scanf("%d",&codeabs);
        /*printf("\nDonner le prenom de l'etudiant que vous voulez modifier : ");
        scanf("%s",prenom);*/
        while(fscanf(b,"%d\t%s\t%s\t%d %s %d\t%d\t%s\n", &(*a).codeabs,(*a).relationedabs.nom,(*a).relationedabs.prenom,&(*a).dateabs.jour,(*a).dateabs.mois,&(*a).dateabs.annee,&(*a).heurabs,(*a).relationedabs.filiere) != EOF)
            {
             if(/*strcmp((*a).relationedabs.prenom,prenom)==0*/(*a).codeabs==codeabs)
             {
            
				
               trouve = 1;
               printf("              Donner le nouveau prenom de l'etudiant : ");
               scanf("%s", (*a).relationedabs.prenom);
               fprintf(c,"%d\t%s\t%s\t%d %s %d\t%d\t%s\n",(*a).codeabs,(*a).relationedabs.nom,(*a).relationedabs.prenom,(*a).dateabs.jour,(*a).dateabs.mois,(*a).dateabs.annee,(*a).heurabs,(*a).relationedabs.filiere);
               
             }
             else
             {
               fprintf(c, "%d\t%s\t%s\t%d %s %d\t%d\t%s\n", (*a).codeabs,(*a).relationedabs.nom,(*a).relationedabs.prenom,(*a).dateabs.jour,(*a).dateabs.mois,(*a).dateabs.annee,(*a).heurabs,(*a).relationedabs.filiere);
             }
             }
            if(trouve == 0)
             {
             	printf("              Le code n'a pas ete trouve\n");
			 }
			fclose(b);
            fclose(c);
            b = fopen("absence.txt", "w"); 
            c = fopen("modabsence.txt", "r"); 
            if(c != NULL && b != NULL)
             {
             	while(fscanf(c,"%d\t%s\t%s\t%d %s %d\t%d\t%s\n", &(*a).codeabs,(*a).relationedabs.nom,(*a).relationedabs.prenom,&(*a).dateabs.jour,(*a).dateabs.mois,&(*a).dateabs.annee,&(*a).heurabs,(*a).relationedabs.filiere) != EOF)
                    {
                    	fprintf(b,"%d\t%s\t%s\t%d %s %d\t%d\t%s\n", (*a).codeabs,(*a).relationedabs.nom,(*a).relationedabs.prenom,(*a).dateabs.jour,(*a).dateabs.mois,(*a).dateabs.annee,(*a).heurabs,(*a).relationedabs.filiere);
					}
			 }
                
            else
             {
             	printf("              une erreur s est produite..!\n");
			 }
               fclose(b);
               fclose(c);
               remove("modabsence.txt");
	
	
	
    }
    
    return (*a);
}

absence modifierfilierelationdeabs(){
	
	
	a=(absence*)malloc(sizeof(absence)); 
    FILE *b= fopen("absence.txt", "r");
    FILE *c= fopen("modabsence.txt", "w");
    char filiere[25];
    int trouve = 0;
    int codeabs;

    if( b == NULL)
        printf("              Erreur lors de l'ouverture du fichier \n");
    else
     {
     	printf("\n              Donner le code d'absence de l'etudiant : ");
        scanf("%d",&codeabs);
        /*printf("\nDonner le nom de la filiere que vous voulez modifier : ");
        scanf("%s",filiere);*/
        while(fscanf(b,"%d\t%s\t%s\t%d %s %d\t%d\t%s\n", &(*a).codeabs,(*a).relationedabs.nom,(*a).relationedabs.prenom,&(*a).dateabs.jour,(*a).dateabs.mois,&(*a).dateabs.annee,&(*a).heurabs,(*a).relationedabs.filiere) != EOF)
            {
             if(/*strcmp((*a).relationedabs.filiere,filiere)==0*/(*a).codeabs==codeabs)
             {
               trouve = 1;
               printf("              Donner le nouveau nom de la filiere : ");
               scanf("%s", (*a).relationedabs.filiere);
               fprintf(c,"%d\t%s\t%s\t%d %s %d\t%d\t%s\n",(*a).codeabs,(*a).relationedabs.nom,(*a).relationedabs.prenom,(*a).dateabs.jour,(*a).dateabs.mois,(*a).dateabs.annee,(*a).heurabs,(*a).relationedabs.filiere);
             }
             else
             {
               fprintf(c, "%d\t%s\t%s\t%d %s %d\t%d\t%s\n", (*a).codeabs,(*a).relationedabs.nom,(*a).relationedabs.prenom,(*a).dateabs.jour,(*a).dateabs.mois,(*a).dateabs.annee,(*a).heurabs,(*a).relationedabs.filiere);
             }
            }
            if(trouve == 0)
             {
             	printf("              Le code n'a pas ete trouve\n");
			 }
			fclose(b);
            fclose(c);
            b = fopen("absence.txt", "w"); 
            c = fopen("modabsence.txt", "r"); 
            if(c != NULL && b != NULL)
             {
             	while(fscanf(c,"%d\t%s\t%s\t%d %s %d\t%d\t%s\n", &(*a).codeabs,(*a).relationedabs.nom,(*a).relationedabs.prenom,&(*a).dateabs.jour,(*a).dateabs.mois,&(*a).dateabs.annee,&(*a).heurabs,(*a).relationedabs.filiere) != EOF)
                    {
                    	fprintf(b,"%d\t%s\t%s\t%d %s %d\t%d\t%s\n", (*a).codeabs,(*a).relationedabs.nom,(*a).relationedabs.prenom,(*a).dateabs.jour,(*a).dateabs.mois,(*a).dateabs.annee,(*a).heurabs,(*a).relationedabs.filiere);
					}
			 }
                
            else
             {
             	printf("              une erreur s est produite..!\n");
			 }
               fclose(b);
               fclose(c);
               remove("modabsence.txt");
	
	
	
    }
    
    return (*a);
}

absence modifiernomrelationedabs(){
	
	
    FILE *b= fopen("absence.txt", "r");
    FILE *c= fopen("modabsence.txt", "w");
    char nom[25];
    int trouve = 0;
    int codeabs;

    if( b == NULL)
        printf("              Erreur lors de l'ouverture du fichier \n");
    else
     {
     	printf("\n              Donner le code d'absence de l'etudiant : ");
        scanf("%d",&codeabs);
       /* printf("\nDonner le nom de l'etudiant absent que vous voulez modifier : ");
        scanf("%s",nom);*/
        while(fscanf(b,"%d\t%s\t%s\t%d %s %d\t%d\t%s\n", &(*a).codeabs,(*a).relationedabs.nom,(*a).relationedabs.prenom,&(*a).dateabs.jour,(*a).dateabs.mois,&(*a).dateabs.annee,&(*a).heurabs,(*a).relationedabs.filiere) != EOF)
            {
             if(/*strcmp((*a).relationedabs.nom,nom)==0*/(*a).codeabs==codeabs)
             {
               trouve = 1;
               printf("              Donner le nouveau nom de l'etudiant : ");
               scanf("%s", (*a).relationedabs.nom);
               fprintf(c,"%d\t%s\t%s\t%d %s %d\t%d\t%s\n",(*a).codeabs,(*a).relationedabs.nom,(*a).relationedabs.prenom,(*a).dateabs.jour,(*a).dateabs.mois,(*a).dateabs.annee,(*a).heurabs,(*a).relationedabs.filiere);
             }
             else
             {
               fprintf(c, "%d\t%s\t%s\t%d %s %d\t%d\t%s\n", (*a).codeabs,(*a).relationedabs.nom,(*a).relationedabs.prenom,(*a).dateabs.jour,(*a).dateabs.mois,(*a).dateabs.annee,(*a).heurabs,(*a).relationedabs.filiere);
             }
            }
            if(trouve == 0)
             {
             	printf("              Le code n'a pas ete trouve\n");
			 }
			fclose(b);
            fclose(c);
            b = fopen("absence.txt", "w"); 
            c = fopen("modabsence.txt", "r"); 
            if(c != NULL && b != NULL)
             {
             	while(fscanf(c,"%d\t%s\t%s\t%d %s %d\t%d\t%s\n", &(*a).codeabs,(*a).relationedabs.nom,(*a).relationedabs.prenom,&(*a).dateabs.jour,(*a).dateabs.mois,&(*a).dateabs.annee,&(*a).heurabs,(*a).relationedabs.filiere) != EOF)
                    {
                    	fprintf(b,"%d\t%s\t%s\t%d %s %d\t%d\t%s\n", (*a).codeabs,(*a).relationedabs.nom,(*a).relationedabs.prenom,(*a).dateabs.jour,(*a).dateabs.mois,(*a).dateabs.annee,(*a).heurabs,(*a).relationedabs.filiere);
					}
			 }
                
            else
             {
             	printf("              une erreur s est produite..!\n");
			 }
               fclose(b);
               fclose(c);
               remove("modabsence.txt");
	
	
	
    }
    
    return (*a);
}


    

 

 




