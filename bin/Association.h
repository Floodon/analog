/*************************************************************************
Association  -  description
-------------------
debut                : 14/01/2020
copyright            : (C) 2020 par Enzo BOSCHERE, Tuoyuan TAN
e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Association> (fichier Association.h) ----------------
#if ! defined ( Association_H )
#define Association_H
//--------------------------------------------------- Interfaces utilisees
#include <stdio.h>
#include <cstdlib>
#include <string>
#include <iostream>
#include <fstream>
#include "Requete.h"
#include <map>
#include <vector>
using namespace std;
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Association>
// Permet de stocker les noeuds qui referent vers le meme document
//----
class Association{

//----------------------------------------------------------------- PUBLIC
//----------------------------------------------------- Methodes publiques

//---------------------------------------------------- Attributs publiques
public:
	typedef vector <Requete> Requetes;
	typedef map <string,Requetes> MapReferants;
	MapReferants Referers;  
	int NbrVisit;

public:
	Association();
	// Mode d'emploi :
	// constructeur de Association par defaut
	//

	void Ajouter (const Requete & Req);

	~Association();
	// Mode d'emploi :
	// destructeur de Association
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
//----------------------------------------- Types dependants de <Association.h>
#endif // Association_H
