#include "CryptAnalysis.h"
#include "LanguageLetters.h"
#include "VigenereCrypt.h"

CryptAnalysis::CryptAnalysis()
{
    //ctor
}

float KeyLength(){ //Finding key length-------------------------------------------------------------------------------
    cout << "Finding key length..." << endl << endl;

    float m; //counts how many coincidences there are between original text and comparison row
    float coincidence = 0; //counts how many rows have coincidences above a certain percent
    float space = 0; //counts how many spaces between coincidences
    float keyLength; //stores key length value
    float rows = 100; //number of rows to shift and test for coincidences
    string shift = onlyAlpha; //stores shifted rows

    int percent; //percent that turns coincidences significant
    cout << "> Enter the number of times, out of 100, that a coincidence must occur to become significant." << endl << "(Recommended is between 10 and 21): ";
    cin >> percent;
    cout << endl;

    for(int i = 1; i < rows; i++){
        m = 0;
        for(int ii = 0; i < onlyAlpha.length(); ii++){ //shifts rows
            if((ii+i+1) >= shift.length()){
                break;
            } else if(ii < i){
                shift.at(ii) = 0;
            } else {
                shift.at(ii) = onlyAlpha.at(ii-i);
            }
            if(onlyAlpha.at(ii) == shift.at(ii)){
                m++;
            }
        }
        if((m/rows)*10 >= percent){ //counts how many spaces in between significant coincidences
            coincidence++;
        } else {
            space++;
        }
    }
    keyLength = (rows/coincidence); //calculates key length

    cout << "> Number of coincidences: " << coincidence << endl << endl;
    cout << "> Key length: " << nearbyint(keyLength);

    cout << endl << endl <<"------------------------------------------------------------" << endl << endl; //formatting
}


void KeyChars(){ //finding key contents-----------------------------------------------------------------------------

    cout << "Finding characters of the key... " << endl << endl;

    long double lettercount[totalletter] = {0}; //counts how many of each character is in the file
    long double fileFreq[totalletter]; //holds frequencies of each character in the ciphertext file
    long double langFreq[totalletter] = {8.34, 1.54, 2.73, 4.14, 12.60, 2.03, 1.92, 6.11, 6.71, 0.23, 0.87, 4.24, 2.53, 6.80, 7.70, 1.66, 0.09, 5.68, 6.11, 9.37, 2.85, 1.06, 2.34, 0.20, 2.04, 0.06};
    long double copyFreq[totalletter] = {0}; //copy of langFreq; Holds frequencies of each character in the language

    int numRow = totalletter; //sets number of rows
    long double temp[1] = {0}; //temp variable for shifting array
    int key[(int)keyLength]; //array for key values; holds characters in the key
    long double sum[numRow] = {0}; //holds sum of calculations for each row
    long double finalsum[numRow] = {0};//holds row with the largest sum
    int finalI = 0; //holds index for the row with largest sum
    long double charKey[(int)keyLength] = {0}; //holds number of characters in file text affected by each character of the key

    cout << "> Key: ";
    for(int k = 0; k < (int)keyLength; k++){

        finalI = 0; //resets value
        finalsum[k] = 0; //resets value

        for (int i = 0; i < totalletter; i++){ //resets letter count value
            lettercount[i] = 0;
            sum[i] = 0;
        }

        //find counts number of each character in a string of only characters affected by each key character
        for(int i = k; i < onlyAlpha.length(); i+= (int)keyLength){
            for(int ii = 0; ii < totalletter; ii++){
                if ((char)ASCII[ii] == onlyAlpha.at(i)){
                    lettercount[ii]++;
                    charKey[k]++;
                }
            }
        }

        for(int i = 0; i < totalletter; i++){ //Calculates frequencies for file and language
            copyFreq[i] = (langFreq[i]/100);
            fileFreq[i] = (lettercount[i]/charKey[k]);
        }

        for(int i = 0; i < numRow; i++){
            for(int ii = 0;  ii < totalletter; ii++){ //Adds freq math to get sum for a single row of a different combination
                sum[i] = sum[i] + (fileFreq[ii] * copyFreq[ii]);
            }
            //After finding totals for each rows, find largest row. The shift for the largest row is the key shift number.
            if((sum[i] > sum[i-1])&&(i > 0)&&(sum[i] > finalsum[k])){ //this is the problem
                finalI = i;
                finalsum[k] = sum[i];
                key[k] = ASCII[finalI]; // ASCII(I) should be the same as shift number
            }
            for(int f = 0; f < totalletter-1; f++){ //shifts rows
                temp[0] = fileFreq[f];
                fileFreq[f] =  fileFreq[f+1];
                fileFreq[f+1] = temp[0];
            }
        }
        cout << (char)key[k];
    }

    cout << endl <<"------------------------------------------------------------" << endl; //formatting
}
