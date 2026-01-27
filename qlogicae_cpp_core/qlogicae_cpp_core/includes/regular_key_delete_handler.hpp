#pragma once

namespace
	QLogicaeCppCore
{
	struct
		RegularKeyDeleteHandler
    {
        void operator() (HKEY handler)
        {
            if (handler)
            {
                RegCloseKey(handler);
            }
        }
    };
}
