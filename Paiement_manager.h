


paiement ecrirepaie(){
	
	
	FILE *g;
	g=fopen("paiement.txt","a");
	if(g==NULL)
	  printf("erreur d'ouverture");
	else
	  {
	  	fprintf(g,"%s\t%s\t%s\t%d\t%d %d\t%d %s %d\t%d\t%d\n",(*p).relationedpaie.nom,(*p).relationedpaie.prenom,(*p).relationedpaie.filiere,(*p).codepaie,(*p).ann_univ.annee1,(*p).ann_univ.annee2,(*p).datepaie.jour,(*p).datepaie.mois,(*p).datepaie.annee,(*p).montpaie,(*p).reste);
	  	fclose(g);
	  }
	  
	return (*p);
	
}

paiement lirpaie(){
	
	
	
	
	p=(paiement*)malloc(sizeof(paiement));
	e=(etudiant*)malloc(sizeof(etudiant));
    int trouve;
	printf("Filiere : ");
	scanf("%s",(*p).relationedpaie.filiere);
	int codepaie;
    do
      {
      	trouve = 0;
      	printf("Code Paiement: ");
	    scanf("%d",&codepaie);
	    FILE *b;
        b=fopen("paiement.txt","r");
        if(b==NULL)
           printf("erreur d'ouverture");
        else
          {
		  
	      while(fscanf(b,"%s\t%s\t%s\t%d\t%d %d\t%d %s %d\t%d\t%d\n", (*p).relationedpaie.nom,(*p).relationedpaie.prenom,(*p).relationedpaie.filiere,&(*p).codepaie,&(*p).ann_univ.annee1,&(*p).ann_univ.annee2,&(*p).datepaie.jour,(*p).datepaie.mois,&(*p).datepaie.annee,&(*p).montpaie,&(*p).reste) != EOF)
             {
              if((*p).codepaie==codepaie)
                {
                	trouve = 1;
				}
              
             }
          }
             if(trouve == 1)
              {
				
                printf("\nle code de paiement saisi existe deja ");
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
                (*p).codepaie=codepaie;
                
	  }while(trouve!=0);
	printf("Annee 1: ");
	scanf("%d",&(*p).ann_univ.annee1);
	printf("Annee 2: ");
	scanf("%d",&(*p).ann_univ.annee2);
	printf("Jour : ");
	scanf("%d",&(*p).datepaie.jour);	
	printf("Mois: ");
	scanf("%s",(*p).datepaie.mois);
	printf("Annee: ");
	scanf("%d",&(*p).datepaie.annee);
	printf("Montant Payer: ");
	scanf("%d",&(*p).montpaie);
	printf("Reste : ");
	scanf("%d",&(*p).reste);
	
	do
      {
      trouve=0;
	  printf("Nom : ");
	  scanf("%s",(*p).relationedpaie.nom);
	  printf("Prenom : ");
	  scanf("%s",(*p).relationedpaie.prenom);
      FILE *b;
      b=fopen("etudiant.txt","r");
      if(b==NULL)
         printf("Erreur d'ouverture du fichier");
      else
       {
       	 
       	  
			   
       	   	 while(fscanf(b,"%d\t%s\t%s\t%d %s %d\t%s\t%d\t%s\n",&(*e).idetudiant,(*e).nom,(*e).prenom,&(*e).datenaiss.jour,(*e).datenaiss.mois,&(*e).datenaiss.annee,(*e).mail,&(*e).numtel,(*e).filiere)!=EOF)
	 	      {
	 	     	if(strcmp((*p).relationedpaie.nom,(*e).nom)==0 && strcmp((*p).relationedpaie.prenom,(*e).prenom)==0)
	 	     	   {
	 	     	   	  trouve = 1;
	 	     	   	  ecrirepaie();
					 }
			  }
			  if(trouve == 0)
			     {
			     	 printf("\nLe nom et le prenom  saisi n'existe pas dans le fichier etudiant\n\n");
			     	 do
			     	   {
					    printf("Tapez 0 pour saisir une nouvelle fois le nom et le prenom ou 1 pour sortir du terminal : ");
			     	    scanf("%d",&trouve);
			     	   }while(trouve != 1 && trouve != 0);
			     	 if(trouve==1)
			     	   {
			     	   	 exit(1);
						}
			      }
			     
		
	   }
      }while(trouve!=1);
	
	return (*p);
	
}



paiement afficherpaie(){
	
	
	p=(paiement*)malloc(sizeof(paiement));
	FILE *g;
	g=fopen("paiement.txt","r");
	if(g==NULL)
	  printf("erreur d'ouverture");
	else
	 {
	 	while(fscanf(g,"%s\t%s\t%s\t%d\t%d %d\t%d %s %d\t%d\t%d\n",(*p).relationedpaie.nom,(*p).relationedpaie.prenom,(*p).relationedpaie.filiere,&(*p).codepaie,&(*p).ann_univ.annee1,&(*p).ann_univ.annee2,&(*p).datepaie.jour,(*p).datepaie.mois,&(*p).datepaie.annee,&(*p).montpaie,&(*p).reste)!=EOF)
	 	   {
	 	   	printf("       Nom : %s\tPrenom  :%s\tFiliere : %s\tCode : %d\tAnnee : %d/%d\tDate Paiement : %d %s %d\tMontant Payer : %d\tReste : %d\n",(*p).relationedpaie.nom,(*p).relationedpaie.prenom,(*p).relationedpaie.filiere,(*p).codepaie,(*p).ann_univ.annee1,(*p).ann_univ.annee2,(*p).datepaie.jour,(*p).datepaie.mois,(*p).datepaie.annee,(*p).montpaie,(*p).reste);
			}
		fclose(g);
	 }
	 
	 
	return (*p);
	
}  	

paiement supprimerpaie()
  {
  	p=(paiement*)malloc(sizeof(paiement));
    FILE * y = fopen("paiement.txt", "r");
    FILE * z = fopen("modpaiement.txt", "w");
    int codepaie;
    int trouve = 0;
    if(y == NULL)
        printf("Erreur lors de l'ouverture du fichier \n");
    else
    {
        printf("\nEntrer le code paiement : ");
        scanf("%d", &codepaie);
        while(fscanf(y,"%s\t%s\t%s\t%d\t%d %d\t%d %s %d\t%d\t%d\n",(*p).relationedpaie.nom,(*p).relationedpaie.prenom,(*p).relationedpaie.filiere,&(*p).codepaie,&(*p).ann_univ.annee1,&(*p).ann_univ.annee2,&(*p).datepaie.jour,(*p).datepaie.mois,&(*p).datepaie.annee,&(*p).montpaie,&(*p).reste) != EOF)
            {
             if((*p).codepaie!=codepaie)
             {
               fprintf(z, "%s\t%s\t%s\t%d\t%d %d\t%d %s %d\t%d\t%d\n",(*p).relationedpaie.nom,(*p).relationedpaie.prenom,(*p).relationedpaie.filiere,(*p).codepaie,(*p).ann_univ.annee1,(*p).ann_univ.annee2,(*p).datepaie.jour,(*p).datepaie.mois,(*p).datepaie.annee,(*p).montpaie,(*p).reste);
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
                	printf("\nle paiement a ete supprime \n\n");
                	
				}
			    
            
    }
    fclose(y);
    fclose(z);
	y = fopen("paiement.txt", "w");
    z = fopen("modpaiement.txt", "r");
   if( y != NULL && z != NULL)
       {
           while(fscanf(z,"%s\t%s\t%s\t%d\t%d %d\t%d %s %d\t%d\t%d\n", (*p).relationedpaie.nom,(*p).relationedpaie.prenom,(*p).relationedpaie.filiere,&(*p).codepaie,&(*p).ann_univ.annee1,&(*p).ann_univ.annee2,&(*p).datepaie.jour,(*p).datepaie.mois,&(*p).datepaie.annee,&(*p).montpaie,&(*p).reste) != EOF)
                {
                   fprintf(y,"%s\t%s\t%s\t%d\t%d %d\t%d %s %d\t%d\t%d\n", (*p).relationedpaie.nom,(*p).relationedpaie.prenom,(*p).relationedpaie.filiere,(*p).codepaie,(*p).ann_univ.annee1,(*p).ann_univ.annee2,(*p).datepaie.jour,(*p).datepaie.mois,(*p).datepaie.annee,(*p).montpaie,(*p).reste);
	               }
	    }
   else
        {
            printf("une erreur s est produite..!\n");
	      }
	    fclose(y);
        fclose(z);
        remove("modpaiement.txt");
    
    return (*p);
    
  }

paiement modifierdatepaie(){
	
	p=(paiement*)malloc(sizeof(paiement));
    FILE *i= fopen("paiement.txt", "r");
    FILE *j= fopen("modpaiement.txt", "w");
    int jour,annee;
    char mois[10];
    int trouve = 0;
    int codepaie;

    if( i == NULL)
        printf("              Erreur lors de l'ouverture du fichier \n");
    else
     {
     	printf("\n              Donner le code de paiement : ");
        scanf("%d",&codepaie);
        /*printf("\nDonner le Jour du paiement que vous souhaitez modifiez : ");
        scanf("%d",&jour);
        printf("\nDonner le mois du paiement que vous souhaitez modifiez : ");
        scanf("%s",mois);
        printf("\nDonner l'annee du paiement que vous souhaitez modifiez : ");
        scanf("%d",&annee);*/
        while(fscanf(i,"%s\t%s\t%s\t%d\t%d %d\t%d %s %d\t%d\t%d\n", (*p).relationedpaie.nom,(*p).relationedpaie.prenom,(*p).relationedpaie.filiere,&(*p).codepaie,&(*p).ann_univ.annee1,&(*p).ann_univ.annee2,&(*p).datepaie.jour,(*p).datepaie.mois,&(*p).datepaie.annee,&(*p).montpaie,&(*p).reste) != EOF)
            {
             if(/*(*p).datepaie.jour==jour && strcmp((*p).datepaie.mois,mois)==0 && (*p).datepaie.annee==annee*/(*p).codepaie==codepaie)
             {
               trouve = 1;
               printf("              Donner le nouveau jour du paiement de la certification : ");
               scanf("%d", &jour);
               printf("              Donner le nouveau mois du paiement de la certification : ");
               scanf("%s", (*p).datepaie.mois);
               printf("              Donner la nouvelle annee du paiement de la certification : ");
               scanf("%d", &annee);
               (*p).datepaie.jour=jour;
               (*p).datepaie.annee=annee;
               fprintf(j,"%s\t%s\t%s\t%d\t%d %d\t%d %s %d\t%d\t%d\n",(*p).relationedpaie.nom,(*p).relationedpaie.prenom,(*p).relationedpaie.filiere,(*p).codepaie,(*p).ann_univ.annee1,(*p).ann_univ.annee2,(*p).datepaie.jour,(*p).datepaie.mois,(*p).datepaie.annee,(*p).montpaie,(*p).reste);
             }
             else
             {
               fprintf(j,"%s\t%s\t%s\t%d\t%d %d\t%d %s %d\t%d\t%d\n", (*p).relationedpaie.nom,(*p).relationedpaie.prenom,(*p).relationedpaie.filiere,(*p).codepaie,(*p).ann_univ.annee1,(*p).ann_univ.annee2,(*p).datepaie.jour,(*p).datepaie.mois,(*p).datepaie.annee,(*p).montpaie,(*p).reste);
		     	 }
            
             }
            }
            if(trouve == 0)
             {
             	printf("              Le code paiement n'a pas ete trouve\n");
			 }
			   fclose(i);
               fclose(j);
               i = fopen("paiement.txt", "w"); 
               j = fopen("modpaiement.txt", "r"); 
               if(i != NULL && j != NULL)
                 {
             	   while(fscanf(j,"%s\t%s\t%s\t%d\t%d %d\t%d %s %d\t%d\t%d\n", (*p).relationedpaie.nom,(*p).relationedpaie.prenom,(*p).relationedpaie.filiere,&(*p).codepaie,&(*p).ann_univ.annee1,&(*p).ann_univ.annee2,&(*p).datepaie.jour,(*p).datepaie.mois,&(*p).datepaie.annee,&(*p).montpaie,&(*p).reste) != EOF)
                    {
                    	fprintf(i,"%s\t%s\t%s\t%d\t%d %d\t%d %s %d\t%d\t%d\n", (*p).relationedpaie.nom,(*p).relationedpaie.prenom,(*p).relationedpaie.filiere,(*p).codepaie,(*p).ann_univ.annee1,(*p).ann_univ.annee2,(*p).datepaie.jour,(*p).datepaie.mois,(*p).datepaie.annee,(*p).montpaie,(*p).reste);
					}
	
	
                 }
                 return (*p);
    }

paiement modifiercodepaie(){
	
	p=(paiement*)malloc(sizeof(paiement));
    FILE *b= fopen("paiement.txt", "r");
    FILE *c= fopen("modpaiement.txt", "w");
    int codepaie;
    int trouve = 0;

    if( b == NULL)
        printf("              Erreur lors de l'ouverture du fichier \n");
    else
     {
        printf("\n              Donner le code de paiement de l'etudiant que vous voulez modifier : ");
        scanf("%d",&codepaie);
        while(fscanf(b,"%s\t%s\t%s\t%d\t%d %d\t%d %s %d\t%d\t%d\n", (*p).relationedpaie.nom,(*p).relationedpaie.prenom,(*p).relationedpaie.filiere,&(*p).codepaie,&(*p).ann_univ.annee1,&(*p).ann_univ.annee2,&(*p).datepaie.jour,(*p).datepaie.mois,&(*p).datepaie.annee,&(*p).montpaie,&(*p).reste) != EOF)
            {
             if((*p).codepaie==codepaie)
             {
               trouve = 1;
               printf("              Donner le nouveau code de paiement : ");
               scanf("%d", &codepaie);
               (*p).codepaie=codepaie;
               fprintf(c,"%s\t%s\t%s\t%d\t%d %d\t%d %s %d\t%d\t%d\n",(*p).relationedpaie.nom,(*p).relationedpaie.prenom,(*p).relationedpaie.filiere,(*p).codepaie,(*p).ann_univ.annee1,(*p).ann_univ.annee2,(*p).datepaie.jour,(*p).datepaie.mois,(*p).datepaie.annee,(*p).montpaie,(*p).reste);
             }
             else
             {
               fprintf(c, "%s\t%s\t%s\t%d\t%d %d\t%d %s %d\t%d\t%d\n", (*p).relationedpaie.nom,(*p).relationedpaie.prenom,(*p).relationedpaie.filiere,(*p).codepaie,(*p).ann_univ.annee1,(*p).ann_univ.annee2,(*p).datepaie.jour,(*p).datepaie.mois,(*p).datepaie.annee,(*p).montpaie,(*p).reste);
             }
            }
            if(trouve == 0)
             {
             	printf("              Le code de paiement saisi n'a pas ete trouve\n");
			 }
			fclose(b);
            fclose(c);
            b = fopen("paiement.txt", "w"); 
            c = fopen("modpaiement.txt", "r"); 
            if(c != NULL && b != NULL)
             {
             	while(fscanf(c,"%s\t%s\t%s\t%d\t%d %d\t%d %s %d\t%d\t%d\n", (*p).relationedpaie.nom,(*p).relationedpaie.prenom,(*p).relationedpaie.filiere,&(*p).codepaie,&(*p).ann_univ.annee1,&(*p).ann_univ.annee2,&(*p).datepaie.jour,(*p).datepaie.mois,&(*p).datepaie.annee,&(*p).montpaie,&(*p).reste) != EOF)
                    {
                    	fprintf(b,"%s\t%s\t%s\t%d\t%d %d\t%d %s %d\t%d\t%d\n", (*p).relationedpaie.nom,(*p).relationedpaie.prenom,(*p).relationedpaie.filiere,(*p).codepaie,(*p).ann_univ.annee1,(*p).ann_univ.annee2,(*p).datepaie.jour,(*p).datepaie.mois,(*p).datepaie.annee,(*p).montpaie,(*p).reste);
					}
			 }
                
            else
             {
             	printf("              une erreur s est produite..!\n");
			 }
               fclose(b);
               fclose(c);
               remove("modpaiement.txt");
	
	
	
    }
    
    return (*p);
}
 	
paiement modifiermontpaie(){
	
	p=(paiement*)malloc(sizeof(paiement));
    FILE *b= fopen("paiement.txt", "r");
    FILE *c= fopen("modpaiement.txt", "w");
    int montpaie;
    int codepaie;
    int trouve = 0;

    if( b == NULL)
        printf("              Erreur lors de l'ouverture du fichier \n");
    else
     {
     	printf("\n              Donner le code de paiement : ");
        scanf("%d",&codepaie);
        /*printf("\nDonner le montant payer que vous voulez modifier : ");
        scanf("%d",&montpaie);*/
        while(fscanf(b,"%s\t%s\t%s\t%d\t%d %d\t%d %s %d\t%d\t%d\n", (*p).relationedpaie.nom,(*p).relationedpaie.prenom,(*p).relationedpaie.filiere,&(*p).codepaie,&(*p).ann_univ.annee1,&(*p).ann_univ.annee2,&(*p).datepaie.jour,(*p).datepaie.mois,&(*p).datepaie.annee,&(*p).montpaie,&(*p).reste) != EOF)
            {
             if(/*(*p).montpaie==montpaie*/(*p).codepaie==codepaie)
             {
               trouve = 1;
               printf("              Donner le nouveau montant : ");
               scanf("%d", &montpaie);
               (*p).montpaie=montpaie;
               fprintf(c,"%s\t%s\t%s\t%d\t%d %d\t%d %s %d\t%d\t%d\n",(*p).relationedpaie.nom,(*p).relationedpaie.prenom,(*p).relationedpaie.filiere,(*p).codepaie,(*p).ann_univ.annee1,(*p).ann_univ.annee2,(*p).datepaie.jour,(*p).datepaie.mois,(*p).datepaie.annee,(*p).montpaie,(*p).reste);
             }
             else
             {
               fprintf(c, "%s\t%s\t%s\t%d\t%d %d\t%d %s %d\t%d\t%d\n", (*p).relationedpaie.nom,(*p).relationedpaie.prenom,(*p).relationedpaie.filiere,(*p).codepaie,(*p).ann_univ.annee1,(*p).ann_univ.annee2,(*p).datepaie.jour,(*p).datepaie.mois,(*p).datepaie.annee,(*p).montpaie,(*p).reste);
             }
            }
            if(trouve == 0)
             {
             	printf("              Le code saisi n'a pas ete trouve\n");
			 }
			fclose(b);
            fclose(c);
            b = fopen("paiement.txt", "w"); 
            c = fopen("modpaiement.txt", "r"); 
            if(c != NULL && b != NULL)
             {
             	while(fscanf(c,"%s\t%s\t%s\t%d\t%d %d\t%d %s %d\t%d\t%d\n", (*p).relationedpaie.nom,(*p).relationedpaie.prenom,(*p).relationedpaie.filiere,&(*p).codepaie,&(*p).ann_univ.annee1,&(*p).ann_univ.annee2,&(*p).datepaie.jour,(*p).datepaie.mois,&(*p).datepaie.annee,&(*p).montpaie,&(*p).reste) != EOF)
                    {
                    	fprintf(b,"%s\t%s\t%s\t%d\t%d %d\t%d %s %d\t%d\t%d\n", (*p).relationedpaie.nom,(*p).relationedpaie.prenom,(*p).relationedpaie.filiere,(*p).codepaie,(*p).ann_univ.annee1,(*p).ann_univ.annee2,(*p).datepaie.jour,(*p).datepaie.mois,(*p).datepaie.annee,(*p).montpaie,(*p).reste);
					}
			 }
                
            else
             {
             	printf("              une erreur s est produite..!\n");
			 }
               fclose(b);
               fclose(c);
               remove("modpaiement.txt");
	
	
	
    }
    
    return (*p);
}
  	
paiement modifiereste(){
	
	p=(paiement*)malloc(sizeof(paiement));
    FILE *b= fopen("paiement.txt", "r");
    FILE *c= fopen("modpaiement.txt", "w");
    int reste;
    int codepaie;
    int trouve = 0;

    if( b == NULL)
        printf("Erreur lors de l'ouverture du fichier \n");
    else
     {
     	printf("\n              Donner le code de paiement : ");
        scanf("%d",&codepaie);
        /*printf("\nDonner le reste du montant que vous voulez modifier : ");
        scanf("%d",&reste);*/
        while(fscanf(b,"%s\t%s\t%s\t%d\t%d %d\t%d %s %d\t%d\t%d\n", (*p).relationedpaie.nom,(*p).relationedpaie.prenom,(*p).relationedpaie.filiere,&(*p).codepaie,&(*p).ann_univ.annee1,&(*p).ann_univ.annee2,&(*p).datepaie.jour,(*p).datepaie.mois,&(*p).datepaie.annee,&(*p).montpaie,&(*p).reste) != EOF)
            {
             if(/*(*p).reste==reste*/(*p).codepaie==codepaie)
             {
               trouve = 1;
               printf("              Donner le nouveau reste du montant : ");
               scanf("%d", &reste);
               (*p).reste=reste;
               fprintf(c,"%s\t%s\t%s\t%d\t%d %d\t%d %s %d\t%d\t%d\n",(*p).relationedpaie.nom,(*p).relationedpaie.prenom,(*p).relationedpaie.filiere,(*p).codepaie,(*p).ann_univ.annee1,(*p).ann_univ.annee2,(*p).datepaie.jour,(*p).datepaie.mois,(*p).datepaie.annee,(*p).montpaie,(*p).reste);
             }
             else
             {
               fprintf(c, "%s\t%s\t%s\t%d\t%d %d\t%d %s %d\t%d\t%d\n", (*p).relationedpaie.nom,(*p).relationedpaie.prenom,(*p).relationedpaie.filiere,(*p).codepaie,(*p).ann_univ.annee1,(*p).ann_univ.annee2,(*p).datepaie.jour,(*p).datepaie.mois,(*p).datepaie.annee,(*p).montpaie,(*p).reste);
             }
            }
            if(trouve == 0)
             {
             	printf("              Le code saisi n'a pas ete trouve\n");
			 }
			fclose(b);
            fclose(c);
            b = fopen("paiement.txt", "w"); 
            c = fopen("modpaiement.txt", "r"); 
            if(c != NULL && b != NULL)
             {
             	while(fscanf(c,"%s\t%s\t%s\t%d\t%d %d\t%d %s %d\t%d\t%d\n", (*p).relationedpaie.nom,(*p).relationedpaie.prenom,(*p).relationedpaie.filiere,&(*p).codepaie,&(*p).ann_univ.annee1,&(*p).ann_univ.annee2,&(*p).datepaie.jour,(*p).datepaie.mois,&(*p).datepaie.annee,&(*p).montpaie,&(*p).reste) != EOF)
                    {
                    	fprintf(b,"%s\t%s\t%s\t%d\t%d %d\t%d %s %d\t%d\t%d\n", (*p).relationedpaie.nom,(*p).relationedpaie.prenom,(*p).relationedpaie.filiere,(*p).codepaie,(*p).ann_univ.annee1,(*p).ann_univ.annee2,(*p).datepaie.jour,(*p).datepaie.mois,(*p).datepaie.annee,(*p).montpaie,(*p).reste);
					}
			 }
                
            else
             {
             	printf("              une erreur s est produite..!\n");
			 }
               fclose(b);
               fclose(c);
               remove("modpaiement.txt");
	
	
	
    }
    
    return (*p);
}

paiement modifierannepaie(){
	
	p=(paiement*)malloc(sizeof(paiement));
    FILE *i = fopen("paiement.txt", "r");
    FILE *j = fopen("modpaiement.txt", "w");
    int anne1;
    int anne2;
    int codepaie;
    int trouve = 0;

    if( i == NULL)
        printf("              Erreur lors de l'ouverture du fichier \n");
    else
     {
     	printf("\n              Donner le code de paiement : ");
        scanf("%d",&codepaie);
       /* printf("\nDonner l'annee 1 du paiement que vous voulez modifier : ");
        scanf("%d",&anne1);
        printf("\nDonner l'annee 2 du paiement que vous voulez modifier : ");
        scanf("%d",&anne2);*/
        while(fscanf(i,"%s\t%s\t%s\t%d\t%d %d\t%d %s %d\t%d\t%d\n", (*p).relationedpaie.nom,(*p).relationedpaie.prenom,(*p).relationedpaie.filiere,&(*p).codepaie,&(*p).ann_univ.annee1,&(*p).ann_univ.annee2,&(*p).datepaie.jour,(*p).datepaie.mois,&(*p).datepaie.annee,&(*p).montpaie,&(*p).reste) != EOF)
            {
             if(/*(*p).ann_univ.annee1==anne1 && (*p).ann_univ.annee2==anne2*/(*p).codepaie==codepaie)
               {
                 trouve = 1;
                 printf("              Donner la nouvelle annee1 : ");
                 scanf("%d",&anne1);
                 printf("              Donner la nouvelle annee2 : ");
                 scanf("%d",&anne2);
                 (*p).ann_univ.annee1=anne1;
                 (*p).ann_univ.annee2=anne2;
               
                fprintf(j,"%s\t%s\t%s\t%d\t%d %d\t%d %s %d\t%d\t%d\n",(*p).relationedpaie.nom,(*p).relationedpaie.prenom,(*p).relationedpaie.filiere,(*p).codepaie,(*p).ann_univ.annee1,(*p).ann_univ.annee2,(*p).datepaie.jour,(*p).datepaie.mois,(*p).datepaie.annee,(*p).montpaie,(*p).reste);
               }
             else
             {
               fprintf(j, "%s\t%s\t%s\t%d\t%d %d\t%d %s %d\t%d\t%d\n",(*p).relationedpaie.nom,(*p).relationedpaie.prenom,(*p).relationedpaie.filiere,(*p).codepaie,(*p).ann_univ.annee1,(*p).ann_univ.annee2,(*p).datepaie.jour,(*p).datepaie.mois,(*p).datepaie.annee,(*p).montpaie,(*p).reste);
             }
            }
            if(trouve == 0)
             {
             	printf("              Le code n'a pas ete trouve\n");
			 }
			fclose(i);
            fclose(j);
            i = fopen("paiement.txt", "w"); 
            j = fopen("modpaiement.txt", "r"); 
            if(j !=NULL && i !=NULL)
             {
             	while(fscanf(j,"%s\t%s\t%s\t%d\t%d %d\t%d %s %d\t%d\t%d\n", (*p).relationedpaie.nom,(*p).relationedpaie.prenom,(*p).relationedpaie.filiere,&(*p).codepaie,&(*p).ann_univ.annee1,&(*p).ann_univ.annee2,&(*p).datepaie.jour,(*p).datepaie.mois,&(*p).datepaie.annee,&(*p).montpaie,&(*p).reste) != EOF)
                    {
                    	fprintf(i,"%s\t%s\t%s\t%d\t%d %d\t%d %s %d\t%d\t%d\n",(*p).relationedpaie.nom,(*p).relationedpaie.prenom,(*p).relationedpaie.filiere,(*p).codepaie,(*p).ann_univ.annee1,(*p).ann_univ.annee2,(*p).datepaie.jour,(*p).datepaie.mois,(*p).datepaie.annee,(*p).montpaie,(*p).reste);
					}
			 }
                
            else
             {
             	printf("une erreur s'est produite..!\n");
			 }
               fclose(i);
               fclose(j);
               remove("modpaiement.txt");
	
	
	
    }
    
    return (*p);
}

paiement recherchernomrelationedpaie()
{
	p=(paiement*)malloc(sizeof(paiement));
    int trouve=0;
    int compte=0;
    FILE * f = fopen("paiement.txt", "r");
    char nomrech[25];
    printf("       Donner le nom a recherche : ");
    scanf("%s", nomrech);
    if(f == NULL)
        printf("Erreur lors de l'ouverture du fichier \n");
    else
    {
        while(fscanf(f,"%s\t%s\t%s\t%d\t%d %d\t%d %s %d\t%d\t%d\n", (*p).relationedpaie.nom,(*p).relationedpaie.prenom,(*p).relationedpaie.filiere,&(*p).codepaie,&(*p).ann_univ.annee1,&(*p).ann_univ.annee2,&(*p).datepaie.jour,(*p).datepaie.mois,&(*p).datepaie.annee,&(*p).montpaie,&(*p).reste)!= EOF )
              {
              	if(strcmp((*p).relationedpaie.nom, nomrech)==0)
              	  {
              	  	trouve= 1;
              	  	compte++;
              	  	printf("       Nom : %s\tPrenom  :%s\tFiliere : %s\tCode : %d\tAnnee : %d/%d\tDate Paiement : %d %s %d\tMontant Payer : %d\tReste : %d\n",(*p).relationedpaie.nom,(*p).relationedpaie.prenom,(*p).relationedpaie.filiere,(*p).codepaie,(*p).ann_univ.annee1,(*p).ann_univ.annee2,(*p).datepaie.jour,(*p).datepaie.mois,(*p).datepaie.annee,(*p).montpaie,(*p).reste);
		            }
              }
              
        fclose(f);
        printf("\n\n       Nombre de Paiement effectue : %d",compte);
	  
    }
    
 if(trouve == 0)
  {
  	printf("\n       le nom n'existe pas \n");
  }
     
	  
    
        
        return (*p);
}

paiement modifiernomrelationedpaie(){
	
	p=(paiement*)malloc(sizeof(paiement));
    FILE *b= fopen("paiement.txt", "r");
    FILE *c= fopen("modpaiement.txt", "w");
    char nom[25];
    int codepaie;
    int trouve = 0;

    if( b == NULL)
        printf("              Erreur lors de l'ouverture du fichier \n");
    else
     {
     	printf("\n              Donner le code de paiement : ");
        scanf("%d",&codepaie);
        /*printf("\nDonner le nom de l'etudiant que vous voulez modifier : ");
        scanf("%s",nom);*/
        while(fscanf(b,"%s\t%s\t%s\t%d\t%d %d\t%d %s %d\t%d\t%d\n", (*p).relationedpaie.nom,(*p).relationedpaie.prenom,(*p).relationedpaie.filiere,&(*p).codepaie,&(*p).ann_univ.annee1,&(*p).ann_univ.annee2,&(*p).datepaie.jour,(*p).datepaie.mois,&(*p).datepaie.annee,&(*p).montpaie,&(*p).reste) != EOF)
            {
             if(/*strcmp((*p).relationedpaie.nom,nom)==0*/(*p).codepaie==codepaie)
             {
               trouve = 1;
               printf("              Donner le nouveau nom de l'etudiant : ");
               scanf("%s", (*p).relationedpaie.nom);
               fprintf(c,"%s\t%s\t%s\t%d\t%d %d\t%d %s %d\t%d\t%d\n",(*p).relationedpaie.nom,(*p).relationedpaie.prenom,(*p).relationedpaie.filiere,(*p).codepaie,(*p).ann_univ.annee1,(*p).ann_univ.annee2,(*p).datepaie.jour,(*p).datepaie.mois,(*p).datepaie.annee,(*p).montpaie,(*p).reste);
             }
             else
             {
               fprintf(c, "%s\t%s\t%s\t%d\t%d %d\t%d %s %d\t%d\t%d\n", (*p).relationedpaie.nom,(*p).relationedpaie.prenom,(*p).relationedpaie.filiere,(*p).codepaie,(*p).ann_univ.annee1,(*p).ann_univ.annee2,(*p).datepaie.jour,(*p).datepaie.mois,(*p).datepaie.annee,(*p).montpaie,(*p).reste);
             }
            }
            if(trouve == 0)
             {
             	printf("              Le code saisi n'a pas ete trouve\n");
			 }
			fclose(b);
            fclose(c);
            b = fopen("paiement.txt", "w"); 
            c = fopen("modpaiement.txt", "r"); 
            if(c != NULL && b != NULL)
             {
             	while(fscanf(c,"%s\t%s\t%s\t%d\t%d %d\t%d %s %d\t%d\t%d\n", (*p).relationedpaie.nom,(*p).relationedpaie.prenom,(*p).relationedpaie.filiere,&(*p).codepaie,&(*p).ann_univ.annee1,&(*p).ann_univ.annee2,&(*p).datepaie.jour,(*p).datepaie.mois,&(*p).datepaie.annee,&(*p).montpaie,&(*p).reste) != EOF)
                    {
                    	fprintf(b,"%s\t%s\t%s\t%d\t%d %d\t%d %s %d\t%d\t%d\n", (*p).relationedpaie.nom,(*p).relationedpaie.prenom,(*p).relationedpaie.filiere,(*p).codepaie,(*p).ann_univ.annee1,(*p).ann_univ.annee2,(*p).datepaie.jour,(*p).datepaie.mois,(*p).datepaie.annee,(*p).montpaie,(*p).reste);
					}
			 }
                
            else
             {
             	printf("              une erreur s est produite..!\n");
			 }
               fclose(b);
               fclose(c);
               remove("modpaiement.txt");
	
	
	
    }
    
    return (*p);
}

paiement modifierprenomrelationedpaie(){
	
	p=(paiement*)malloc(sizeof(paiement));
    FILE *b= fopen("paiement.txt", "r");
    FILE *c= fopen("modpaiement.txt", "w");
    char prenom[25];
    int codepaie;
    int trouve = 0;

    if( b == NULL)
        printf("              Erreur lors de l'ouverture du fichier \n");
    else
     {
     	printf("\n              Donner le code de paiement : ");
        scanf("%d",&codepaie);
        /*printf("\nDonner le prenom de l'etudiant que vous voulez modifier : ");
        scanf("%s", prenom);*/
        while(fscanf(b,"%s\t%s\t%s\t%d\t%d %d\t%d %s %d\t%d\t%d\n", (*p).relationedpaie.nom,(*p).relationedpaie.prenom,(*p).relationedpaie.filiere,&(*p).codepaie,&(*p).ann_univ.annee1,&(*p).ann_univ.annee2,&(*p).datepaie.jour,(*p).datepaie.mois,&(*p).datepaie.annee,&(*p).montpaie,&(*p).reste) != EOF)
            {
             if(/*strcmp((*p).relationedpaie.prenom,prenom)==0*/(*p).codepaie==codepaie)
             {
               trouve = 1;
               printf("              Donner le nouveau prenom de l'etudiant : ");
               scanf("%s", (*p).relationedpaie.prenom);
               fprintf(c,"%s\t%s\t%s\t%d\t%d %d\t%d %s %d\t%d\t%d\n",(*p).relationedpaie.nom,(*p).relationedpaie.prenom,(*p).relationedpaie.filiere,(*p).codepaie,(*p).ann_univ.annee1,(*p).ann_univ.annee2,(*p).datepaie.jour,(*p).datepaie.mois,(*p).datepaie.annee,(*p).montpaie,(*p).reste);
             }
             else
             {
               fprintf(c, "%s\t%s\t%s\t%d\t%d %d\t%d %s %d\t%d\t%d\n", (*p).relationedpaie.nom,(*p).relationedpaie.prenom,(*p).relationedpaie.filiere,(*p).codepaie,(*p).ann_univ.annee1,(*p).ann_univ.annee2,(*p).datepaie.jour,(*p).datepaie.mois,(*p).datepaie.annee,(*p).montpaie,(*p).reste);
             }
            }
            if(trouve == 0)
             {
             	printf("              Le code saisi n'a pas ete trouve\n");
			 }
			fclose(b);
            fclose(c);
            b = fopen("paiement.txt", "w"); 
            c = fopen("modpaiement.txt", "r"); 
            if(c != NULL && b != NULL)
             {
             	while(fscanf(c,"%s\t%s\t%s\t%d\t%d %d\t%d %s %d\t%d\t%d\n", (*p).relationedpaie.nom,(*p).relationedpaie.prenom,(*p).relationedpaie.filiere,&(*p).codepaie,&(*p).ann_univ.annee1,&(*p).ann_univ.annee2,&(*p).datepaie.jour,(*p).datepaie.mois,&(*p).datepaie.annee,&(*p).montpaie,&(*p).reste) != EOF)
                    {
                    	fprintf(b,"%s\t%s\t%s\t%d\t%d %d\t%d %s %d\t%d\t%d\n", (*p).relationedpaie.nom,(*p).relationedpaie.prenom,(*p).relationedpaie.filiere,(*p).codepaie,(*p).ann_univ.annee1,(*p).ann_univ.annee2,(*p).datepaie.jour,(*p).datepaie.mois,(*p).datepaie.annee,(*p).montpaie,(*p).reste);
					}
			 }
                
            else
             {
             	printf("              une erreur s est produite..!\n");
			 }
               fclose(b);
               fclose(c);
               remove("modpaiement.txt");
	
	
	
    }
    
    return (*p);
}

paiement modifierfiliererelationedpaie(){
	
	p=(paiement*)malloc(sizeof(paiement));
    FILE *b= fopen("paiement.txt", "r");
    FILE *c= fopen("modpaiement.txt", "w");
    char filiere[25];
    int codepaie;
    int trouve = 0;

    if( b == NULL)
        printf("              Erreur lors de l'ouverture du fichier \n");
    else
     {
     	printf("\n              Donner le code de paiement : ");
        scanf("%d",&codepaie);
       /* printf("\nDonner la filiere de l'etudiant que vous voulez modifier : ");
        scanf("%s", filiere);*/
        while(fscanf(b,"%s\t%s\t%s\t%d\t%d %d\t%d %s %d\t%d\t%d\n", (*p).relationedpaie.nom,(*p).relationedpaie.prenom,(*p).relationedpaie.filiere,&(*p).codepaie,&(*p).ann_univ.annee1,&(*p).ann_univ.annee2,&(*p).datepaie.jour,(*p).datepaie.mois,&(*p).datepaie.annee,&(*p).montpaie,&(*p).reste) != EOF)
            {
             if(/*strcmp((*p).relationedpaie.filiere,filiere)==0*/(*p).codepaie==codepaie)
             {
               trouve = 1;
               printf("              Donner la nouvelle filiere de l'etudiant : ");
               scanf("%s", (*p).relationedpaie.filiere);
               fprintf(c,"%s\t%s\t%s\t%d\t%d %d\t%d %s %d\t%d\t%d\n",(*p).relationedpaie.nom,(*p).relationedpaie.prenom,(*p).relationedpaie.filiere,(*p).codepaie,(*p).ann_univ.annee1,(*p).ann_univ.annee2,(*p).datepaie.jour,(*p).datepaie.mois,(*p).datepaie.annee,(*p).montpaie,(*p).reste);
             }
             else
             {
               fprintf(c, "%s\t%s\t%s\t%d\t%d %d\t%d %s %d\t%d\t%d\n", (*p).relationedpaie.nom,(*p).relationedpaie.prenom,(*p).relationedpaie.filiere,(*p).codepaie,(*p).ann_univ.annee1,(*p).ann_univ.annee2,(*p).datepaie.jour,(*p).datepaie.mois,(*p).datepaie.annee,(*p).montpaie,(*p).reste);
             }
            }
            if(trouve == 0)
             {
             	printf("              Le code saisi n'a pas ete trouve\n");
			 }
			fclose(b);
            fclose(c);
            b = fopen("paiement.txt", "w"); 
            c = fopen("modpaiement.txt", "r"); 
            if(c != NULL && b != NULL)
             {
             	while(fscanf(c,"%s\t%s\t%s\t%d\t%d %d\t%d %s %d\t%d\t%d\n", (*p).relationedpaie.nom,(*p).relationedpaie.prenom,(*p).relationedpaie.filiere,&(*p).codepaie,&(*p).ann_univ.annee1,&(*p).ann_univ.annee2,&(*p).datepaie.jour,(*p).datepaie.mois,&(*p).datepaie.annee,&(*p).montpaie,&(*p).reste) != EOF)
                    {
                    	fprintf(b,"%s\t%s\t%s\t%d\t%d %d\t%d %s %d\t%d\t%d\n", (*p).relationedpaie.nom,(*p).relationedpaie.prenom,(*p).relationedpaie.filiere,(*p).codepaie,(*p).ann_univ.annee1,(*p).ann_univ.annee2,(*p).datepaie.jour,(*p).datepaie.mois,(*p).datepaie.annee,(*p).montpaie,(*p).reste);
					}
			 }
                
            else
             {
             	printf("              une erreur s est produite..!\n");
			 }
               fclose(b);
               fclose(c);
               remove("modpaiement.txt");
	
	
	
    }
    
    return (*p);
}

  	
paiement modifierfiliererelationedpaie();paiement modifierprenomrelationedpaie();paiement modifiernomrelationedpaie();paiement recherchernomrelationedpaie();paiement modifierannepaie();paiement modifiereste();paiement ecrirepaie();paiement lirpaie();paiement afficherpaie();paiement supprimerpaie();paiement modifierdatepaie();paiement modifiercodepaie();paiement modifiermontpaie();
