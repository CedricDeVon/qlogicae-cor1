#pragma once

namespace
	QLogicaeCppCore
{
    struct
		ValueEnumKeyDeleteHandler
    {
        void operator()(HKEY handler) const
        {
            if (handler)
            {
                RegCloseKey(handler);
            }
        }
    };
}