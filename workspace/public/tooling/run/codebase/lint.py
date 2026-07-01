import argparse

from library.target_cache_value import TargetCacheValue
from library.execute_command_return import ExecuteCommandReturn
from library import log_manager, system_manager, handler_manager, value_cache_manager, macros_manager


def handle_manager_callback():
    cli_parser = argparse.ArgumentParser(
        description="'codebase.lint' command",
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
    pass


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
                system_manager.singleton.execute_command(
                    "bun run lint",
                    ExecuteCommandReturn.FULL_RETURN
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

