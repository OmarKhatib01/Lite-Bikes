#include "controller.hxx"

using namespace ge211;

Controller::Controller()
        : model_(Arena()), view_(model_) {}

void Controller::on_key(ge211::Key key) {
    if (key == ge211::Key::code('q')) {
        quit();
    }
    if (key == ge211::Key::code(' ')) {
        model_.launch();
    }
    if (model_.is_game_over() && key == ge211::Key::code('r')) {
        model_.reset();
    } else {
        if (model_.is_live() && key == ge211::Key::code('k')) {
            model_.bike1.rotate_left();
        }
        if (model_.is_live() && key == ge211::Key::code('l')) {
            model_.bike1.rotate_right();
        }
        if (model_.is_live() && key == ge211::Key::code('a')) {
            model_.bike2.rotate_left();
        }
        if (model_.is_live() && key == ge211::Key::code('s')) {
            model_.bike2.rotate_right();
        }
    }
}

void Controller::draw(Sprite_set &sprites) {
    view_.draw(sprites);
}

void Controller::on_frame(double dt) {
    model_.update();
}

Dimensions Controller::initial_window_dimensions() const {
    return view_.initial_window_dimensions();
}

std::string Controller::initial_window_title() const {
    return view_.initial_window_title();
}