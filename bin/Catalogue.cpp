/*************************************************************************
Catalogue  -  description
-------------------
debut                : 14/01/2020
copyright            : (C) 2020 par Enzo Boschere, Tuoyuan TAN
e-mail               : $EMAIL$
*************************************************************************/
//---------- Realisation de la classe <Catalogue> (fichier Catalogue.cpp) ------------

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
#include "Catalogue.h"
//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Methodes publiques

Catalogue::Catalogue(){
	// constructeur par defaut qui ne fait rien et qui n'a pas de parametres
}//----- Fin de Methode

void Catalogue::Ajouter(const Requete & Req){
	MapNoeuds::iterator it;
	it = Noeuds.find(Req.Document);
	if(it != Noeuds.end()){
	it -> second.Ajouter(Req); 
	}else{
	Association NouvelleAsso;
	NouvelleAsso.Ajouter(Req);
	Noeuds.insert(make_pair(Req.Document,NouvelleAsso));
	}
	it = Noeuds.find(Req.Referer);
	if(it == Noeuds.end()){
	Association Asso;
	Noeuds.insert(make_pair(Req.Referer,Asso));
	}
}

void Catalogue::Charger(ifstream & entree,bool e,string temps){
	Requete Req;
	while(entree >> Req){
	if((! e || Req.BonType())&&(temps == "-1" || Req.Heure == temps)){
	Ajouter(Req);
	}
	}
}

void Catalogue::AfficherparDefaut(){
	if(! Noeuds.empty()){
	multimap <int,string> Populaire;
	multimap <int,string>::iterator P_it;
	P_it = Populaire.end();
	MapNoeuds::const_iterator N_it;
	N_it = Noeuds.begin();
	while(N_it != Noeuds.end()){
	Populaire.insert(make_pair(N_it -> second.NbrVisit,N_it -> first));
	++N_it;
	}
	if(Populaire.size() > 10){
		int i;
		for(i=1;i<=10;i++){
		P_it--;
		if(P_it -> first != 0){
		cout << P_it -> second << " (" << P_it -> first << " hits)" << endl;
		}
		}
	}else{
		for(--P_it;P_it != Populaire.begin();--P_it){
		if(P_it -> first != 0){
		cout << P_it -> second << " (" << P_it -> first << " hits)" << endl;
		}
		}
		if(P_it -> first != 0){
		cout << P_it -> second << " (" << P_it -> first << " hits)" << endl;
		}
	}
	}else{
	cout << "No data matches your requirement" << endl;
	}
}

void Catalogue::GraphViz(ofstream & sortie){
	sortie << "digraph {" << endl;
	if(! Noeuds.empty()){
	MapNoeuds::const_iterator N_it;
	N_it = Noeuds.begin();
	while(N_it != Noeuds.end()){
	sortie << N_it -> first << ";" << endl;
	++N_it;
	}
	MapReferants::const_iterator R_it;
	N_it = Noeuds.begin();
	while(N_it != Noeuds.end()){
	if(N_it -> second.NbrVisit != 0){
		R_it = N_it -> second.Referers.begin();
		while(R_it != N_it -> second.Referers.end()){
		sortie << R_it -> first << " -> " << N_it -> first << " [label=" << R_it -> second.size() << "];" << endl;
		++R_it;
		}
	}
	++N_it;
	}
	} 
	sortie << "}" << endl;
}
		
Catalogue::~Catalogue(){}
//----- Fin de Methode
