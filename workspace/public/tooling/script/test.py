import argparse
import subprocess

from library.target_cache_value import TargetCacheValue
from library import log_manager, system_manager, handler_manager, value_cache_manager, macros_manager, filesystem_manager


def handle_manager_callback():
    cli_parser = argparse.ArgumentParser(
        description="build tool",
        epilog="...",
    )

    cli_parser.add_argument(
        "-t",
        "--target",
        help="target",
        dest="target",
        default=value_cache_manager.singleton.get_one_value(
            ["all-workspace-target"],
            target_cache_value=TargetCacheValue.DEFINED,
        ),
        choices=(value_cache_manager.singleton.get_one_value(
            ["all-workspace-project-targets"],
            target_cache_value=TargetCacheValue.DEFINED,
        ) or {})
    )

    cli_parser.add_argument(
        "-s",
        "--strategy",
        help="strategy",
        dest="strategy",
        default="unit",
        choices={ "unit", "benchmark" }
    )

    cli_arguments = cli_parser.parse_args()      


    system_manager.singleton.change_cli_filesystem_path(
        macros_manager.singleton.parse_one(
            value_cache_manager.singleton.get_one_value(
                [
                    f"root-workspace/public/configuration/workspace.yaml-raw",
                    "data",
                    "all",
                    "full-path",
                    cli_arguments.target
                ],                
                target_cache_value=TargetCacheValue.DEFINED,
            ),
            (value_cache_manager.singleton.get_one_value(
                ["all-macros"],
                target_cache_value=TargetCacheValue.DEFINED,
            ) or {})
        )
    )


    if cli_arguments.target == "typescript": 
        if cli_arguments.strategy == "unit": 
            log_manager.singleton.log_info(
                system_manager.singleton.execute_command(
                    "bun run test:unit"
                )                 
            )

        elif cli_arguments.strategy == "benchmark": 
            log_manager.singleton.log_info(
                system_manager.singleton.execute_command(
                    "bun run test:benchmark"
                )                 
            )

    system_manager.singleton.change_cli_filesystem_path(
        f"{value_cache_manager.singleton.get_one_value(
            [
                "root-current-full-path"
            ],
            target_cache_value=TargetCacheValue.FOLDER_PATH,
        )}"
    )


handler_manager.singleton.handle(
    handle_manager_callback
)
