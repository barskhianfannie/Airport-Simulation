#ifndef STRIP_H
#define STRIP_H

//  Author : Fannie Barskhian
//  Project : Airport Simulate
//  Class   : CS8 Data Structures


#include <stdlib.h>

class Strip
{
public:

    Strip(unsigned int l_sec = 60, unsigned int t_sec = 60 );



    void one_second();
    void start_land_strip_occupation(); // Start the time that the strip is now occupied
    void start_take_off_strip_occupation();
    bool strip_occupied() const {return (time_Left > 0);} // will let you know if the strip is occupied or not
    int fuel_gage();


private:

    unsigned int total_land_occupied_time;  // seconds for a single land or takeoff period
    unsigned int total_take_off_occupied_time;  // seconds for a single land or takeoff period
    unsigned int time_Left;      // time left for the landing strip to be empty
    int fuel_limit;


};

class Bool_Source
{
public:

    Bool_Source(double l_p = 0.5, double t_p = 0.5);
    bool land_query() const;
    bool take_off_query() const;


private:

    double l_prob; // land probability
    double t_probability;  // take off probability
};


class Averager
{
public:
    Averager();
    void land_next_number(double value); // adds times into the average calculation
    void take_off_next_number(double val);
    double land_average() const; // calculates landing average
    double take_off_average() const;
    size_t lnd_count( ) const { return land_count; }
    size_t t_count( ) const { return take_off_count; }

public:

    size_t land_count;
    size_t take_off_count;
    int land_time_sum;
    int take_off_sum;
};

#endif // STRIP_H
