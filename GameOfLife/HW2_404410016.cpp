#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <unistd.h>
using namespace std;
class GameOfLife  {
 public:
   GameOfLife():w(80),h(23){}  // PRE:It's a default constructor, take no input. POS:give no return value.
   GameOfLife( int x, int y ):w(x), h(y){} //PRE:a constructor with certain value, take int x and int y as input. POS:no return value
   void SetOwnValue( int x, int y ); //PRE:take int x and int y as input POS:no return values
   void initialize( int p ); //PRE: take int p as input, stands for the prototype user wants to observe. POS:None
   void proceed( int t ); //PRE: take int t as input, stands for the generations user wants to observe. POS:None
   void display(); //PRE: None. POS:None. It just prints out the situation of the current world.
 private:
   int w, h; // stands for width and height of the world respectively
   bool cell[256][256];
};

void demo(); //PRE:none POS:none. It is for the requirement-7, to run each of four types in 100 generation in main.
void GameOfLife::SetOwnValue( int x, int y ) {
  w = x;
  h = y;
}
void GameOfLife::initialize( int p )  {
  int midw = (w+1)/2 , midh = (h+1)/2, i;
  memset( cell, false, sizeof(cell) );
  if( p == 1 )  {
    int x[]={-1,0,1,-1,0};
    int y[]={-1,-1,-1,0,1};

    for( i=0; i<5; i++ )
      cell[ midh+y[i] ][ midw+x[i] ] = true;
  }
  else if( p == 2 )  {
    int x[]={-1,2,-2,-2,2,-2,-1,0,1};
    int y[]={-1,-1,0,1,1,2,2,2,2};
    for( i=0; i<9; i++ )
      cell[ midh+y[i] ][ midw+x[i] ] = true;
  }
  else if( p == 3 ) {
    int x[]={-4,-3,-3,-2,-6,-3,-1,-6,-5,-4,-2,-1,-5,-3,-1,-4,-3,-2};
    int y[]={-6,-6,-5,-5,-4,-4,-4,-3,-3,-3,-3,-3,-2,-2,-2,-1,-1,-1};
    for(i=0; i<18;i++)  {
      cell[ midh+y[i] ][midw+x[i]] = true;
      cell[ midh-y[i] ][midw-x[i]] = true;
      cell[ midh+y[i] ][midw-x[i]] = true;
      cell[ midh-y[i] ][midw+x[i]] = true;
    }
  }
  else  {
    int total = p*w*h/100, cellcnt(0), randw, randh;
    unsigned seed = (unsigned)time(NULL);
    srand(seed);
    while( cellcnt!= total )  {
      randw = rand()%w+1;
      randh = rand()%h+1;
      if( cell[randh][randw] )
        continue;
      else  {
        cell[randh][randw] = true;
        cellcnt++;
      }
    }
  }
}
void GameOfLife::display()  {
  int i, j;
  for( i=0; i<h; i++ )  {
    for( j=0; j<w; j++ )  {
      if( cell[i][j] )
        cout << "0";
      else
        cout << " ";
    }
    cout << endl;
  }
  usleep(75000);
}
void GameOfLife::proceed( int t )  {

  bool temp[256][256];
  int i,j, neighbor, times;
  for( times=0; times<t; times++ )  {
    system("clear");
    cout << "Generation:" << times+1 <<endl;
    display();
    for(i =0; i<256; i++) // Copying cell to temp
      for(j=0; j<256; j++)
        temp[i][j] = cell[i][j];

    for( i =0; i< h ; i++ ) { // counting number of neighbors of each cell
      for(j =0 ; j<w; j++)  {

        neighbor = 0;
        if( i-1 >= 0 && temp[i-1][j] ) neighbor++;
        if( i-1 >=0 && j+1<w && temp[i-1][j+1] ) neighbor++;
        if( j+1<w && temp[i][j+1] ) neighbor++;
        if( i+1 <h && j+1 <w && temp[i+1][j+1] ) neighbor++;
        if( i+1 <h && temp[i+1][j] ) neighbor++;
        if( i+1 <h && j-1 >=0 && temp[i+1][j-1] ) neighbor++;
        if( j-1 >=0 && temp[i][j-1] ) neighbor++;
        if( j-1 >=0 && i-1 >=0 && temp[i-1][j-1] ) neighbor++;

        if( neighbor <=1 )
          cell[i][j]=false;
        else if (neighbor > 3)
          cell[i][j]=false;
        else if (neighbor ==3 )
          cell[i][j]=true;
        else
          continue;
      }
    }
  }
}
void demo() {
  int fourth;
  string watever;
  cout << "Demo time, press enter to observe the first prototype:glider in a evolution of 100 generations" << endl;
  getchar();
  GameOfLife *demo = new GameOfLife;
  demo->initialize(1);
  demo->proceed(100);
  cout << "Press enter to observe the second prototype:light-weight spaceship in a evolution of 100 generations" <<endl;
  getchar();
  demo->initialize(2);
  demo->proceed(100);
  cout << "Press enter to observe the third prototype:pulsar in a evolution of 100 generations" << endl;
  getchar();
  demo->initialize(3);
  demo->proceed(100);
  cout << "To observe the fourth prototype(random percentage), input an integer between 4~100" <<endl;
  cin>> fourth;
  while( fourth >100 || fourth <4 ) {
    cout << "Invalid input!" << endl;
    cin >> fourth;
  }
  demo->initialize(fourth);
  demo->proceed(100);
  cout << "Demo is done, you can test your own data now!" << endl;
  delete demo;
}
int main()  {

  demo();
  GameOfLife GOL; //WITH DEFAULT VALUES
  char ifOwn; //IF USER WANTS TO GIVE CERTAIN SIZE OF MAP
  int uw, uh, prototype, generation; //VARIABLE FOR USER INPUT SIZE OF MAP
  cout << "Make own size(y/n)?(If not, with default value Width:80, Height:23)" << endl;
  while(1)  {
    cin >> ifOwn;
    if( ifOwn == 'y' || ifOwn =='Y' ){
      cout << "enter width and height, note that 16≦ w,h ≦256" <<endl;
      cin >> uw >> uh;
      while( uw < 16 || uh < 16 || 256< uw || 256 < uh) {
        cout << "Invalid input!"<<endl;
        cin >> uw >> uh;
      }
      GOL.SetOwnValue(uw, uh);
      break;
    }
    else if( ifOwn == 'n' || ifOwn =='N' )  {
      break;
    }
    else
      cout << "Invalid input!" << endl;
  }
  cout << "Select a prototype(integer between 1~100):" << endl;
  cin >> prototype;
  while( prototype < 1 || 100 < prototype ) {
    cout << "Invalid input!" <<endl;
    cin >> prototype;
  }
  GOL.initialize( prototype );
  cout << "Enter a generation you want to observe(at least 1)" << endl;
  cin >> generation;
  while( generation<1 ) {
    cout << "Invalid input!" << endl;
    cin >> generation;
  }
  GOL.proceed( generation );
  return 0;
}
