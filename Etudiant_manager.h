#include <stdio.h>
#include <stdlib.h>





etudiant liretudiant(){
	
	
	e=(etudiant*)malloc(sizeof(etudiant));
	int idetudiant;
	int trouve;
    do
      {
      	trouve = 0;
      	printf("       idetudiant : ");
    	scanf("%d",&idetudiant);
	    FILE *b;
        b=fopen("etudiant.txt","r");
        if(b==NULL)
           printf("erreur d'ouverture");
        else
          {
		  
	      while(fscanf(b,"%d\t%s\t%s\t%d %s %d\t%s\t%d\t%s\n", &(*e).idetudiant,(*e).nom,(*e).prenom,&(*e).datenaiss.jour,(*e).datenaiss.mois,&(*e).datenaiss.annee,(*e).mail,&(*e).numtel,(*e).filiere) != EOF)
             {
              if((*e).idetudiant==idetudiant)
                {
                	trouve = 1;
				}
              
             }
          }
             if(trouve == 1)
              {
				
                printf("\n       le code etudiant saisi existe deja ");
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
                (*e).idetudiant=idetudiant;
                
	  }while(trouve!=0);
	printf("       Nom : ");
	scanf("%s",(*e).nom);
	printf("       Prenom : ");
	scanf("%s",(*e).prenom);
	printf("       Jour : ");
	scanf("%d",&(*e).datenaiss.jour);
	printf("       Mois : ");
	scanf("%s",(*e).datenaiss.mois);
	printf("       Annee : ");
	scanf("%d",&(*e).datenaiss.annee);
	printf("       Adresse Mail : ");
	scanf("%s",(*e).mail);
	printf("       Numéro de telephone : ");
	scanf("%d",&(*e).numtel);
	printf("       Filiere : ");
	scanf("%s",(*e).filiere);
	
	return (*e);
	
	
}



etudiant ecriretudiant()
 {
	
	
	FILE *f;
	f=fopen("etudiant.txt","a");
	if(f==NULL)
	  printf("erreur d'ouverture");
	else
	  {
	  	fprintf(f,"%d\t%s\t%s\t%d %s %d\t%s\t%d\t%s\n",(*e).idetudiant,(*e).nom,(*e).prenom,(*e).datenaiss.jour,(*e).datenaiss.mois,(*e).datenaiss.annee,(*e).mail,(*e).numtel,(*e).filiere);
	  	fclose(f);
	  }
	  
    return (*e);	
	
 }



etudiant afficheretudiant()
 {
	
	
    e=(etudiant*)malloc(sizeof(etudiant));
	FILE *f;
	f=fopen("etudiant.txt","r");
	if(f==NULL)
	  printf("erreur d'ouverture");
	else
	 {
	 	while(fscanf(f,"%d\t%s\t%s\t%d %s %d\t%s\t%d\t%s\n",&(*e).idetudiant,(*e).nom,(*e).prenom,&(*e).datenaiss.jour,(*e).datenaiss.mois,&(*e).datenaiss.annee,(*e).mail,&(*e).numtel,(*e).filiere)!=EOF)
	 	     {
	 	     	printf("       code etudiant: %d\tNom: %s\tPrenom: %s\tdate de naissance: %d/%s/%d\tMail: %s\tTel: %d\tFiliere: %s \n",(*e).idetudiant,(*e).nom,(*e).prenom,(*e).datenaiss.jour,(*e).datenaiss.mois,(*e).datenaiss.annee,(*e).mail,(*e).numtel,(*e).filiere);
		        
			  }
	 	   	fclose(f);
	 }
	 
	 
	return (*e);
	
 }

etudiant supprimered()
  {
    e=(etudiant*)malloc(sizeof(etudiant));
    FILE * y = fopen("etudiant.txt", "r");
    FILE * z = fopen("modetudiant.txt", "w");
    int idetudiant;
    int trouve = 0;
    if(y == NULL)
        printf("       Erreur lors de l'ouverture du fichier \n");
    else
    {
        printf("\n       Entrer le code de l'etudiant : ");
        scanf("%d", &idetudiant);
        while(fscanf(y,"%d\t%s\t%s\t%d %s %d\t%s\t%d\t%s\n",&(*e).idetudiant,(*e).nom,(*e).prenom,&(*e).datenaiss.jour,(*e).datenaiss.mois,&(*e).datenaiss.annee,(*e).mail,&(*e).numtel,(*e).filiere) != EOF)
            {
             if((*e).idetudiant!=idetudiant)
             {
               fprintf(z, "%d\t%s\t%s\t%d %s %d\t%s\t%d\t%s\n",(*e).idetudiant,(*e).nom,(*e).prenom,(*e).datenaiss.jour,(*e).datenaiss.mois,(*e).datenaiss.annee,(*e).mail,(*e).numtel,(*e).filiere);
              }
             else
             {
               trouve = 1;
             }
            }
            if(trouve == 0)
                {
                	printf("\n       le code saisi n'a pas ete trouve ");
				}
            else
                {
                	printf("\n       l'etudiant a ete supprime \n\n");
                	
				}
			    
            
    }
    fclose(y);
    fclose(z);
	y = fopen("etudiant.txt", "w");
    z = fopen("modetudiant.txt", "r");
   if( y != NULL && z != NULL)
       {
           while(fscanf(z,"%d\t%s\t%s\t%d %s %d\t%s\t%d\t%s\n", &(*e).idetudiant,(*e).nom,(*e).prenom,&(*e).datenaiss.jour,(*e).datenaiss.mois,&(*e).datenaiss.annee,(*e).mail,&(*e).numtel,(*e).filiere) != EOF)
                {
                   fprintf(y,"%d\t%s\t%s\t%d %s %d\t%s\t%d\t%s\n", (*e).idetudiant,(*e).nom,(*e).prenom,(*e).datenaiss.jour,(*e).datenaiss.mois,(*e).datenaiss.annee,(*e).mail,(*e).numtel,(*e).filiere);
	               }
	    }
   else
        {
            printf("       une erreur s est produite..!\n");
	      }
	    fclose(y);
        fclose(z);
        remove("modetudiant.txt");
    
    return (*e);
    
  }
  
  
etudiant modifierdatetudiant(){
	
	e=(etudiant*)malloc(sizeof(etudiant));
    FILE *i= fopen("etudiant.txt", "r");
    FILE *j= fopen("modetudiant.txt", "w");
    int jour,annee;
    char mois[10];
    int idetudiant;
    int trouve = 0;

    if( i == NULL)
        printf("              Erreur lors de l'ouverture du fichier \n");
    else
     {
     	printf("\n              Donner l'idendifiant de l'etudiant : ");
        scanf("%d",&idetudiant);
        /*printf("\nDonner le Jour d'inscription de l'etudiant que vous souhaitez modifiez : ");
        scanf("%d",&jour);
        printf("\nDonner le mois d'inscription de l'etduiant que vous souhaitez modifiez : ");
        scanf("%s",mois);
        printf("\nDonner l'annee d'inscription de l'etduiant que vous souhaitez modifiez : ");
        scanf("%d",&annee);*/
        while(fscanf(i,"%d\t%s\t%s\t%d %s %d\t%s\t%d\t%s\n", &(*e).idetudiant,(*e).nom,(*e).prenom,&(*e).datenaiss.jour,(*e).datenaiss.mois,&(*e).datenaiss.annee,(*e).mail,&(*e).numtel,(*e).filiere) != EOF)
            {
             if(/*(*e).datenaiss.jour==jour && strcmp((*e).datenaiss.mois,mois)==0 && (*e).datenaiss.annee==annee*/(*e).idetudiant==idetudiant)
             {
               trouve = 1;
               printf("              Donner le nouveau Jour d'inscription de l'etudiant que vous souhaitez modifiez : ");
               scanf("%d", &jour);
               printf("              Donner le nouveau mois d'inscription de l'etudiant que vous souhaitez modifiez : ");
               scanf("%s", (*e).datenaiss.mois);
               printf("              Donner la nouvelle annee d'inscription de l'etudiant que vous souhaitez modifiez : ");
               scanf("%d", &annee);
               (*e).datenaiss.jour=jour;
               (*e).datenaiss.annee=annee;
               fprintf(j,"%d\t%s\t%s\t%d %s %d\t%s\t%d\t%s\n",(*e).idetudiant,(*e).nom,(*e).prenom,(*e).datenaiss.jour,(*e).datenaiss.mois,(*e).datenaiss.annee,(*e).mail,(*e).numtel,(*e).filiere);
             }
             else
             {
               fprintf(j,"%d\t%s\t%s\t%d %s %d\t%s\t%d\t%s\n",(*e).idetudiant,(*e).nom,(*e).prenom,(*e).datenaiss.jour,(*e).datenaiss.mois,(*e).datenaiss.annee,(*e).mail,(*e).numtel,(*e).filiere);
		     	 }
            
             }
            }
            if(trouve == 0)
             {
             	printf("              L'identifiant saisi n'a pas ete trouve\n");
			 }
			   fclose(i);
               fclose(j);
               i = fopen("etudiant.txt", "w"); 
               j = fopen("modetudiant.txt", "r"); 
               if(i != NULL && j != NULL)
                 {
             	   while(fscanf(j,"%d\t%s\t%s\t%d %s %d\t%s\t%d\t%s\n", &(*e).idetudiant,(*e).nom,(*e).prenom,&(*e).datenaiss.jour,(*e).datenaiss.mois,&(*e).datenaiss.annee,(*e).mail,&(*e).numtel,(*e).filiere) != EOF)
                    {
                    	fprintf(i,"%d\t%s\t%s\t%d %s %d\t%s\t%d\t%s\n", (*e).idetudiant,(*e).nom,(*e).prenom,(*e).datenaiss.jour,(*e).datenaiss.mois,(*e).datenaiss.annee,(*e).mail,(*e).numtel,(*e).filiere);
					}
	
	
                 }
               else
                {
             	 printf("              une erreur s est produite..!\n");
			    }
               fclose(i);
               fclose(j);
               remove("modetudiant.txt");
                return (*e);
    }
    
etudiant modifieridetudiant(){
	
	e=(etudiant*)malloc(sizeof(etudiant));
    FILE *b= fopen("etudiant.txt", "r");
    FILE *c= fopen("modetudiant.txt", "w");
    int idetudiant;
    int trouve = 0;

    if( b == NULL)
        printf("              Erreur lors de l'ouverture du fichier \n");
    else
     {
        printf("\n              Donner l'idendifiant de l'etudiant que vous voulez modifier : ");
        scanf("%d",&idetudiant);
        while(fscanf(b,"%d\t%s\t%s\t%d %s %d\t%s\t%d\t%s\n", &(*e).idetudiant,(*e).nom,(*e).prenom,&(*e).datenaiss.jour,(*e).datenaiss.mois,&(*e).datenaiss.annee,(*e).mail,&(*e).numtel,(*e).filiere) != EOF)
            {
             if((*e).idetudiant==idetudiant)
             {
               trouve = 1;
               printf("              Donner le nouvel identifiant de l'etudiant : ");
               scanf("%d", &idetudiant);
               (*e).idetudiant=idetudiant;
               fprintf(c,"%d\t%s\t%s\t%d %s %d\t%s\t%d\t%s\n",(*e).idetudiant,(*e).nom,(*e).prenom,(*e).datenaiss.jour,(*e).datenaiss.mois,(*e).datenaiss.annee,(*e).mail,(*e).numtel,(*e).filiere);
             }
             else
             {
               fprintf(c, "%d\t%s\t%s\t%d %s %d\t%s\t%d\t%s\n", (*e).idetudiant,(*e).nom,(*e).prenom,(*e).datenaiss.jour,(*e).datenaiss.mois,(*e).datenaiss.annee,(*e).mail,(*e).numtel,(*e).filiere);
             }
            }
            if(trouve == 0)
             {
             	printf("              L'identifiant saisi n'a pas ete trouve\n");
			 }
			fclose(b);
            fclose(c);
            b = fopen("etudiant.txt", "w"); 
            c = fopen("modetudiant.txt", "r"); 
            if(c != NULL && b != NULL)
             {
             	while(fscanf(c,"%d\t%s\t%s\t%d %s %d\t%s\t%d\t%s\n", &(*e).idetudiant,(*e).nom,(*e).prenom,&(*e).datenaiss.jour,(*e).datenaiss.mois,&(*e).datenaiss.annee,(*e).mail,&(*e).numtel,(*e).filiere) != EOF)
                    {
                    	fprintf(b,"%d\t%s\t%s\t%d %s %d\t%s\t%d\t%s\n", (*e).idetudiant,(*e).nom,(*e).prenom,(*e).datenaiss.jour,(*e).datenaiss.mois,(*e).datenaiss.annee,(*e).mail,(*e).numtel,(*e).filiere);
					}
			 }
                
            else
             {
             	printf("              une erreur s est produite..!\n");
			 }
               fclose(b);
               fclose(c);
               remove("modetudiant.txt");
	
	
	
    }
    
    return (*e);
}
  
etudiant modifiernumtel(){
	
	e=(etudiant*)malloc(sizeof(etudiant));
    FILE *b= fopen("etudiant.txt", "r");
    FILE *c= fopen("modetudiant.txt", "w");
    int numtel;
    int trouve = 0;
    int idetudiant;

    if( b == NULL)
        printf("              Erreur lors de l'ouverture du fichier \n");
    else
     {
     	printf("\n              Donner l'idendifiant de l'etudiant : ");
        scanf("%d",&idetudiant);
        /*printf("\nDonner le numero de l'etudiant que vous voulez modifier : ");
        scanf("%d",&numtel);*/
        while(fscanf(b,"%d\t%s\t%s\t%d %s %d\t%s\t%d\t%s\n", &(*e).idetudiant,(*e).nom,(*e).prenom,&(*e).datenaiss.jour,(*e).datenaiss.mois,&(*e).datenaiss.annee,(*e).mail,&(*e).numtel,(*e).filiere) != EOF)
            {
             if(/*(*e).numtel==numtel*/(*e).idetudiant==idetudiant)
             {
               trouve = 1;
               printf("              Donner le nouveau numero de l'etudiant : ");
               scanf("%d", &numtel);
               (*e).numtel=numtel;
               fprintf(c,"%d\t%s\t%s\t%d %s %d\t%s\t%d\t%s\n",(*e).idetudiant,(*e).nom,(*e).prenom,(*e).datenaiss.jour,(*e).datenaiss.mois,(*e).datenaiss.annee,(*e).mail,(*e).numtel,(*e).filiere);
             }
             else
             {
               fprintf(c, "%d\t%s\t%s\t%d %s %d\t%s\t%d\t%s\n", (*e).idetudiant,(*e).nom,(*e).prenom,(*e).datenaiss.jour,(*e).datenaiss.mois,(*e).datenaiss.annee,(*e).mail,(*e).numtel,(*e).filiere);
             }
            }
            if(trouve == 0)
             {
             	printf("              L'identifiant n'a pas ete trouve\n");
			 }
			fclose(b);
            fclose(c);
            b = fopen("etudiant.txt", "w"); 
            c = fopen("modetudiant.txt", "r"); 
            if(c != NULL && b != NULL)
             {
             	while(fscanf(c,"%d\t%s\t%s\t%d %s %d\t%s\t%d\t%s\n", &(*e).idetudiant,(*e).nom,(*e).prenom,&(*e).datenaiss.jour,(*e).datenaiss.mois,&(*e).datenaiss.annee,(*e).mail,&(*e).numtel,(*e).filiere) != EOF)
                    {
                    	fprintf(b,"%d\t%s\t%s\t%d %s %d\t%s\t%d\t%s\n", (*e).idetudiant,(*e).nom,(*e).prenom,(*e).datenaiss.jour,(*e).datenaiss.mois,(*e).datenaiss.annee,(*e).mail,(*e).numtel,(*e).filiere);
					}
			 }
                
            else
             {
             	printf("              une erreur s est produite..!\n");
			 }
               fclose(b);
               fclose(c);
               remove("modetudiant.txt");
	
	
	
    }
    
    return (*e);
}

etudiant modifiernom(){
	
	e=(etudiant*)malloc(sizeof(etudiant));
    FILE *b= fopen("etudiant.txt", "r");
    FILE *c= fopen("modetudiant.txt", "w");
    char nom[25];
    int trouve = 0;
    int idetudiant;

    if( b == NULL)
        printf("Erreur lors de l'ouverture du fichier \n");
    else
     {
     	printf("\n              Donner l'idendifiant de l'etudiant : ");
        scanf("%d",&idetudiant);
        /*printf("\nDonner le nom de l'etudiant que vous voulez modifier : ");
        scanf("%s",nom);*/
        while(fscanf(b,"%d\t%s\t%s\t%d %s %d\t%s\t%d\t%s\n", &(*e).idetudiant,(*e).nom,(*e).prenom,&(*e).datenaiss.jour,(*e).datenaiss.mois,&(*e).datenaiss.annee,(*e).mail,&(*e).numtel,(*e).filiere) != EOF)
            {
             if(/*strcmp((*e).nom,nom)==0*/(*e).idetudiant==idetudiant)
             {
               trouve = 1;
               printf("              Donner le nouveau nom de l'etudiant : ");
               scanf("%s", (*e).nom);
               fprintf(c,"%d\t%s\t%s\t%d %s %d\t%s\t%d\t%s\n",(*e).idetudiant,(*e).nom,(*e).prenom,(*e).datenaiss.jour,(*e).datenaiss.mois,(*e).datenaiss.annee,(*e).mail,(*e).numtel,(*e).filiere);
             }
             else
             {
               fprintf(c, "%d\t%s\t%s\t%d %s %d\t%s\t%d\t%s\n", (*e).idetudiant,(*e).nom,(*e).prenom,(*e).datenaiss.jour,(*e).datenaiss.mois,(*e).datenaiss.annee,(*e).mail,(*e).numtel,(*e).filiere);
             }
            }
            if(trouve == 0)
             {
             	printf("              L'identifiant n'a pas ete trouve\n");
			 }
			fclose(b);
            fclose(c);
            b = fopen("etudiant.txt", "w"); 
            c = fopen("modetudiant.txt", "r"); 
            if(c != NULL && b != NULL)
             {
             	while(fscanf(c,"%d\t%s\t%s\t%d %s %d\t%s\t%d\t%s\n", &(*e).idetudiant,(*e).nom,(*e).prenom,&(*e).datenaiss.jour,(*e).datenaiss.mois,&(*e).datenaiss.annee,(*e).mail,&(*e).numtel,(*e).filiere) != EOF)
                    {
                    	fprintf(b,"%d\t%s\t%s\t%d %s %d\t%s\t%d\t%s\n", (*e).idetudiant,(*e).nom,(*e).prenom,(*e).datenaiss.jour,(*e).datenaiss.mois,(*e).datenaiss.annee,(*e).mail,(*e).numtel,(*e).filiere);
					}
			 }
                
            else
             {
             	printf("              une erreur s est produite..!\n");
			 }
               fclose(b);
               fclose(c);
               remove("modetudiant.txt");
	
	
	
    }
    
    return (*e);
}

etudiant modifierprenom(){
	
	e=(etudiant*)malloc(sizeof(etudiant));
    FILE *b= fopen("etudiant.txt", "r");
    FILE *c= fopen("modetudiant.txt", "w");
    char prenom[25];
    int trouve = 0;
    int idetudiant;

    if( b == NULL)
        printf("              Erreur lors de l'ouverture du fichier \n");
    else
     {
     	printf("\n              Donner l'idendifiant de l'etudiant : ");
        scanf("%d",&idetudiant);
        /*printf("\nDonner le prenom de l'etudiant que vous voulez modifier : ");
        scanf("%s", prenom);*/
        while(fscanf(b,"%d\t%s\t%s\t%d %s %d\t%s\t%d\t%s\n", &(*e).idetudiant,(*e).nom,(*e).prenom,&(*e).datenaiss.jour,(*e).datenaiss.mois,&(*e).datenaiss.annee,(*e).mail,&(*e).numtel,(*e).filiere) != EOF)
            {
             if(/*strcmp((*e).prenom,prenom)==0*/(*e).idetudiant==idetudiant)
             {
               trouve = 1;
               printf("              Donner le nouveau prenom de l'etudiant : ");
               scanf("%s", (*e).prenom);
               fprintf(c,"%d\t%s\t%s\t%d %s %d\t%s\t%d\t%s\n",(*e).idetudiant,(*e).nom,(*e).prenom,(*e).datenaiss.jour,(*e).datenaiss.mois,(*e).datenaiss.annee,(*e).mail,(*e).numtel,(*e).filiere);
             }
             else
             {
               fprintf(c, "%d\t%s\t%s\t%d %s %d\t%s\t%d\t%s\n", (*e).idetudiant,(*e).nom,(*e).prenom,(*e).datenaiss.jour,(*e).datenaiss.mois,(*e).datenaiss.annee,(*e).mail,(*e).numtel,(*e).filiere);
             }
            }
            if(trouve == 0)
             {
             	printf("              L'identifiant saisi n'a pas ete trouve\n");
			 }
			fclose(b);
            fclose(c);
            b = fopen("etudiant.txt", "w"); 
            c = fopen("modetudiant.txt", "r"); 
            if(c != NULL && b != NULL)
             {
             	while(fscanf(c,"%d\t%s\t%s\t%d %s %d\t%s\t%d\t%s\n", &(*e).idetudiant,(*e).nom,(*e).prenom,&(*e).datenaiss.jour,(*e).datenaiss.mois,&(*e).datenaiss.annee,(*e).mail,&(*e).numtel,(*e).filiere) != EOF)
                    {
                    	fprintf(b,"%d\t%s\t%s\t%d %s %d\t%s\t%d\t%s\n", (*e).idetudiant,(*e).nom,(*e).prenom,(*e).datenaiss.jour,(*e).datenaiss.mois,(*e).datenaiss.annee,(*e).mail,(*e).numtel,(*e).filiere);
					}
			 }
                
            else
             {
             	printf("              une erreur s est produite..!\n");
			 }
               fclose(b);
               fclose(c);
               remove("modetudiant.txt");
	
	
	
    }
    
    return (*e);
}

etudiant modifierfiliere(){
	
	e=(etudiant*)malloc(sizeof(etudiant));
    FILE *b= fopen("etudiant.txt", "r");
    FILE *c= fopen("modetudiant.txt", "w");
    char filiere[25];
    int trouve = 0;
    int idetudiant;

    if( b == NULL)
        printf("Erreur lors de l'ouverture du fichier \n");
    else
     {
     	printf("\n              Donner l'idendifiant de l'etudiant : ");
        scanf("%d",&idetudiant);
       /* printf("\nDonner la filiere que vous voulez modifier : ");
        scanf("%s", filiere);*/
        while(fscanf(b,"%d\t%s\t%s\t%d %s %d\t%s\t%d\t%s\n", &(*e).idetudiant,(*e).nom,(*e).prenom,&(*e).datenaiss.jour,(*e).datenaiss.mois,&(*e).datenaiss.annee,(*e).mail,&(*e).numtel,(*e).filiere) != EOF)
            {
             if(/*strcmp((*e).filiere,filiere)==0*/(*e).idetudiant==idetudiant)
             {
               trouve = 1;
               printf("              Donner le nouvelle filiere de l'etudiant : ");
               scanf("%s", (*e).filiere);
               fprintf(c,"%d\t%s\t%s\t%d %s %d\t%s\t%d\t%s\n",(*e).idetudiant,(*e).nom,(*e).prenom,(*e).datenaiss.jour,(*e).datenaiss.mois,(*e).datenaiss.annee,(*e).mail,(*e).numtel,(*e).filiere);
             }
             else
             {
               fprintf(c, "%d\t%s\t%s\t%d %s %d\t%s\t%d\t%s\n", (*e).idetudiant,(*e).nom,(*e).prenom,(*e).datenaiss.jour,(*e).datenaiss.mois,(*e).datenaiss.annee,(*e).mail,(*e).numtel,(*e).filiere);
             }
            }
            if(trouve == 0)
             {
             	printf("              L'identifiant saisi n'a pas ete trouve\n");
			 }
			fclose(b);
            fclose(c);
            b = fopen("etudiant.txt", "w"); 
            c = fopen("modetudiant.txt", "r"); 
            if(c != NULL && b != NULL)
             {
             	while(fscanf(c,"%d\t%s\t%s\t%d %s %d\t%s\t%d\t%s\n", &(*e).idetudiant,(*e).nom,(*e).prenom,&(*e).datenaiss.jour,(*e).datenaiss.mois,&(*e).datenaiss.annee,(*e).mail,&(*e).numtel,(*e).filiere) != EOF)
                    {
                    	fprintf(b,"%d\t%s\t%s\t%d %s %d\t%s\t%d\t%s\n", (*e).idetudiant,(*e).nom,(*e).prenom,(*e).datenaiss.jour,(*e).datenaiss.mois,(*e).datenaiss.annee,(*e).mail,(*e).numtel,(*e).filiere);
					}
			 }
                
            else
             {
             	printf("              une erreur s est produite..!\n");
			 }
               fclose(b);
               fclose(c);
               remove("modetudiant.txt");
	
	
	
    }
    
    return (*e);
}

etudiant modifiermail(){
	
	e=(etudiant*)malloc(sizeof(etudiant));
    FILE *b= fopen("etudiant.txt", "r");
    FILE *c= fopen("modetudiant.txt", "w");
    char mail[20];
    int trouve = 0;
    int idetudiant;
    
    if( b == NULL)
        printf("Erreur lors de l'ouverture du fichier \n");
    else
     {
     	printf("\n              Donner l'idendifiant de l'etudiant : ");
        scanf("%d",&idetudiant);
        /*printf("\nDonner le mail que vous voulez modifier : ");
        scanf("%s", mail);*/
        while(fscanf(b,"%d\t%s\t%s\t%d %s %d\t%s\t%d\t%s\n", &(*e).idetudiant,(*e).nom,(*e).prenom,&(*e).datenaiss.jour,(*e).datenaiss.mois,&(*e).datenaiss.annee,(*e).mail,&(*e).numtel,(*e).filiere) != EOF)
            {
             if(/*strcmp((*e).mail,mail)==0*/(*e).idetudiant==idetudiant)
             {
               trouve = 1;
               printf("              Donner le nouveau mail de l'etudiant : ");
               scanf("%s", (*e).mail);
               fprintf(c,"%d\t%s\t%s\t%d %s %d\t%s\t%d\t%s\n",(*e).idetudiant,(*e).nom,(*e).prenom,(*e).datenaiss.jour,(*e).datenaiss.mois,(*e).datenaiss.annee,(*e).mail,(*e).numtel,(*e).filiere);
             }
             else
             {
               fprintf(c, "%d\t%s\t%s\t%d %s %d\t%s\t%d\t%s\n", (*e).idetudiant,(*e).nom,(*e).prenom,(*e).datenaiss.jour,(*e).datenaiss.mois,(*e).datenaiss.annee,(*e).mail,(*e).numtel,(*e).filiere);
             }
            }
            if(trouve == 0)
             {
             	printf("              L'identifiant saisi n'a pas ete trouve\n");
			 }
			fclose(b);
            fclose(c);
            b = fopen("etudiant.txt", "w"); 
            c = fopen("modetudiant.txt", "r"); 
            if(c != NULL && b != NULL)
             {
             	while(fscanf(c,"%d\t%s\t%s\t%d %s %d\t%s\t%d\t%s\n", &(*e).idetudiant,(*e).nom,(*e).prenom,&(*e).datenaiss.jour,(*e).datenaiss.mois,&(*e).datenaiss.annee,(*e).mail,&(*e).numtel,(*e).filiere) != EOF)
                    {
                    	fprintf(b,"%d\t%s\t%s\t%d %s %d\t%s\t%d\t%s\n", (*e).idetudiant,(*e).nom,(*e).prenom,(*e).datenaiss.jour,(*e).datenaiss.mois,(*e).datenaiss.annee,(*e).mail,(*e).numtel,(*e).filiere);
					}
			 }
                
            else
             {
             	printf("              une erreur s est produite..!\n");
			 }
               fclose(b);
               fclose(c);
               remove("modetudiant.txt");
	
	
	
    }
    
    return (*e);
}

etudiant recherchernom()
{
	e=(etudiant*)malloc(sizeof(etudiant));
    int trouve=0;
    FILE * f = fopen("etudiant.txt", "r");
    char nomrech[25];
    printf("       Donner le nom a recherche : ");
    scanf("%s", nomrech);
    if(f == NULL)
        printf("Erreur lors de l'ouverture du fichier \n");
    else
    {
        while(fscanf(f,"%d\t%s\t%s\t%d %s %d\t%s\t%d\t%s", &(*e).idetudiant,(*e).nom,(*e).prenom,&(*e).datenaiss.jour,(*e).datenaiss.mois,&(*e).datenaiss.annee,(*e).mail,&(*e).numtel,(*e).filiere)!= EOF )
              {
              	if(strcmp((*e).nom, nomrech)==0)
              	  {
              	  	trouve= 1;
              	  	printf("\n       code etudiant: %d\tNom: %s\tPrenom: %s\tdate de naissance: %d/%s/%d\tMail: %s\tTel: %d\tFiliere: %s \n",(*e).idetudiant,(*e).nom,(*e).prenom,(*e).datenaiss.jour,(*e).datenaiss.mois,(*e).datenaiss.annee,(*e).mail,(*e).numtel,(*e).filiere);
		            }
              }
              
        fclose(f);
    }

    if(trouve == 0)
      {
      	printf("       le nom n'existe pas \n");
	  }
    
        
        
        return (*e);
}
    
    


