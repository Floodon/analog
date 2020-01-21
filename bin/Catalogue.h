/*************************************************************************
Catalogue  -  description
-------------------
debut                : 14/01/2020
copyright            : (C) 2020 par Enzo BOSCHERE, Tuoyuan TAN
e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Catalogue> (fichier Catalogue.h) ----------------
#if ! defined ( Catalogue_H )
#define Catalogue_H
//--------------------------------------------------- Interfaces utilisees
#include <stdio.h>
#include <cstdlib>
#include <string>
#include <iostream>
#include <fstream>
#include "Requete.h"
#include "Association.h"
#include <map>
#include <vector>
using namespace std;
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Catalogue>
// Permet de stocker tous les infos, trie par le document demande
//----
class Catalogue{

//----------------------------------------------------------------- PUBLIC
//----------------------------------------------------- Methodes publiques

//---------------------------------------------------- Attributs publiques
public:
	typedef vector <Requete> Requetes;
	typedef map <string,Requetes> MapReferants;
	typedef map <string,Association> MapNoeuds;
	MapNoeuds Noeuds;  

public:
	Catalogue();
	// Mode d'emploi :
	// constructeur de Catalogue par defaut
	//

	void Ajouter(const Requete & Req);

	void Charger(ifstream & entree,bool e,string temps); // Si l'utilisateur ne met pas "-t heure" dans la ligne de commande, temps == "-1"

	void AfficherparDefaut(); //Affichage par defaut

	void GraphViz(ofstream & sortie); //Generer le GraphViz dans le fichier dont le nom passe en paramettre

	~Catalogue();
	// Mode d'emploi :
	// destructeur de Catalogue
	//
			 
//------------------------------------------------------------------ PRIVE 

protected:
//----------------------------------------------------- Methodes protected

private:
//------------------------------------------------------- Methodes prives
	

protected:
//----------------------------------------------------- Attributs protected

private:
//------------------------------------------------------- Attributs prives
	
//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes prives

//----------------------------------------------------------- Types prives
};
//----------------------------------------- Types dependants de <Catalogue.h>
#endif // Catalogue_H
