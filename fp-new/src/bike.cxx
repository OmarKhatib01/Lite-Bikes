#include "bike.hxx"
#include "model.hxx"


Bike::Bike(ge211::Dimensions velocity, ge211::Position position, int speed)
        : velocity_(velocity), center_(position), speed_val(speed),
          up_{0, -speed}, down_{0, speed}, left_{-speed, 0}, right_{speed, 0} {}

Bike Bike::next() const {
    Bike next_bike = *this;
    next_bike.center_ += next_bike.velocity_;

    return next_bike;
}

void Bike::rotate_right() {

    if (velocity_ == up_)
        velocity_ = right_;
    else if (velocity_ == right_)
        velocity_ = down_;
    else if (velocity_ == down_)
        velocity_ = left_;
    else
        velocity_ = up_;
}

void Bike::rotate_left() {

    if (velocity_ == up_)
        velocity_ = left_;
    else if (velocity_ == left_)
        velocity_ = down_;
    else if (velocity_ == down_)
        velocity_ = right_;
    else
        velocity_ = up_;
}