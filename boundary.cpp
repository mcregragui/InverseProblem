#include "include/boundary.h"


double g(double x,double y)
{
    return 1.0;
}


std::vector<double> getBoundary()
{
    std::vector<double> boundary;

    // B*V_x

    for(int i=0;i<Nx*(Ny+1);i++)
    {
        if(i%Nx==0)
        {
            boundary.push_back(g(((int)i/Nx),0.0)/dx);
        }
        if((i+1)%Nx==0&& i!=0)
        {
            boundary.push_back(-g(((int)i/Nx),Lx)/dx);
        }
        else
        {
            boundary.push_back(0.0);
        }
    }

    // B*V_y

    for(int i=Nx*(Ny+1);i<Ny*(Nx+1)+Nx*(Ny+1);i++)
    {
        if(i%Nx==0)
        {
            boundary.push_back(g(((int)i/Nx),0.0)/dy);
        }
        if((i+1)%Nx==0&& i!=0)
        {
            boundary.push_back(-g(((int)i/Nx),Ly)/dy);
        }
        else
        {
            boundary.push_back(0.0);
        }
    }

    return boundary;
}