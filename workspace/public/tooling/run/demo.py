from pathlib import Path

from library.target_cache_value import TargetCacheValue
from library.execute_command_return import ExecuteCommandReturn
from library import (
    log_manager,
    system_manager,
    handler_manager,
    value_cache_manager,
    macros_manager,
    filesystem_manager,
)


def handle_manager_callback():
    pass


handler_manager.singleton.handle(handle_manager_callback)
