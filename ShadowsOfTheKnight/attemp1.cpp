#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
* Don't let the machines win. You are humanity's last hope...
**/

int main()
{
  int width; // the number of cells on the X axis
  cin >> width; cin.ignore();
  int height; // the number of cells on the Y axis
  cin >> height; cin.ignore();

  int nx = -1, ny = -1;
  int rx = -1, ry = -1;
  int pnx = -1, pny = -1;
  int prx = -1, pry = -1;
  int pbx = -1, pby = -1;

  string line;
  getline(cin, line); // width characters, each either 0 or .
  for(int j = 0; j < width; j++){
    if(line.at(j) == '0'){
      if(pnx == -1){
        pny = 0;
        pnx = j;
      }
      else if(prx == -1){
        pry = 0;
        prx = j;
      }
    }
  }

  for (int i = 1; i < height+1; i++) {
    getline(cin, line); // width characters, each either 0 or .
    for(int j = 0; j < width; j++){
      if(line.at(j) == '0' && ((pbx == -1) || (nx == -1) || (rx == -1))){
        if((pnx == j) && (pny == i - 1)){
          pby = i;
          pbx = j;
        }
        if(nx == -1){
          ny = i;
          nx = j;
        }
        else if(rx == -1){
          ry = i;
          rx = j;
        }
      }
    }

    // tab[i] = to_string(pnx) + " " + to_string(pny) + " " + to_string(prx) + " " + to_string(pry) + " " + to_string(pbx) + " " + to_string(pby);
    // cerr << pnx << " " << pny << " " << prx << " " << pry << " " << pbx << " " << pby;
    cout << pnx << " " << pny << " " << prx << " " << pry << " " << pbx << " " << pby << endl;

    pnx = nx;
    pny = ny;
    prx = rx;
    pry = ry;

    nx = ny = -1;
    rx = ry = -1;
    pbx = pby = -1;
  }

  // for(int i = 0; i < height; i++) {
  //   cout << tab[i] << endl;
  // }
}
