import os
import shutil
import argparse
import subprocess

from utility.cache import utility_cache
from utility.logger import utility_logger
from utility.handler import utility_handler


def handle_all_target_option():
    handle_root_target_option();
    handle_projects_target_option();


def handle_root_target_option():
    utility_logger.log_info(f"copying file system 'all' - start")
    shutil.copytree(
        f"{utility_cache.get_value(f"all-current-root-project-full-path")}/workspace/public/target/all/filesystem",
        f"{utility_cache.get_value(f"all-current-root-project-full-path")}",
        dirs_exist_ok=True
    )
    utility_logger.log_info(f"copying file system 'all' - complete")

    utility_logger.log_info(f"copying file system 'root' - start")
    shutil.copytree(
        f"{utility_cache.get_value(f"all-current-root-project-full-path")}/workspace/public/target/root/filesystem",
        f"{utility_cache.get_value(f"all-current-root-project-full-path")}",
        dirs_exist_ok=True
    )
    utility_logger.log_info(f"copying file system 'root' - complete")


def handle_projects_target_option():
    for project_name in utility_cache.get_value("all-workspace-project-names"):
        handle_project_target_option(project_name)


def handle_project_target_option(project_name):
    utility_logger.log_info(f"copying file system '{project_name}' - start")
    shutil.copytree(
        f"{utility_cache.get_value(f"all-current-root-project-full-path")}/workspace/public/target/all/filesystem",
        f"{utility_cache.get_value(f"all-current-root-project-full-path")}/{project_name}",
        dirs_exist_ok=True
    )
    shutil.copytree(
        f"{utility_cache.get_value(f"all-current-root-project-full-path")}/workspace/public/target/projects/filesystem",
        f"{utility_cache.get_value(f"all-current-root-project-full-path")}/{project_name}",
        dirs_exist_ok=True
    )
    shutil.copytree(
        f"{utility_cache.get_value(f"all-current-root-project-full-path")}/workspace/public/target/{project_name}/filesystem",
        f"{utility_cache.get_value(f"all-current-root-project-full-path")}/{project_name}",
        dirs_exist_ok=True
    )
    utility_logger.log_info(f"copying file system '{project_name}' - complete")


cli_parser = argparse.ArgumentParser()

cli_parser.add_argument(
    "--target",
    default="all"
)

cli_arguments = cli_parser.parse_args()

utility_handler.handle_setup()

if "all" in cli_arguments.target:
    handle_all_target_option()

elif "root" in cli_arguments.target:
    handle_root_target_option()

elif "projects" in cli_arguments.target:
    handle_projects_target_option()

elif cli_arguments.target in utility_cache.get_value("all-workspace-project-names"):
    handle_project_target_option(
        cli_arguments.target
    )
    
utility_handler.handle_shutdown()

