#include "Airport.h"
#include <utility>
#include <vector>
#include <string>
using namespace std;

Airport::Airport (const vector<string> &field){
//    vector<string> field;
//    string fieldword;
//    stringstream s(line);
//    while (getline(s, fieldword, ',')){
//        field.push_back(fieldword);
//    }
        airportId = stoi(field[0]);
        airportName = field[1];
        City = field[2];
        Country = field[3];
        IATA = field[4];
        ICAO = field[5];
        Latitude = stof(field[6]);
        Longitude = stof(field[7]);
       
    }
int Airport::getAirportId() const{return airportId;}
void Airport::setAirportId(int aId){airportId = aId;}
string Airport::getAirportName(){return airportName;}
void Airport::setAirportName(string aportName){airportName = std::move(aportName);}
string Airport::getCity(){return City;}
void Airport::setCity(string city_name){City = std::move(city_name);}
string Airport::getCountryName(){return Country;}
void Airport::setCountry(string country_name){Country = std::move(country_name);}
string Airport::getIATA(){return IATA;}
void Airport::setIATA(string iata){IATA = std::move(iata);}
string Airport::getICAO(){return ICAO;}
void Airport::setICOA(string icao){ICAO = std::move(icao);}
float Airport::getLatitude() const{return Latitude;}
void Airport::setLatitude(float lat){Latitude = lat;}
float Airport::getLongitude() const{return Longitude;}
void Airport::setLongitude(float longt){Longitude = longt;}