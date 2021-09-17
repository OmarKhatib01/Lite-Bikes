#pragma once

#include <iostream>
#include <vector>
#include <ge211.hxx>

//Arena class contains the default game values to be used by the model and view
class Arena {

public:

    //Construct an arena
    explicit Arena();

    explicit Arena(int speed,
                   ge211::Dimensions arena_dimensions,
                   ge211::Dimensions bike_dimensions);

    const ge211::Position bike1_init_pos;
    const ge211::Position bike2_init_pos;
    const ge211::Dimensions bike1_init_velocity;
    const ge211::Dimensions bike2_init_velocity;
    const int speed_val;

    const ge211::Dimensions dimensions;
    const ge211::Dimensions bike_dims;

};