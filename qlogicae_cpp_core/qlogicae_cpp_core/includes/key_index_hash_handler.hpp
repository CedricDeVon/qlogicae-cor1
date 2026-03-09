#pragma once

namespace
	QLogicaeCppCore
{
	struct
		KeyIndexHashHandler
	{
		size_t operator()(
			const std::variant<std::string, size_t>&
				values
			) const
		{
			return
				std::visit(
					[](auto&& value)
					{
						using Type = std::decay_t<decltype(value)>;

						if constexpr (std::is_same_v<Type, std::string>)
						{
							return
								std::hash<std::string>{}(value);
						}
						else
						{
							return
								std::hash<size_t>{}(value);
						}
					},
					values
				);
		}
	};
}
