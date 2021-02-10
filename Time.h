#pragma once
#include <ctime>
namespace SiriusFM
{
    inline double YearFracSec(time_t a_t)
    {
        //avg year in sec
        constexpr double SecY = 365.25 * 86400.0;
        return 1970.0 + double(a_t)/SecY;
    }
}