import os
import argparse
import subprocess

from utility.cache import utility_cache
from utility.logger import utility_logger
from utility.handler import utility_handler


def handle_root_target_option():
    os.chdir(
        f"{utility_cache.get_value(
            "all-current-root-project-full-path"
        )}"
    )
    utility_logger.log_info(f"{subprocess.check_output(
        ["git", "add", "."],
        text=True
    ).strip()}")
    utility_logger.log_info(f"{subprocess.check_output(
        ["git", "add", "."],
        text=True
    ).strip()}")
    utility_logger.log_info(f"{subprocess.check_output(
        ["git", "add", "."],
        text=True
    ).strip()}")


def handle_project_target_option(project_name):
    os.chdir(
        f"{utility_cache.get_value(
            "all-current-root-project-full-path"
        )}/${project_name}"
    )    
    

cli_parser = argparse.ArgumentParser()

cli_parser.add_argument(
    "--target",
    default="root"
)

cli_arguments = cli_parser.parse_args()

utility_handler.handle_setup()

if "root" in cli_arguments.target:
    handle_root_target_option();

elif cli_arguments.target in utility_cache.get_value("all-workspace-project-names"):
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

