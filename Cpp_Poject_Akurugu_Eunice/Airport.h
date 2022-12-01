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
        explicit Airport(const vector<string> &field);
        int getAirportId() const;
        void setAirportId(int aId);
        string getAirportName();
        void setAirportName(string aportName);
        string getCity();
        void setCity(string city_name);
        string getCountryName();
        void setCountry(string country_name);
        string getIATA();
        void setIATA(string iata);
        string getICAO();
        void setICOA(string icao);
        float getLatitude() const;
        void setLatitude(float lat);
        float getLongitude() const;
        void setLongitude(float longt);
};
// 