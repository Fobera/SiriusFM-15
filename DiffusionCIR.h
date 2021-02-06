#pragma once
#include <stdexcept>
#include <cmath>

namespace SiriusFM
{
    class DiffusionCIR
    {
        private:
            double const m_kappa;
            double const m_teta;
            double const m_sigma;
        public:
            double mu(double S, double t) const
            {
                if(S < 0) return 0;
                return m_kappa * (m_teta - S);
            }
            double sigma(double S, double t) const
            {
                if(S < 0) return 0;
                return m_sigma * pow(S, 0.5);
            }
            DiffusionCIR(double a_kappa, double a_sigma, double a_teta)
                :m_kappa(a_kappa),
                m_sigma(a_sigma),
                m_teta(a_teta)
                {
                    if(m_sigma <= 0)
                    {
                        throw std::invalid_argument("Invalid argument\n");
                    }
                    if(m_kappa <= 0)
                    {
                        throw std::invalid_argument("Invalid argument\n");
                    }
                }
    };
}