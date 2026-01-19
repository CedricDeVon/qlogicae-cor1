#pragma once

namespace
	QLogicaeCppCore
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
