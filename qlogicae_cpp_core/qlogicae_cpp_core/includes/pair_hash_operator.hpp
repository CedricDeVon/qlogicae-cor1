#pragma once

namespace
	QLogicaeCppCore
{
    struct
		PairHashOperator
    {
        std::size_t operator()(
            const std::pair<void*,
            std::string>& pair
        ) const noexcept
        {
            return std::hash<void*>{}(pair.first) ^
                (std::hash<std::string>{}(pair.second) << 1);
        }
    };
}

