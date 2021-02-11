#include "DiffusionGBM.h"
#include "IRProviderConst.h"
#include "MCEngine1D.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include "VanillaOptions.h"

using namespace SiriusFM;
using namespace std;

int main(int argc, char* argv[])
{
    if(argc != 9)
    {
        cerr << "PARAMS: mu, sigma....." << endl;
        return 1;
    }

    double mu = atof(argv[1]);
    double sigma = atof(argv[2]);
    double S0 = atof(argv[3]);
    char const* optType = argv[4];
    double K = atof(argv[5]);
    long T_days = atol(argv[6]);
    int tau_min = atoi(argv[7]);
    long P = atol(argv[8]);
    if(sigma <= 0 || S0 <= 0 || K <= 0 || T_days <= 0 || tau_min <= 0 || P <= 0)
    {
        cerr << "Some parameters <= 0" << endl;
        return 2;
    }

    CcyE ccyA = CcyE::USD;
    IRProvider<IRModeE::Const> irp(nullptr);
    DiffusionGBM diff(mu, sigma);
    MCEngine1D<decltype(diff), decltype(irp), decltype(irp), decltype(ccyA), decltype(ccyA)> mce(20000, 20000);
    time_t t0 = time(nullptr);
    time_t T = t0 + T_days * 86400.0;
    double Ty = double(T_days)/365.25;

    //Run MC
    mce.Simulate<false>(t0, T, tau_min, S0, P, &diff, &irp, &irp, ccyA, ccyA);

    //Analyze the result
    auto res = mce.GetPaths();
    long L1 = get<0>(res);
    long P1 = get<1>(res);
    double const* paths = get<2>(res);

    Option const* option = nullptr;;
    
    if(strcmp(optType, "Call") == 0)
    {
        option = new EurCallOption(K, T_days);
    }
    else
    if(strcmp(optType, "Put") == 0)
    {
        option = new EurPutOption(K, T_days);
    }
    else
    {
        throw std::invalid_argument("Not Call or Put Option");
    }
    

    //cout << L1 << " " << P1 << "\n";

    //Compute E of log(S_T)
    double EST = 0.0;
    int NVP = 0;
    for(int p = 0; p < P1; ++p)
    {
        double const* path = paths + p * L1;
        double ST = path[L1 - 1];
        //may be get ST <= ST
        if(ST <= 0.0)
        {
            continue;
        }
        ++NVP;
        double RT = option -> payoff(L1, nullptr, path);;
        //cout << ST << " " << S0 << " " << RT << endl;
        EST = EST + RT;
    }
    //cout << EST << " " << EST2 << " " << NVP << " " << Ty << "\n";
    //end of p loop
    assert (NVP > 1);
    EST /= double(NVP);
    

    cout << "Res = " << EST << endl;
    return 0;
}