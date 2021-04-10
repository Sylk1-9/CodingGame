#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
* Auto-generated code below aims at helping you parse
* the standard input according to the problem statement.
**/

int main()
{
  int W; // width of the building.
  int H; // height of the building.
  cin >> W >> H; cin.ignore();
  int N; // maximum number of turns before game over.
  cin >> N; cin.ignore();
  int X0;
  int Y0;
  cin >> X0 >> Y0; cin.ignore();

  float X=X0;
  float Y=Y0;
  float jX=X0;
  float jY=Y0;
  int lr=0;
  float Xfac=1;
  float Yfac=1;
  string prevbombDir;
  // game loop
  bool firstit=true;
  while (1) {
    string bombDir; // the direction of the bombs from batman's current location (U, UR, R, DR, D, DL, L or UL)
    cin >> bombDir; cin.ignore();
    // Write an action using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;

    lr = (bombDir.length() ==1) ? 0 : 1;

    if (firstit){
      firstit=false;
      prevbombDir = bombDir;
      if(bombDir.at(0) == 'D')
      jY = (H-Y0);
      if(bombDir.at(lr) == 'R')
      jX = (W-X0);
    }


    cerr << "lr=" << lr << endl;
    cerr << "jX=" << jX << endl;
    cerr << "jY=" << jY << endl;

    if((bombDir.at(0) == 'U') && (prevbombDir.at(0) == 'D')){
      Yfac=2./4.;
      jY*=Yfac;
      Y-=jY;
    }
    else if (bombDir.at(0) == 'U'){
      Yfac=1./2.;
      jY*=Yfac;
      Y-=jY;
    }
    else if((bombDir.at(0) == 'D') && (prevbombDir.at(0) == 'U')){
      Yfac=2./4.;
      jY*=Yfac;
      Y+=jY;
    }
    else if (bombDir.at(0) == 'D'){
      Yfac=1./2.;
      jY*=Yfac;
      Y+=jY;
    }

    if ((bombDir.at(lr) == 'R') && (prevbombDir.at(lr) == 'L')){
      Xfac=2./4.;
      jX*=Xfac;
      X+=jX;
    }
    else if (bombDir.at(lr) == 'R'){
      Xfac=1./2.;
      jX*=Xfac;
      X+=jX;
    }
    else if((bombDir.at(lr) == 'L') && (prevbombDir.at(lr) == 'R')){
      Xfac=2./4.;
      jX*=Xfac;
      X-=jX;
    }
    else if (bombDir.at(lr) == 'L'){
      Xfac=1./2.;
      jX*=Xfac;
      X-=jX;
    }

    if(X>W-1)
    X=W-1;
    else if(X<0)
    X = 0;

    if(Y>H-1)
    Y=H-1;
    else if(Y<0)
    Y=0;

    prevbombDir = bombDir;
    // the location of the next window Batman should jump to.
    cout << (int)X << " " << (int)Y << endl;
  }
}
