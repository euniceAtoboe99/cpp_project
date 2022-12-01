
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

class Route{

    //creating member variables
    private:
        string Airline;
        int AirlineID;
        string startAirport;
        int startAirportID;
        string goalAirport;
        int goalAirportID;
        string Codeshare;
        int Stops;
        string Equipment;

    public:

        //creating member functions:
        explicit Route(vector<string> &route_fields);
        string getAirline(){return Airline;}
        void setAirline(string air_line){Airline = air_line;}
        string getstartAirport(){return startAirport;}
        void setstartAirport(string airport){startAirport = airport;}
        int getstartAirportId() const{return startAirportID;}
        void setstartAirportId(int source_airport_id){startAirportID = source_airport_id;}
        string getgoalAirport(){return goalAirport;}
        void setgoalAirport(string de_airport){goalAirport = de_airport;}
        int getgoalAirportId() const{return goalAirportID;}
        void setgoalAirportId(int de_airportID){goalAirportID = de_airportID;}
        string getCodeshare(){return Codeshare;}
        void setCodeshare(string codes_share){Codeshare = codes_share;}
        int getStops() const{return Stops;}
        void setStops(int no_stops){Stops = no_stops;}
        string getEquipment(){return Equipment;}
        void setEquipment(string eqi){Equipment = eqi;}

};
