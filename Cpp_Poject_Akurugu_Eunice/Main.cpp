
#include <vector>
#include <sstream>
#include <fstream>
#include <cmath>
#include <iostream>
#include <string>
#include "Airline.h"
#include "Airport.h"
#include "Route.h"
#include "Airline.cpp"
#include "Route.cpp"
#include "Airport.cpp"
using namespace std;

string distance(Airport Start,Airport goal)
{
    Adjacent = Start.getLatitude -goal.getLatitude;
    Opposite = Start.getLongitude - goal.getLongitude;
    Hypotenuse1=sqrt(pow(Adjacent, 2)) + pow(Opposite, 2);
    return Hypotenus;
}

Airport createAirport(const string &airport_City, const string &airport_Country) {
    /*This function takes a city name and country name and finds the corresponding airport associated with it */
    string line, token;
    fstream airport;
    airport.open("Airports.csv");
    
    while (!airport.eof()) {
        getline(airport, line);
        stringstream s(line);
        vector<string> strArray;

        while (getline(s, token, ',')) {
            strArray.push_back(token);
        }
        if (strArray[2].compare(airport_City) == 0 && strArray[3].compare(airport_Country) == 0) {
        Airport centre(line);
        return centre;
        }
    }
   
}

vector<Airport> locatePossibleGoalStateAirports(Airport startAirpot) {
    /*This functions takes a starting airport and locates all possible lines 
    that can be reached as the flight progress to a final stop.*/
    ifstream route;
    route.open("routes.csv");

    vector<Airport> setsOfGoalStates;
    //declaring a dynamic-sized array of type Airport:
    string s;
    string line, token;
    while (route.peek() != EOF) {

        getline(route, line);
        stringstream s(line);
        vector<string> strArray;
        while (getline(s, token, ',')) {
            strArray.push_back(token);
        }

        try {
                if (strArray[5] !="\N" && strArray[2] == startAirpot.getIATA() ||
                    strArray[2] == startAirpot.getICAO()) {

                    setsOfGoalStates.push_back(creatAirport(  stoi(strArray[5])));
                }

            }
            catch (const exception &e) {
                e.what();
            }
        }
    route.close();
    return setsOfGoalStates;
    }


   