#include <vector>
#include <sstream>
#include <fstream>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
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
        string Active;

    //creating member functions:
    public:
        Airline(string &line);
        int getAirlineId(){return AirlineID;}
        void setAirlineId(int airlineId){AirlineID = airlineId;}
        void setName(string name){Name = name;}
        string getName(){return Name;}
        string getAlias(){return Alias;}
        void setAlias(string alias){Alias = alias;}
        string getCountry(){return Country;}
        void setCountry(string country){Country = country;}

};