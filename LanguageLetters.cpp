#include "LanguageLetters.h"

LanguageLetters::LangChar(){

    LanguageLetters ll; //create object

    //input characters used in the language----------------------------------------------------
    int totalletter;
    cout << "> Please enter the total number of characters in the alphabet: ";
    cin >> totalletter;
    ll.totalletter = totalletter;
    cout << endl;

    int ASCII[totalletter];
    int AZ = 0; //input for A-Z shortcut answer
    int c = 0; //Used to keep track of how many characters have been entered
    int AZnum = 65; //ASCII number for "A"; to start filling in characters A-Z

    if(totalletter >= 26){
        cout << "> Does this language use A-Z characters? Input 0 if no and 1 if yes: ";
        cin >> AZ;
        cout << endl;
    }

    if (AZ == 0){
            cout << "> Please enter other ASCII characters used in this language one by one: " << endl;
            for(; c < totalletter; c++){
                cin >> ASCII[c];
            }
    } else if (AZ == 1){
        for(; c < 26; c++){
            ASCII[c] = AZnum;
            AZnum++;
        }
        if (totalletter > 26){
            cout << "> Please enter other ASCII characters used in this language one by one: " << endl;
            for(; c < totalletter; c++){
                cin >> ASCII[c];
                ll.ASCII[c] = ASCII[c]; //send to class variables
            }
        }
    } else {
        cout << "Input is invalid, try again" << endl;
        cin >> AZ;
    }
    return 0;
}

long double LanguageLetters::LangFreq(){
    LanguageLetters ll; //create object
    long double langFreq[ll.totalletter] = {8.34, 1.54, 2.73, 4.14, 12.60, 2.03, 1.92, 6.11, 6.71, 0.23, 0.87, 4.24, 2.53, 6.80, 7.70, 1.66, 0.09, 5.68, 6.11, 9.37, 2.85, 1.06, 2.34, 0.20, 2.04, 0.06};
}
