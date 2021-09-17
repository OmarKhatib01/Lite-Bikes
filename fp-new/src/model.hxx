#pragma once

#include <ge211.hxx>
#include <iostream>
#include <vector>

#include "arena.hxx"
#include "bike.hxx"

// used for the pixel array (trail for bikes)
// state of 1 is bike1's trail, state of 2 is bike2's trail
struct Pixel {

    ge211::Position position;
    int state;

    Pixel(ge211::Position pos, int s)
            : position{pos}, state(s) {}
};

// The game model holds the arena and bikes, and it dictates the game mechanics
class Model {

public:

    //Struct for testing
    friend struct Test_access;

    //Construct a Model with the values from the given Arena
    Model(Arena);

    //Set live_ to be true, signaling that the bikes are moving
    void launch();

    //Return if the game is finished
    bool is_game_over() const;

    //Return the winner of the game:
    //  1: Bike1 is the winner
    //  2: Bike2 is the winner
    //  3: Both bikes were destroyed, so it is a tie
    int winner() const { return winner_; }

    //Updates the state of the game for one frame
    // 1. If a bike is off the edge of the screen,
    //    the other bike is the winner.
    // 2. If a bike is intersecting with the trail
    //    of the other bike, the other bike is the winner.
    // 3. If the bikes collide, there is no winner.
    // 4. Move both bikes to their next position based on their current
    //    velocities.
    void update();

    //Reset all the attributes of the model
    void reset();

    //Return whether or not the model is live
    bool is_live() const { return live_; }

    //2D array of "pixels" (and integer 0, 1, or 2: representing the color of
    // the trail.
    std::vector<Pixel> pixels;

    Bike bike1;
    Bike bike2;
    Arena arena;

    int bike1_tally; //game score of bike1
    int bike2_tally; //game score of bike2

private:

    bool game_over_;
    bool live_;
    int winner_;

    // These helper functions all perform collision detection by telling us whether
    // this bike is past the given edge.
    bool bike_hits_edge(Bike bike) const;

    bool bike_hits_trail(Bike bike) const;

    bool bikes_collide() const;

};