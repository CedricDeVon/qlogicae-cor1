import os
import argparse
import subprocess

from utility.cache import utility_cache
from utility.logger import utility_logger
from utility.handler import utility_handler
from utility.filesystem import utility_filesystem


def handle_all_target_option():
    handle_root_target_option();
    handle_projects_target_option();


def handle_root_target_option():
    os.chdir(
        f"{utility_cache.get_value(
            "all-current-root-project-full-path"
        )}"
    )

    utility_filesystem.clean_filesystem_path(
        f"{utility_cache.get_value(
            "all-current-root-project-full-path"
        )}/workspace/private/temporary"
    )


def handle_projects_target_option():
    for project_name in utility_cache.get_value("all-workspace-projects"):
        handle_project_target_option(project_name)


def handle_project_target_option(project_name):
    os.chdir(
        f"{utility_cache.get_value(
            "all-current-root-project-full-path"
        )}/{project_name}"
    )    
    
    utility_filesystem.clean_filesystem_path(
        f"{utility_cache.get_value(
            "all-current-root-project-full-path"
        )}/{project_name}/workspace/private/temporary"
    )
    

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

elif cli_arguments.target in utility_cache.get_value("all-workspace-projects"):
    handle_project_target_option(
        cli_arguments.target
    )
    


utility_handler.handle_shutdown()


# feat:
# fix:
# refactor:
# perf:
# test:
# docs:
# style:
# build:
# ci:
# chore:
# deps:
# security:
# revert:
# release:
# config:

