import os
import argparse

from library import (
    system_manager,
    filesystem_manager,
    handler_manager,
    macros_manager,
    file_log_manager,
    value_cache_manager,
)
from library.target_cache_value import TargetCacheValue
from library.execute_command_return import ExecuteCommandReturn


def handler_manager_callback():
    cli_parser = argparse.ArgumentParser(
        description="'script' command",
        epilog="...",
    )
    cli_parser.add_argument(
        "-t",
        "--target",
        help="target",
        dest="target",
        choices=(value_cache_manager.singleton.get_one_value(
            [
                "all-script-targets"
            ],
            target_cache_value=TargetCacheValue.DEFINED,
        ) or {}),
    )
    cli_arguments = cli_parser.parse_args()      


    target_type = value_cache_manager.singleton.get_one_value(
        [
            f"root-workspace/public/configuration/workspace.yaml-raw",
            "data",
            "all",
            "script",
            "targets",
            cli_arguments.target,
            "type"
        ],
        target_cache_value=TargetCacheValue.ANY,
    )

    if target_type == "individual":
        handle_target_option(
            cli_arguments.target
        )
    elif target_type == "collection":
        for collection_script_name in (value_cache_manager.singleton.get_one_value(
            [
                f"root-workspace/public/configuration/workspace.yaml-raw",
                "data",
                "all",
                "script",
                "targets",
                cli_arguments.target,
                "commands"
            ],
            target_cache_value=TargetCacheValue.ANY
        ) or []):
            handle_target_option(
                collection_script_name
            )
    else:
        handler_manager.singleton.handle_cli_argument_set_invalid(
            cli_arguments
        )

def handle_target_option(target_name):
    system_manager.singleton.change_cli_filesystem_path(
        macros_manager.singleton.parse_one(
            value_cache_manager.singleton.get_one_value(
                [
                    f"root-workspace/public/configuration/workspace.yaml-raw",
                    "data",
                    "all",
                    "script",
                    "targets",
                    target_name,
                    "enter-full-path"
                ],
                target_cache_value=TargetCacheValue.ANY,
            ) or "{{ root-current-full-path }}",
            (value_cache_manager.singleton.get_one_value(
                ["all-macros"],
                target_cache_value=TargetCacheValue.DEFINED,
            ) or {})
        )        
    )

    for current_command in (value_cache_manager.singleton.get_one_value(
        [
            f"root-workspace/public/configuration/workspace.yaml-raw",
            "data",
            "all",
            "script",
            "targets",
            target_name,
            "commands"
        ],
        target_cache_value=TargetCacheValue.DEFINED,
    ) or []):
        file_log_manager.singleton.log_info(
            system_manager.singleton.execute_command(
                macros_manager.singleton.parse_one(
                    current_command,
                    (value_cache_manager.singleton.get_one_value(
                        ["all-macros"],
                        target_cache_value=TargetCacheValue.DEFINED,
                    ) or {})
                ),
                ExecuteCommandReturn.MINIMAL_RETURN
            )                 
        )

    system_manager.singleton.change_cli_filesystem_path(
        macros_manager.singleton.parse_one(
            value_cache_manager.singleton.get_one_value(
                [
                    f"root-workspace/public/configuration/workspace.yaml-raw",
                    "data",
                    "all",
                    "script",
                    "targets",
                    target_name,
                    "exit-full-path"
                ],
                target_cache_value=TargetCacheValue.ANY,
            ) or "{{ root-current-full-path }}",
            (value_cache_manager.singleton.get_one_value(
                ["all-macros"],
                target_cache_value=TargetCacheValue.DEFINED,
            ) or {})
        )       
    )


handler_manager.singleton.handle(
    handler_manager_callback
)
