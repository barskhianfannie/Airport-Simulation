//  Author : Fannie Barskhian
//  Project : Airport Simulate
//  Class   : CS8 Data Structures

#include <iostream>
#include "../../airport/airport/simulate.h"
#include "../../Includes/Stack_Queue/queue_class.h"
#include "../../airport/airport/strip.h"


Simulate::Simulate(unsigned int land_occup_time,unsigned int take_off_occup_time,
         double land_prob, double take_off_prob
         , unsigned int total_t, int crash_lim)
{
    land_occupation_time = land_occup_time;
    take_off_occupation_time = take_off_occup_time;
    land_probability = land_prob;
    take_off_probability = take_off_prob;
    total_time = total_t;
    crash_limit = crash_lim;
}


void Simulate::airport_simulate()
{
    Queue<unsigned int> landing_times;
    Queue<unsigned int> take_off_times;
    unsigned int next;
    unsigned int take_off_next;
    int crashed_planes = 0;
    Bool_Source arrival(land_probability, take_off_probability);
    Strip strip(land_occupation_time, take_off_occupation_time);
    Averager wait_times;
    unsigned int current_second;

    cout << "==========================================================================" << endl;
    cout << "WELCOME TO LAX INTERNATIONAL AIRPORT SIMULATION " << endl;
    cout << "==========================================================================" << endl;
    cout << "Land Strip Occupation Time: " << land_occupation_time << endl;
    cout << "Take Off Strip Occupation Time: " << take_off_occupation_time << endl;
    cout << "Probability of Plane Landing  during a second: ";
    cout << land_probability << endl;
    cout << "Probability of Plane Takeoff during a second: ";
    cout << take_off_probability << endl;
    cout << "Total simulation seconds: " << total_time << endl;

    for (current_second = 1; current_second <= total_time; current_second++) {

        if (arrival.take_off_query())
        {
             take_off_times.push(current_second);
        }else if(arrival.land_query()){
            landing_times.push(current_second);
        }

        if ((!strip.strip_occupied()) && (!landing_times.empty()))
        {
            next = landing_times.front( );
            if((current_second - next) >= crash_limit)
            {
                landing_times.pop( );
                crashed_planes += 1;
            }else{
                landing_times.pop();
                wait_times.land_next_number(current_second - next);
                strip.start_land_strip_occupation();

            }
        }else if((!strip.strip_occupied()) && (landing_times.empty()) && (!take_off_times.empty()))
        {
            take_off_next = take_off_times.front( );
            take_off_times.pop( );
            wait_times.take_off_next_number(current_second - take_off_next);
            strip.start_take_off_strip_occupation();
        }
        strip.one_second();
        }
    cout << endl;
    cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl << endl << endl;

    cout << wait_times.t_count() << " Planes Took Off. " <<  endl;
    cout <<  wait_times.lnd_count() <<" Planes Landed.  " << endl;
    if (wait_times.t_count() > 0)
    cout << "Average Take Off Wait Time: " << wait_times.take_off_average() << " Seconds. " << endl;
    if (wait_times.lnd_count() > 0)
    cout << "Average Landing Wait Time: " << wait_times.land_average() << " Seconds. " << endl;
    if(crashed_planes > 0)
    {
        cout <<  crashed_planes << " Planes Crashed :( " << endl;
    }else{
        cout << "No Planes Crashed Today! :)" << endl;
    }

    cout << "Planes Left in Landing Queue: " << landing_times.get_size() << endl;
    cout << "Planes Left in Take Off Queue: " << take_off_times.get_size() << endl << endl;
    cout << "==========================================================================" << endl << endl << endl;
}
