#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

//GET THE ID OF THE FLOOR
string getFloorID(string line) {
    string newID;
    int ipos; //pos of colon
    ipos = line.find(":",0);

    newID.append(line , ipos +1 , line.length());
    return newID;
}//works >>>>>>>>> cout << "ID TEst = " << getFloorID("Mugler:in mt") << endl;

//CONVERT STRING TO INTEGER
int stringToInt(string line) {
	stringstream s1(line);
	int temp = 0;
	s1 >> temp;
	return temp;
}

//SEPERATE TENANT NAMES
void SeperateTenantNames(string OriginalLine , int iNumCommas) {
    string line = "";
    string fileLine = OriginalLine;
    int ipos;
for(int i = 0 ; i <iNumCommas; i++) {
//while (fileLine.find(',' ,0) >= 0 || fileLine.find(',',0) < fileLine.length()) {//(fileLine.find(',' , 0) != npos) {
    ipos = fileLine.find(',' , 0);
    cout <<"ipos : " << ipos;
    line.append( fileLine , 0, ipos);//first x numbers from fileLine to line
    cout << " The line : " << line << endl;
    fileLine.erase(0, ipos+1 );  //all i needed was to say ipos+1 INSTEAD OF ipos  
    line = "";
}
cout <<"last : " << fileLine << endl;
}//end of SeperateTenantNames(string fileLine)

//GET NUMBER OF DELIMETERS IN STRING
int getNumDelim(string line) {
    int iDelimCount = 0;
    while ( (line.find(',' , 0) != string::npos) ) {
        iDelimCount++;
        line.erase(0, line.find(',' , 0) +1 ); 
    }
    //cout << "The number of commas : " << iDelimCount << endl;
    return iDelimCount;//REMEMBER THIS SHOWS NUMBER OF COMMAS AND NOT WORDS
}


//get comma delimeted list and assign each value to dynamic string array
void CommaListToDynamicStringArray(string CommaList , string * arrDynamicArray) {
    //get number of commas in list
    int iCommaCount = getNumDelim(CommaList);//iComma count gets number of commas
    int ipos;
    string line;

for(int i = 0 ; i <iCommaCount; i++) {
    ipos = CommaList.find(',' , 0);
    //cout <<"ipos : " << ipos;
    line.append( CommaList , 0, ipos);//first x numbers from fileLine to line
    cout << "The line : " << line << endl;
    arrDynamicArray[i] = line;//forgot to do the actual assignment of these values
    CommaList.erase(0, ipos+1 );  //all i needed was to say ipos+1 INSTEAD OF ipos  
    line = "";
}
cout << "The Last Line : " << CommaList << endl;
//arrDynamicArray[iCommaCount+1] = CommaList;
arrDynamicArray[iCommaCount] = CommaList;
    //<<"last : " << fileLine << endl;
    //cout << arrDynamicArray[i];
    
}

//================================================================================
int main() {//BEGINNING OF MAIN FUNCTIONS
//================================================================================
//define file name and open the buidling data fil
fstream fFile("building.data");
string sLine;
/*display all contents
while (getline(fFile , sLine)) {
    cout << "Line : " << sLine << endl;
}*/ 
//cout << "this is sLine : " << sLine <<" " << sLine.size() << endl;

getline(fFile , sLine);//this gets the FIRST line in the building data
cout << sLine << endl;//dsiplay the first line of text file
int NumFloorVisits = getNumDelim(sLine) + 1;
cout << getNumDelim(sLine) + 1 << " is the number of floors to visit" << endl;

//assign each of the random orders to a spot in the order array
string * FloorVisitOrder = NULL;
FloorVisitOrder = new string[ getNumDelim(sLine) + 1 ];//dynamic array w 8 floors to visit

CommaListToDynamicStringArray(sLine , FloorVisitOrder); //gets the order in which we visit the floors
//Display all the whole floor visit array : 
cout << endl << endl << "Floor Visit Order Dynamic Array Printed : " << endl;
for (int i = 0 ; i < getNumDelim(sLine)+1 ; i++) {
    cout << i+1 << " - " << FloorVisitOrder[i] << endl;//consisting Floor IDs
}//display all of the Floor Order Visit Array

//=================================================================
//find the largest (highest) floor ID of the building
int BiggestFloorID;
string sBiggestFloorID;
BiggestFloorID = -1;

/*for (int i = 0 ; i < NumFloorVisits-1 ; i++) {//NumFloorVisits instead of another getNumDelim(sLine)+1
cout << i <<" the value we are currently looking at : " << stringToInt(FloorVisitOrder[i]) << " curr big val " << BiggestFloorID << endl;
    if ( (stringToInt(FloorVisitOrder[i+1]))  > (stringToInt(FloorVisitOrder[i])) ) {
    //if ( stringToInt(FloorVisitOrder[i]) < stringToInt(FloorVisitOrder[i+1]) ) {
        BiggestFloorID = stringToInt(FloorVisitOrder[i+1]);
        cout << "the current biggest " << stringToInt(FloorVisitOrder[i+1]) << endl;
        sBiggestFloorID = FloorVisitOrder[i+1];

    }
    
}//ssssssssssooooooooooooo why cant i find the biggest value here?
cout << "The biggest Floor id : " << BiggestFloorID << " " << sBiggestFloorID << endl;*/

for (int i = 0 ; i < NumFloorVisits-1 ; i++) {
    if( (stringToInt(FloorVisitOrder[i]))  < (stringToInt(FloorVisitOrder[i+1]) ) ) {
    //if( (stringToInt(FloorVisitOrder[i-1]))  < (stringToInt(FloorVisitOrder[i]) ) ) {
        BiggestFloorID = stringToInt(FloorVisitOrder[i+1]);
    }

}
cout << "The biggest Floor ID is : " << BiggestFloorID << endl;

//the biggest in this case is 10 so I will just make the biggest floor id = 10 by force for now
BiggestFloorID = 10;//well 0 to 10 floors is ACTUALLY 11 floors so we will always have to add one
//==================================================================


//the big dynamic shit
//==================================================================
//create array AND THEN create dynamic number of arrays at each point
int FloorID, numTenants;
string ** Floors = new string * [BiggestFloorID+1];//so we have the 10 floors now
for (int i = 0; i < BiggestFloorID+1; i++)
{
    Floors[i] = NULL;
}

//string ** Floors = new string[BiggestFloorID+1];//so we have the 10 floors now

for (int i = 0 ; i < NumFloorVisits ; i++) {//so 8 floors we have to visit
    
    getline(fFile , sLine);//this gets the first line that contains the id number
    //cout << sLine << endl;
    FloorID = stringToInt( getFloorID(sLine) );
    numTenants = 1 + getNumDelim(sLine);
    Floors[FloorID] = new string [numTenants];


    //assign floors[floorID][numTenants] a name each;
    getline(fFile , sLine);//now we are at the number of 
    //cout << "sLine : Names - " << sLine << endl;
    for (int t = 0; t < numTenants-1; t++)//eg 4 tenants 
    {
       //Floors[FloorID][t] = 
       CommaListToDynamicStringArray( sLine , Floors[FloorID]);

    }

    
    cout << "Floor Level ID : " << i << endl;// i think lik, it has to be a conditional loop bc 
    if (Floors[i] != NULL) {
    for (int t = 0; t < numTenants; t++)//I love you so much and I hope you'll forgive me for confusing the shit out of you because you from rn is going to go watch westworld
    {
        cout << t << " - " << Floors[i][t] << " ";
    }


}//the end - we are going to deal with the next floor now
//the big dynamic shit
//==================================================================


//DISPLAYING THE SHITSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSS

/*for (int i = 0; i < NumFloorVisits ; i++) {//    Floors[FloorID] = new string [numTenants];
    cout << "Floor Level ID : " << i << endl;// i think lik, it has to be a conditional loop bc 
    if Floors[i] != NULL {
    for (int t = 0; t < numTenants; t++)//
    {
        cout << t << " - " << Floors[i][t] << " ";
    }
    }//end of if the shit isnt null*/
}
//DISPLAYING THE SHITSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSS


//DEALLOCATION OF EVERYTHING
for (int i = 0; i < BiggestFloorID+1 ; i++) {//    Floors[FloorID] = new string [numTenants];
    delete [] Floors[i];
    Floors[i] = NULL;
}
delete [] Floors;//for string ** Floors = new string * [BiggestFloorID+1];
Floors = NULL;

delete [] FloorVisitOrder;//get rid of the Dynamic VIsit Floors Order Array for FloorVisitOrder = new string[ getNumDelim(sLine) + 1 ];
FloorVisitOrder = NULL;
//getline(fFile , sLine);
//getline(fFile , sLine);
//SeperateTenantNames("Siya,four,g" , getNumDelim("Siya,four,g"));
//SeperateTenantNames(sLine , getNumDelim(sLine));

fFile.close();//close the file


return 0;
//================================================================================    
}//END OF MAIN FUNCTION
//================================================================================