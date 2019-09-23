//  Author : Fannie Barskhian
//  Project : Airport Simulate
//  Class   : CS8 Data Structures

#include <iostream>
#include <cstdlib>
#include "../../Includes/Stack_Queue/queue_class.h"
#include "../../Includes/Stack_Queue/stack_class.h"
#include "../../airport/airport/strip.h"
#include "../../airport/airport/simulate.h"

using namespace std;


int main()
{

    // Land Occupation Time, Take Off Occupation Time, land probability, take off probability, simulation time, fuel limit
    Simulate airport1(5, 15, 0.1, 0.09, 1000000, 20);
    airport1.airport_simulate();

    Simulate airport2(5, 15, 0.1, 0.09, 1440, 20);
    airport2.airport_simulate();

    Simulate airport3(5, 15, 0.1, 0.2, 1440, 20);
    airport3.airport_simulate();

    Simulate airport4(5, 15, 0.8, 0.9, 14445634, 20);
    airport4.airport_simulate();

    Simulate airport5(15, 15, 0.08, 0.09, 10000, 20);
    airport4.airport_simulate();


    return 0;
}
