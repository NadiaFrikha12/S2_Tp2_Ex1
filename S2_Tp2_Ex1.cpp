#include<stdio.h>
#include<string.h>
#include<stdlib.h>


typedef struct{
	char rue[20]; //nom de la rue
	int code_postal; // numero du code postal
	char ville[20]; //nom de la ville
}adr;

typedef struct{
	int jour; //jour de naissance 
	int mois; //mois de naissance
	int annee; //annee de naissance 
}date;

typedef struct{
	char nom[20]; //nom de l'employe
	char prenom[20]; //prenom de l'employe
	adr adresse ; //adresse de l'employe
	int telephone; //numero du telephone 
	date date_naissance ; //date de naissance de l'employe
}fiche;

//fonction pour lire une fiche 
void lireFiche (fiche *f){
	
	//lire une fiche 
	printf("Veuillez remplir cette fiche :\n");
	printf("nom : ");
	scanf("%s",f->nom);
	printf("prenom : ");
	scanf("%s",f->prenom);
	printf("adresse :\n");
	printf("rue : ");
	scanf("%s",f->adresse.rue);
	printf("code postal : ");
	scanf("%d",&f->adresse.code_postal);
	printf("ville : ");
	scanf("%s",f->adresse.ville);
	printf("telephone : ");
	scanf("%d",&f->telephone);
	printf("jour de naissance : ");
	scanf("%d",&f->date_naissance.jour);
	printf("mois de naissance : ");
	scanf("%d",&f->date_naissance.mois);
	printf("annee de naissance : ");
	scanf("%d",&f->date_naissance.annee);
}

void remplirTab (fiche *f, fiche *t, int n ){
	
	//remplir un tableau de fiche
	for(int i=0; i<n ; i++){
		lireFiche ((&t[i]));
	}	
}

void rechNom ( fiche *t,int n ){
	int i=0;
	char nom1[20]; // nom a chercher 
	
	//lire le nom a chercher
	printf ("donnez le nom a chercher : \n");
	gets(nom1);
	
	//chercher le nom
	for( i; i<n ; i++){
		if (strcmp(t[i].nom,nom1) == 0){
			printf("le nom existe\n");
			break;
		}
		else{
			printf("le nom n'existe pas\n");
		}
	}
}

void rechTel( fiche *t, int n){
	int i=0;
	int telephone1; //numero de telephone
	
	//lire le numero a chercher
	printf("donner le numero a chercher\n");
	scanf("%d",&telephone1);
	
	//chercher le numero
	for(i; i<n ; i++){
		if ((t[i].telephone) == telephone1 ){
			printf("numero bien trouve\n");
			break;
		}
		else{
			printf("numero n'existe pas\n");
		}
	}
}

void affichePers( fiche *t, int i ){
	printf("la fiche de l'employe numero %d :\n",i);
	printf("nom : %s\n",t[i].nom);
	printf("prenom : %s\n",t[i].prenom);
	printf("adresse :\n");
	printf("\true : %s\n",t[i].adresse.rue);
	printf("\tcode postal : %d\n",t[i].adresse.code_postal);
	printf("\tville : %s\n",t[i].adresse.ville);
	printf("telephone : %d\n",t[i].telephone);
	printf("date de naissance:\n ");
	printf("\tjour : %d\n",t[i].date_naissance.jour);
	printf("\tmois : %d\n",t[i].date_naissance.mois);
	printf("\tannee : %d\n",t[i].date_naissance.annee);
		
}

int main(){
	fiche *f; //fiche d'un employe
	fiche *t; //tableau de fiche
	int n; //taille du tableau
	int i; //numero d'un employe
	
	//lire la taille du tablau
	printf("donnez le nombre d'employes : ");
	scanf("%d",&n);
	
	//allocation de la memoire pour le tableau
	t=(fiche*)malloc(n*sizeof(fiche));
	if (t==NULL){
		printf("erreur");
		return 0;
	}
	
	//remplir le tableau 
	remplirTab(f,t,n); //appel de la fonction 
	
	//chercher un nom
	rechNom(t,n);
	
	//chercher un numero de telephone 
	rechTel(t,n);
	
	//afficher une fiche
	printf("donner le nom de la fiche de l'employe ");
	scanf("%d",&i);
	affichePers(t,i);
	
	//liberer la memoire 
	for (int i =0; i<n; i++){
		if (t != NULL){
			if (f != NULL){
			free(f);
			}	
		}
	}
	if (t != NULL){
		free(t);
	}
		
	
	
	return 0;
}
