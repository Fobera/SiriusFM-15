#pragma once
#include <stdexcept>

namespace SiriusFM
{
    class DiffusionLipton
    {
        private:
            double const m_mu;
            double const m_sigma_0;
            double const m_sigma_1;
            double const m_sigma_2;
        public:
            double mu(double S, double t) const
            {
                if(S < 0) return 0;
                return m_mu * S;
            }
            double sigma(double S, double t) const
            {
                if(S < 0) return 0;
                return m_sigma_0 + m_sigma_1 * S + m_sigma_2 * S * S;
            }
            DiffusionLipton(double a_mu, double a_sigma_0, double a_sigma_1, double a_sigma_2)
                :m_mu(a_mu),
                m_sigma_0(a_sigma_0),
                m_sigma_1(a_sigma_1),
                m_sigma_2(a_sigma_2)
                {
                    if(m_sigma_0 < 0 || m_sigma_2 < 0 || m_sigma_1 * m_sigma_1 - 4 * m_sigma_0 * m_sigma_2 >= 0)
                    {
                        throw std::invalid_argument("Invalid argument\n");
                    }
                }
    };
}