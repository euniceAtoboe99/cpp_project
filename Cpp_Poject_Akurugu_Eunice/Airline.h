
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

class Airline{
    //declaring fields for Airline:
    private: 
        int AirlineID;
        string Name;
        string Alias;
        string IATA;
        string ICAO;
        string Callsign;
        string Country;
        char Active;

    //creating member functions:
    public:
        Airport(string line);
        int getAirlineId(){return AirlineID;}
        void setAirlineId(int airlineId){AirlineID = airlineId;}
        void setName(string name){Name = name;}
        string getName(){return Name;}
        string getAlias(){return Alias;}
        void setAlias(string alias){Alias = alias;}
        string getCountry(){return Country;}
        void setCountry(string country){Country = country;}
        string getICAO(){return ICAO;}
        void setICOA(string icao){ICAO = icao;}
        string getIATA(){return IATA;}
        void setIATA(string iata){IATA = iata;}

};

int main(){
    fstream Airline;
    string line;
    Airline.open("airlines.csv");
    while (Airline.is_open() != EOF){
        getline(Airline, line);
        cout << line << endl;
    }
    return 0;
}