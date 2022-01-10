#include<iostream>
#include<vector>


#include "variables.h"
#include "boundary.h"
#include "Template.h"

std::vector<double> Bvelocity(std::vector<double> u0);

std::vector<double> Bpressure(std::vector<double> p0);

std::vector<double> BBT(std::vector<double> p0);


double Qerreur(std::vector<double> u0,std::vector<double> u1);