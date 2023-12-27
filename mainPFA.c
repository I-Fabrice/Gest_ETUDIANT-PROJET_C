#include <stdio.h>
#include <stdlib.h>  
#include <string.h>
#include "date.h"
#include "annee.h"
#include "etudiant.h"
#include "Etudiant_manager.h"
#include "Absence.h"
#include "Certification.h"
#include "matiere.h"
#include "paiement.h"
#include "connexion.h"
#include "Matiere_manager.h"
#include "Paiement_manager.h"
#include "Absence_manager.h"
#include "Certification_manager.h"
#include "Manager_connexion.h"


/* run this program using the console pauser or add your own getch, system("pause") or input loop */
absence ecrireabs();absence lireabs();absence afficheabs();absence supprimerabs();absence modifiercodeabs();absence modifierheurabs();absence modifierdateabs();absence recherchernomrelationedabs();absence modifierprenomrelationedabs();absence modifierfilierelationdeabs();absence modifiernomrelationedabs();certification ecrirecertif();certification lirecertif();certification affichercertif();certification supprimercert();certification modifiernomcert();certification modifiercodecertif();certification modifierdateobt();certification modifierannecertif();certification recherchernomrelationcert();certification modifierprenomrelationcert();certification modifiernomrelationcert();certification modifierfiliererelationcert();etudiant liretudiant();etudiant ecriretudiant();etudiant afficheretudiant();etudiant supprimered();etudiant modifierdatetudiant();etudiant modifieridetudiant();etudiant modifiernumtel();etudiant modifiernom();etudiant modifierprenom();etudiant modifierfiliere();etudiant modifiermail();etudiant recherchernom();matiere ecriremat();matiere liremat();matiere affichermat();matiere supprimermat();matiere modifiernomrelationedmat();matiere modifierprenomrelationedmat();matiere modifierfiliererelationedmat();matiere modifiernote();matiere recherchernomrelationedmat();matiere modifieridmat();matiere modifiercoef();matiere modifiernomat();matiere modifiernomod();paiement modifierfiliererelationedpaie();paiement modifierprenomrelationedpaie();paiement modifiernomrelationedpaie();paiement recherchernomrelationedpaie();paiement modifierannepaie();paiement modifiereste();paiement ecrirepaie();paiement lirpaie();paiement afficherpaie();paiement supprimerpaie();paiement modifierdatepaie();paiement modifiercodepaie();paiement modifiermontpaie();
int main(){
    
	 
    
   
     char choix;
     int choix2;
     printf("       A.	Espace administration\n");
	 printf("       B.	Espace etudiant\n\n");
	 do
	   {
	    printf("       Entrez votre choix : ");
	    scanf("%s",&choix);
	    }while(choix!='A' && choix!='a' && choix!='B' && choix!='b');

		   if(choix=='A' || choix=='a' )
	         {
	          printf("\n\n       *********************\n       Espace Administration\n       *********************\n\n");
	       	  printf("       A.	Directeur\n");
              printf("       B.	Le Service comptabilite\n");
              printf("       C.	Responsable de la vie scolaire\n");
              printf("       D.	Espace professeur\n\n");
             
              
			 
               do
                {
                	printf("       Entrez votre choix : ");
	                scanf("%s",&choix);
	            }while(choix!='A' && choix!='a' && choix!='B' && choix!='b' && choix!='C' && choix!='c' && choix!='D' && choix!='d');
	                 /*espace directeur*/
	                if(choix=='A' || choix=='a')
	                  {
	            	    printf("\n\n       *****************\n       Espace Directeur\n       *****************\n\n");
			     	    connectionmdp();
					    printf( "       A.	Voir les informations d'un etudiant\n");
                        printf( "       B.	Voir les notes d'un etudiant\n");
                        printf( "       C.	Voir les certifications d'un etudiant\n");
                        printf( "       D.	Voir les absences d'un etudiant\n");
                        printf( "       E.	Voir les informations relatives au paiement d'un etudiant\n");
                        printf( "       F.	Changer le mot de passe d'acces a son espace\n");
                      do
                       {
					   do
                        {
                        	printf("\n       Entrez votre choix : ");
	                        scanf("%s",&choix);
	                    }while(choix!='A' && choix!='a' && choix!='B' && choix!='b' && choix!='C' && choix!='c' && choix!='D' && choix!='d' && choix!='E' && choix!='e' && choix!='F' && choix!='f');
			     	   
			     	    if(choix=='A' || choix=='a')
			     	       {
			     	       	recherchernom();
						   }
					    else if(choix=='B' || choix=='b')
					      {
					      	recherchernomrelationedmat();
						  }
					    else if(choix=='C' || choix=='c')
			             {
			     	        recherchernomrelationcert();
				          }
			     	    else if(choix=='D' || choix=='d')
			             {
			             	recherchernomrelationedabs();
			               }
			            else if(choix=='E' || choix=='e')
			             {
			             	recherchernomrelationedpaie();
			               }
			            else if(choix=='F' || choix=='f')
			              {
			             	modifiermotdepasse();
			               }
			            
			             do
			              {
				           printf("   \n\n       Tapez 1 pour effectuer une autre tache ou Tapez 2 pour sortir du terminal : ");
	                       scanf("%d",&choix2);
	                      }while(choix2!=1 && choix2!=2 );
	                     if(choix2==2)
	                      {
	                  	  exit(1);
					      }
					    }while(choix2==1);
				      }
				      /*service comptabilité*/
			        else if(choix=='B' || choix=='b')
			         {
			     	  printf("\n\n       *********************\n       Service Comptabilite\n       *********************\n\n");
			     	  connectionmdp();
			     	  printf("       A.	Ajouter paiement\n");
			     	  printf("       B.	Afficher la liste de paiement\n");
			     	  printf("       C.	Rechercher paiement\n");
			     	  printf("       D.	Supprimer paiement\n");
			     	  printf("       E.	Modifier paiement\n");
			     	  printf("       F.	Changer le mot de passe d'acces a son espace\n\n");
			     	 
			     	 do
			     	 {
					   
			     	  do
                       {
                       	printf("       Entrez votre choix : ");
	                    scanf("%s",&choix);
	                   }while(choix!='A' && choix!='a' && choix!='B' && choix!='b' && choix!='C' && choix!='c' && choix!='D' && choix!='d' && choix!='E' && choix!='e' && choix!='F' && choix!='f');
			     	   
			     	  if(choix=='A' || choix=='a')
			     	     {
			     	     	lirpaie();
						  }
					  else if(choix=='B' || choix=='b')
					      {
					      	afficherpaie();
						  }
					  else if(choix=='C' || choix=='c')
			             {
			             	recherchernomrelationedpaie();
				          }
			     	  else if(choix=='D' || choix=='d')
			             {
			                supprimerpaie();
			            }
			            else if(choix=='E' || choix=='e')
			               {
			               	printf("\n\n              A.	Modifier la date d'un paiement\n");
			     	        printf("              B.	Modifier le code d'un paiement\n");
			     	        printf("              C.	Modifier le montant d'un paiement\n");
			     	        printf("              D.	Modifier le reste d'un paiement\n");
			     	        printf("              E.	Modifier l'annee d'un paiement\n");
			     	        printf("              F.	Modifier le nom d'un Etudiant\n");
			     	        printf("              G.	Modifier le prenom d'un Etudiant\n");
			     	        printf("              H.	Modifier la filiere d'un paiement\n");
			     	        do
                             {
                       	     printf("\n\n              Entrez votre choix : ");
	                         scanf("%s",&choix);
	                         }while(choix!='A' && choix!='a' && choix!='B' && choix!='b' && choix!='C' && choix!='c' && choix!='D' && choix!='d' && choix!='E' && choix!='e' && choix!='F' && choix!='f' && choix!='G' && choix!='g' && choix!='H' && choix!='h');
				            
				            if(choix=='A' || choix=='a')
			                   {
			     	            modifierdatepaie();
				                }
				            else if(choix=='B' || choix=='b')
			                  {
			     	            modifiercodepaie();
				                }
				            else if(choix=='C' || choix=='c')
			                  {
			     	           modifiermontpaie();
				                }
				           else if(choix=='D' || choix=='d')
			                  {
			     	           modifiereste();
				                }
				           else if(choix=='E' || choix=='e')
			                  {
			     	            modifierannepaie();
				                }
				            else if(choix=='F' || choix=='f')
			                  {
			     	           modifiernomrelationedpaie();
				                }
				            else if(choix=='G' || choix=='g')
			                  {
			     	            modifierprenomrelationedpaie();
				                }
				            else if(choix=='H' || choix=='h')
			                  {
			     	           modifierfiliererelationedpaie();
				              }
						   }
						else if(choix=='F' || choix=='f')
			               {
			                 modifiermotdepasse();
			               }
			            do
			             {
				          printf("   \n\n       Tapez 1 pour effectuer une autre tache ou Tapez 2 pour sortir du terminal : ");
	                      scanf("%d",&choix2);
	                     }while(choix2!=1 && choix2!=2 );
	                   
	                    if(choix2==2)
	                     {
	                  	  exit(1);
					     }
				      }while(choix2==1);
				    }
				     /*responsable de la vie scolaire*/
			        else if(choix=='C' || choix=='c')
			         {
			     	  printf("\n\n       *****************\n       Services scolaire\n       *****************\n\n");
			     	  connectionmdp();
			     	  
			     	  
                      printf("\n       A.	Ajouter un etudiant\n");
                      printf("       B.	Afficher la liste etudiant\n");
					  printf("       C.	Modifier les informations d'un etudiant\n");
					  printf("       D.	Supprimer un etudiant\n");
					  printf("       E.	Rechercher un etudiant\n");
                      printf("       F.	Definir un nouvel identifiant\n");
                      printf("       G.	Voir les absences d'un etudiant\n");
                      printf("       H.	Voir les notes d'un etudiants\n");
                      printf("       I.	Voir les informations relatives au paiement d'un etudiant\n");
                      printf("       J.	Changer le mot de passe d'acces a son compte\n\n");
                      do
					   {
						   
                           do
                            {
                       	    printf("\n\n              Entrez votre choix : ");
	                        scanf("%s",&choix);
	                        }while(choix!='A' && choix!='a' && choix!='B' && choix!='b' && choix!='C' && choix!='c' && choix!='D' && choix!='d' && choix!='E' && choix!='e' && choix!='F' && choix!='f' && choix!='G' && choix!='g' && choix!='H' && choix!='h'&& choix!='I' && choix!='i' && choix!='J' && choix!='j');
				            
                        
                        
                           if(choix=='A' || choix=='a')
			                  {
			     	            liretudiant();
			     	            ecriretudiant();
				               }
				           else if(choix=='B' || choix=='b')
			                  {
			     	            afficheretudiant();
				                }
				           else if(choix=='C' || choix=='c')
			                  {
			     	            printf("\n\n              A.	Modifier la date d'inscription\n");
			     	            printf("              B.	Modifier l'identifiant d'un etudiant\n");
			     	            printf("              C.	Modifier le numero de telephone d'un etudiant\n");
			     	            printf("              D.	Modifier l'adresse electronique d'un etudiant\n");
			     	            printf("              E.	Modifier la filiere d'un etudiant\n");
			     	            printf("              F.	Modifier le nom d'un Etudiant\n");
			     	            printf("              G.	Modifier le prenom d'un Etudiant\n");
			     	           
                                do
                                 {
                       	          printf("\n\n              Entrez votre choix : ");
	                              scanf("%s",&choix);
	                              }while(choix!='A' && choix!='a' && choix!='B' && choix!='b' && choix!='C' && choix!='c' && choix!='D' && choix!='d' && choix!='E' && choix!='e' && choix!='F' && choix!='f' && choix!='G' && choix!='g');
				            
                                
                                if(choix=='A' || choix=='a')
			                      {
			     	               modifierdatetudiant();
				                  }
				                else if(choix=='B' || choix=='b')
			                      {
			     	               modifieridetudiant();
				                  }
				                else if(choix=='C' || choix=='c')
			                     {
			     	              modifiernumtel();
				                 }
				                else if(choix=='D' || choix=='d')
			                     {
			     	              modifiermail();
				                 }
				                else if(choix=='E' || choix=='e')
			                     {
			     	              modifierfiliere();
				                 }
				                else if(choix=='F' || choix=='f')
			                     {
			     	              modifiernom();
				                }
				                else if(choix=='G' || choix=='g')
			                      {
			     	               modifierprenom();
				                   }
				                   
				              }
				           else if(choix=='D' || choix=='d')
			                  {
			     	           supprimered();
				                }
				           else if(choix=='E' || choix=='e')
			                  {
			                  	recherchernom();
				                }
				            else if(choix=='F' || choix=='f')
			                  {
			                  	liremdp();
			     	            ecriremdp();
				                }
				            else if(choix=='G' || choix=='g')
			                  {
			                  	recherchernomrelationedabs();
				                }
				            else if(choix=='H' || choix=='h')
			                  {
			                  	recherchernomrelationedmat();
				                }
				            else if(choix=='I' || choix=='i')
			                     {
			                      recherchernomrelationedpaie();
						         }
						    else if(choix=='J' || choix=='j')
						         {
						         	modifiermotdepasse();
								 }
						         
						    
							 do
			                  {
				              printf("   \n\n       Tapez 1 pour effectuer une autre tache ou Tapez 2 pour sortir du terminal : ");
	                          scanf("%d",&choix2);
	                          }while(choix2!=1 && choix2!=2 );
	                         if(choix2==2)
	                           {
	                  	       exit(1);
					           }
				        }while(choix2==1);     
				     }
				      /*espace professeur*/
			        else if(choix=='D' || choix=='d')
			         {
			         	printf("\n\n       *****************\n       Espace Professeur\n       *****************\n\n");
	       	            connectionmdp();
			            printf("       A.	Service Certification\n");	
			            printf("       B.	Service Absence\n");
			            printf("       C.	Service Matiere\n");
			            printf("       D.	Changer le mot de passe d'acces a son espace\n\n");
			         do
					  {
					    
				        do
			             {
				         printf("   \n\n       Entrez votre choix : ");
	                     scanf("%s",&choix);
	                     }while(choix!='A' && choix!='a' && choix!='B' && choix!='b' && choix!='C' && choix!='c' && choix!='D' && choix!='d');
	                    /*premier choix*/
	                    if(choix=='A' || choix=='a')
	                       {
						     printf("\n       A.	Ajouter certification(s)\n");
			     	         printf("       B.	Afficher la liste certification\n");
			     	         printf("       C.	Rechercher certification(s)\n");
					         printf("       D.	Supprimer certifiaction(s)\n");
					         printf("       E.	Modifier certification(s)\n");
	
				               do
			                    {
				                printf("   \n\n       Entrez votre choix : ");
	                            scanf("%s",&choix);
	                            }while(choix!='A' && choix!='a' && choix!='B' && choix!='b' && choix!='C' && choix!='c' && choix!='D' && choix!='d' && choix!='E' && choix!='e');
	                        
							if(choix=='A' || choix=='a')
	                          {
	       	                    lirecertif();
		                      }
		                    else if(choix=='B' || choix=='b')
	                          {
	                          	affichercertif();
		                      }
		                    else if(choix=='C' || choix=='c')
	                          {
	                          	recherchernomrelationcert();
		                      }
		                    else if(choix=='D' || choix=='d')
	                          {
	       	                    supprimercert();
		                       }
		                    else if(choix=='E' || choix=='e')
	                          {
	                          	printf("\n              A.	Modifier le nom d'un Etudiant\n");
			     	            printf("              B.	Modifier le prenom d'un Etudiant\n");
			     	            printf("              C.	Modifier l'identifiant\n");
			     	            printf("              D.	Modifier le nom de la certification\n");
			     	            printf("              E.	Modifier la filiere d'un etudiant\n");
	       	                    printf("              F.	Modifier la date\n");
			     	            printf("              G.	Modifier l'annee\n");
			     	            
			     	               do
                                    {
                       	             printf("\n\n              Entrez votre choix : ");
	                                 scanf("%s",&choix);
	                                }while(choix!='A' && choix!='a' && choix!='B' && choix!='b' && choix!='C' && choix!='c' && choix!='D' && choix!='d' && choix!='E' && choix!='e' && choix!='F' && choix!='f' && choix!='G' && choix!='g');
				            
			     	            
                                if(choix=='A' || choix=='a')
			                      {
			     	               modifiernomrelationcert();
				                  }
				                else if(choix=='B' || choix=='b')
			                      {
			     	               modifierprenomrelationcert();
				                  }
				                else if(choix=='C' || choix=='c')
			                     {
			     	              modifiercodecertif();
				                 }
				                else if(choix=='D' || choix=='d')
			                     {
			     	              modifiernomcert();
				                 }
				                else if(choix=='E' || choix=='e')
			                     {
			     	              modifierfiliererelationcert();
				                 }
				                else if(choix=='F' || choix=='f')
			                     {
			     	              modifierdateobt();
				                }
				                else if(choix=='G' || choix=='g')
			                      {
			     	               modifierannecertif();
				                   }
			     	            
			     	            
			     	            
		                       }
					        
					       }
					    /*second choix*/
					    else if(choix=='B' || choix=='b')
					        {
					        	printf("\n       A.	Ajouter absence(s)\n");
			     	            printf("       B.	Afficher absence(s)\n");
			     	            printf("       C.	Rechercher absence(s)\n");
					            printf("       D.	Supprimer absence(s)\n");
					            printf("       E.	Modifier absence(s)\n");
					            
					               do
			                        {
				                    printf("   \n\n       Entrez votre choix : ");
	                                scanf("%s",&choix);
	                                }while(choix!='A' && choix!='a' && choix!='B' && choix!='b' && choix!='C' && choix!='c' && choix!='D' && choix!='d' && choix!='E' && choix!='e');
	                            

								if(choix=='A' || choix=='a')
	                              {
	       	                        lireabs();
		                           }
		                        else if(choix=='B' || choix=='b')
	                              {
	                          	    afficheabs();
		                          }
		                        else if(choix=='C' || choix=='c')
	                              {
	                              	recherchernomrelationedabs();
		                          }
		                        else if(choix=='D' || choix=='d')
	                              {
	       	                        supprimerabs();
		                          }
		                        else if(choix=='E' || choix=='e')
	                               {
	       	                         	printf("\n              A.	Modifier le nom d'un Etudiant\n");
			     	                    printf("              B.	Modifier le prenom d'un Etudiant\n");
			     	                    printf("              C.	Modifier le code absence\n");
			     	                    printf("              D.	Modifier la filiere\n");
			     	                    printf("              E.	Modifier la date\n");
	       	                            printf("              F.	Modifier l'heure\n");
			     	                    
			     	                    do
			                              {
				                              printf("   \n\n              Entrez votre choix : ");
	                                          scanf("%s",&choix);
	                                      }while(choix!='A' && choix!='a' && choix!='B' && choix!='b' && choix!='C' && choix!='c' && choix!='D' && choix!='d' && choix!='E' && choix!='e' && choix!='F' && choix!='f');
	                            
	                                    if(choix=='A' || choix=='a')
			                              {
			     	                        modifiernomrelationedabs();
				                          }
				                        else if(choix=='B' || choix=='b')
			                             {
			     	                        modifierprenomrelationedabs();
				                         }
				                        else if(choix=='C' || choix=='c')
			                             {
			     	                        modifiercodeabs();
				                          }
				                        else if(choix=='D' || choix=='d')
			                             {
			     	                       modifierfilierelationdeabs();
				                         }
				                        else if(choix=='E' || choix=='e')
			                             {
			     	                       modifierdateabs();
				                         }
				                        else if(choix=='F' || choix=='f')
			                              {
			     	                        modifierheurabs();
				                            }
	                            
		                            }
		                            
		                            
							}
					    /*troisieme choix*/
						else if(choix=='C' || choix=='c')
					        {
					        	printf("\n       A.	Ajouter Matiere(s)\n");
			     	        	printf("       B.	Afficher Matiere(s)\n");
			     	        	printf("       C.	Rechercher Matiere(s)\n");
					        	printf("       D.	Supprimer Matiere(s)\n");
					        	printf("       E.	Modifier Matiere(s)\n");
					        	
					        	    do
			                          {
				                      printf("   \n\n       Entrez votre choix : ");
	                                  scanf("%s",&choix);
	                                 }while(choix!='A' && choix!='a' && choix!='B' && choix!='b' && choix!='C' && choix!='c' && choix!='D' && choix!='d' && choix!='E' && choix!='e');
	                            
								if(choix=='A' || choix=='a')
	                              {
	       	                        liremat();
		                           }
		                        else if(choix=='B' || choix=='b')
	                              {
	                          	    affichermat();
		                          }
		                        else if(choix=='C' || choix=='c')
	                              {
	                              	recherchernomrelationedmat();
		                          }
		                        else if(choix=='D' || choix=='d')
	                              {
	       	                        supprimermat();
		                          }
		                        else if(choix=='E' || choix=='e')
	                               {
	       	                           	printf("\n              A.	Modifier nom etudiant\n");
			     	        	        printf("              B.	Modifier prenom etudiant\n");
			     	        	        printf("              C.	Modifier filiere\n");
					        	        printf("              D.	Modifier note\n");
					        	        printf("              E.	Modifier identifiant matiere\n");
					        	        printf("              F.	Modifier coefficient\n");
			     	        	        printf("              G.	Modifier nom matiere\n");
			     	        	        printf("              H.	Modifier nom module\n");
			     	        	        
					        	        
					        	         do
			                               {
				                           printf("   \n\n              Entrez votre choix : ");
	                                       scanf("%s",&choix);
	                                       }while(choix!='A' && choix!='a' && choix!='B' && choix!='b' && choix!='C' && choix!='c' && choix!='D' && choix!='d' && choix!='E' && choix!='e' && choix!='F' && choix!='f' && choix!='G' && choix!='g' && choix!='H' && choix!='h');
	                        
	                        
                                        if(choix=='A' || choix=='a')
	                                       {
	       	                                 modifiernomrelationedmat();
		                                   }
		                                else if(choix=='B' || choix=='b')
	                                      {
	                          	           modifierprenomrelationedmat();
		                                  }
		                                else if(choix=='C' || choix=='c')
	                                       {
	                              	        modifierfiliererelationedmat();
		                                   }
		                                else if(choix=='D' || choix=='d')
	                                      {
	       	                                modifiernote();
		                                   }
		                                 else if(choix=='E' || choix=='e')
	                                      {
	       	                                modifieridmat();
		                                   }
		                                 else if(choix=='F' || choix=='f')
	                                      {
	       	                                modifiercoef();
		                                   }
		                                else if(choix=='G' || choix=='g')
	                                      {
	       	                                modifiernomat();
		                                   }
		                                else if(choix=='H' || choix=='h')
	                                      {
	       	                                modifiernomod();
		                                   }

		                            }
                            }
                            
                        else if(choix=='D' || choix=='d')
                            {
                             modifiermotdepasse();	
							}
						
						do
			             {
				         printf("   \n\n       Tapez 1 pour effectuer une autre tache ou Tapez 2 pour sortir du terminal : ");
	                     scanf("%d",&choix2);
	                     }while(choix2!=1 && choix2!=2 );
	                    if(choix2==2)
	                     {
	                    	exit(1);
					      }
	               
                      }while(choix2==1);	
							
				    }
			   
			  
		     }
		     
		     /*espace etudiant*/
	         else if(choix=='B' || choix=='b')
	           {
	       	 
				printf("\n\n       ***************\n       Espace etudiant\n       ***************\n\n");
	       	    connectionmdp();
	       	
					 
                     printf("       A.	Acceder a vos notes\n");
                     printf("       B.	Acceder a vos absences\n");
                     printf("       C.	Acceder a vos paiements\n");
                     printf("       D.	Acceder a vos certifications\n");
                     printf("       E.	Changer le mot de passe d'accès à son compte\n\n");
                
                  
                do
                  {
				  
				   do
			        {
				    printf("   \n\n       Entrez votre choix : ");
	                scanf("%s",&choix);
	                }while(choix!='A' && choix!='a' && choix!='B' && choix!='b' && choix!='C' && choix!='c' && choix!='D' && choix!='d' && choix!='E' && choix!='e');
	               
	               
	             
	              
					 if(choix=='A' || choix=='a')
	                  {
	       	           recherchernomrelationedmat();
		              }
		             else if(choix=='B' || choix=='b')
	                   {
	       	            recherchernomrelationedabs();
		                }
		             else if(choix=='C' || choix=='c')
	                   {
	       	            recherchernomrelationedpaie();
		                }
		             else if(choix=='D' || choix=='d')
	                   {
	       	            recherchernomrelationcert();
		                }
		             else if(choix=='E' || choix=='e')
			            {
			             modifiermotdepasse();
						 }
		              
		              
					   
		            
		           do
			        {
				    printf("   \n\n       Tapez 1 pour effectuer une autre tache ou Tapez 2 pour sortir du terminal : ");
	                scanf("%d",&choix2);
	                }while(choix2!=1 && choix2!=2 );
	                if(choix2==2)
	                  {
	                  	exit(1);
					  }
	               
                  }while(choix2==1);
		       }
    
       
    
	   
	
	 
	return 0;
}
