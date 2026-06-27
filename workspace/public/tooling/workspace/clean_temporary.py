import os
import argparse
import subprocess

from library.target_cache_value import TargetCacheValue
from library import value_cache, logger, filesystem, handler, file_logger


def handle_all_target_option():
    handle_root_target_option();
    handle_projects_target_option();


def handle_root_target_option():
    os.chdir(
        f"{value_cache.singleton.get_one_value(
            "all-current-root-project-full-path",
            target_cache_value=TargetCacheValue.FOLDER_PATH
        )}"
    )

    filesystem.singleton.clean_filesystem_path(
        f"{value_cache.singleton.get_one_value(
            "all-current-root-project-full-path",
            target_cache_value=TargetCacheValue.FOLDER_PATH
        )}/workspace/private/temporary"
    )


def handle_projects_target_option():
    for project_name in value_cache.singleton.get_one_value(
        "all-workspace-projects",
        target_cache_value=TargetCacheValue.DEFINED
    ):
        handle_project_target_option(project_name)


def handle_project_target_option(project_name):
    os.chdir(
        f"{value_cache.singleton.get_one_value(
            "all-current-root-project-full-path",
            target_cache_value=TargetCacheValue.FOLDER_PATH
        )}/{project_name}"
    )    
    
    filesystem.singleton.clean_filesystem_path(
        f"{value_cache.singleton.get_one_value(
            "all-current-root-project-full-path",
            target_cache_value=TargetCacheValue.FOLDER_PATH
        )}/{project_name}/workspace/private/temporary"
    )
    

cli_parser = argparse.ArgumentParser()

cli_parser.add_argument(
    "--target",
    default="all"
)

cli_arguments = cli_parser.parse_args()

handler.singleton.handle_setup()

if "all" in cli_arguments.target:
    handle_all_target_option()

elif "root" in cli_arguments.target:
    handle_root_target_option()

elif "projects" in cli_arguments.target:
    handle_projects_target_option()

elif cli_arguments.target in value_cache.singleton.get_one_value(
    "all-workspace-projects",
    target_cache_value=TargetCacheValue.DEFINED
):
    handle_project_target_option(
        cli_arguments.target
    )


handler.singleton.handle_shutdown()
