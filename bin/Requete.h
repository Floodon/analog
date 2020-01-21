/*************************************************************************
Requete  -  description
-------------------
debut                : 14/01/2020
copyright            : (C) 2020 par Enzo BOSCHERE, Tuoyuan TAN
e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Requete> (fichier Requete.h) ----------------
#if ! defined ( Requete_H )
#define Requete_H
//--------------------------------------------------- Interfaces utilisees
#include <stdio.h>
#include <cstdlib>
#include <string>
using namespace std;
#include <iostream>
#include <fstream>

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Requete>
// Permet de stocker les logs
//----
class Requete{

//----------------------------------------------------------------- PUBLIC
//----------------------------------------------------- Methodes publiques
public:
	Requete();
	// Mode d'emploi :
	// constructeur de Requete par defaut
	//


	~Requete();
	// Mode d'emploi :
	// destructeur de Requete
	//

	bool BonType(); // True si son extension n'est pas de type image, css ou javascript

	friend istream & operator >> (istream & is,Requete & Req);
	


//---------------------------------------------------- Attributs publiques
public:
	string Heure;
	string Document; // Le document demande
	string Referer;

				 
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
//----------------------------------------- Types dependants de <Requete.h>
#endif // Requete_H
