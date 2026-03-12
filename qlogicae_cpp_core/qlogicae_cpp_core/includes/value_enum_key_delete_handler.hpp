#pragma once

namespace
	QLogicae::Cor::V1
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