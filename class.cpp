#include <iostream>
#include "DiffusionGBM.h"
#include "DiffusionCEV.h"
#include "DiffusionOU.h"
#include "DiffusionCIR.h"
#include "DiffusionLipton.h"

int main(void)
{
    SiriusFM::DiffusionGBM MOD_GBM(1, 1);
    std::cout << MOD_GBM.mu(10, 1) << " " << MOD_GBM.sigma(10, 1) << "\n";

    SiriusFM::DiffusionCEV MOD_CEV(1, 1, 0.5);
    std::cout << MOD_CEV.mu(10, 1) << " " << MOD_CEV.sigma(10, 1) << "\n";

    SiriusFM::DiffusionOU MOD_OU(1, 1, 1);
    std::cout << MOD_OU.mu(10, 1) << " " << MOD_OU.sigma(10, 1) << "\n";

    SiriusFM::DiffusionCIR MOD_CIR(1, 1, 1);
    std::cout << MOD_CIR.mu(10, 1) << " " << MOD_CIR.sigma(10, 1) << "\n";

    SiriusFM::DiffusionLipton MOD_Lipton(1, 1, 1, 1);
    std::cout << MOD_Lipton.mu(10, 1) << " " << MOD_Lipton.sigma(10, 1) << "\n";
    return 1;
}