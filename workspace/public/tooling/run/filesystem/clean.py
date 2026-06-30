import os
import argparse

from library import (
    filesystem_manager,
    handler_manager,
    macros_manager,
    log_manager,
    value_cache_manager,
)
from library.target_cache_value import TargetCacheValue
from library.execute_command_return import ExecuteCommandReturn


def handler_manager_callback():
    cli_parser = argparse.ArgumentParser(
        description="'run.filesystem.clean' command",
        epilog="...",
    )
    cli_parser.add_argument(
        "-t",
        "--target",
        help="combination target",
        dest="target",
        choices=(value_cache_manager.singleton.get_one_value(
            ["all-clean-include-targets"],
            target_cache_value=TargetCacheValue.DEFINED,
        ) or {}),
    )
    cli_parser.add_argument(
        "-dt",
        "--display-target",
        dest="display_target",
        help="displays target filesystem paths",
        action=argparse.BooleanOptionalAction,
        default=False,
    )    
    cli_arguments = cli_parser.parse_args()


    for include_path in value_cache_manager.singleton.get_one_value(
        [
            f"root-workspace/public/configuration/workspace.yaml-raw",
            "data",
            "all",
            "clean",
            "include",
            "targets",
            cli_arguments.target,
        ],
        target_cache_value=TargetCacheValue.DEFINED,
    ) or {}:      
        parsed_include_path = macros_manager.singleton.parse_one(
            include_path,
            (value_cache_manager.singleton.get_one_value(
                ["all-macros"],
                target_cache_value=TargetCacheValue.DEFINED,
            ) or {})
        )

        if parsed_include_path in (value_cache_manager.singleton.get_one_value(
            ["all-clean-exclude-targets"],
            target_cache_value=TargetCacheValue.DEFINED,
        ) or {}):
            log_manager.singleton.log_info(
                f"filesystem '{parsed_include_path}' ignored for cleaning"
            )
            continue

        if cli_arguments.display_target:
            log_manager.singleton.log_info(
                parsed_include_path
            )
            continue        

        filesystem_manager.singleton.clean_filesystem_path(
            parsed_include_path
        )
        log_manager.singleton.log_info(
            f"filesystem '{parsed_include_path}' cleaned"
        )


handler_manager.singleton.handle(
    handler_manager_callback
)

