#include <iostream>
#include <math.h>
#include <cstdlib>


using namespace std; 

int main(){

  int seedd;

  cout<<"--------The Pi Calculator---------"<<endl;
  
  cout<<"give seed"<<endl;
  cin>>seedd; 
  srand(seedd);
  

  int in  = 0; 
  int loops = 0;
  
  cout<<"give evaluation points"<<endl;
  cin>>loops; 
  cout<<" eval points :"<<loops<<endl;
  for( int i = 0 ; i < loops; i++){

    
    double x = (rand() % 10000)/1000.;
    double y = (rand() % 10000)/1000.; 
    double ycr = sqrt(100. - x*x);
    
    if(y < ycr) in ++;
    



  }
  
  cout<<endl;
  cout<<endl;
  cout<<endl;
  
  cout<<"Pi :"<<(4*in*1.0/loops)<<endl; 


}
