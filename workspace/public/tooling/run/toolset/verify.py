import os
import argparse
import subprocess

from library.target_cache_value import TargetCacheValue
from library.execute_command_return import ExecuteCommandReturn
from library import handler_manager, log_manager, value_cache_manager, system_manager, macros_manager


def handle_manager_callback():
    cli_parser = argparse.ArgumentParser(
        description="'run.toolset.verify' command",
        epilog="...",
    )
    cli_parser.add_argument(
        "-t",
        "--target",
        help="workspace target",
        dest="target",
        default=value_cache_manager.singleton.get_one_value(
            ["all-workspace-target"],
            target_cache_value=TargetCacheValue.DEFINED,
        ),
        choices=(value_cache_manager.singleton.get_one_value(
            ["all-workspace-targets"],
            target_cache_value=TargetCacheValue.DEFINED,
        ) or {})
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


    if "root" in cli_arguments.target:
        log_manager.singleton.log_info(
            f"Docker: {
                system_manager.singleton.execute_command(
                    'docker --version',
                    ExecuteCommandReturn.FULL_RETURN
                )
            }"
        )
        log_manager.singleton.log_info(
            f"Git: {
                system_manager.singleton.execute_command(
                    'git --version',
                    ExecuteCommandReturn.FULL_RETURN
                )
            }"
        )
        log_manager.singleton.log_info(
            f"GitHub CLI: {
                system_manager.singleton.execute_command(
                    'gh --version',
                    ExecuteCommandReturn.FULL_RETURN
                )
            }"
        )
        
    if "typescript" in cli_arguments.target:
        log_manager.singleton.log_info(
            f"Node: {
                system_manager.singleton.execute_command(
                    'node --version',
                    ExecuteCommandReturn.FULL_RETURN
                )
            }"
        )
        log_manager.singleton.log_info(
            f"FNM: {
                system_manager.singleton.execute_command(
                    'fnm --version',
                    ExecuteCommandReturn.FULL_RETURN
                )
            }"
        )
        log_manager.singleton.log_info(
            f"NPM: {
                system_manager.singleton.execute_command(
                    'npm --version',
                    ExecuteCommandReturn.FULL_RETURN
                )
            }"
        )
        log_manager.singleton.log_info(
            f"Bun: {
                system_manager.singleton.execute_command(
                    'bun --version',
                    ExecuteCommandReturn.FULL_RETURN
                )
            }"
        )
        log_manager.singleton.log_info(
            f"Corepack: {
                system_manager.singleton.execute_command(
                    'bunx corepack --version',
                    ExecuteCommandReturn.FULL_RETURN
                )
            }"
        )
        log_manager.singleton.log_info(
            f"PNPM: {
                system_manager.singleton.execute_command(
                    'bunx pnpm --version',
                    ExecuteCommandReturn.FULL_RETURN
                )
            }"
        )
        log_manager.singleton.log_info(
            f"Yarn: {
                system_manager.singleton.execute_command(
                    'bunx yarn --version',
                    ExecuteCommandReturn.FULL_RETURN
                )
            }"
        )  

    else:
        log_manager.singleton.log_info(
            f"'{cli_arguments}' is not an existing cli option set"
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


