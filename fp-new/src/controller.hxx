#pragma once

#include "model.hxx"
#include "view.hxx"
#include <ge211.hxx>

//Controller class interacts with the computer clicks and the ge211 game
//framework to make the game run
class Controller : public ge211::Abstract_game {

public:

    //Construct a controller
    explicit Controller();

protected:

    //When certain keys are pressed, call a function in model
    void on_key(ge211::Key) override;

    //Draw each frame of the game
    void draw(ge211::Sprite_set &) override;

    //Update the state of the model every frame
    void on_frame(double dt) override;

    //Return the initial window dimensions
    ge211::Dimensions initial_window_dimensions() const override;

    //Return the initial window title
    std::string initial_window_title() const override;

private:
    Model model_;
    View view_;

};

