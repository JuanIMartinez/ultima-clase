#include<math.h>
#include<iostream>
#include<fstream>
#include <string>
#include <sstream>
using namespace std;

void frontera_fija(double tiempo_final);

int main(){
    double t_final_1=0, t_final_2=15, t_final_3=100;
    
    frontera_fija(t_final_1);
    frontera_fija(t_final_2);
    frontera_fija(t_final_3);
          
    return 0;
}

// Metodo  para resolver la ecuacion diferencial con fronteras fijas  
void frontera_fija(double tiempo_final){
    
    double dx=0.01, c=300, dt, k, t_inicial=0.0;
    std::string nombre = "";
    
    dt=sqrt((dx*dx)/(2*c*c));
    k=(c*c*dt*dt)/(dx*dx);
    
    float cuerda[100];

    for (int i=0;i<51;i++){
        cuerda[i]=(0.1/0.5)*i*dx;
    }

    for (int i=50;i<100;i++){
        cuerda[i]=(-0.1/0.5)*(i-50)*dx+0.1;
    }
    
    while(t_inicial<tiempo_final){
        for (int i=1;i<99;i++){

        double A_xs, A_xa, A_xp,A_ts, A_ta, A_tp=0, suma_A;        
        A_xs=cuerda[i+1];
        A_xa=cuerda[i-1];
        A_xp=cuerda[i];
            
        A_tp=cuerda[i];

        suma_A= A_xs+A_xa-2*A_xp;

        A_ts=(k*(suma_A)+2*A_tp)*0.5;

        cuerda[i]= A_ts;
        t_inicial=t_inicial+dt;

        }   
        
    }   
    
    nombre = static_cast<std::ostringstream*>(&(std::ostringstream() << tiempo_final))->str();
    ofstream outfile;
    outfile.open("Amplitud"+nombre+".dat");
    for (int i=0;i<100;i++){
        
        outfile <<cuerda[i] <<endl;
    }
    
    outfile.close();
}




