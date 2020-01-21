/*************************************************************************
Requete  -  description
-------------------
debut                : 14/01/2020
copyright            : (C) 2020 par Ezor Boschere, Tuoyuan TAN
e-mail               : $EMAIL$
*************************************************************************/
//---------- R��alisation de la classe <Requete> (fichier Requete.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include syst��me
#include <stdio.h>
#include <cstdlib>
#include <string>
using namespace std;
#include <iostream>
#include <fstream>
#include<regex>

//------------------------------------------------------ Include personnel
#include "Requete.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Methodes publiques

Requete::Requete(){
	// constructeur par defaut qui ne fait rien et qui n'a pas de parametres
}//----- Fin de Methode
	
Requete::~Requete(){}
//----- Fin de Methode

istream & operator >> (istream & is,Requete & Req){
	string inutile;  //qui permet de recevoir les infos inutiles
	getline(is,inutile,':');
	getline(is,Req.Heure,':');
	getline(is,inutile,'"');
	getline(is,inutile,' ');
	getline(is,Req.Document,' ');
	getline(is,inutile,'"');
	getline(is,inutile,'"');
	getline(is,Req.Referer,'"');
	getline(is,inutile); 
	string local_addr = "http://intranet-if.insa-lyon.fr";
	string extraire = Req.Referer;
	extraire = extraire.substr(0,local_addr.length());
	if(extraire == local_addr){
	Req.Referer = Req.Referer.substr(local_addr.length(),Req.Referer.length()-local_addr.length());
	}
	return is;
}

bool Requete::BonType(){
	regex BadType {"^.*\\.(jpg|png|css|js|gif)"};
	if(regex_match(Document,BadType)){
	return false;
	}else{
	return true;
	}
}



















