#include "main.h"

using namespace pros;

#define MOTOR_PORT 1
Motor mtr(MOTOR_PORT, E_MOTOR_GEARSET_18, false);
Controller con(E_CONTROLLER_MASTER);

void initialize()
{
    pros::lcd::initialize();
}

void opcontrol()
{
    int time = 0;
    int speed = 0;

    bool first = true;

    while(true)
    {
        mtr.move(speed);
        
        pros::lcd::print(0, "%d: %lf", speed, mtr.get_actual_velocity());
        pros::lcd::print(1, "%d: %lf", mtr.get_target_velocity());
        
        if(con.get_digital(E_CONTROLLER_DIGITAL_A))
        {
            if(first == true)
            {
                first = false;
                speed += 5;
            }
        }
        else { first = true; }
    }
} 