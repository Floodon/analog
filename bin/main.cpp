#include<iostream>
#include<string>
#include<regex>
#include<fstream>
using namespace std;
#include "Catalogue.h"
void raise_error(string txt_to_display) {
    cerr << "usage: " << txt_to_display << "\nuse man analog for more informations" << endl;
}


int main(int argc, char** argv) {
    bool g = false;
    bool e = false;
    bool t = false;
    string dotfile_str;
    string temps = "-1";
    if(argc==1) {
        raise_error("[options] <filename.log>\n \toptions:\n\t\t-g <filename.dot>\n\t\t-e\n\t\t-t <hour>");
        return 20;
    }
    int i = 1;
    while(i != argc-1) {
        if(argv[i][0] == '-') {
            if(argv[i][1] == 'g') {
                if(!g) {    
                    regex dot {"^.*\\.dot"};
                    if(argc >= i+3 ) {
                        if(!regex_match(argv[i+1],dot)) {
                            raise_error("-g <filename.dot> <filename.log>\n\t\tFile needs to have .dot extension");
                            return 25;
                        }
                    } else {
                        raise_error("-g <filename.dot> <filename.log>\n\t\t-g needs a file with the .dot extension");
                        return 24;
                    }
                    g = true;
                    i++;
                    dotfile_str = argv[i];
                } else {
                    raise_error("-g <filename.dot> <filename.log>\n\t\tyou can't use -g twice");
                    return 23;
                }
            } else if(argv[i][1] == 'e') {
                if(!e) {
                    e = true;
                } else {
                    raise_error("-e <filename.log>\n\t\tyou can't use -e twice");
                    return 26;
                }
            } else if(argv[i][1] == 't') {
                if(!t) {    
                    if(argc >= i+3 ) {
                        regex number {"[[:digit:]]+"};
                        if(!regex_match(argv[i+1],number)) {
                            raise_error("-t <hour> <filename.log>\n\t\tHour needs to be a positive number");
                            return 29;
                        } else if (atoi(argv[i+1]) > 23 ) {
                            raise_error("-t <hour> <filename.log\n\t\tHour needs to be between 0 & 23");
                            return 30;
                        }
                        t = true;
                        i++;
                        temps = argv[i];
                
                    } else {
                        raise_error("-t <hour> <filename.log>\n\t\t-t needs an hour");
                        return 28;
                    }
                } else {
                    raise_error("-t <hour> <filename.log>\n\t\tyou can't use -t twice");
                    return 27;
                }
            } else {
                raise_error("options accepted:\n\t\t-g <filename.dot>\n\t\t-e\n\t\t-t <heure>");
                return 22;
            }
        } else {
	    	raise_error("options accepted:\n\t\t-g <filename.dot>\n\t\t-e\n\t\t-t <hour>\n\t\tPlease don't forget to input a '-' before the option");
	    return 21;
		}
        i++;
    }
    regex log {"^.*\\.log"};
    if(!regex_match(argv[i],log)) {
        raise_error("<filename.log> expected\n\t\tVerify your log file has the .log extension");
        return 31;
    }
    ifstream logfile(argv[i]);
    if(!logfile) {
        raise_error("<filename.log>\n\t\tError when opening the log file");
        return 32;
    }
	Catalogue c;
	c.Charger(logfile,e,temps);
	if(t){
		if(temps != "23"){ 
		cout << "Warning : only hits between " << temps << "h and " << atoi(temps.c_str())+1 << "h have been taken into account" << endl;
 		}else{
		cout << "Warning : only hits between 23h and 0h have been taken into account" << endl;
		}
	}
	c.AfficherparDefaut();
	if(g){
       ofstream dotfile(dotfile_str.c_str());
        if(!dotfile) {
            raise_error("<filename.dot>\n\t\tError when opening the dot file");
            return 33;
        }else{
		cout << "Dot-file " << dotfile_str << " generated" << endl;
		c.GraphViz(dotfile);
		}
	}
    return 0;
}
