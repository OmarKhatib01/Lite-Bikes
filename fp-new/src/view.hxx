#pragma once

#include "model.hxx"
#include <ge211.hxx>

#include <string>

//View controls what is displayed on the screen
class View {

public:
    //Construct a View
    explicit View(Model const &);

    //Draw the sprites in Sprite_set
    void draw(ge211::Sprite_set &sprites);

    //Return the initial window dimensions
    ge211::Dimensions initial_window_dimensions() const;

    //Return the initial window title
    std::string initial_window_title() const;


private:
    Model const &model_;
    std::string window_title;

    //Sprites that are used in View::draw() :

    ge211::Color const bike1_color_{255, 0, 0};
    ge211::Color const bike2_color_{0, 255, 0};

    ge211::Rectangle_sprite const bike1_sprite_vert{{model_.arena
                                                             .bike_dims},
                                                    bike1_color_};
    ge211::Rectangle_sprite const bike2_sprite_vert{{model_.arena
                                                             .bike_dims},
                                                    bike2_color_};

    ge211::Rectangle_sprite const bike1_sprite_horiz{
            {model_.arena
                     .bike_dims.height, model_.arena
                     .bike_dims.width},
            bike1_color_};
    ge211::Rectangle_sprite const bike2_sprite_horiz{
            {model_.arena
                     .bike_dims.height, model_.arena
                     .bike_dims.width},
            bike2_color_};

    ge211::Rectangle_sprite const
            bike1_trail_pixel{ge211::Dimensions{model_.arena.speed_val - 2,
                                                model_.arena.speed_val - 2},
                              bike1_color_.lighten(.7)};
    ge211::Rectangle_sprite const bike2_trail_pixel{
            ge211::Dimensions{model_.arena.speed_val - 2,
                              model_.arena.speed_val - 2},
            bike2_color_.lighten(.7)};

    ge211::Text_sprite const bike1_wins_msg{"GAME OVER: Red Wins!",
                                            ge211::Font("sans.ttf", 40)};
    ge211::Text_sprite const bike2_wins_msg{"GAME OVER: Green Wins!",
                                            ge211::Font("sans.ttf", 40)};
    ge211::Text_sprite const tie_msg{"GAME OVER: Both Bikes Were Destroyed!",
                                     ge211::Font("sans.ttf", 40)};

    ge211::Text_sprite const restart_msg{"Press r to restart",
                                         ge211::Font("sans.ttf", 25)};
    ge211::Text_sprite const start_msg{"Press space to play",
                                       ge211::Font("sans.ttf", 25)};

    ge211::Text_sprite bike1_score{"0", (ge211::Font("sans.ttf", 30))};
    ge211::Text_sprite bike2_score{"0", ge211::Font("sans.ttf", 30)};

};