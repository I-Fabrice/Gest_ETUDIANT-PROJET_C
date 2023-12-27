




motdepasse liremdp(){
	
	printf("Donner l'identifiant de votre compte : ");
	scanf("%d",&mo.idmdp);
	printf("Donner le mot de passe de votre compte : ");
	scanf("%s",mo.mdp);
	
	return (mo);
}

motdepasse ecriremdp(){
	
	FILE *r;
	r=fopen("motdepasse.txt","a");
	if(r==NULL)
       printf(" erreur d'ouverture du fichier");
	else
	 {
	 	fprintf(r,"\n%d\t%s",mo.idmdp,mo.mdp);
	  }	
	fclose(r);
	
	return (mo);
}

motdepasse affichermdp(){
	
	FILE *r;
	r=fopen("motdepasse.txt","r");
	if(r==NULL)
	  printf(" erreur d'ouverture du fichier");
	else
	  {
	  	while(fscanf(r,"\n%d\t%s",&mo.idmdp,mo.mdp)!=EOF)
	  	    {
	  	    	printf("\n%d\t%s",mo.idmdp,mo.mdp);
			  }
	  }
	
	fclose(r);
	
	return (mo);
	
}

motdepasse connectionmdp(){
	
	
    int idmdp;
    char mdp[10];
    int trouve;
     	do
     	 {
	      
	      trouve=0;
          printf("\n       Saisissez l'identifiant de votre compte : ");
          scanf("%d",&idmdp);
          printf("       Saisissez le mot de passe de votre compte : ");
          scanf("%s",mdp);
          FILE *r= fopen("motdepasse.txt", "r");
          while(fscanf(r,"%d\t%s",&mo.idmdp,mo.mdp)!=EOF)
            {
             if(mo.idmdp==idmdp && strcmp(mo.mdp,mdp)==0)
             {
               trouve=1;
             }
               
            }
            fclose(r); 
            if(trouve==0)
              {
              	printf("\n       Le mot de passe ou/et l'identifiant saisi sont incorrects\n");
                printf("       Tapez 0 pour saisir de nouvaeu vos identifiants sinon appuiyez sur 1 pour sortir du terminal : ");
			    scanf("%d",&trouve);
			    if(trouve==1)
                   {
             	     exit(0);
			       }     
			  }
			else
			    {
				 printf("\n\n       connexion reussi\n\n");
			    }
			     
            
              
			
			 
		  }while(trouve!=1);
		  
	
	return (mo);
    
    
	
}
	
motdepasse modifiermotdepasse(){
	
	
    FILE *b= fopen("motdepasse.txt", "r");
    FILE *c= fopen("modmotdepasse.txt", "w");
    int idmdp;
    char mdp[10];
    int trouve = 0;

    if( b == NULL)
        printf("Erreur lors de l'ouverture du fichier \n");
    else
     {
        printf("\n       Donner l'identifiant de votre mot de passe : ");
        scanf("%d",&idmdp);
        printf("       Donner le mot de passe de votre compte : ");
    	scanf("%s",mdp);
        while(fscanf(b,"\n%d\t%s", &mo.idmdp,mo.mdp) != EOF)
            {
             if(mo.idmdp==idmdp && strcmp(mo.mdp,mdp)==0 )
             {
               trouve = 1;
               printf("       Donner le nouvel identifiant de votre compte : ");
	           scanf("%d",&mo.idmdp);
	           printf("       Donner le nouveau mot de passe de votre compte : ");
	           scanf("%s",mo.mdp);
               fprintf(c,"\n%d\t%s",mo.idmdp,mo.mdp);
             }
             else
             {
               fprintf(c, "\n%d\t%s", mo.idmdp,mo.mdp);
             }
            }
            if(trouve == 0)
             {
             	printf("       L'identifiant et/ou le mot de passe saisi est incorrect\n");
			 }
			fclose(b);
            fclose(c);
            b = fopen("motdepasse.txt", "w"); 
            c = fopen("modmotdepasse.txt", "r"); 
            if(c != NULL && b != NULL)
             {
             	while(fscanf(c,"\n%d\t%s", &mo.idmdp,mo.mdp) != EOF)
                    {
                    	fprintf(b,"\n%d\t%s", mo.idmdp,mo.mdp);
					}
			 }
                
            else
             {
             	printf("       une erreur s est produite..!\n");
			 }
               fclose(b);
               fclose(c);
               remove("modmotdepasse.txt");
	
	
	
    }
    
    return (mo);
}
