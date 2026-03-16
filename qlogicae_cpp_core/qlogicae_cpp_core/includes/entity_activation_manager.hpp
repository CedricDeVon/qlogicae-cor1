#pragma once

#include "abstract_class.hpp"
#include "entity_activation_status.hpp"
#include "entity_activation_manager_configurations.hpp"

namespace
	QLogicae::Cor::V1
{
    class
		EntityActivationManager :
			public AbstractClass<EntityActivationManagerConfigurations>
    {
    public:
		std::unordered_map<void*, EntityActivationStatus>
			entity_collection;

		EntityActivationManager();

		EntityActivationStatus
			get_entity_status(
				void*
					value
			);

		bool        
			set_entity_status(
				void*
					value,
				const EntityActivationStatus&
					status
			);

		bool        
			is_entity_status_equal(
				void*
					value,
				const EntityActivationStatus&
					status
			);

		bool        
			remove_entity(
				void*
					value
			);
        
		bool        
			clear_entities();		
	};
}
