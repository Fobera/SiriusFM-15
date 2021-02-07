#include <cstdio>
#include <cstdlib>
#include <stdexcept>
#include "IRProviderConst.h"

namespace SiriusFM
{
    IRProvider <IRModeE::Const>::IRProvider(char const* a_file)
    {
        FILE* fin = fopen(a_file, "r");
        if (fin == 0)
        {
            throw std::invalid_argument("File opens with error");
        }

        char buff[128] = {0};
        char name[4] = {0};
        int i;

        while(!feof(fin))
        {
            fgets(buff, 100, fin);
            for(i = 0; i < 3; i++)
            {
                name[i] = buff[i];
            }
            m_IRs[int(Str2CcyE(name))] = atof(buff + 4);
        }
        fclose(fin);
    }
}