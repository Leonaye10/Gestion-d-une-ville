#include<iostream>
#include<fstream>
#include<iomanip>
#include<string.h>
using namespace std;

struct resident
{
	int num;
	string nom;
	string prenom;
	string numero_civique;
	string rue;
	float surface;

};
void inscrire();
void afficher();
void modifier();
void supprimer();
void Taxe(float taxe,float*total,resident*plustaxe,resident*moinstaxe);
float arrendissement(float tax);

int main()
{
	int choix1;
	float taxe;
	float taxeto;
	resident plustaxe;
	plustaxe.surface=0;
	resident moinstaxe;
	moinstaxe.surface=2000000;
		float taxarren=0;
	do
	{
		cout<<"1) Inscrire un resident :"<<endl;
		cout<<"2) Afficher la liste des residents (avec ordre alphabetique) :"<<endl;
		cout<<"3) Modifier un resident :"<<endl;
		cout<<"4) Supprimer un resident :"<<endl;
		cout<<"5)  Taxe :"<<endl;
		cout<<"6) Sortir"<<endl;
		cin>>choix1;
		if(choix1<=0 || choix1>5)
		{
			cout<<"Choix invalide !"<<endl;
		}
			switch (choix1)
				{
					case 1:
						inscrire();
						break;
					case 2:
						afficher();
						break;
					case 3:
						 modifier();
						 break;
					case 4:
						supprimer();
						break;
					case 5:
						int choix2;
							cout<<"Saisir le taux de taxation par mettre carre :";
							cin>>taxe;
						do{
							Taxe(taxe,&taxeto,&plustaxe,&moinstaxe);
							cout<<"1)la taxe total :"<<endl;
							cout<<"2) taxe total pour chaque arrondissememt :"<<endl;
							cout<<"3) le resident qui paye le plus / le resident qui pay le moins :"<<endl;
							cout<<"4) sortir "<<endl;
							cin>>choix2;
							if(choix2<=0 || choix2>4)
							{
								cout<<"Choix invalide :"<<endl;
							}
							switch(choix2)
							{
								case 1:
									cout<<" le totale des taxes :"<<taxeto<<endl;
									break;
								case 2:
									
									taxarren=arrendissement(taxe);
									cout<<" la taxe de l'arrendissement ' :"<<taxarren<<endl;
									break;
								case 3:
										cout<<" le resident qui paye le plus :"<<endl;
											cout<<"Nom :"<<	plustaxe.nom<<endl;
											cout<<"Prenom :"<<plustaxe.prenom<<endl;
											cout<<"numero_civique :"<<plustaxe.numero_civique<<endl;
											cout<<"rue :"<<plustaxe.rue<<endl;
											cout<<"surface :"<<plustaxe.surface<<endl;
											cout<<"---------------------------------"<<endl;
											
										cout<<" le resident qui paye le moins :"<<endl;
											cout<<"Nom :"<<	moinstaxe.nom<<endl;
											cout<<"Prenom :"<<moinstaxe.prenom<<endl;
											cout<<"numero_civique :"<<moinstaxe.numero_civique<<endl;
											cout<<"rue :"<<moinstaxe.rue<<endl;
											cout<<"surface :"<<moinstaxe.surface<<endl;
											cout<<"---------------------------------"<<endl;
									break;
							}
						}while(choix2!=4);
						break;		
				}
	}while(choix1!=6);
	if(choix1==6)
	{
		cout<<"AU REVOIR "<<endl;
	}
	return 0;
}
void inscrire() 
{
	resident nouveauxresident;
	cout<<"Entrez le nom de resident :";
	cin>>nouveauxresident.nom;
	cout<<endl;
	
	cout<<"Entrez le prenom de resident :";
	cin>>nouveauxresident.prenom;
	cout<<endl;
	
	cout<<"Entrez le numero_civique de resident :";
	cin>>nouveauxresident.numero_civique;
	cout<<endl;
	
	cout<<"Entrez la rue de resident :";
	cin>>nouveauxresident.rue;
	cout<<endl;
	
	cout<<"Entrez la surface de resident :";
	cin>>nouveauxresident.surface;
	cout<<endl;
	ofstream fichier("information_residents.txt",ios::out |ios::app);
	fichier<<nouveauxresident.nom<<endl;
	fichier<<nouveauxresident.prenom<<endl;
	fichier<<nouveauxresident.numero_civique<<endl;
	fichier<<nouveauxresident.rue<<endl;
	fichier<<nouveauxresident.surface<<endl;
	fichier.close();
	
}
void afficher()
{
	ifstream fichier("information_residents.txt",ios::in);
	string ligne;
	int compteur=3;
	while(getline(fichier,ligne))
	{
		if(ligne!="")
		{
				if(compteur%3==0)
			{
				cout<<"------------------------Groupe:"<<compteur-(compteur-1)<<"--------------------------------"<<endl;
			}
			resident recuper;
			recuper.nom=ligne;
			fichier>>recuper.prenom;
			fichier>>recuper.numero_civique;
			fichier>>recuper.rue;
			fichier>>recuper.surface;
			cout<<"Nom :"<<	recuper.nom<<endl;
			cout<<"Prenom :"<<recuper.prenom<<endl;
			cout<<"numero_civique :"<<recuper.numero_civique<<endl;
			cout<<"rue :"<<recuper.rue<<endl;
			cout<<"surface :"<<recuper.surface<<endl;
			cout<<"---------------------------------"<<endl;
			compteur++;
		
		}
	}
}
void  modifier()
{
	resident recuper;
	string nommodifier;
	cout<<"Entrez le nom pour le modifier :";
	cin>>nommodifier;
	cout<<endl;
	ifstream fichier("information_residents.txt",ios::in);
	ofstream element("temporere.txt",ios::out |ios::trunc);
	string ligne;
	bool trouv;
	while(getline(fichier,ligne))
	{
		if(ligne!="")
		{
			if(nommodifier==ligne)
			{
				recuper.nom=ligne;
				fichier>>recuper.prenom;
				fichier>>recuper.numero_civique;
				fichier>>recuper.rue;
				fichier>>recuper.surface;
				trouv=true;
			}else
			{
				resident garder;
				garder.nom=ligne;
				fichier>>garder.prenom;
				fichier>>garder.numero_civique;
				fichier>>garder.rue;
				fichier>>garder.surface;
				
				element<<garder.nom<<endl;
				element<<garder.prenom<<endl;
				element<<garder.numero_civique<<endl;
				element<<garder.rue<<endl;
				element<<garder.surface<<endl;	
			}
		}
	}
		element.close();
		fichier.close();
		if(trouv==true)
		{
			cout<<"Modification du resident :"<<recuper.nom<<endl;
			cout<<"Entrez le prenom :";
			cin>>recuper.prenom;
			cout<<"Entrez la rue :";
			cin>>recuper.rue;
			cout<<"Entrez la surface :";
			cin>>recuper.surface;
		}else
		{
			cout<<"Aucun resident ne porte ce nom :";
		}
	ifstream fichi("temporere.txt",ios::in);
	ofstream elemen("information_residents.txt",ios::out |ios::trunc);
	while(getline(fichi,ligne))
	{
		if(ligne!="")
		{
			resident ajouter;
			ajouter.nom=ligne;
			fichi>>ajouter.prenom;
			fichi>>ajouter.numero_civique;
			fichi>>ajouter.rue;
			fichi>>ajouter.surface;
			
			elemen<<ajouter.nom<<endl;
			elemen<<ajouter.prenom<<endl;	
			elemen<<ajouter.numero_civique<<endl;	
			elemen<<ajouter.rue<<endl;	
			elemen<<ajouter.surface<<endl;	
			
		}
	}
	elemen<<recuper.nom<<endl;
	elemen<<recuper.prenom<<endl;
	elemen<<recuper.numero_civique<<endl;
	elemen<<recuper.rue<<endl;
	elemen<<recuper.surface<<endl;
		elemen.close();
		fichi.close();
		
}

void supprimer()
{
	resident recuper;
	string nommodifier;
	cout<<"Entrez le nom pour le modifier :";
	cin>>nommodifier;
	cout<<endl;
	ifstream fichier("information_residents.txt",ios::in);
	ofstream element("temporere.txt",ios::out |ios::trunc);
	string ligne;
	bool trouv;
	while(getline(fichier,ligne))
	{
		if(ligne!="")
		{
			if(nommodifier==ligne)
			{
				recuper.nom=ligne;
				fichier>>recuper.prenom;
				fichier>>recuper.numero_civique;
				fichier>>recuper.rue;
				fichier>>recuper.surface;
				trouv=true;
			}else
			{
				resident garder;
				garder.nom=ligne;
				fichier>>garder.prenom;
				fichier>>garder.numero_civique;
				fichier>>garder.rue;
				fichier>>garder.surface;
				
				element<<garder.nom<<endl;
				element<<garder.prenom<<endl;
				element<<garder.numero_civique<<endl;
				element<<garder.rue<<endl;
				element<<garder.surface<<endl;	
			}
		}
	}
		element.close();
		fichier.close();
		if(trouv==true)
		{
			cout<<"Ce resident a ete supprime avec succes :"<<recuper.nom<<endl;
		}else
		{
			cout<<"Aucun resident ne porte ce nom :";
		}
	ifstream fichi("temporere.txt",ios::in);
	ofstream elemen("information_residents.txt",ios::out |ios::trunc);
	while(getline(fichi,ligne))
	{
		if(ligne!="")
		{
			resident ajouter;
			ajouter.nom=ligne;
			fichi>>ajouter.prenom;
			fichi>>ajouter.numero_civique;
			fichi>>ajouter.rue;
			fichi>>ajouter.surface;
			
			elemen<<ajouter.nom<<endl;
			elemen<<ajouter.prenom<<endl;	
			elemen<<ajouter.numero_civique<<endl;	
			elemen<<ajouter.rue<<endl;	
			elemen<<ajouter.surface<<endl;	
			
		}
	}

		elemen.close();
		fichi.close();
		
}
void Taxe(float taxe,float*total,resident*plustaxe,resident*moinstaxe)
{
	ifstream fichier("information_residents.txt",ios::in);
	string ligne;
	while(getline(fichier,ligne))
	{
		if(ligne!="")
		{
			resident recuper;
			recuper.nom=ligne;
			fichier>>recuper.prenom;
			fichier>>recuper.numero_civique;
			fichier>>recuper.rue;
			fichier>>recuper.surface;
			
			*total+=(recuper.surface * taxe);
			if(recuper.surface>plustaxe->surface)
			{
				*plustaxe=recuper;	
			}
			if(recuper.surface<moinstaxe->surface)
			{
				*moinstaxe=recuper;	
			}
		
		}
	}
		
}
float arrendissement(float tax)
{
	float tota=0;
	string rue,ligne;
	cout<<"saisir la rue :"<<endl;
	cin>>rue;
	ifstream fichier("information_residents.txt",ios::in);
		while(getline(fichier,ligne))
		{
			if(ligne!="")
			{
				resident recuper;
				recuper.nom=ligne;
				fichier>>recuper.prenom;
				fichier>>recuper.numero_civique;
				fichier>>recuper.rue;
				fichier>>recuper.surface;
				
				if(recuper.rue==rue)
				{
					tota+=tax*recuper.surface;
				}
			
			}
		}
		return tota;
}
