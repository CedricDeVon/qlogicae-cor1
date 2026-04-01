#pragma once

namespace
	QLOGICAE_COR_V1__BASE__HPP_CPP__COR_NAMESPACE_NAME
{
    enum class
		TimeFormat :
			uint8_t
    {
        UNIX,
        
        ISO8601,
        
        SECOND_LEVEL_TIMESTAMP,
        
        MILLISECOND_LEVEL_TIMESTAMP,
        
        MICROSECOND_LEVEL_TIMESTAMP,
        
        FULL_TIMESTAMP,
        
        FULL_DASHED_TIMESTAMP,
        
        HOUR_12,
        
        HOUR_24,
        
        MILLISECOND_MICROSECOND_NANOSECOND,
        
        DATE_DASHED,
        
        DATE_MDY_SLASHED,
        
        DATE_DMY_SLASHED,
        
        DATE_DMY_SPACED,
        
        DATE_VERBOSE,
		
		NONE
    };
}
