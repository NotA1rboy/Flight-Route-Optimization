#ifndef FLIGHT_H
#define FLIGHT_H

#include <bits/stdc++.h>
using namespace std;

class Flight {
public:
    int flight_no;
    int start_city;
    int departure_time;
    int end_city;
    int arrival_time;
    int fare;

    Flight(int f_no, int s_city, int dep_t, int e_city, int arr_t, int cost) {
        flight_no = f_no;
        start_city = s_city;
        departure_time = dep_t;
        end_city = e_city;
        arrival_time = arr_t;
        fare = cost;
    }

    bool operator==(const Flight& other) const {
        return flight_no == other.flight_no;
    }
};

#endif