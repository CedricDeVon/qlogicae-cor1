#pragma once

namespace
	QLogicae::Cor::V1
{
    enum class
		TimeScaleUnit :
			uint8_t
    {
        YEARS,

        MONTHS,

        WEEKS,

        DAYS,
        
        HOURS,
        
        MINUTES,              
        
        SECONDS,
        
        MILLISECONDS,
        
        MICROSECONDS,
        
        NANOSECONDS,        

		NONE
    };
}

