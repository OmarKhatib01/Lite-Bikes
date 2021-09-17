#include "view.hxx"

using namespace ge211;

View::View(Model const &model)
        : model_(model), window_title("Light Bikes") {}

void View::draw(Sprite_set &sprites) {

    bike1_score = Text_sprite::Builder(ge211::Font("sans.ttf", 30)).message(
            (std::to_string(model_.bike1_tally))).color(bike1_color_).build();
    bike2_score = Text_sprite::Builder(ge211::Font("sans.ttf", 30)).message(
            (std::to_string(model_.bike2_tally))).color(bike2_color_).build();

    if (bike1_score >= 99){
        sprites.add_sprite(bike1_score,
                           Position{model_.arena.dimensions.width - 45, 0}, 4);
    } else {
        sprites.add_sprite(bike1_score,
                           Position{model_.arena.dimensions.width - 35, 0}, 4);
    }

    sprites.add_sprite(bike2_score, Position{10, 0}, 4);


    if (!model_.is_game_over() && !model_.is_live()) {
        sprites.add_sprite(start_msg,
                           {model_.arena.dimensions.width / 5 * 2 + 20,
                            model_.arena.dimensions.height / 2}, 4);
    }

    if (model_.bike1.get_velocity().height != 0) {
        Position vert_adjusted_pos1(
                model_.bike1.get_position().x - model_.arena.bike_dims
                                                        .width / 2,
                model_.bike1.get_position().y - model_.arena.bike_dims
                                                        .height / 2);
        sprites.add_sprite(bike1_sprite_vert, vert_adjusted_pos1, 3);
    } else {
        Position horiz_adjusted_pos1(
                model_.bike1.get_position().x - model_.arena.bike_dims
                                                        .height / 2,
                model_.bike1.get_position().y - model_.arena.bike_dims
                                                        .width / 2);
        sprites.add_sprite(bike1_sprite_horiz, horiz_adjusted_pos1, 3);
    }

    if (model_.bike2.get_velocity().height != 0) {
        Position vert_adjusted_pos2(
                model_.bike2.get_position().x - model_.arena.bike_dims
                                                        .width / 2,
                model_.bike2.get_position().y - model_.arena.bike_dims
                                                        .height / 2);
        sprites.add_sprite(bike2_sprite_vert, vert_adjusted_pos2, 2);

    } else {
        Position horiz_adjusted_pos2(
                model_.bike2.get_position().x - model_.arena.bike_dims
                                                        .height / 2,
                model_.bike2.get_position().y - model_.arena.bike_dims
                                                        .width / 2);
        sprites.add_sprite(bike2_sprite_horiz, horiz_adjusted_pos2, 2);
    }

    for (Pixel p : model_.pixels) {
        Position pos(p.position.x - (model_.arena.speed_val - 2)/2, p
        .position.y - (model_.arena.speed_val-2)/2);
        switch (p.state) {
            case 1:
                sprites.add_sprite(bike1_trail_pixel, pos);
                break;
            case 2:
                sprites.add_sprite(bike2_trail_pixel, pos);
                break;
        }
    }

    if (model_.is_game_over()) {
        switch (model_.winner()) {
            case 3:
                sprites.add_sprite(tie_msg,
                                   {model_.arena.dimensions.width / 6,
                                    model_.arena.dimensions.height / 5 * 2}, 4);
                sprites.add_sprite(restart_msg,
                                   {model_.arena.dimensions.width / 5 * 2 + 20,
                                    model_.arena.dimensions.height / 2}, 4);
                break;
            case 1:
                sprites.add_sprite(bike1_wins_msg,
                                   {model_.arena.dimensions.width / 4 + 40,
                                    model_.arena.dimensions.height / 5 * 2}, 4);
                sprites.add_sprite(restart_msg,
                                   {model_.arena.dimensions.width / 5 * 2 + 20,
                                    model_.arena.dimensions.height / 2}, 4);

                break;
            case 2:
                sprites.add_sprite(bike2_wins_msg,
                                   {model_.arena.dimensions.width / 4 + 40,
                                    model_.arena.dimensions.height / 5 * 2}, 4);
                sprites.add_sprite(restart_msg,
                                   {model_.arena.dimensions.width / 5 * 2 + 20,
                                    model_.arena.dimensions.height / 2}, 4);

                break;
        }
    }
}

ge211::Dimensions View::initial_window_dimensions() const {
    return model_.arena.dimensions;
}

std::string View::initial_window_title() const {
    return window_title;
};