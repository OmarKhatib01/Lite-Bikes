# Proposal: 2D Light Bike

## Synopsis

### Game play
My game is a 2D representation of a Tron Light Bike type of game.
The game consists of a square Arena
where two players control
"bikes" that leave a color trail. If one player's bike comes into
contact with the "trail" left by the other bike, that player's
bike is destroyed and they lose the game. Also, if a bike hits
one of the borders of the game, it is destroyed.

The game is played by two players, with one player using the
"AD" keys and one using the arrow keys to control their bike.

### Elements

- An empty vector is created, and every position that a bike has
passed through is pushed back into the vector. The view() uses
this vector to draw the trails, and the model uses this vector
to do collision detection. 
- Two bike elements. Each is a different color and they both move
at the same speed. Keyboard clicks by the user change the direction
of that user's bike. Each bike leaves a color trail on the Arena
that cannot be crossed by either user.

### Goal

Each player's goal is to destroy the other player's bike by leaving
a trail that its bike crashes into. Similarly, each player's goal
is also to avoid hitting the other player's (or their own) color trail.

## Functional requirements

1. The two bikes begin the game centered on the left and right
sides of the arena, stationary. The bike on the left of the Arena
faces towards the right, and the bike on the right of the arena
faces left.
2. A text sprite tells the user to press the space bar to play.
Prior to pressing the space bar, both bikes are stationary. Once 
the space bar is pressed, both 
bikes begin moving in the direction 
that they are facing (downwards for the top bike, upwards for the
bottom bike).
3. As the bikes move, each bike leaves a "light trail": a line that
matches the color of the bike and represents the path that the
bike has travelled.
4. The bikes move with a velocity of 4 pixels per tick (the velocity
can be adjusted in the "arena.cxx" file) in either the x or y direction 
(the bikes cannot move diagonally).
5. The arrow keys control the direction of movement of one bike,
and the "AD" keys control the other ("A" is rotate left, "D" is rotate 
right).
6. Every x number of ticks, a player may press a key to temporarily
slow down their bike. For the arrow key player, the down arrow key 
will brake their bike. For the "WASD" player, the S key will brake 
their bike.
7. Every x number of ticks, a player may press a key to add a
"boost" to their bike. This means the bike temporarily speeds up.
For the arrow key player, the up arrow key will boost their bike.
For the WASD player, the W key will boost their bike.
8. If a bike comes into contact with the edge of the Arena, it 
is destroyed and the other bike wins the game.
9. If the space bar is pressed at any point during the game,
the game is paused, and the space bar must be pressed again to
resume the game.
10. If a bike comes into contact with either its own light trail
or the light trail of the other bike, is destroyed and the other
bike wins the game.
11. Once a bike wins the game, the location of the bikes is frozen
on the screen and the message "GAME OVER: [Color] Wins!" is displayed.
12. In addition, a text sprite with the message "Press r to restart"
is shown. If a user presses "r" at this point, the model is 
"reset" and the bikes begin moving from their start positions.
13. In the rare occurrence that the bikes perfectly collide or
both hit a wall or trail during the same "tick", a message is 
displayed telling the player that both bikes were destroyed.
14. The player scores (number of wins during the session) are
displayed in the upper corners and are updated after a player
wins a match.

## Open questions

How do I make  the height of the square Arena the same as the
y-dimension of the monitor?

What is the best way to track where the existing trails are to
check for collisions? If the solution is an array that represents
each pixel on the Arena, how do we create this? How do we store
if that position is "filled" by the trail of a bike or "empty"?

What dimensions and velocities make the game most playable?

Which attributes of the model and bikes do we need to make private
(and only accessible by helper functions), and which should be
public?

