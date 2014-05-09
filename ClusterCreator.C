#include <cstdlib>
#include <iostream> 
#include <fstream>
#include <time.h>
#include <math.h>
using namespace std; 

int main(){


  ofstream out;
  out.open("Cluster.dat");

  srand(7834);
  
  cout<<"2D cluster generator"<<endl;

  double x = 0;
  double y  = 0;
  //Background field

  for (int i  = 0 ; i < 1000; i++){
    
    x = (rand() % 10000)/10.;
    y = (rand() % 10000)/10.;
    out<<x<<" "<<y<<endl;
    cout<<"x: "<<x<<"y: "<<y<<endl;


  }

  for (int  i = 0 ;  i < 60 ; i++ ){ 
    
    double xc = (rand() % 10000)/10.;
    double yc = (rand() % 10000)/10.;
    double r = (rand() %1000)/20. + 5; 
    
    int Pop = (rand() % 100 + 10);


    cout<<"  Cluster :"<<i <<"Position : "<< xc <<" "<<yc<<endl;
    cout<<"  Population: "<<Pop<<"radius :"<<r <<endl;

    int j = 0;
    while( j  < Pop){
      
      double r1 = (rand() % 100 )/100.*2*r;
      double r2 = (rand() % 100 )/100.*2*r;
      
      double x1 = xc -r + r1;
      double y1 = yc -r + r2; 
      
      if( sqrt((r-r1)*(r-r1) + (r-r2)*(r-r2)) < r){
	if(( x1 > 0)&&(x1 < 1000)){
	  if(( y1 > 0)&&(y1 < 1000)){
		out<<x1<<" "<<y1<<endl;
	      }
	  }
	j = j +1;
      }
      
      //cout<<"          stars"<<j<<endl;
    

    }
  }
  return 0;



}
