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
    if(argc==1) {
        raise_error("[options] <filename.log>\n \toptions:\n\t\t-g <filename.dot>\n\t\t-e\n\t\t-t <heure>\nuse man analog for more informations");
        return 0;
    }
    int i = 1;
    while(i != argv) {
        if(argv[i][0] == '-') {
            if(argv[i][1] == 'g') {
                regex dot {"^.*\\.dot"};
                if(argc >= i+1 ) {
                    if(!regex_match(argv[i+1],dot)) {
                        raise_error("-g <filename.dot> <filename.log>\n\t\tFile needs to have .dot extension");
                        return 21;
                    }
                } else {
                    raise_error("-g <filename.dot> <filename.log\n\t\t-g needs a file with the .dot extension");
                }
                g = true;
                i++;
                dotfile = argv[i];
            } else if(argv[i][1] == 'e') {
                e = true;
            } else if(argv[i][1] == 't') {
                if(argc >= i+1 ) {
                    regex number {"[[:digit:]]+"};
                    if(!regex_match(argv[i+1],number)) {
                        raise_error("-t <hour> <filename.log>\n\t\tHour needs to be a number");
                        return 25;
                    } else if (atoi(argv[i+1] < 0 || atoi(argv[i+1] > 23 )) {
                        raise_error("-t <hour> <filename.log\n\t\tHour needs to be between 0 & 23");
                        return 28;
                    }

                } else {
                    raise_error("-g <hour> <filename.log\n\t\t-t needs an hour");
                    return 29;
                }
            } else {
                raise_error("options accepted:\n\t\t-g <filename.dot>\n\t\t-e\n\t\t-t <heure>\nuse man analog for more informations");
                return 22;
            }
        }
        i++;
    }
}