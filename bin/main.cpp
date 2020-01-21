#include<iostream>
#include<string>
#include<regex>
using namespace std;

void raise_error(string txt_to_display) {
    cout << "usage: " << txt_to_display << endl;
}


int main(int argc, char** argv) {
    bool g = false;
    bool e = false;
    bool t = false;
    string dotfile;
    string temps = "-1";
    if(argc==1) {
        raise_error("[options] <filename.log>\n \toptions:\n\t\t-g <filename.dot>\n\t\t-e\n\t\t-t <heure>\nuse man analog for more informations");
        return 0;
    }
    int i = 1;
    while(i != argc) {
        if(argv[i][0] == '-') {
            if(argv[i][1] == 'g') {
                if(!g) {    
                    regex dot {"^.*\\.dot"};
                    if(argc >= i+2 ) {
                        if(!regex_match(argv[i+1],dot)) {
                            raise_error("-g <filename.dot> <filename.log>\n\t\tFile needs to have .dot extension");
                            return 21;
                        }
                    } else {
                        raise_error("-g <filename.dot> <filename.log>\n\t\t-g needs a file with the .dot extension");
                        return 0;
                    }
                    g = true;
                    i++;
                    dotfile = argv[i];
                } else {
                    raise_error("-g <filename.dot> <filename.log>\n\t\tyou can't use -g twice");
                    return 0;
                }
            } else if(argv[i][1] == 'e') {
                if(!e) {
                    e = true;
                } else {
                    raise_error("-e <filename.log>\n\t\tyou can't use -e twice");
                    return 0;
                }
            } else if(argv[i][1] == 't') {
                if(!t) {    
                    if(argc >= i+2 ) {
                        regex number {"[[:digit:]]+"};
                        if(!regex_match(argv[i+1],number)) {
                            raise_error("-t <hour> <filename.log>\n\t\tHour needs to be a positive number");
                            return 25;
                        } else if (atoi(argv[i+1]) > 23 ) {
                            raise_error("-t <hour> <filename.log\n\t\tHour needs to be between 0 & 23");
                            return 28;
                        }
                        t = true;
                        i++;
                        temps = argv[i];
                
                    } else {
                        raise_error("-t <hour> <filename.log>\n\t\t-t needs an hour");
                        return 29;
                    }
                } else {
                    raise_error("-t <hour> <filename.log>\n\t\tyou can't use -t twice");
                    return 0;
                }
            } else {
                raise_error("options accepted:\n\t\t-g <filename.dot>\n\t\t-e\n\t\t-t <heure>\nuse man analog for more informations");
                return 22;
            }
        }
        i++;
    }
    regex log {"^.*\\.log"};
    if(!regex_match(argv[i-1],log)) {
        raise_error("<filename.log> expected\n\t\tVerify your file has the right extension");
        return 0;
    }
    return 0;
}