#pragma once

class Car
{
private:
    static constexpr int default_speed = 80;
    int _speed;
    double _time_for_1km;
    void compute_time_for_1km();
public:
    Car(int speed);
    Car();
    ~Car() {};
    int get_speed() const;
    void set_speed(int speed);
};
