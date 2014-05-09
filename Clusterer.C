#include <iostream>
#include <fstream>
#include <math.h>
#include <cstdlib>
#include <vector>

using namespace std;

void Cluster(int x_i, int y_j, vector<double> posx,vector<double> posy, double dens1, vector<int> &x_1 , vector<int> &y_1 ){


  int Grid2[10][10] = {};

  for(int i  = 0; i < posx.size(); i ++){

    double x = posx[i];
    double y = posy[i];
    
    if(int(x/100) != x_i)continue;
    if(int(y/100) != y_j)continue;
    
    int xi = int(int(x) %100)/10;
    int yi = int(int(y) %100)/10;
    

    Grid2[xi][yi] ++;
  }
  
  for(int i = 0; i < 10 ; i++){
    for(int j = 0; j <10 ; j++){


      double dens2 = Grid2[i][j]/100.; 
	
      if(dens1 <  dens2){
	cout<<"found cluster in sub area:"<<x_i<<"  "<<y_j<<endl;
	x_1.push_back(i);
	y_1.push_back(j);
      }



      }
  }

}




int main(){


  cout<<"--------------Cluster Finder------------"<<endl;

  ofstream out2; 
  
  out2.open("Haloes.dat");

  
  ifstream in; 
  in.open("Cluster.dat",ios::in);
  
  double number; 
  vector<double> posx,posy;

  int i = 0;

  //feeding in the data
  while(!in.eof()){ 
  
    in>>number;
    
    //cout<<number<<endl;


    if( i%2 == 0 )posx.push_back(number);
    if( i%2 == 1) posy.push_back(number);
    //cout<<i%2<<endl;

    i++;
  }

  //general density of space
  
  
  
  double dens0 = posx.size()/(1000.*1000.);
  
  

  int Grid [10][10] = {};


  for (int i = 0; i  < posx.size(); i++){

    double x = posx[i]; 
    double y = posy[i];
        
    int ix = int(x/100);
    int iy = int(y/100);
    
    Grid[ix][iy] ++;

  }

  

  for(int i  = 0; i < 10; i++){
    for(int j = 0; j < 10 ; j++){
      vector<int> x_1;
      vector<int> y_1;

      double dens1 = Grid[i][j]*100./(1000000);
      if(dens1 > dens0) Cluster(i,j, posx,posy,dens1,x_1,y_1 );
      for(int ik = 0; ik < x_1.size();ik++){
	
	  out2<< i*100 + x_1[ik]*10 <<"  "<< j*100 + y_1[ik]*10<<endl;

      }
      
    }
  }

  return 0;


  posx.resize(0);
  posy.resize(0);

}





