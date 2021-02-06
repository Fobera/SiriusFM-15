#pragma once
#include <stdexcept>
#include <cmath>

namespace SiriusFM
{
    class DiffusionCEV
    {
        private:
            double const m_mu;
            double const m_sigma;
            double const m_beta;
        public:
            double mu(double S, double t) const
            {
                if(S < 0) return 0;
                return m_mu * S;
            }
            double sigma(double S, double t) const
            {
                if(S < 0) return 0;
                return m_sigma * pow(S, m_beta);
            }
            DiffusionCEV(double a_mu, double a_sigma, double a_beta)
                :m_mu(a_mu),
                m_sigma(a_sigma),
                m_beta(a_beta)
                {
                    if(m_sigma <= 0)
                    {
                        throw std::invalid_argument("Invalid argument\n");
                    }
                    if(m_beta < 0)
                    {
                        throw std::invalid_argument("Invalid argument\n");
                    }
                }
    };
}