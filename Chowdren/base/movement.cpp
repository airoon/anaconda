#include "movement.h"
#include "frameobject.h"
#include "common.h"
#include "mathcommon.h"
#include <iostream>

inline double get_pixels(int speed)
{
    return speed / 8.0;
}

inline void get_dir(int dir, double & x, double & y)
{
    double r = rad(dir * 11.25);
    x = cos(r);
    y = -sin(r);
}

// Movement

Movement::Movement(FrameObject * instance)
: instance(instance), speed(0), add_x(0), add_y(0)
{

}

void Movement::update(float dt)
{

}

void Movement::set_max_speed(int v)
{
}

int Movement::get_speed()
{
    return speed;
}

void Movement::set_speed(int v)
{
    speed = v;
}

void Movement::start()
{
}

void Movement::stop()
{
    set_speed(0);
}

void Movement::bounce()
{
    set_speed(0);
}

bool Movement::is_stopped()
{
    return speed == 0;
}

void Movement::move(double x, double y)
{
    add_x += x;
    add_y += y;
    int xx = int(add_x);
    int yy = int(add_y);
    add_x -= xx;
    add_y -= yy;
    instance->set_position(instance->x + xx,
                           instance->y + yy);
}

void Movement::set_directions(unsigned int directions)
{
    this->directions = directions;
}

void Movement::set_node(const std::string & node)
{
}

bool Movement::is_path_finished()
{
    return false;
}

bool Movement::is_node_reached()
{
    return false;
}

// StaticMovement

StaticMovement::StaticMovement(FrameObject * instance)
: Movement(instance)
{

}

// BallMovement

BallMovement::BallMovement(FrameObject * instance)
: Movement(instance)
{

}

void BallMovement::update(float dt)
{
    double add_x, add_y;
    get_dir(instance->direction, add_x, add_y);
    double m = get_pixels(speed) * dt * instance->frame->timer_base;
    move(add_x * m, add_y * m);
}

// ShootMovement

ShootMovement::ShootMovement(FrameObject * instance)
: Movement(instance)
{

}

void ShootMovement::update(float dt)
{
    double add_x, add_y;
    get_dir(instance->direction, add_x, add_y);
    double m = get_pixels(speed) * dt * instance->frame->timer_base;
    move(add_x * m, add_y * m);
}
