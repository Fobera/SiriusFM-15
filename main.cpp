#include <iostream>
#include "DiffusionGBM.h"
#include "DiffusionCEV.h"
#include "DiffusionOU.h"
#include "DiffusionCIR.h"
#include "DiffusionLipton.h"
#include "IRProviderConst.h"
#include "MCEngine1D.hpp"

using namespace SiriusFM;
int main(void)
{
    DiffusionGBM MOD_GBM(1, 1);
    std::cout << MOD_GBM.mu(10, 1) << " " << MOD_GBM.sigma(10, 1) << "\n";

    DiffusionCEV MOD_CEV(1, 1, 0.5);
    std::cout << MOD_CEV.mu(10, 1) << " " << MOD_CEV.sigma(10, 1) << "\n";

    DiffusionOU MOD_OU(1, 1, 1);
    std::cout << MOD_OU.mu(10, 1) << " " << MOD_OU.sigma(10, 1) << "\n";

    DiffusionCIR MOD_CIR(1, 1, 1);
    std::cout << MOD_CIR.mu(10, 1) << " " << MOD_CIR.sigma(10, 1) << "\n";

    DiffusionLipton MOD_Lipton(1, 1, 1, 1);
    std::cout << MOD_Lipton.mu(10, 1) << " " << MOD_Lipton.sigma(10, 1) << "\n";

    std::cout << "_____________\n";

    IRProvider<IRModeE::Const> irp("File_R.txt");
    std::cout << irp.r(CcyE::USD, 1) << "\n";

    /*MCEngine1D<DiffusionGBM, IRProvider <IRModeE::Const>, IRProvider <IRModeE::Const>, CcyE, CcyE> mce(100, 100);
    mce.Simulate(1, 100, 0.1, 100, 1, MOD_GBM, irp, irp, CcyE::USD, CcyE::RUB, 0);
    
    std::cout << std::get<0>(tuple) << " " << std::get<1>(tuple) << " " << std::get<2>(tuple) << "\n";*/

    return 1;
}