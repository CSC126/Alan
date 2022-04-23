//CSC 126 hw#8
//I pledge this work to be my own Alan Mackiewicz
/*
This code makes use of global variables and two void functions that are put in a flag controlled while loop to create
a game. One of the functions is move() an just allows the user to move in any direction they want and adds values to the x,y counters
respectfully. The other is a update() function which just allows the code to process where you currently are and how far away
the treasure is from you. While the user is playing the game if he/she happens to stand on the spot where the treasure is
(be on the x and y coordinate) then an if statement in the update() function makes the treasure sentinel variable = true
thus ending the while loop and informing the user that he/she won and shows the amount of turns it took. The key to This
game is that the treasure is in a random integer for x and y at 1-30 so the treasure is in a new spot every time the code is ran.
*/
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;
void move();
void update();

int x=15, y=15;
int xRand, yRand;
char direction;
double theDistance;
bool treasure=false;
int moves = 0;

int main () {
     cout << "Please Enter a direction(n,s,e,w)" << endl;
     while(treasure != true){
       move();
       update();
     }
     return 0;
   }

void move(){
  cin >> direction;

  if(direction == 'n'){
    y++;
    moves++;
  }
  else if(direction == 's'){
    y--;
    moves++;
  }
  else if(direction == 'e'){
    x++;
    moves++;
  }
  else if(direction == 'w'){
    x--;
    moves++;
  }
  else{
    cout << "Not a valid input" << endl;
  }
}
void update(){
  if(moves < 2){
  srand(time(0));//secretly seed the rand
  xRand=rand() % 30 + 1;// set x1 to random bewtween 1 and 30
  yRand=rand() % 30 + 1;// sets y2 to random between 1 and 30
}
  theDistance = sqrt(static_cast<double>((x-xRand) *(x-xRand) + (y-yRand)*(y-yRand)));
  if((x != xRand)||(y != yRand)){
  cout << "Your coordinates are: (" << x << "," << y << ")" << endl;
  cout << "The distance from the treasure is " << theDistance << ", keep going!" << endl;
  }
  if((x == xRand)&&(y == yRand)){
    cout << endl << "Wow you got it!, it took you " << moves << " moves!";
    treasure = true;
  }
}
/*
OUTPUT
Please Enter a direction(n,s,e,w)
n
Your coordinates are: (15,16)
The distance from the treasure is 3, keep going!
n
Your coordinates are: (15,17)
The distance from the treasure is 3.16228, keep going!
s
Your coordinates are: (15,16)
The distance from the treasure is 3, keep going!
e
Your coordinates are: (16,16)
The distance from the treasure is 4, keep going!
w
Your coordinates are: (15,16)
The distance from the treasure is 3, keep going!
w
Your coordinates are: (14,16)
The distance from the treasure is 2, keep going!
w
Your coordinates are: (13,16)
The distance from the treasure is 1, keep going!
w

Wow you got it!, it took you 8 moves!
*/
