import os
import shutil
import argparse
import subprocess

from library.target_cache_value import TargetCacheValue
from library import value_cache, logger, handler, filesystem


def handle_all_target_option():
    handle_root_target_option();
    handle_projects_target_option();


def handle_root_target_option():
    logger.singleton.log_info(f"copying file system 'all' - start")
    filesystem.singleton.copy_filesystem_path(
        f"{value_cache.singleton.get_one_value(f"all-current-root-project-full-path", target_cache_value=TargetCacheValue.FOLDER_PATH)}/workspace/public/target/all/filesystem",
        f"{value_cache.singleton.get_one_value(f"all-current-root-project-full-path", target_cache_value=TargetCacheValue.FOLDER_PATH)}"        
    )
    logger.singleton.log_info(f"copying file system 'all' - complete")

    logger.singleton.log_info(f"copying file system 'root' - start")
    filesystem.singleton.copy_filesystem_path(
        f"{value_cache.singleton.get_one_value(f"all-current-root-project-full-path", target_cache_value=TargetCacheValue.FOLDER_PATH)}/workspace/public/target/root/filesystem",
        f"{value_cache.singleton.get_one_value(f"all-current-root-project-full-path", target_cache_value=TargetCacheValue.FOLDER_PATH)}"        
    )
    logger.singleton.log_info(f"copying file system 'root' - complete")


def handle_projects_target_option():
    for project_name in value_cache.singleton.get_one_value("all-workspace-projects", target_cache_value=TargetCacheValue.DEFINED):
        handle_project_target_option(project_name)


def handle_project_target_option(project_name):
    logger.singleton.log_info(f"copying file system '{project_name}' - start")
    filesystem.singleton.copy_filesystem_path(
        f"{value_cache.singleton.get_one_value(f"all-current-root-project-full-path", target_cache_value=TargetCacheValue.FOLDER_PATH)}/workspace/public/target/all/filesystem",
        f"{value_cache.singleton.get_one_value(f"all-current-root-project-full-path", target_cache_value=TargetCacheValue.FOLDER_PATH)}/{project_name}"        
    )
    filesystem.singleton.copy_filesystem_path(
        f"{value_cache.singleton.get_one_value(f"all-current-root-project-full-path", target_cache_value=TargetCacheValue.FOLDER_PATH)}/workspace/public/target/projects/filesystem",
        f"{value_cache.singleton.get_one_value(f"all-current-root-project-full-path", target_cache_value=TargetCacheValue.FOLDER_PATH)}/{project_name}"        
    )
    filesystem.singleton.copy_filesystem_path(
        f"{value_cache.singleton.get_one_value(f"all-current-root-project-full-path", target_cache_value=TargetCacheValue.FOLDER_PATH)}/workspace/public/target/{project_name}/filesystem",
        f"{value_cache.singleton.get_one_value(f"all-current-root-project-full-path", target_cache_value=TargetCacheValue.FOLDER_PATH)}/{project_name}"        
    )
    logger.singleton.log_info(f"copying file system '{project_name}' - complete")


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

elif cli_arguments.target in value_cache.singleton.get_one_value("all-workspace-projects", target_cache_value=TargetCacheValue.DEFINED):
    handle_project_target_option(
        cli_arguments.target
    )
    
handler.singleton.handle_shutdown()

