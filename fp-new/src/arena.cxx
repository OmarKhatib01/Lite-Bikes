#include "arena.hxx"

using namespace ge211;


Arena::Arena(int speed, ge211::Dimensions arena_dimensions,
             ge211::Dimensions bike_dimensions)
        : dimensions{arena_dimensions}, bike_dims{bike_dimensions},
          speed_val{speed},
          bike1_init_pos{arena_dimensions.width - bike_dimensions.width * 5,
                         arena_dimensions.height / 2},
          bike2_init_pos{bike_dimensions.width * 5,
                         arena_dimensions.height / 2},
          bike1_init_velocity{-speed, 0},
          bike2_init_velocity{speed, 0}
          {}

Arena::Arena()
        : Arena(6, {1300, 800}, {10, 20}) {}


