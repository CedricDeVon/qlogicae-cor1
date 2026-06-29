from library import handler_manager, value_cache_manager


handler_manager.singleton.handle_setup()

value_cache_manager.singleton.display_all_items()

handler_manager.singleton.handle_shutdown()
