/*************************************************************************
Association  -  description
-------------------
debut                : 14/01/2020
copyright            : (C) 2020 par Enzo Boschere, Tuoyuan TAN
e-mail               : $EMAIL$
*************************************************************************/
//---------- R��alisation de la classe <Association> (fichier Association.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include systeme
#include <stdio.h>
#include <cstdlib>
#include <string>
using namespace std;
#include <iostream>
#include <fstream>
#include <map>
#include <vector>
//------------------------------------------------------ Include personnel
#include "Requete.h"
#include "Association.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Methodes publiques

Association::Association(){
	NbrVisit = 0;
	// constructeur par defaut 
}//----- Fin de Methode

void Association::Ajouter(const Requete & Req){
	MapReferants::iterator it;
	it = Referers.find(Req.Referer);
	if(it != Referers.end()){
	it -> second.push_back(Req);  //Ajouter une requete dans le vecteur "Requetes"
	}else{
	Requetes NouvellesRequetes;
	NouvellesRequetes.push_back(Req);
	Referers.insert(make_pair(Req.Referer,NouvellesRequetes));
	}
	NbrVisit++;
}
	
Association::~Association(){}
//----- Fin de Methode
