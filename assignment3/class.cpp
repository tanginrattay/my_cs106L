#include "class.h"

Car::Car(int speed)
{
    this->_speed = speed;
    this->compute_time_for_1km();
}

Car::Car()
{
    this->_speed = default_speed;
    this->compute_time_for_1km();
}


int Car::get_speed() const
{
    return this->_speed;
}

void Car::set_speed(int speed)
{
    this->_speed = speed;
    this->compute_time_for_1km();
}

void Car::compute_time_for_1km()
{
    this->_time_for_1km = 1.0 / this->_speed;
}