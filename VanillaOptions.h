#pragma once
#include "Option.h"
#include <stdexcept>

namespace SiriusFM
{
    class EurCallOption final: public Option
    {
        private:
            double const m_K;

        public:
            EurCallOption(double a_K, int a_Tdays):
            Option(false, a_Tdays),
            m_K(a_K)
            {
                if(m_K <= 0)
                {
                    throw std::invalid_argument("m_K<= 0");
                }
            }

            ~EurCallOption() override
            {

            }

            double payoff(long a_L, double const* a_t, double const* a_S) const override
            {
                assert(a_L > 0 /*&& a_t != nullptr*/ && a_S != nullptr);
                double ST = a_S[a_L - 1];
                return std::max<double>(ST - m_K, 0.0);
            }
    };

    class EurPutOption final: public Option
    {
        private:
            double const m_K;

        public:
            EurPutOption(double a_K, int a_Tdays):
            Option(false, a_Tdays),
            m_K(a_K)
            {
                if(m_K <= 0)
                {
                    throw std::invalid_argument("m_K<= 0");
                }
            }

            ~EurPutOption() override
            {

            }

            double payoff(long a_L, double const* a_t, double const* a_S) const override
            {
                assert(a_L > 0 /*&& a_t != nullptr*/ && a_S != nullptr);
                double ST = a_S[a_L - 1];
                return std::max<double>(m_K - ST, 0.0);
            }
    };
}