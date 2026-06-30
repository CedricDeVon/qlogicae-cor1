import argparse
import subprocess

from library.target_cache_value import TargetCacheValue
from library.execute_command_return import ExecuteCommandReturn
from library import log_manager, system_manager, handler_manager, value_cache_manager, macros_manager, filesystem_manager


def handle_manager_callback():
    cli_parser = argparse.ArgumentParser(
        description="'run.test.benchmark' command",
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
            ["all-workspace-project-targets"],
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


    if cli_arguments.target == "typescript": 
        log_manager.singleton.log_info(
            system_manager.singleton.execute_command(
                "bun run test:benchmark",
                ExecuteCommandReturn.MINIMAL_RETURN
            )                 
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



# def handle_all_target_option():
#     handle_root_target_option()
#     handle_projects_target_option()


# def handle_root_target_option():
#     logger.singleton.log_info("copying file system 'all' - start")
#     filesystem.singleton.copy_filesystem_path(
#         f"{value_cache.singleton.get_one_value('root-current-full-path', target_cache_value=TargetCacheValue.FOLDER_PATH)}/workspace/public/target/all/filesystem",
#         f"{value_cache.singleton.get_one_value('root-current-full-path', target_cache_value=TargetCacheValue.FOLDER_PATH)}",
#     )
#     logger.singleton.log_info("copying file system 'all' - complete")

#     logger.singleton.log_info("copying file system 'root' - start")
#     filesystem.singleton.copy_filesystem_path(
#         f"{value_cache.singleton.get_one_value('root-current-full-path', target_cache_value=TargetCacheValue.FOLDER_PATH)}/workspace/public/target/root/filesystem",
#         f"{value_cache.singleton.get_one_value('root-current-full-path', target_cache_value=TargetCacheValue.FOLDER_PATH)}",
#     )
#     logger.singleton.log_info("copying file system 'root' - complete")


# def handle_projects_target_option():
#     for project_name in value_cache.singleton.get_one_value(
#         "project-selections",
#         target_cache_value=TargetCacheValue.DEFINED,
#     ):
#         handle_project_target_option(project_name)


# def handle_project_target_option(project_name):
#     logger.singleton.log_info(f"copying file system '{project_name}' - start")
#     filesystem.singleton.copy_filesystem_path(
#         f"{value_cache.singleton.get_one_value('root-current-full-path', target_cache_value=TargetCacheValue.FOLDER_PATH)}/workspace/public/target/all/filesystem",
#         f"{value_cache.singleton.get_one_value('root-current-full-path', target_cache_value=TargetCacheValue.FOLDER_PATH)}/selection/{project_name}",
#     )
#     filesystem.singleton.copy_filesystem_path(
#         f"{value_cache.singleton.get_one_value('root-current-full-path', target_cache_value=TargetCacheValue.FOLDER_PATH)}/workspace/public/target/project/filesystem",
#         f"{value_cache.singleton.get_one_value('root-current-full-path', target_cache_value=TargetCacheValue.FOLDER_PATH)}/selection/{project_name}",
#     )
#     filesystem.singleton.copy_filesystem_path(
#         f"{value_cache.singleton.get_one_value('root-current-full-path', target_cache_value=TargetCacheValue.FOLDER_PATH)}/workspace/public/target/project/selection/{project_name}/filesystem",
#         f"{value_cache.singleton.get_one_value('root-current-full-path', target_cache_value=TargetCacheValue.FOLDER_PATH)}/selection/{project_name}",
#     )
#     logger.singleton.log_info(
#         f"copying file system '{project_name}' - complete"
#     )


# cli_parser = argparse.ArgumentParser()

# cli_parser.add_argument("--target", default="all")

# cli_arguments = cli_parser.parse_args()

# handler.singleton.handle_setup()

# if "all" in cli_arguments.target:
#     handle_all_target_option()

# elif "root" in cli_arguments.target:
#     handle_root_target_option()

# elif "projects" in cli_arguments.target:
#     handle_projects_target_option()

# elif cli_arguments.target in value_cache.singleton.get_one_value(
#     "project-selections", target_cache_value=TargetCacheValue.DEFINED
# ):
#     handle_project_target_option(cli_arguments.target)

# handler.singleton.handle_shutdown()
