#include "include/operations.h"


std::vector<double> Bvelocity(std::vector<double> u0)
{
    std::vector<double> prod;

    // B*V_x

    for(int i=0;i<Nx*(Ny+1);i++)
    {
        if(i%Nx==0)
        {
            prod.push_back(u0[i]/dx);
        }
        if((i+1)%Nx==0&& i!=0)
        {
            prod.push_back(-u0[i]/dx);
        }
        else
        {
            prod.push_back((u0[i]-u0[i-1])/dx);
        }
    }

    // B*V_y

    for(int i=Nx*(Ny+1);i<Ny*(Nx+1)+Nx*(Ny+1);i++)
    {
        if(i%Nx==0)
        {
            prod.push_back(u0[i]/dy);
        }
        if((i+1)%Nx==0&& i!=0)
        {
            prod.push_back(-u0[i]/dy);
        }
        else
        {
            prod.push_back((u0[i]-u0[i-1])/dy);
        }
    }

    return prod;
}


std::vector<double> Bpressure(std::vector<double> p0)
{

    std::vector<double> prod;

    // U_x=B*P
    for(int j=0;j<Ny+1;j++)
    {
        for(int i=0;i<Nx;i++)
        {

            prod.push_back((p0[i+j*(Nx+1)+1]-p0[i+j*(Nx+1)])/dx);

        }
    }
    
    // V_y=B*P
    for(int i=0;i<Nx+1;i++)
    {
        for(int j=1;j<Ny+1;j++)
        {

            prod.push_back((p0[i+j*(Nx+1)+1]-p0[i+(j-1)*Nx])/dy);

        }
    }

    return prod;
}

std::vector<double> BBT(std::vector<double> p0)
{
    std::vector<double> res;

    res=Bpressure(p0);

    res=Bvelocity(res);

    return res;

}


double Qerreur(std::vector<double> u0,std::vector<double> u1)
{
    double erreur=0.0;
    for(int i=0;i<u0.size();i++)
    {
        erreur+=(u0[i]-u1[i])*(u0[i]-u1[i]);
    }

    return sqrt(erreur);
}
