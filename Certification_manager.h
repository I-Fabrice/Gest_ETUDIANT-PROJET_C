#include <stdio.h>
#include <stdlib.h>


certification ecrirecertif()
  {
	
	
	FILE *d;
	d=fopen("certification.txt","a");
	if(d==NULL)
	  printf("erreur d'ouverture");
	else
	  {
	  	fprintf(d,"%s\t%s\t%d\t%s\t%d\t%d\t%d\t%s\t%d\t%s\n",(*c).relationcert.nom,(*c).relationcert.prenom,(*c).codecert,(*c).nomcert,(*c).anunive.annee1,(*c).anunive.annee2,(*c).dateobt.jour,(*c).dateobt.mois,(*c).dateobt.annee,(*c).relationcert.filiere);
		fclose(d);
	  
	  }
	  	
	  	return (*c);
	  
	
 }

certification lirecertif(){
	
		
	c=(certification*)malloc(sizeof(certification));
	e=(etudiant*)malloc(sizeof(etudiant));
	int codecert;
    int trouve;
    do
      {
      	trouve = 0;
      	printf("       code certification: ");
    	scanf("%d",&codecert);
	    FILE *b;
        b=fopen("certification.txt","r");
        if(b==NULL)
           printf("       erreur d'ouverture");
        else
          {
		  
	      while(fscanf(b,"%s\t%s\t%d\t%s\t%d\t%d\t%d\t%s\t%d\t%s\n", (*c).relationcert.nom,(*c).relationcert.prenom,&(*c).codecert,(*c).nomcert,&(*c).anunive.annee1,&(*c).anunive.annee2,&(*c).dateobt.jour,(*c).dateobt.mois,&(*c).dateobt.annee,(*c).relationcert.filiere) != EOF)
             {
              if((*c).codecert==codecert)
                {
                	trouve = 1;
				}
              
             }
          }
             if(trouve == 1)
              {
				
                printf("\n       le code de la certification saisi existe deja ");
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
                (*c).codecert=codecert;
                
	  }while(trouve!=0);
	  
	printf("\n       Nom Certifcation: ");
	scanf("%s",(*c).nomcert);
	printf("       Annee Universitaire\n\nAnnee1 : ");
	scanf("%d",&(*c).anunive.annee1);
	printf("       Annee2 : ");
	scanf("%d",&(*c).anunive.annee2);
	printf("\n\n       Date d'obtention\nJour : ");
	scanf("%d",&(*c).dateobt.jour);
	printf("       Mois : ");
	scanf("%s",(*c).dateobt.mois);
	printf("       Annee : ");
	scanf("%d",&(*c).dateobt.annee);
	printf("       Filiere : ");
	scanf("%s",(*c).relationcert.filiere);
	 
    do
      {
      trouve = 0;
	  printf("       Nom : ");
	  scanf("%s",(*c).relationcert.nom);
	  printf("       Prenom : ");
	  scanf("%s",(*c).relationcert.prenom);
      FILE *b;
      b=fopen("etudiant.txt","r");
      if(b==NULL)
         printf("       Erreur d'ouverture du fichier");
      else
       {
       	 
       	  
			 
       	   	 while(fscanf(b,"%d\t%s\t%s\t%d %s %d\t%s\t%d\t%s\n",&(*e).idetudiant,(*e).nom,(*e).prenom,&(*e).datenaiss.jour,(*e).datenaiss.mois,&(*e).datenaiss.annee,(*e).mail,&(*e).numtel,(*e).filiere)!=EOF)
	 	      {
	 	     	if(strcmp((*c).relationcert.nom,(*e).nom)==0 && strcmp((*c).relationcert.prenom,(*e).prenom)==0)
	 	     	   {
	 	     	   	  trouve = 1;
	 	     	   	  ecrirecertif();
					 }
			  }
			  if(trouve == 0)
			     {
			     	 printf("\n       Le nom et/ou le prenom  saisi n'existe pas dans le fichier etudiant\n\n");
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
      
    

	return (*c);
	
	
}




certification affichercertif(){
	
	
	c=(certification*)malloc(sizeof(certification));
	FILE *d;
	d=fopen("certification.txt","r");
	if(d==NULL)
	  printf("erreur d'ouverture");
	else
	  {
	    while(fscanf(d,"%s\t%s\t%d %s %d %d  %d %s %d\t%s\n",(*c).relationcert.nom,(*c).relationcert.prenom,&(*c).codecert,(*c).nomcert,&(*c).anunive.annee1,&(*c).anunive.annee2,&(*c).dateobt.jour,(*c).dateobt.mois,&(*c).dateobt.annee,(*c).relationcert.filiere)!=EOF)
	 	  {
	 	  	printf("       Nom : %s\tPrenom : %s\tCode : %d Nom Certification : %s Annee : %d/%d  Date D'obtention : %d %s %d\tFiliere : %s\n",(*c).relationcert.nom,(*c).relationcert.prenom,(*c).codecert,(*c).nomcert,(*c).anunive.annee1,(*c).anunive.annee2,(*c).dateobt.jour,(*c).dateobt.mois,(*c).dateobt.annee,(*c).relationcert.filiere);
		    
		   }
		fclose(d);
	  }
	
	 	   return (*c);
	
	
}

certification supprimercert()
  {
    c=(certification*)malloc(sizeof(certification));
    FILE * y = fopen("certification.txt", "r");
    FILE * z = fopen("modcertification.txt", "w");
    int codecert;
    int trouve = 0;
    if(y == NULL)
        printf("       Erreur lors de l'ouverture du fichier \n");
    else
    {
        printf("\n       Entrer le code de la certification  : ");
        scanf("%d", &codecert);
        while(fscanf(y,"%s\t%s\t%d %s %d %d  %d %s %d\t%s\n",(*c).relationcert.nom,(*c).relationcert.prenom,&(*c).codecert,(*c).nomcert,&(*c).anunive.annee1,&(*c).anunive.annee2,&(*c).dateobt.jour,(*c).dateobt.mois,&(*c).dateobt.annee,(*c).relationcert.filiere) != EOF)
            {
             if((*c).codecert!=codecert)
             {
               fprintf(z, "%s\t%s\t%d %s %d %d  %d %s %d\t%s\n",(*c).relationcert.nom,(*c).relationcert.prenom,(*c).codecert,(*c).nomcert,(*c).anunive.annee1,(*c).anunive.annee2,(*c).dateobt.jour,(*c).dateobt.mois,(*c).dateobt.annee,(*c).relationcert.filiere);
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
                	printf("\n       la certification de l'etudiant a ete supprime \n\n");
                	
				}
			    
            
    }
    fclose(y);
    fclose(z);
	y = fopen("certification.txt", "w");
    z = fopen("modcertification.txt", "r");
   if( y != NULL && z != NULL)
       {
           while(fscanf(z,"%s\t%s\t%d %s %d %d  %d %s %d\t%s\n", (*c).relationcert.nom,(*c).relationcert.prenom,&(*c).codecert,(*c).nomcert,&(*c).anunive.annee1,&(*c).anunive.annee2,&(*c).dateobt.jour,(*c).dateobt.mois,&(*c).dateobt.annee,(*c).relationcert.filiere) != EOF)
                {
                   fprintf(y,"%s\t%s\t%d %s %d %d  %d %s %d\t%s\n", (*c).relationcert.nom,(*c).relationcert.prenom,(*c).codecert,(*c).nomcert,(*c).anunive.annee1,(*c).anunive.annee2,(*c).dateobt.jour,(*c).dateobt.mois,(*c).dateobt.annee,(*c).relationcert.filiere);
	               }
	    }
   else
        {
            printf("       une erreur s est produite..!\n");
	      }
	    fclose(y);
        fclose(z);
        remove("modcertification.txt");
    
    return (*c);
    
  }

certification modifiernomcert(){
	
	c=(certification*)malloc(sizeof(certification));
    FILE *i = fopen("certification.txt", "r");
    FILE *j = fopen("modcertification.txt", "w");
    char nomcert[10];
    int codecertif;
    int trouve = 0;

    if( i == NULL)
        printf("              Erreur lors de l'ouverture du fichier \n");
    else
     {
     	printf("\n              Donner le code certification de l'etudiant : ");
        scanf("%d",&codecertif);
        /*printf("\nDonner le nom de la certification que vous voulez modifier : ");
        scanf("%s",nomcert);*/
        while(fscanf(i,"%s\t%s\t%d %s %d %d  %d %s %d\t%s\n", (*c).relationcert.nom,(*c).relationcert.prenom,&(*c).codecert,(*c).nomcert,&(*c).anunive.annee1,&(*c).anunive.annee2,&(*c).dateobt.jour,(*c).dateobt.mois,&(*c).dateobt.annee,(*c).relationcert.filiere) != EOF)
            {
             if(/*strcmp((*c).nomcert,nomcert==0*/(*c).codecert==codecertif)
             {
               trouve = 1;
               printf("              Donner le nouveau nom de la certification : ");
               scanf("%s", (*c).nomcert);
               fprintf(j,"%s\t%s\t%d %s %d %d  %d %s %d\t%s\n",(*c).relationcert.nom,(*c).relationcert.prenom,(*c).codecert,(*c).nomcert,(*c).anunive.annee1,(*c).anunive.annee2,(*c).dateobt.jour,(*c).dateobt.mois,(*c).dateobt.annee,(*c).relationcert.filiere);
             }
             else
             {
               fprintf(j, "%s\t%s\t%d %s %d %d  %d %s %d\t%s\n", (*c).relationcert.nom,(*c).relationcert.prenom,(*c).codecert,(*c).nomcert,(*c).anunive.annee1,(*c).anunive.annee2,(*c).dateobt.jour,(*c).dateobt.mois,(*c).dateobt.annee,(*c).relationcert.filiere);
             }
            }
            if(trouve == 0)
             {
             	printf("              Le code saisi n'a pas ete trouve\n");
			 }
			fclose(i);
            fclose(j);
            i = fopen("certification.txt", "w"); 
            j = fopen("modcertification.txt", "r"); 
            if(j !=NULL && i !=NULL)
             {
             	while(fscanf(j,"%s\t%s\t%d %s %d %d  %d %s %d\t%s\n", (*c).relationcert.nom,(*c).relationcert.prenom,&(*c).codecert,(*c).nomcert,&(*c).anunive.annee1,&(*c).anunive.annee2,&(*c).dateobt.jour,(*c).dateobt.mois,&(*c).dateobt.annee,(*c).relationcert.filiere) != EOF)
                    {
                    	fprintf(i,"%s\t%s\t%d %s %d %d  %d %s %d\t%s\n", (*c).relationcert.nom,(*c).relationcert.prenom,(*c).codecert,(*c).nomcert,(*c).anunive.annee1,(*c).anunive.annee2,(*c).dateobt.jour,(*c).dateobt.mois,(*c).dateobt.annee,(*c).relationcert.filiere);
					}
			 }
                
            else
             {
             	printf("              une erreur s est produite..!\n");
			 }
               fclose(i);
               fclose(j);
               remove("modcertification.txt");
	
	
	
    }
    
    return (*c);
}



certification modifiercodecertif(){
	
	c=(certification*)malloc(sizeof(certification));
    FILE *i = fopen("certification.txt", "r");
    FILE *j = fopen("modcertification.txt", "w");
    int codecertif;
    int trouve = 0;

    if( i == NULL)
        printf("              Erreur lors de l'ouverture du fichier \n");
    else
     {
     	
        printf("\n              Donner le code certification de l'etudiant que vous voulez modifier : ");
        scanf("%d",&codecertif);
        while(fscanf(i,"%s\t%s\t%d %s %d %d  %d %s %d\t%s\n", (*c).relationcert.nom,(*c).relationcert.prenom,&(*c).codecert,(*c).nomcert,&(*c).anunive.annee1,&(*c).anunive.annee2,&(*c).dateobt.jour,(*c).dateobt.mois,&(*c).dateobt.annee,(*c).relationcert.filiere) != EOF)
            {
             if((*c).codecert==codecertif)
             {
               trouve = 1;
               printf("              Donner le nouveau code certification : ");
               scanf("%d", &codecertif);
               (*c).codecert=codecertif;
               fprintf(j,"%s\t%s\t%d %s %d %d  %d %s %d\t%s\n",(*c).relationcert.nom,(*c).relationcert.prenom,(*c).codecert,(*c).nomcert,(*c).anunive.annee1,(*c).anunive.annee2,(*c).dateobt.jour,(*c).dateobt.mois,(*c).dateobt.annee,(*c).relationcert.filiere);
             }
             else
             {
               fprintf(j, "%s\t%s\t%d %s %d %d  %d %s %d\t%s\n", (*c).relationcert.nom,(*c).relationcert.prenom,(*c).codecert,(*c).nomcert,(*c).anunive.annee1,(*c).anunive.annee2,(*c).dateobt.jour,(*c).dateobt.mois,(*c).dateobt.annee,(*c).relationcert.filiere);
             }
            }
            if(trouve == 0)
             {
             	printf("              Le code certification n'a pas ete trouve\n");
			 }
			fclose(i);
            fclose(j);
            i = fopen("certification.txt", "w"); 
            j = fopen("modcertification.txt", "r"); 
            if(j !=NULL && i !=NULL)
             {
             	while(fscanf(j,"%s\t%s\t%d %s %d %d  %d %s %d\t%s\n", (*c).relationcert.nom,(*c).relationcert.prenom,&(*c).codecert,(*c).nomcert,&(*c).anunive.annee1,&(*c).anunive.annee2,&(*c).dateobt.jour,(*c).dateobt.mois,&(*c).dateobt.annee,(*c).relationcert.filiere) != EOF)
                    {
                    	fprintf(i,"%s\t%s\t%d %s %d %d  %d %s %d\t%s\n", (*c).relationcert.nom,(*c).relationcert.prenom,(*c).codecert,(*c).nomcert,(*c).anunive.annee1,(*c).anunive.annee2,(*c).dateobt.jour,(*c).dateobt.mois,(*c).dateobt.annee,(*c).relationcert.filiere);
					}
			 }
                
            else
             {
             	printf("              une erreur s est produite..!\n");
			 }
               fclose(i);
               fclose(j);
               remove("modcertification.txt");
	
	
	
    }
    
    return (*c);
}


certification modifierdateobt(){
	
	c=(certification*)malloc(sizeof(certification));
    FILE *i= fopen("certification.txt", "r");
    FILE *j= fopen("modcertification.txt", "w");
    int jour,annee;
    int codecertif;
    char mois[10];
    int trouve = 0;

    if( i == NULL)
        printf("              Erreur lors de l'ouverture du fichier \n");
    else
     {
     	printf("\n              Donner le code certification de l'etudiant : ");
        scanf("%d",&codecertif);
        /*printf("\nDonner le Jour d'obtention de la certification que vous souhaitez modifiez : ");
        scanf("%d",&jour);
        printf("\nDonner le mois d'obtention de la certification que vous souhaitez modifiez : ");
        scanf("%s",mois);
        printf("\nDonner l'annee d'obtention de la certification que vous souhaitez modifiez : ");
        scanf("%d",&annee);*/
        while(fscanf(i,"%s\t%s\t%d %s %d %d  %d %s %d\t%s\n", (*c).relationcert.nom,(*c).relationcert.prenom,&(*c).codecert,(*c).nomcert,&(*c).anunive.annee1,&(*c).anunive.annee2,&(*c).dateobt.jour,(*c).dateobt.mois,&(*c).dateobt.annee,(*c).relationcert.filiere) != EOF)
            {
             if(/*(*c).dateobt.jour==jour && strcmp((*c).dateobt.mois,mois)==0 && (*c).dateobt.annee==annee*/(*c).codecert==codecertif)
             {
               trouve = 1;
               printf("              Donner le nouveau jour d'obtention de la certification : ");
               scanf("%d", &jour);
               printf("              Donner le nouveau mois d'obtention de la certification : ");
               scanf("%s", (*c).dateobt.mois);
               printf("              Donner la nouvelle annee d'obtention de la certification : ");
               scanf("%d", &annee);
               (*c).dateobt.jour=jour;
               (*c).dateobt.annee=annee;
               fprintf(j,"%s\t%s\t%d %s %d %d  %d %s %d\t%s\n",(*c).relationcert.nom,(*c).relationcert.prenom,(*c).codecert,(*c).nomcert,(*c).anunive.annee1,(*c).anunive.annee2,(*c).dateobt.jour,(*c).dateobt.mois,(*c).dateobt.annee,(*c).relationcert.filiere);
             }
             else
             {
               fprintf(j, "%s\t%s\t%d %s %d %d  %d %s %d\t%s\n", (*c).relationcert.nom,(*c).relationcert.prenom,(*c).codecert,(*c).nomcert,(*c).anunive.annee1,(*c).anunive.annee2,(*c).dateobt.jour,(*c).dateobt.mois,(*c).dateobt.annee,(*c).relationcert.filiere);
		     	 }
            
             }
            }
            if(trouve == 0)
             {
             	printf("              Le code saisi n'a pas ete trouve\n");
			 }
			   fclose(i);
               fclose(j);
               i = fopen("certification.txt", "w"); 
               j = fopen("modcertification.txt", "r"); 
               if(i != NULL && j != NULL)
                 {
             	   while(fscanf(j,"%s\t%s\t%d %s %d %d  %d %s %d\t%s\n", (*c).relationcert.nom,(*c).relationcert.prenom,&(*c).codecert,(*c).nomcert,&(*c).anunive.annee1,&(*c).anunive.annee2,&(*c).dateobt.jour,(*c).dateobt.mois,&(*c).dateobt.annee,(*c).relationcert.filiere) != EOF)
                    {
                    	fprintf(i,"%s\t%s\t%d %s %d %d  %d %s %d\t%s\n", (*c).relationcert.nom,(*c).relationcert.prenom,(*c).codecert,(*c).nomcert,(*c).anunive.annee1,(*c).anunive.annee2,(*c).dateobt.jour,(*c).dateobt.mois,(*c).dateobt.annee,(*c).relationcert.filiere);
					}
	
	
                 }
                 return (*c);
    }
    

certification modifierannecertif(){
	
	c=(certification*)malloc(sizeof(certification));
    FILE *i = fopen("certification.txt", "r");
    FILE *j = fopen("modcertification.txt", "w");
    int codecertif;
    int anne1;
    int anne2;
    int trouve = 0;

    if( i == NULL)
        printf("              Erreur lors de l'ouverture du fichier \n");
    else
     {
     	printf("\n              Donner le code certification de l'etudiant : ");
        scanf("%d",&codecertif);
        /*printf("\nDonner l'annee 1 de la certification que vous voulez modifier : ");
        scanf("%d",&anne1);
        printf("\nDonner l'annee 2 de la certification que vous voulez modifier : ");
        scanf("%d",&anne2);*/
        while(fscanf(i,"%s\t%s\t%d %s %d %d  %d %s %d\t%s\n", (*c).relationcert.nom,(*c).relationcert.prenom,&(*c).codecert,(*c).nomcert,&(*c).anunive.annee1,&(*c).anunive.annee2,&(*c).dateobt.jour,(*c).dateobt.mois,&(*c).dateobt.annee,(*c).relationcert.filiere) != EOF)
            {
             if(/*(*c).anunive.annee1==anne1 && (*c).anunive.annee2==anne2*/(*c).codecert==codecertif)
               {
                 trouve = 1;
                 printf("              Donner la nouvelle annee1 : ");
                 scanf("%d",&anne1);
                 printf("              Donner la nouvelle annee1 : ");
                 scanf("%d",&anne2);
                 (*c).anunive.annee1=anne1;
                 (*c).anunive.annee2=anne2;
               
                fprintf(j,"%s\t%s\t%d %s %d %d  %d %s %d\t%s\n",(*c).relationcert.nom,(*c).relationcert.prenom,(*c).codecert,(*c).nomcert,(*c).anunive.annee1,(*c).anunive.annee2,(*c).dateobt.jour,(*c).dateobt.mois,(*c).dateobt.annee,(*c).relationcert.filiere);
               }
             else
             {
               fprintf(j, "%s\t%s\t%d %s %d %d  %d %s %d\t%s\n", (*c).relationcert.nom,(*c).relationcert.prenom,(*c).codecert,(*c).nomcert,(*c).anunive.annee1,(*c).anunive.annee2,(*c).dateobt.jour,(*c).dateobt.mois,(*c).dateobt.annee,(*c).relationcert.filiere);
             }
            }
            if(trouve == 0)
             {
             	printf("              Le code saisi n'a pas ete trouve\n");
			 }
			fclose(i);
            fclose(j);
            i = fopen("certification.txt", "w"); 
            j = fopen("modcertification.txt", "r"); 
            if(j !=NULL && i !=NULL)
             {
             	while(fscanf(j,"%s\t%s\t%d %s %d %d  %d %s %d\t%s\n", (*c).relationcert.nom,(*c).relationcert.prenom,&(*c).codecert,(*c).nomcert,&(*c).anunive.annee1,&(*c).anunive.annee2,&(*c).dateobt.jour,(*c).dateobt.mois,&(*c).dateobt.annee,(*c).relationcert.filiere) != EOF)
                    {
                    	fprintf(i,"%s\t%s\t%d %s %d %d  %d %s %d\t%s\n", (*c).relationcert.nom,(*c).relationcert.prenom,(*c).codecert,(*c).nomcert,(*c).anunive.annee1,(*c).anunive.annee2,(*c).dateobt.jour,(*c).dateobt.mois,(*c).dateobt.annee,(*c).relationcert.filiere);
					}
			 }
                
            else
             {
             	printf("              une erreur s'est produite..!\n");
			 }
               fclose(i);
               fclose(j);
               remove("modcertification.txt");
	
	
	
    }
    
    return (*c);
}

certification recherchernomrelationcert()
{
	c=(certification*)malloc(sizeof(certification));
    int trouve=0;
    int compte=0;
    FILE * f = fopen("certification.txt", "r");
    char nomrech[25];
    printf("       Donner le nom a recherche : ");
    scanf("%s", nomrech);
    if(f == NULL)
        printf("       Erreur lors de l'ouverture du fichier \n");
    else
    {
        while(fscanf(f,"%s\t%s\t%d %s %d %d  %d %s %d\t%s\n", (*c).relationcert.nom,(*c).relationcert.prenom,&(*c).codecert,(*c).nomcert,&(*c).anunive.annee1,&(*c).anunive.annee2,&(*c).dateobt.jour,(*c).dateobt.mois,&(*c).dateobt.annee,(*c).relationcert.filiere)!= EOF )
              {
              	if(strcmp((*c).relationcert.nom,nomrech)==0)
              	  {
              	  	trouve= 1;
              	  	compte++;
              	  	printf("       Nom : %s\tPrenom : %s\tCode : %d Nom Certification : %s Annee : %d/%d  Date D'obtention : %d %s %d\tFiliere : %s\n",(*c).relationcert.nom,(*c).relationcert.prenom,(*c).codecert,(*c).nomcert,(*c).anunive.annee1,(*c).anunive.annee2,(*c).dateobt.jour,(*c).dateobt.mois,(*c).dateobt.annee,(*c).relationcert.filiere);
		            }
              }
              
        printf("\n\n       Nombre de certification Obtenue : %d",compte);
        fclose(f);
    }
  if(trouve==0)
        printf("\n\n       le nom n'existe pas \n");
        
        return (*c);
}

certification modifierprenomrelationcert(){
	
	c=(certification*)malloc(sizeof(certification));
    FILE *o= fopen("certification.txt", "r");
    FILE *p= fopen("modcertification.txt", "w");
    int codecertif;
    char prenom[25];
    int trouve = 0;

    if( o == NULL)
        printf("              Erreur lors de l'ouverture du fichier \n");
    else
     {
     	printf("\n              Donner le code certification de l'etudiant : ");
        scanf("%d",&codecertif);
        /*printf("\nDonner le prenom de l'etudiant que vous voulez modifier : ");
        scanf("%s",prenom);*/
        while(fscanf(o,"%s\t%s\t%d %s %d %d  %d %s %d\t%s\n", (*c).relationcert.nom,(*c).relationcert.prenom,&(*c).codecert,(*c).nomcert,&(*c).anunive.annee1,&(*c).anunive.annee2,&(*c).dateobt.jour,(*c).dateobt.mois,&(*c).dateobt.annee,(*c).relationcert.filiere) != EOF)
            {
             if(/*strcmp((*c).relationcert.prenom,prenom)==0*/(*c).codecert==codecertif)
             {
               trouve = 1;
               printf("              Donner le nouveau prenom de l'etudiant : ");
               scanf("%s", (*c).relationcert.prenom);
               fprintf(p,"%s\t%s\t%d %s %d %d  %d %s %d\t%s\n",(*c).relationcert.nom,(*c).relationcert.prenom,(*c).codecert,(*c).nomcert,(*c).anunive.annee1,(*c).anunive.annee2,(*c).dateobt.jour,(*c).dateobt.mois,(*c).dateobt.annee,(*c).relationcert.filiere);
             }
             else
             {
               fprintf(p, "%s\t%s\t%d %s %d %d  %d %s %d\t%s\n", (*c).relationcert.nom,(*c).relationcert.prenom,(*c).codecert,(*c).nomcert,(*c).anunive.annee1,(*c).anunive.annee2,(*c).dateobt.jour,(*c).dateobt.mois,(*c).dateobt.annee,(*c).relationcert.filiere);
             }
            }
            if(trouve == 0)
             {
             	printf("              Le code saisi n'a pas ete trouve\n");
			 }
			fclose(o);
            fclose(p);
            o = fopen("certification.txt", "w"); 
            p = fopen("modcertification.txt", "r"); 
            if(o != NULL && p != NULL)
             {
             	while(fscanf(p,"%s\t%s\t%d %s %d %d  %d %s %d\t%s\n", (*c).relationcert.nom,(*c).relationcert.prenom,&(*c).codecert,(*c).nomcert,&(*c).anunive.annee1,&(*c).anunive.annee2,&(*c).dateobt.jour,(*c).dateobt.mois,&(*c).dateobt.annee,(*c).relationcert.filiere) != EOF)
                    {
                    	fprintf(o,"%s\t%s\t%d %s %d %d  %d %s %d\t%s\n", (*c).relationcert.nom,(*c).relationcert.prenom,(*c).codecert,(*c).nomcert,(*c).anunive.annee1,(*c).anunive.annee2,(*c).dateobt.jour,(*c).dateobt.mois,(*c).dateobt.annee,(*c).relationcert.filiere);
					}
			 }
                
            else
             {
             	printf("              une erreur s est produite..!\n");
			 }
               fclose(o);
               fclose(p);
               remove("modcertification.txt");
	
	
	
    }
    
    return (*c);
}

certification modifiernomrelationcert(){
	
	c=(certification*)malloc(sizeof(certification));
    FILE *o= fopen("certification.txt", "r");
    FILE *p= fopen("modcertification.txt", "w");
    int codecertif;
    char nom[25];
    int trouve = 0;

    if( o == NULL)
        printf("              Erreur lors de l'ouverture du fichier \n");
    else
     {
     	printf("\n              Donner le code certification de l'etudiant : ");
        scanf("%d",&codecertif);
        /*printf("\nDonner le nom de l'etudiant que vous voulez modifier : ");
        scanf("%s",nom);*/
        while(fscanf(o,"%s\t%s\t%d %s %d %d  %d %s %d\t%s\n", (*c).relationcert.nom,(*c).relationcert.prenom,&(*c).codecert,(*c).nomcert,&(*c).anunive.annee1,&(*c).anunive.annee2,&(*c).dateobt.jour,(*c).dateobt.mois,&(*c).dateobt.annee,(*c).relationcert.filiere) != EOF)
            {
             if(/*strcmp((*c).relationcert.nom,nom)==0*/(*c).codecert==codecertif)
             {
               trouve = 1;
               printf("              Donner le nouveau nom de l'etudiant : ");
               scanf("%s", (*c).relationcert.nom);
               fprintf(p,"%s\t%s\t%d %s %d %d  %d %s %d\t%s\n",(*c).relationcert.nom,(*c).relationcert.prenom,(*c).codecert,(*c).nomcert,(*c).anunive.annee1,(*c).anunive.annee2,(*c).dateobt.jour,(*c).dateobt.mois,(*c).dateobt.annee,(*c).relationcert.filiere);
             }
             else
             {
               fprintf(p, "%s\t%s\t%d %s %d %d  %d %s %d\t%s\n", (*c).relationcert.nom,(*c).relationcert.prenom,(*c).codecert,(*c).nomcert,(*c).anunive.annee1,(*c).anunive.annee2,(*c).dateobt.jour,(*c).dateobt.mois,(*c).dateobt.annee,(*c).relationcert.filiere);
             }
            }
            if(trouve == 0)
             {
             	printf("              Le code saisi n'a pas ete trouve\n");
			 }
			fclose(o);
            fclose(p);
            o = fopen("certification.txt", "w"); 
            p = fopen("modcertification.txt", "r"); 
            if(o != NULL && p != NULL)
             {
             	while(fscanf(p,"%s\t%s\t%d %s %d %d  %d %s %d\t%s\n", (*c).relationcert.nom,(*c).relationcert.prenom,&(*c).codecert,(*c).nomcert,&(*c).anunive.annee1,&(*c).anunive.annee2,&(*c).dateobt.jour,(*c).dateobt.mois,&(*c).dateobt.annee,(*c).relationcert.filiere) != EOF)
                    {
                    	fprintf(o,"%s\t%s\t%d %s %d %d  %d %s %d\t%s\n", (*c).relationcert.nom,(*c).relationcert.prenom,(*c).codecert,(*c).nomcert,(*c).anunive.annee1,(*c).anunive.annee2,(*c).dateobt.jour,(*c).dateobt.mois,(*c).dateobt.annee,(*c).relationcert.filiere);
					}
			 }
                
            else
             {
             	printf("              une erreur s est produite..!\n");
			 }
               fclose(o);
               fclose(p);
               remove("modcertification.txt");
	
	
	
    }
    
    return (*c);
}

certification modifierfiliererelationcert(){
	
	c=(certification*)malloc(sizeof(certification));
    FILE *o= fopen("certification.txt", "r");
    FILE *p= fopen("modcertification.txt", "w");
    int codecertif;
    char filiere[25];
    int trouve = 0;

    if( o == NULL)
        printf("              Erreur lors de l'ouverture du fichier \n");
    else
     {
     	printf("\n              Donner le code certification de l'etudiant : ");
        scanf("%d",&codecertif);
       /* printf("\nDonner le filiere de l'etudiant que vous voulez modifier : ");
        scanf("%s",filiere);*/
        while(fscanf(o,"%s\t%s\t%d %s %d %d  %d %s %d\t%s\n", (*c).relationcert.nom,(*c).relationcert.prenom,&(*c).codecert,(*c).nomcert,&(*c).anunive.annee1,&(*c).anunive.annee2,&(*c).dateobt.jour,(*c).dateobt.mois,&(*c).dateobt.annee,(*c).relationcert.filiere) != EOF)
            {
             if(/*strcmp((*c).relationcert.filiere,filiere)==0*/(*c).codecert==codecertif)
             {
               trouve = 1;
               printf("              Donner le nouvelle filiere de l'etudiant : ");
               scanf("%s", (*c).relationcert.filiere);
               fprintf(p,"%s\t%s\t%d %s %d %d  %d %s %d\t%s\n",(*c).relationcert.nom,(*c).relationcert.prenom,(*c).codecert,(*c).nomcert,(*c).anunive.annee1,(*c).anunive.annee2,(*c).dateobt.jour,(*c).dateobt.mois,(*c).dateobt.annee,(*c).relationcert.filiere);
             }
             else
             {
               fprintf(p, "%s\t%s\t%d %s %d %d  %d %s %d\t%s\n", (*c).relationcert.nom,(*c).relationcert.prenom,(*c).codecert,(*c).nomcert,(*c).anunive.annee1,(*c).anunive.annee2,(*c).dateobt.jour,(*c).dateobt.mois,(*c).dateobt.annee,(*c).relationcert.filiere);
             }
            }
            if(trouve == 0)
             {
             	printf("              Le code saisi n'a pas ete trouve\n");
			 }
			fclose(o);
            fclose(p);
            o = fopen("certification.txt", "w"); 
            p = fopen("modcertification.txt", "r"); 
            if(o != NULL && p != NULL)
             {
             	while(fscanf(p,"%s\t%s\t%d %s %d %d  %d %s %d\t%s\n", (*c).relationcert.nom,(*c).relationcert.prenom,&(*c).codecert,(*c).nomcert,&(*c).anunive.annee1,&(*c).anunive.annee2,&(*c).dateobt.jour,(*c).dateobt.mois,&(*c).dateobt.annee,(*c).relationcert.filiere) != EOF)
                    {
                    	fprintf(o,"%s\t%s\t%d %s %d %d  %d %s %d\t%s\n", (*c).relationcert.nom,(*c).relationcert.prenom,(*c).codecert,(*c).nomcert,(*c).anunive.annee1,(*c).anunive.annee2,(*c).dateobt.jour,(*c).dateobt.mois,(*c).dateobt.annee,(*c).relationcert.filiere);
					}
			 }
                
            else
             {
             	printf("              une erreur s est produite..!\n");
			 }
               fclose(o);
               fclose(p);
               remove("modcertification.txt");
	
	
	
    }
    
    return (*c);
}













    
