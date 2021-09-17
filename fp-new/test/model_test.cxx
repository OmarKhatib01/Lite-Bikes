#include "model.hxx"
#include <catch.hxx>
#include <ge211.hxx>

struct Test_access {
    Model &m_;

    bool bike_hits_edge(Bike bike) {
        return m_.bike_hits_edge(bike);
    }

    Bike &bike1;

    void set_bike1_pos(ge211::Position pos) {
        bike1.center_ = pos;
    }

    void set_bike1_vel(ge211::Dimensions dims) {
        bike1.velocity_ = dims;
    }

    Bike &bike2;

    void set_bike2_pos(ge211::Position pos) {
        bike2.center_ = pos;
    }

    void set_bike2_vel(ge211::Dimensions dims) {
        bike2.velocity_ = dims;
    }
};

TEST_CASE ("1: wall collision") {
    Model model = Model(Arena());
    Test_access t{model, model.bike1, model.bike2};

    t.set_bike1_pos({0, 200});
    CHECK (t.bike_hits_edge(model.bike1));
    t.set_bike1_pos({-4, 50});
    CHECK (t.bike_hits_edge(model.bike1));

    t.set_bike1_pos({50, -4});
    CHECK (t.bike_hits_edge(model.bike1));
    t.set_bike1_pos({1, 1});
    CHECK (!t.bike_hits_edge(model.bike1));

    t.set_bike1_pos({5, 5});
    t.set_bike1_vel({-6, 0}); //bike going up
    model.launch();
    model.update();
    model.update();

    CHECK (t.bike_hits_edge(model.bike1));
    CHECK (model.is_game_over());
    CHECK (model.winner() == 2); //winner is bike2
}

TEST_CASE ("2: bike collides with trail") {
    Model model = Model(Arena());
    Test_access t{model, model.bike1, model.bike2};
    t.set_bike1_pos({1, 1});
    t.set_bike1_vel({6, 0});

    t.set_bike2_pos({4, 4});
    t.set_bike2_vel({0, -6});

    model.launch();
    model.update();
    model.update();

    CHECK (model.is_game_over());
    CHECK (model.winner() == 1); //winner is bike1
}

TEST_CASE ("3: bikes collide (tie)") {
    //test 1, bikes going in different directions and colliding
    Model model = Model(Arena());
    Test_access t{model, model.bike1, model.bike2};
    t.set_bike1_pos({50, 50});
    t.set_bike1_vel({6, 0});
    t.set_bike2_pos({56, 56});
    t.set_bike2_vel({0, -6});

    model.launch();
    model.update();
    model.update();

    CHECK(model.is_game_over());
    CHECK(model.winner() == 3); //3=> no winner, bikes tie

    //test 2, bikes hit walls at same time
    t.set_bike1_pos({50, 50});
    t.set_bike1_vel({0, -6});
    t.set_bike2_pos({50, 200});
    t.set_bike2_vel({6, 0});

    model.update();
    model.update();

    CHECK(model.is_game_over());
    CHECK(model.winner() == 3); //3=> no winner, bikes tie
}

TEST_CASE ("4: bike initial moving velocities correct") {
    Model model = Model(Arena());
    model.launch();
    CHECK(model.bike1.get_velocity().width == -6);
    CHECK(model.bike1.get_velocity().height == 0);
    CHECK(model.bike2.get_velocity().width == 6);
    CHECK(model.bike2.get_velocity().height == 0);

    //means the same thing but these show that you can alter
    //the speed (speed_val) from the arena class
    CHECK(model.bike1.get_velocity().width == -model.arena.speed_val);
    CHECK(model.bike1.get_velocity().height == 0);
    CHECK(model.bike2.get_velocity().width == model.arena.speed_val);
    CHECK(model.bike2.get_velocity().height == 0);
}

TEST_CASE ("5: rotating a bike correctly changes its velocity") {
    Model model = Model(Arena());

    //going to the left
    CHECK(model.bike1.get_velocity().width == -6);
    CHECK(model.bike1.get_velocity().height == 0);

    model.bike1.rotate_left(); //now going downward
    CHECK(model.bike1.get_velocity().width == 0);
    CHECK(model.bike1.get_velocity().height == 6);

    model.bike1.rotate_left(); //now going right
    CHECK(model.bike1.get_velocity().width == 6);
    CHECK(model.bike1.get_velocity().height == 0);

    model.bike1.rotate_left(); //now going up
    CHECK(model.bike1.get_velocity().width == 0);
    CHECK(model.bike1.get_velocity().height == -6);

    model.bike1.rotate_right(); //now going right again
    CHECK(model.bike1.get_velocity().width == 6);
    CHECK(model.bike1.get_velocity().height == 0);
}