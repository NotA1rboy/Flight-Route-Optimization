#ifndef PLANNER_H
#define PLANNER_H

#include <bits/stdc++.h>
#include "flight.h"
using namespace std;

struct SearchState {
    int city;
    int current_time;
    vector<Flight> route;
};

struct DijkstraState {
    int fare;
    int city;
    int current_time;
    vector<Flight> route;

    bool operator>(const DijkstraState& other) const {
        return fare > other.fare;
    }
};

class Planner {
private:
    vector<Flight> flights;

public:
    Planner(vector<Flight> f_list);
    vector<Flight> least_flights_earliest_route(int start_city, int end_city, int t1, int t2);
    vector<Flight> cheapest_route(int start_city, int end_city, int t1, int t2);
    vector<Flight> least_flights_cheapest_route(int start_city, int end_city, int t1, int t2);
};

#endif