// made by THE madeline
// i wrote this while sleep deprived i cant remember what any of this does tbh

#include <iostream>
#include <fstream>
#include <math.h>
#include <cmath>
#include <cctype>

using namespace std;

int main(int argc, char **argv) {

	// OS VAR
	string line;
	ifstream file ("/etc/os-release");
        string os = "FUCK";

	if(file.is_open()) {

		while(getline(file, line)) {

			// check if prefix is "NAME", gets distro name
			if(line.substr(0, 4) == "NAME") {

				// get substring starting at the first quotmark. len to get whole line
				os = line.substr(line.find("\"") + 1, line.length());
				// cut off the last quotmark
				os = os.substr(0, os.length() - 1);


				break;

			}

		}

		file.close();

	}


	// final output
	// i really should have made these ansi codes into variables. whoops
	cout<<"   \e[1m\e[38;5;202m\e[1m\e[38;5;255m_,-='\e[1m\e[38;5;202m\"-.__               /\\_/\\      \n";
	cout<<"   \e[1m\e[38;5;255m`-.}       \e[1m\e[38;5;202m`=._,.-==-._.,  \033[0m0 0\e[1m\e[38;5;202m._,\n";
	cout<<"      \e[1m\e[38;5;255m`\e[1m\e[38;5;202m-.__   _,-.   )       _,.-'\n";
	cout<<"           `\"     \e[1m\e[38;5;232mG\e[1m\e[38;5;202m..\e[1m\e[38;5;232mm\e[1m\e[38;5;202m-\"^\e[1m\e[38;5;232mm\e[1m\e[38;5;202m`\e[1m\e[38;5;232mm\e[1m\e[38;5;202m'\n";
	cout<<"\033[0m\e[38;5;064m┌─────────────────────────────────────┐\e[38;5;094m\n";

  	// WM VAR
	string wm = getenv("GDMSESSION");

	// output vars
	// string osF = "os: " + os;
	// string wmF = "wm: " + wm;

	string osF = "os: " + os;
	string wmF = "wm: " + wm;

	// beep boop translate that sweet sweet lua logic into this janky shit
  int x = floor(37 - osF.length() - wmF.length()); //- osF.length() - wmF.length();
  
  string spc1;
  string spc2;

  if(x % 3 == 0) {

    string spc1(floor(x / 3), ' ');
    string spc2(floor(x / 3), ' ');
    cout << "│"<< spc1 << "\e[1m\e[38;5;202m" << osF << spc2 << wmF << "\033[0m" << spc1 << "\e[38;5;094m│"; // os & wm

  }
  else {

    int rem = remainder(x, 3);

    if(remainder(rem, 2) == 0) {
      
      string spc1(floor(x / 3) + rem / 2, ' ');
      string spc2(floor(x / 3), ' ');

      cout << "│"<< spc1 << "\e[1m\e[38;5;202m" << osF << spc2 << wmF << "\033[0m" << spc1 << "\e[38;5;094m│"; // os & wm

    }
    else {

      string spc1(floor(x / 3), ' ');
      string spc2(floor(x / 3) + rem, ' ');

	  cout << "│"<< spc1 << "\e[1m\e[38;5;202m" << osF << spc2 << wmF << "\033[0m" << spc1 << "\e[38;5;094m│"; // os & wm

    }

  }
	
	cout<<"\n└─────────────────────────────────────┘\n";



    for (int i = 0; i < argc; i++) {

        string arg = argv[i];


        if(arg == "--debug" || arg == "-d") {

            cout<<"\n";
			if(x % 3 == 0) {

    			string spc1(floor(x / 3), ' ');
  				string spc2(floor(x / 3), ' ');

				cout<<"\nIF";
				cout<<"\nx    :  "<<x;
				cout<<"\nspc1 :  "<<spc1.length();
				cout<<"\nspc2 :  "<<spc2.length();

			}
			else {

  				string spc1(remainder(x, 3), ' ');
  				string spc2(x - remainder(x, 3), ' ');

				cout<<"\nELSE";
				cout<<"\nx    :  "<<x;
				cout<<"\nspc1 :  "<<spc1.length();
				cout<<"\nspc2 :  "<<spc2.length();

			}


			cout<<"\n";

        }

    }

	return 0;

}

// ugh
