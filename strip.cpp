//  Author : Fannie Barskhian
//  Project : Airport Simulate
//  Class   : CS8 Data Structures

#include "strip.h"
#include <cstdlib>
#include <cassert>
using namespace std;
#include <iostream>




Strip::Strip(unsigned int l_sec, unsigned int t_sec)
{
    total_take_off_occupied_time = t_sec;
    total_land_occupied_time = l_sec;
    time_Left = 0;
}

void Strip::one_second()
{
    if(strip_occupied())
    {
      --time_Left;
    }
}

void Strip::start_land_strip_occupation()
{
    time_Left = total_land_occupied_time;
}

void Strip::start_take_off_strip_occupation()
{
    time_Left = total_take_off_occupied_time;
}


Bool_Source::Bool_Source(double l_p, double t_p)
{
    assert(l_p >= 0);
    assert(l_p <= 1);
    assert(t_p >= 0);
    assert(t_p <= 1);
    l_prob= l_p;
    t_probability = t_p;
}

bool Bool_Source::land_query() const
{

    return (rand() < l_prob * RAND_MAX);
}

bool Bool_Source::take_off_query() const
{

    return (rand() < t_probability * RAND_MAX);
}

Averager::Averager()
{
    land_time_sum = 0;
    land_count = 0;
    take_off_count = 0;
    take_off_sum = 0;
}

void Averager::land_next_number(double value)
{
    land_count++;
    land_time_sum += value;
}


void Averager:: take_off_next_number(double val)
{
    take_off_count++;
    take_off_sum += val;
}

double Averager::land_average() const
{
    assert(land_count > 0);
    return (land_time_sum / land_count);

}

double Averager::take_off_average() const
{
    assert(take_off_count > 0);
    return (take_off_sum / take_off_count);
}





