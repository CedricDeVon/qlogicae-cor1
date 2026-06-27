from library import value_cache, handler


handler.singleton.handle_setup()

value_cache.singleton.display_all_items()

handler.singleton.handle_shutdown()

