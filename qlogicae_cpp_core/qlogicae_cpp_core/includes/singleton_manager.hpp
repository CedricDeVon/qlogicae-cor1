#pragma once

#include "singleton_manager_configurations.hpp"

namespace
	QLogicae::Cor::V1
{        
    class
		SingletonManager
    {
    public:     
		static SingletonManagerConfigurations
			configurations;

		static boost::mutex
			feature_handling_mutex_1;
     
		SingletonManager();

		~SingletonManager();

		static bool
			construct();

		static bool
			destruct();

		static bool
			setup(
				const SingletonManagerConfigurations&
					new_configurations
			);

		static bool
			reset();

		template <typename Type> static Type&
			get_singleton();
	
		template <typename Type, std::size_t InstanceCount> static Type&
			get_singleton();

		static SingletonManager&
			get_this_singleton();		
    };

    template <typename Type> Type&
        SingletonManager
			::get_singleton()
    {			
		boost::unique_lock<boost::mutex>
			mutex_lock;
		if (configurations.is_thread_safety_enabled_for_feature_handling())
		{
			mutex_lock =
				boost::unique_lock<boost::mutex>
				(
					feature_handling_mutex_1
				);
		}
			
        static Type
            singleton;		  

        return
            singleton;
    }    

	template <typename Type, std::size_t InstanceCount> static Type&
		SingletonManager
			::get_singleton()
	{
		static_assert(InstanceCount > 0);

		boost::unique_lock<boost::mutex>
			mutex_lock;
		if (configurations.is_thread_safety_enabled_for_feature_handling())
		{
			mutex_lock =
				boost::unique_lock<boost::mutex>
				(
					feature_handling_mutex_1
				);
		}		

		static std::array<Type, InstanceCount>
			instances{};

		return
			instances
			[
				std::hash<std::thread::id>{}(
					std::this_thread::get_id()
				) % InstanceCount
			];
	}
}
