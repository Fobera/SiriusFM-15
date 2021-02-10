#pragma once
#include <cstring>
#include <stdexcept>
namespace SiriusFM
{
    enum class CcyE
    {
        UNDEFINED = -1,
        USD = 0,
        RUB = 1,
        N = 2
    };

    inline CcyE Str2CcyE(char const* a_str)
    {
        if(strcmp(a_str, "USD") == 0)
        {
            return CcyE::USD;
        }
        else if(strcmp(a_str, "RUB") == 0)
        {
            return CcyE::RUB;
        }
        else 
        {
            throw std::invalid_argument("Invalid name");
        }
    }

    inline char const* CcyE2Str(CcyE a_ccy)
    {
        switch(a_ccy)
        {
            case CcyE::USD: return "USD";
            case CcyE::RUB: return "RUB";
            default: throw std::invalid_argument("Invalid name");
        }
    }

    enum class IRModeE
    {
        Const = 0,
        FwdCurve = 1,
        Stoch = 2
    };

    template <IRModeE IRM>
    class IRProvider;
}