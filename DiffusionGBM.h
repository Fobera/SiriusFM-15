#pragma once
#include <stdexcept>

namespace SiriusFM
{
    class DiffusionGBM
    {
        private:
            double const m_mu;
            double const m_sigma;
        public:
            double mu(double S, double t) const
            {
                if(S < 0) return 0;
                return m_mu * S;
            }
            double sigma(double S, double t) const
            {
                if(S < 0) return 0;
                return m_sigma * S;
            }
            DiffusionGBM(double a_mu, double a_sigma)
                :m_mu(a_mu),
                m_sigma(a_sigma)
                {
                    if(m_sigma <= 0)
                    {
                        throw std::invalid_argument("Invalid argument\n");
                    }
                }
    };
}