#pragma once

#include <iostream>
#include <vector>
#include <ge211.hxx>

//Bike class contains information about each bike and functions for altering
//their motion
class Bike {

    // Constructs a new bike. The bikes will be positioned at the top
    // center of the Arena (bike1) and at the bottom center of the Arena
    // (bike2). The bikes start not moving.

public:

    friend struct Test_access;

    //Construct a bike
    Bike();

    Bike(ge211::Dimensions, ge211::Position, int);

    // Returns a new bike like this one but whose position has been
    // updated by adding on the velocity.
    Bike next() const;

    // Rotate the direction of the velocity right 90 degrees.
    void rotate_right();

    // Rotate the direction of the velocity left 90 degrees.
    void rotate_left();

    // Return the current position of the center of the bike
    ge211::Position get_position() const { return center_; }

    // Return the current velocity of the bike
    ge211::Dimensions get_velocity() const { return velocity_; }

    // Directional vectors that are used throughout the program to assess the
    // direction of a bike
    ge211::Dimensions up_;
    ge211::Dimensions down_;
    ge211::Dimensions left_;
    ge211::Dimensions right_;

private:

    // The velocity of the bike in pixels per tick.
    ge211::Dimensions velocity_;

    int speed_val;

    // The position of the center of the bike.
    ge211::Position center_;

};