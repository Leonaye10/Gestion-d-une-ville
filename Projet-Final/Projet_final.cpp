#include<iostream>
#include<fstream>
#include<iomanip>
#include<string.h>

using namespace std;
// Creation de la structure du residents
struct Infos_Residents
{
	int Num;
	string Nom;
	string Prenom;
	string NumCivique;
	string Rue;
	string Arrondissment;
	float Superficie;
};
void menu();
void Inscrire();
void Afficher();
void Modifier();
void Supprimer();
void Taxes();
//fonction pricipale
int main()
{
	menu();
}
//fonction menu 
// C'est ici qu'on retrouve toutes les autres fonctions pour un bon fonctionnement
void menu()
{
	//Menu principale ou on peut acceder a toutes les fonctions
	int choix;
	do{
		cout << "1) Inscrire" << endl;
		cout << "2) Afficher" << endl; 
		cout << "3) Modifier" << endl;
		cout << "4) Supprimer " << endl;
		cout << "5) Taxes " << endl;
		cout << "6) Quittez " << endl;
	cin >> choix;
	if(choix==1)
	{
		Inscrire();
	}
	else if(choix==2)
	{
		Afficher();
	}
	else if(choix==3)
	{
		Modifier();
	}
	else if(choix==4)
	{
		Supprimer();
	}
	else if(choix==5)
	{
		Taxes();
	}
	else
	{
		system("exit");
	}
	}while(choix != 6);
}
//fonction inscrire
void Inscrire()
{
	
	string ligne;
	//Ouverture de fichier text pour lire et ecrire
	ofstream Residents("Residents.dat",ios::out|ios::app);
	ifstream ResidTemp("Residents.dat",ios::in);
	Infos_Residents Resid;
	Resid.Num = 0;
	//on compte les lignes du fichiers
	while(getline(ResidTemp,ligne))
	{
		Resid.Num++;
	}
	cout << "*******Inscription d'un nouveau resident************" << endl;
	cout << "Veuillez entrer le nom du resident : ";
	cin >> Resid.Nom;
	cout << "Veuillez entrer le prenom du resident : ";
	cin >> Resid.Prenom;
	cout << "Veuillez entrer le numero civique : ";
	cin >> Resid.NumCivique;
	cout << "Veuillez entrer la rue : ";
	cin >> Resid.Rue;
	cout << "Veuillez specifier l'arrondissement : ";
	cin >> Resid.Arrondissment;
	cout << "Veuillez entrer la superficie : ";
	cin >> Resid.Superficie;
	//Ecriture des donnees saisi par l'utilisateur dans le fichier text
	Residents << Resid.Num + 1 << " "<< Resid.Nom << " " << Resid.Prenom << " " << Resid.NumCivique << " " << Resid.Rue << " " << Resid.Arrondissment << " " << Resid.Superficie << " \n";
	Resid.Num++;
	//fermeture des fichier ( la lecture et l'ecriture
	ResidTemp.close();
	Residents.close();

}
void Afficher()
{
	int countGroupe=3;
	int nbreLigne=0;
	string ligne;
	//ouverture du fichier pour lire
	ifstream ResidTemp("Residents.dat",ios::in);
	//Comptage des lignes du fichier
	while(getline(ResidTemp,ligne))
	{
		nbreLigne++;
	}
	ResidTemp.close();
	ifstream fichier("Residents.dat",ios::in);
	Infos_Residents Affi[nbreLigne];
	int k=1;
	for(int i=0; i<nbreLigne;i++)
	{	//c'est pour separer les residents en groupes de 3
		if(countGroupe%3==0)
		{
			cout <<"***Groupe "<<k<<"*****************************" << endl;
			k++;
		}//recuperation des donnees dans le fichier text
		fichier >> Affi[i].Num >> Affi[i].Nom >> Affi[i].Prenom >> Affi[i].NumCivique >> Affi[i].Rue >> Affi[i].Arrondissment >> Affi[i].Superficie;
		//affichages des residents dans la console
		cout << "-------------- Resident numero => " << Affi[i].Num << endl;
		cout << "Nom => " << Affi[i].Nom  << endl;
		cout << "Prenom => " <<Affi[i].Prenom << endl;
		cout << "Adresse => " << Affi[i].NumCivique << " " << Affi[i].Rue << endl;
		cout << "Arrondissement => " << Affi[i].Arrondissment << endl;
		cout << "Superficie du terrain => " << Affi[i].Superficie << endl;
		
		countGroupe++;
	}
	fichier.close();
	return;
}
void Modifier()
{
	int nbreLigne=0;
	int num;
	string ligne;
	cout << "Entrer le numero de resident a modifie : ";
	cin >> num;
	//ouverture du fichier
	ifstream ResidTemp("Residents.dat",ios::in);
	//comptage des lignes
	while(getline(ResidTemp,ligne))
	{
		nbreLigne++;
	}//fermeture du fichier pour ne pas avoir de bug
	ResidTemp.close();
	//ouverture du fichier de lecture encore 
	ifstream fichier("Residents.dat",ios::in);
	//ouverture du fichier d'ecriture
	fstream mod("Mod.dat",ios::out);
	Infos_Residents ModiRes[nbreLigne];
	//on cparcours le fichier
	for(int i=0;i<nbreLigne;i++)
	{	//on recupere les donnees
		fichier >> ModiRes[i].Num >> ModiRes[i].Nom >> ModiRes[i].Prenom >> ModiRes[i].NumCivique >> ModiRes[i].Rue >> ModiRes[i].Arrondissment >> ModiRes[i].Superficie;
		//on compare l'ID du resident avec le nombre saisi par l'utilisateur pour modifier le residents non desiré
		if(ModiRes[i].Num==num)
		{
			cout << "Entrer le nouveau nom : ";
			cin >> ModiRes[num].Nom;
			cout << "Entrez le nouveau prenom : ";
			cin >> ModiRes[num].Prenom;
			cout << "Entrez le nouveau numero civique : ";
			cin >> ModiRes[num].NumCivique;
			cout << "Entrez la nouvelle rue : ";
			cin >> ModiRes[num].Rue;
			cout << "Entrez l'arrondissement : ";
			cin >> ModiRes[num].Arrondissment;
			cout << "Entrez la nouvelle superficie : ";
			cin >> ModiRes[num].Superficie;
			//apres la modification on ecrit dans le fichier temporaire
			mod << num << " " << ModiRes[num].Nom << " "<< ModiRes[num].Prenom << " "<< ModiRes[num].NumCivique << " "<< ModiRes[num].Rue << " " << ModiRes[num].Arrondissment << ModiRes[num].Superficie <<endl;
			
		}
		else
		{
			mod<< i+1 << " " << ModiRes[i].Nom << " "<< ModiRes[i].Prenom << " "<< ModiRes[i].NumCivique << " "<< ModiRes[i].Rue << " " << ModiRes[i].Arrondissment << " "<< ModiRes[i].Superficie <<endl;
		}
	}
		mod.close();
		fichier.close();
		
		fstream LireFichier("Mod.dat",ios::in);
		fstream EcrireFichier("Residents.dat",ios::out);
		//ici on recuper les donnes du fichier temporaire pour les mettre dans le fichier principale
		for(int i=0;i<nbreLigne;i++)
		{
			LireFichier >> ModiRes[i].Num >> ModiRes[i].Nom >> ModiRes[i].Prenom >> ModiRes[i].NumCivique >> ModiRes[i].Rue >> ModiRes[i].Arrondissment >> ModiRes[i].Superficie;
			EcrireFichier << ModiRes[i].Num << " " << ModiRes[i].Nom << " "<< ModiRes[i].Prenom << " "<< ModiRes[i].NumCivique << " "<< ModiRes[i].Rue << " " << ModiRes[i].Arrondissment << " "<< ModiRes[i].Superficie <<endl;
		}
		LireFichier.close();
		EcrireFichier.close();
		
	
}
//meme principe avec la fonction modifier
void Supprimer()
{
	int nbreLigne=0;
	int num;
	string ligne;
	cout << "Entrer le numero de resident a supprime : ";
	cin >> num;
	ifstream ResidTemp("Residents.dat",ios::in);
	
	while(getline(ResidTemp,ligne))
	{
		nbreLigne++;
	}
	ResidTemp.close();
	ifstream fichier("Residents.dat",ios::in);
	
	fstream mod("Mod.dat",ios::out);
	Infos_Residents ModiRes[nbreLigne];
	
	for(int i=0;i<nbreLigne;i++)
	{
		fichier >> ModiRes[i].Num >> ModiRes[i].Nom >> ModiRes[i].Prenom >> ModiRes[i].NumCivique >> ModiRes[i].Rue >> ModiRes[i].Arrondissment >> ModiRes[i].Superficie;
		if(ModiRes[i].Num!=num)
		{
			mod<< i+1 << " " << ModiRes[i].Nom << " "<< ModiRes[i].Prenom << " "<< ModiRes[i].NumCivique << " "<< ModiRes[i].Rue << " " << ModiRes[i].Arrondissment << " "<< ModiRes[i].Superficie <<endl;
			
		}
	}
	nbreLigne--;
		mod.close();
		fichier.close();
		
		fstream LireFichier("Mod.dat",ios::in);
		fstream EcrireFichier("Residents.dat",ios::out);
		
		for(int i=0;i<nbreLigne;i++)
		{
			LireFichier >> ModiRes[i].Num >> ModiRes[i].Nom >> ModiRes[i].Prenom >> ModiRes[i].NumCivique >> ModiRes[i].Rue >> ModiRes[i].Arrondissment >> ModiRes[i].Superficie;
			EcrireFichier << ModiRes[i].Num << " " << ModiRes[i].Nom << " "<< ModiRes[i].Prenom << " "<< ModiRes[i].NumCivique << " "<< ModiRes[i].Rue << " " << ModiRes[i].Arrondissment << " "<< ModiRes[i].Superficie <<endl;
		}
		LireFichier.close();
		EcrireFichier.close();
		
	
}
void Taxes()
{
	Infos_Residents TempPlus;
	TempPlus.Superficie=0;
	int Taxe, choix;
	//recuperation de la taxe entre par l'utilisateur
	cout << "Veuillez entrer le taux de taxes : ";
	cin >> Taxe;
	do{
	cout << endl;
	cout << "1) Total des taxes recueillies par la municipalite " << endl;
	cout << "2) Total des taxes par arrondissement " << endl;
	cout << "3) Le resident qui paye le plus et celui qui paye le moins " << endl;
	cout << "4) Sortir vers menu principal " << endl ;
	cin >> choix;
	float min;
	if(choix==1)
	{
		string ligne;
		int nbreLigne=0;
		ifstream ResidTemp("Residents.dat",ios::in);
		while(getline(ResidTemp,ligne))
		{
			nbreLigne++;
		}
		
		ResidTemp.close();
		ifstream fichier("Residents.dat",ios::in);
		Infos_Residents Residents[nbreLigne];
		float TaxeRecolte=0;
		//parcourir le fichier pour recupere les taxes de tous les residents
		//ensuite multipli2 leur superficie avec la taxe
		for(int i=0;i<nbreLigne;i++)
		{
			fichier >> Residents[i].Num >> Residents[i].Nom >> Residents[i].Prenom >> Residents[i].NumCivique >> Residents[i].Rue >> Residents[i].Arrondissment >> Residents[i].Superficie;
			//somme de toutes les taxes
			TaxeRecolte += Residents[i].Superficie*Taxe;
		}
		cout << "Le total des taxes recueillies par la municipalite est de : " << TaxeRecolte << " $"<< endl;
		fichier.close();
		
	}
	else if(choix==2)
	{
		string Arron;
		int nbreLigne=0;
		string ligne;
		cout << "Veuillez preciser l'arrondissement ----> " ;
		cin >> Arron;
		ifstream ResidTemp("Residents.dat",ios::in);
		while(getline(ResidTemp,ligne))
		{
			nbreLigne++;
		}
		
		ResidTemp.close();
		ifstream fichier("Residents.dat",ios::in);
		Infos_Residents Residents[nbreLigne];
		float TaxeRecolte=0;
		//calcul de taxes par arrondissements
		//meme principe avec taxe recueilli par municpalité
		for(int i=0;i<nbreLigne;i++)
		{
			fichier >> Residents[i].Num >> Residents[i].Nom >> Residents[i].Prenom >> Residents[i].NumCivique >> Residents[i].Rue >> Residents[i].Arrondissment >> Residents[i].Superficie;
			if(Residents[i].Arrondissment == Arron)
			{
				TaxeRecolte += Residents[i].Superficie*Taxe;
			}
		}
		cout << "Les taxes recueillies de " << Arron << " sont estimes a : " << TaxeRecolte << " $" << endl;
	}
	else if(choix==3)
	{
		string ligne;
		int nbreLigne=0;
		ifstream ResidTemp("Residents.dat",ios::in);
		while(getline(ResidTemp,ligne))
		{
			nbreLigne++;
		}
		
		ResidTemp.close();
		ifstream fichier("Residents.dat",ios::in);
		Infos_Residents Residents[nbreLigne];
		float Temp=0;
		string nomMax,nomMin;
		for(int i=0;i<nbreLigne;i++)
		{
			fichier >> Residents[i].Num >> Residents[i].Nom >> Residents[i].Prenom >> Residents[i].NumCivique >> Residents[i].Rue >> Residents[i].Arrondissment >> Residents[i].Superficie;
			min = Residents[i].Superficie;
		}
		for(int i=0;i<nbreLigne;i++)
		{
			fichier >> Residents[i].Num >> Residents[i].Nom >> Residents[i].Prenom >> Residents[i].NumCivique >> Residents[i].Rue >> Residents[i].Arrondissment >> Residents[i].Superficie;
			if(Residents[i].Superficie>Temp)
			{
				Temp = Residents[i].Superficie;
				nomMax = Residents[i].Nom + " " + Residents[i].Prenom;
			}
			if(Residents[i].Superficie<min)
			{
				min = Residents[i].Superficie;
				nomMin = Residents[i].Nom + " " + Residents[i].Prenom ;
			}
		}
		cout <<"Le resident qui paye le plus de taxe est : "<<nomMax<<endl;
		cout<<"Le resident qui paye le moins de taxe est : "<<nomMin<<endl;
	}
	else if(choix==4)
	{
		menu();
	}
	}while(choix!=4);
	return;	
}




