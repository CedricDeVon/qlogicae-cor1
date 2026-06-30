import argparse
import os
import subprocess

from library import handler_manager, log_manager, value_cache_manager, system_manager, macros_manager
from library.target_cache_value import TargetCacheValue



def handle_manager_callback():
    cli_parser = argparse.ArgumentParser(
        description="verify toolsets",
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
            f"Docker: {subprocess.check_output(['docker', '--version'], text=True).strip()}"
        )
        log_manager.singleton.log_info(
            f"Git: {subprocess.check_output(['git', '--version'], text=True).strip()}"
        )
        log_manager.singleton.log_info(
            f"GitHub CLI: {subprocess.check_output(['gh', '--version'], text=True).strip()}"
        )
        
    elif "typescript" in cli_arguments.target:
        log_manager.singleton.log_info(
            f"Node: {subprocess.check_output(['node', '--version'], text=True).strip()}"
        )
        log_manager.singleton.log_info(
            f"FNM: {subprocess.check_output(['fnm', '--version'], text=True).strip()}"
        )
        log_manager.singleton.log_info(
            f"NPM: {subprocess.check_output(['npm', '--version'], text=True).strip()}"
        )
        log_manager.singleton.log_info(
            f"Bun: {subprocess.check_output(['bun', '--version'], text=True).strip()}"
        )
        log_manager.singleton.log_info(
            f"Corepack: {
                subprocess.check_output(
                    ['bunx', 'corepack', '--version'], text=True
                ).strip()
            }"
        )
        log_manager.singleton.log_info(
            f"PNPM: {
                subprocess.check_output(
                    ['bunx', 'pnpm', '--version'], text=True
                ).strip()
            }"
        )
        log_manager.singleton.log_info(
            f"Yarn: {
                subprocess.check_output(
                    ['bunx', 'yarn', '--version'], text=True
                ).strip()
            }"
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


