#pragma once

namespace
	QLOGICAE_COR1__BASE__HPP_CPP__COR_NAMESPACE_NAME
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
