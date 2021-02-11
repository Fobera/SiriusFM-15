#pragma once
#include <stdexcept>
namespace SiriusFM
{
    class Option
    {
        protected:
            bool const m_IsAmerican;
            int const m_Tdays;
            Option(bool a_IsAmerican, int a_Tdays):
            m_IsAmerican(a_IsAmerican),
            m_Tdays(a_Tdays)            
            {
                if(m_Tdays <= 0)
                {
                    throw std::invalid_argument("m_Tdays <= 0");
                }
            }
        public:
            bool IsAmerican() const
            {
                return m_IsAmerican;
            }

            virtual double payoff(long a_L, double const* a_t, double const* a_S) const = 0;

            virtual ~Option()
            {

            }

    };
}