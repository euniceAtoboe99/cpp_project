#include <bits/stdc++.h>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

class Airport{
    private: 
        int airportId;
        string airportName;
        string City;
        string Country;
        string IATA;
        string ICAO;
        float Latitude;
        float Longitude;
    

    public:
    //creating member functions:
        int getAirportId(){return airportId;}
        void setAirportId(int aId){airportId = aId;}
        string getAirportName(){return airportName;}
        void setAirportName(string aportName){airportName = aportName;}
        string getCity(){return City;}
        void setCity(string city_name){City = city_name;}
        string getCountryName(){return Country;}
        void setCountry(string country_name){Country = country_name;}
        string getIATA(){return IATA;}
        void setIATA(string iata){IATA = iata;}
        string getICAO(){return ICAO;}
        void setICOA(string icao){ICAO = icao;}
        float getLatitude(){return Latitude;}
        void setLatitude(float lat){Latitude = lat;}
        float getLongitude(){return Longitude;}
        void setLongitude(float longt){Longitude = longt;}
        int getAltitude(){return Altitude;}
        void setAltitude(int alt){Altitude = alt;}
        float getTimezone(){return Timezone;}
        void setTimezone(float t_zone){Timezone = t_zone;}   

};
// 