#pragma once

namespace
	QLOGICAE_COR1__BASE__HPP_CPP__COR_NAMESPACE_NAME
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
