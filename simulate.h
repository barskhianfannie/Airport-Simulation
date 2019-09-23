#ifndef SIMULATE_H
#define SIMULATE_H

//  Author : Fannie Barskhian
//  Project : Airport Simulate
//  Class   : CS8 Data Structures


/**This Class will take user conditions to simulate an airport
    The airport simulation will provide information regarding landings / takeoffs and plane crashes
    The simulator will use the Strip Class to check if the strip is occupied and if it isn't and if planes
    are in the queue, it will occupy the strip.
    The simulator will also use the Bool Source Class to calculate probability and add's to the land / take_off queues.
    The simulator will also use the Averager Class to take the time and plane count calculated in the airport function
    to calculate the average wait times for landing and take offs.
**/


class Simulate
{
    public:

        Simulate(unsigned int land_occup_time,unsigned int take_off_occup_time,
                 double land_prob, double take_off_prob
                 , unsigned int total_t, int crash_lim);

        void airport_simulate();


    private:

        unsigned int land_occupation_time;
        unsigned int take_off_occupation_time;
        double land_probability;
        double take_off_probability;
        unsigned int total_time;
        int crash_limit;

};





#endif // SIMULATE_H
