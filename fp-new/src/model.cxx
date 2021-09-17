#include "model.hxx"

Model::Model(Arena a)
        : pixels(), arena(a),
          bike1(a.bike1_init_velocity, a.bike1_init_pos, a.speed_val),
          bike2(a.bike2_init_velocity, a.bike2_init_pos, a.speed_val),
          live_(false), game_over_(false), winner_(0), bike1_tally(0),
          bike2_tally(0) {}

void Model::update() {
    if (live_) {

        if (bike_hits_edge(bike1) && bike_hits_edge(bike2)) {
            game_over_ = true;
            winner_ = 3;
            live_ = false;
        } else if (bike_hits_edge(bike1)) {
            game_over_ = true;
            winner_ = 2;
            bike2_tally++;
            live_ = false;
        } else if (bike_hits_edge(bike2)) {
            game_over_ = true;
            winner_ = 1;
            bike1_tally++;
            live_ = false;
        } else if (bikes_collide()) {
            game_over_ = true;
            winner_ = 3;
            live_ = false;
        } else if (bike_hits_trail(bike1)) {
            game_over_ = true;
            winner_ = 2;
            bike2_tally++;
            live_ = false;
        } else if (bike_hits_trail(bike2)) {
            game_over_ = true;
            winner_ = 1;
            bike1_tally++;
            live_ = false;
        }

        if (!game_over_) {
            pixels.push_back(Pixel(bike1.get_position(), 1));
            pixels.push_back(Pixel(bike2.get_position(), 2));

            bike1 = bike1.next();
            bike2 = bike2.next();

        }
    }
}

void Model::launch() {
    live_ = !live_;
}

void Model::reset() {
    live_ = true;
    game_over_ = false;
    winner_ = 0;
    pixels.clear();
    bike1 = Bike(arena.bike1_init_velocity, arena.bike1_init_pos,
                 arena.speed_val);
    bike2 = Bike(arena.bike2_init_velocity, arena.bike2_init_pos,
                 arena.speed_val);
}

bool Model::is_game_over() const {

    return game_over_;
}

bool Model::bike_hits_edge(Bike bike) const {

    //right
    return bike.get_position().x >= arena.dimensions.width ||
           //left
           bike.get_position().x <= 0 ||
           //bottom
           bike.get_position().y >= arena.dimensions.height ||
           //top
           bike.get_position().y <= 0;
}

bool Model::bikes_collide() const {
    return ((bike1.get_velocity().width == 0 &&
             bike2.get_velocity().width == 0 &&
             abs(bike1.get_position().y - bike2.get_position().y) <=
             arena.speed_val &&
             bike1.get_position().x == bike2.get_position().x)
            ||
            (bike1.get_velocity().height == 0 &&
             bike2.get_velocity().height == 0 &&
             abs(bike1.get_position().x - bike2.get_position().x) <=
             arena.speed_val &&
             bike1.get_position().y == bike2.get_position().y)
            ||
            (bike1.get_position() == bike2.get_position()));
}

//loop through all indices of trail and check for collision
//with the bike
//see if the current position of bike matches any position in pixels
bool Model::bike_hits_trail(Bike bike) const {
    for (Pixel p : pixels) {
        if ((abs(bike.get_position().x - p.position.x) < arena.speed_val) &&
            abs(bike.get_position().y - p.position.y) < arena.speed_val)
            return true;
    }
    return false;
}