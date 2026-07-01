import argparse

from library.target_cache_value import TargetCacheValue
from library.execute_command_return import ExecuteCommandReturn
from library import log_manager, system_manager, handler_manager, value_cache_manager, macros_manager


def handle_manager_callback():
    cli_parser = argparse.ArgumentParser(
        description="'toolset.verify' command",
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


    if cli_arguments.target == "all":
        handle_target_root()
        handle_target_project()

    elif cli_arguments.target == "root":
        handle_target_root()

    elif cli_arguments.target == "project":
        handle_target_project()

    elif cli_arguments.target in value_cache_manager.singleton.get_one_value(
        ["all-workspace-project-targets"],
        target_cache_value=TargetCacheValue.DEFINED,
    ):
        handle_target_project_selection(
            cli_arguments.target
        )

    else:
        handler_manager.singleton.handle_cli_argument_set_invalid(
            cli_arguments
        )    


def handle_target_root():    
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


def handle_target_project():
    for project_name in value_cache_manager.singleton.get_one_value(
        ["all-workspace-project-targets"],
        target_cache_value=TargetCacheValue.DEFINED,
    ):
        handle_target_project_selection(
            project_name
        )


def handle_target_project_selection(project_name):
    system_manager.singleton.change_cli_filesystem_path(
        macros_manager.singleton.parse_one(
            value_cache_manager.singleton.get_one_value(
                [
                    f"root-workspace/public/configuration/workspace.yaml-raw",
                    "data",
                    "all",
                    "full-path",
                    project_name
                ],                
                target_cache_value=TargetCacheValue.DEFINED,
            ),
            (value_cache_manager.singleton.get_one_value(
                ["all-macros"],
                target_cache_value=TargetCacheValue.DEFINED,
            ) or {})
        )
    )

    match project_name:
        case "typescript":
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

