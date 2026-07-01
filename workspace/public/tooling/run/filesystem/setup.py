import argparse

from library.target_cache_value import TargetCacheValue
from library.execute_command_return import ExecuteCommandReturn
from library import log_manager, system_manager, handler_manager, value_cache_manager, macros_manager, filesystem_manager


def handle_manager_callback():
    cli_parser = argparse.ArgumentParser(
        description="'filesystem.setup' command",
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
        log_manager.singleton.log_info(
            f"'{cli_arguments}' is not an existing cli option set"
        )    


def handle_target_root():
    parsed_filesystem_path = macros_manager.singleton.parse_one(
        value_cache_manager.singleton.get_one_value(
            [
                f"root-workspace/public/configuration/workspace.yaml-raw",
                "data",
                "all",
                "full-path",
                "root"
            ],                
            target_cache_value=TargetCacheValue.DEFINED,
        ),
        (value_cache_manager.singleton.get_one_value(
            ["all-macros"],
            target_cache_value=TargetCacheValue.DEFINED,
        ) or {})
    )

    filesystem_manager.singleton.copy_filesystem_path(
        f"{value_cache_manager.singleton.get_one_value(
            ['root-current-full-path'],
            target_cache_value=TargetCacheValue.FOLDER_PATH
        )}/workspace/public/target/all/filesystem",
        parsed_filesystem_path
    )

    filesystem_manager.singleton.copy_filesystem_path(
        f"{value_cache_manager.singleton.get_one_value(
            ['root-current-full-path'],
            target_cache_value=TargetCacheValue.FOLDER_PATH
        )}/workspace/public/target/root/filesystem",
        parsed_filesystem_path
    )


def handle_target_project():
    for project_name in value_cache_manager.singleton.get_one_value(
        ["all-workspace-project-targets"],
        target_cache_value=TargetCacheValue.DEFINED,
    ):
        handle_target_project_selection(project_name)


def handle_target_project_selection(project_name):
    parsed_filesystem_path = macros_manager.singleton.parse_one(
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

    filesystem_manager.singleton.copy_filesystem_path(
        f"{value_cache_manager.singleton.get_one_value([
            'root-current-full-path'],
            target_cache_value=TargetCacheValue.FOLDER_PATH
        )}/workspace/public/target/all/filesystem",
        parsed_filesystem_path
    )
    filesystem_manager.singleton.copy_filesystem_path(
        f"{value_cache_manager.singleton.get_one_value([
            'root-current-full-path'],
            target_cache_value=TargetCacheValue.FOLDER_PATH
        )}/workspace/public/target/project/filesystem",
        parsed_filesystem_path
    )
    filesystem_manager.singleton.copy_filesystem_path(
        f"{value_cache_manager.singleton.get_one_value([
            'root-current-full-path'],
            target_cache_value=TargetCacheValue.FOLDER_PATH
        )}/workspace/public/target/project/selection/{project_name}/filesystem",
        parsed_filesystem_path
    )        


handler_manager.singleton.handle(
    handle_manager_callback
)


