#pragma once

namespace
	QLogicae::Cor::V1
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
