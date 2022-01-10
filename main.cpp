#include "include/operations.h"

#include "include/boundary.h"

#include "include/solver.h"

#include<fstream>






int Nx(10), Ny(10);
double Lx(1.0), Ly(0.1);

double dx=Lx/(Nx+2),dy=Ly/(Ny+2);

int main()
{
    //Initialize
    std::vector<double> u0(2*Nx*Ny+Nx+Ny,100.0);

    std::vector<double> p0((Nx+1)*(Ny+1),1e+7);

    std::vector<double> temp_u;
    std::vector<double> temp_p;





    ///Uzawa
    std::vector<double> temp;
    std::vector<double> boundary;
    boundary=getBoundary();
    double err=10.0;
    temp_p=p0;
    temp=u0;
    int cpt=0;
    while(err>1e-10)
    {

        std::cout<<"here "<<std::endl;
        temp_u=Bpressure(temp_p); //U=B*P
        std::cout<<"here "<<std::endl;
        //temp_p=temp_p+Bvelocity(temp_u);
        temp_p=SolveBICG(temp_p,boundary);// P=(B^-1)g
        err=Qerreur(temp_u,temp);
        temp=temp_u;
        cpt++;
        
    }


    std::ofstream myfile;
    myfile.open ("u_x.txt");
    for(int i=0;i<Nx*(Ny+1);i++)
    {
        myfile <<temp_u[i]<<std::endl;
    }
    
    myfile.close();



}