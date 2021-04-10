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

  // initilize arrays
  int horiz[height+1][width+1];
  int verti[width+1][height+1];

  for (int i = 0; i < height+1; i++) {
    for (int j = 0; j < width+1; j++) {
      horiz[i][j] = -1;
      verti[j][i] = -1;
    }
  }

  int countH[height] = {0};
  int countV[width] = {0};
  int total = 0;
  // building arrays
  for (int i = 0; i < height; i++) {
    string line;
    getline(cin, line);
    for(int j = 0; j < width; j++) {
      if(line.at(j) == '0'){
        horiz[i][countH[i]] = j;
        verti[j][countV[j]] = i;
        countH[i] += 1;
        countV[j] += 1;
        total+=1;
      }
    }
  }

  // debug
  cerr << "horiz" << endl;
  for (int i = 0; i < height; i++) {
    for(int j = 0; j < width; j++) {
      cerr << horiz[i][j] << " ";
    }
    cerr << endl;
  }

  cerr << "verti" << endl;
  for(int j = 0; j < width; j++) {
    for (int i = 0; i < height; i++) {
      cerr << verti[j][i] << " ";
    }
    cerr << endl;
  }

  cerr << "countH" << endl;
  for (int i = 0; i < height; i++) {
    cerr << countH[i] << " ";
  }
  cerr << endl;

  cerr << "countV" << endl;
  for(int j = 0; j < width; j++) {
    cerr << countV[j] << " ";
  }
  cerr << endl;

  // sending results
  cerr << "results" << endl;
  int countVv[width] = {0};
  for(int i = 0; i < height; i++) {
    for(int k = 0; k < countH[i]; k++) {

      int j = horiz[i][k];

      int ri = -1;
      int rj = horiz[i][k+1];
      if (rj != -1) {
        ri = i;
      }

      int bi = verti[j][countVv[j]+1];
      int bj = -1;
      if (bi != -1) {
        bj = j;
        countVv[j] +=1;
      }

      cerr << j << " " << i << " " << rj << " " << ri << " " << bj << " " << bi << endl;
      cout << j << " " << i << " " << rj << " " << ri << " " << bj << " " << bi << endl;
    }
  }

}
