
// Mastermind
// Adjy Sedar DESIR, 18/01/2020
// inclure la classe d'entrées/sorties
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <cmath>
#include <string>
// définir std comme namespace de base
using namespace std;

int Compteur=0;
string Ch;

int alea(int n1, int n2){
	return n1+rand()%(n2-n1) ;
}

int saisirNbLettres(){
	int nbr;
	cout<<"Nombre de lettres (entre 1 et 10) ?";
	cin>>nbr;
	if(nbr>=1 and nbr<=10){
		// cout<<"Controle ok";
		return nbr;
	}
	cout<<"Erreur !";
	return saisirNbLettres();
}

string saisirCharMax(string charMin){
	string charMax;
	cout<<"Caractere maxi? ";
	cin>>charMax;
	if(charMin<charMax){
		return charMax;
	}
	cout<<"Erreur! ";
	return saisirCharMax(charMin);
}

string initChaine(int nbLettres, string charMin, string charMax){
	string randC,L;
	randC=rand()% 'z' ;
	if(nbLettres==0){
		return L;
	}
	if(randC>=charMin and randC<=charMax){
		L=L+randC;
		return initChaine(nbLettres-1, charMin, charMax)+L;
	}
	return initChaine(nbLettres, charMin, charMax);
	
}

// string verifChaine(int nbLettres, string chaineRef, string chaine){

// 	string L;
// 	if(nbLettres<-1){
// 		return L;
// 	}

// 	if (chaineRef[nbLettres]==chaine[nbLettres]){
		
// 			L=L+chaine[nbLettres];
// 	}
// 	else{
// 		L=L+chaine[nbLettres]='*';
// 	}
// 	return verifChaine(nbLettres-1,chaineRef, chaine)+L;
// }
string verifChaine(int nbLettres, string chaineRef, string chaine){

	string L;
	if(nbLettres<-1){
		return Ch;
	}

	if (chaineRef[nbLettres]==chaine[nbLettres]){
		
			Ch[nbLettres]=chaine[nbLettres];
	}
	// else{
	// 	L=L+chaine[nbLettres]='*';
	// }
	return verifChaine(nbLettres-1,chaineRef, chaine);
}
void afficher(int nbLettres, string chaine){
	int Compteurs=0;
	if (Compteurs==nbLettres){
		cout<<":";

	}
	else{
		cout<<chaine[Compteurs]<<" ";
		
		Compteurs++;

		return  afficher(nbLettres,chaine);
	}
}
string saisir(int nbLettres){
	string L,C;
	
	if (nbLettres==0){
		return L;
	}
	else{
	cout<<" ";
	cin>>C;
	L=L+C;
	}
	
	return L+saisir(nbLettres-1);
}

bool estGagne(int nbLettres, string chaineRef, string chaine){
	if (nbLettres==0){
		return true;
	}
	if (chaineRef[nbLettres]!=chaine[nbLettres]){
		return false;
	}return estGagne(nbLettres-1,chaineRef, chaine);

}

// void jouer(){
// 	bool jouer=true;
	
// 	while(jouer){
// 		int nbr;
// 		int essai=1;
// 		int score;
// 	string Min,Max,chaineRef,chaine,T,f;
// 	Ch=f;
// 		nbr=saisirNbLettres();
// 		cout<<"Caractere mini ?";
// 		cin>>Min;
// 		Max=saisirCharMax(Min);
// 		chaineRef=initChaine(nbr,Min,Max);

// 		cout<<"Debut de la partie :"<<endl;

// 		for(int i=0;i<nbr;i++){
// 			Ch=Ch+"*";
// 		}
// 		cout<<chaineRef;
// 		cout<<"1er essai: ";
// 		chaine=saisir(nbr);
// 		Ch=verifChaine(nbr, chaineRef, chaine);
// 		cout<<Ch;

// 		while(estGagne( nbr,chaineRef,Ch)==false){
// 			cout<<essai<<"eme essai: ";
// 			essai++;
// 		chaine=saisir(nbr);
// 		Ch=verifChaine(nbr, chaineRef, chaine);
// 		cout<<Ch;


// 	}
// 	cout<<"\nBravo !Recommencer (o/autre) ? ";
// 	cin>>T;
// 	if(T!="o"){
// 		jouer=false;

// 	}}
// }


void jouer(){
	bool jouer=true;
	
	while(jouer){
		int nbr;
		int essai=2;
		int score;

	string Min,Max,chaineRef,chaine,T,f;
	Ch=f;

		nbr=saisirNbLettres();
		cout<<"Caractere mini ?";
		cin>>Min;

		score = 10;

		Max=saisirCharMax(Min);
		chaineRef=initChaine(nbr,Min,Max);

		cout<<"Debut de la partie :"<<endl;

		for(int i=0;i<nbr;i++){
			Ch=Ch+"*";
		}

		cout<<"1er essai: ("<<chaineRef<<")";
		chaine=saisir(nbr);
		Ch=verifChaine(nbr, chaineRef, chaine);
		cout<<Ch<<endl;

		

		while((estGagne( nbr,chaineRef,Ch)==false) and essai<=10){
			score--;
			cout<<endl;

			cout<<essai<<"eme essai:";
			essai++;

		chaine=saisir(nbr);
		Ch=verifChaine(nbr, chaineRef, chaine);
		cout<<Ch;


	}
	cout<<"\nVous avez fini apres "<<essai-1<<" essais et votre score est: "<<score<<endl;
	if(estGagne( nbr,chaineRef,Ch)){
		cout<<"\nBravo !";

	}
	cout<<"\nRecommencer (o/autre) ? ";
	
	cin>>T;
	if(T!="o"){
		jouer=false;

	}}
}
// Programme principal
int main()
{
// INSERER VOTRE ALGORITHME ICI
	srand(time(NULL));
	cout<<"Bienvenu "<<endl;

	
	jouer();


	// fin du programme
	return 0;
} // main


		
