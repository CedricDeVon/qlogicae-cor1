import os
import json
import shutil
import subprocess
from pathlib import Path

from all.cache import cache
from all.logger import logger
from all.filesystem import filesystem


class Utility:
    def handle_setup(self):
        logger.log_info("all setup - start")

        # Temporary Values
        value_1 = ""
        value_2 = ""
        value_3 = ""
        value_4 = ""

        # Essential File System Paths
        value_1 = Path(__file__).resolve().parent.parent.parent.parent.parent
        filesystem.is_folder_path_valid(
            value_1
        )
        cache.set_value(
            "all-current-root-project-full-path",
            value_1
        )
        

        value_1 = Path.cwd()
        filesystem.is_folder_path_valid(
            value_1
        )
        cache.set_value(
            "all-original-cli-full-path",
            value_1
        )
        cache.set_value(
            "all-current-cli-full-path",
            cache.get_value(
                "all-current-root-project-full-path"
            )
        )
        os.chdir(
            cache.get_value(
                "all-current-root-project-full-path"
            )    
        )


        # # Workspace Log File
        cache.set_value(
            "all-workspace-private-log-all-full-path",
            f"{cache.get_value("all-current-root-project-full-path")}/workspace/private/log/all.log"
        )
        logger.add_file_output(
            cache.get_value("all-workspace-private-log-all-full-path")
        )


        # Configurations
        logger.log_info("file logging start")

        value_1 = f"{cache.get_value("all-current-root-project-full-path")}/workspace/public/configuration/settings.json"
        filesystem.is_file_path_valid(
            value_1
        )
        cache.set_value(
            "all-workspace-public-configuration-settings-full-path",
            value_1
        )
        value_1 = f"{cache.get_value("all-current-root-project-full-path")}/workspace/private/configuration/settings.json"
        filesystem.is_file_path_valid(
            value_1
        )
        cache.set_value(
            "all-workspace-private-configuration-settings-full-path",
            value_1
        )

        with open(
            cache.get_value(
                "all-workspace-public-configuration-settings-full-path"
            ),
            "r",
            encoding="utf-8"
        ) as file:
            cache.set_value(
                "all-workspace-public-configuration-settings-data",
                json.load(file)
            )

        with open(
            cache.get_value(
                "all-workspace-private-configuration-settings-full-path"
            ),
            "r",
            encoding="utf-8"
        ) as file:
            cache.set_value(
                "all-workspace-private-configuration-settings-data",
                json.load(file)
            )        

        cache.set_value(
            "all-workspace-project-names",
            cache.get_value(
                "all-workspace-public-configuration-settings-data"
            ).get("all", {}).get("workspace-projects", {})
        )   

        logger.log_info("all setup - complete")

    def handle_shutdown(self):
        logger.shutdown()

    def handle_debug(self):
        self.handle_setup();

        cache.view_values()

        self.handle_shutdown()

    def handle_setup_filesystem(self):
        logger.log_info("all filesystem setup - start")

        # # All
        for project_name in cache.get_value("all-workspace-project-names"):
            logger.log_info(f"copying 'all' file system to '{project_name}' file system - start")
            shutil.copytree(
                f"{cache.get_value(f"all-current-root-project-full-path")}/workspace/public/target/all/filesystem",
                f"{cache.get_value(f"all-current-root-project-full-path")}/{project_name}",
                dirs_exist_ok=True
            )
            logger.log_info(f"copying 'all' file system to '{project_name}' file system - complete")


            logger.log_info(f"copying 'projects' file system to '{project_name}' file system - start")
            shutil.copytree(
                f"{cache.get_value(f"all-current-root-project-full-path")}/workspace/public/target/projects/filesystem",
                f"{cache.get_value(f"all-current-root-project-full-path")}/{project_name}",
                dirs_exist_ok=True
            )
            logger.log_info(f"copying 'projects' file system to '{project_name}' file system - complete")


            logger.log_info(f"copying '{project_name}' file system to '{project_name}' file system - start")
            shutil.copytree(
                f"{cache.get_value(f"all-current-root-project-full-path")}/workspace/public/target/{project_name}/filesystem",
                f"{cache.get_value(f"all-current-root-project-full-path")}/{project_name}",
                dirs_exist_ok=True
            )
            logger.log_info(f"copying '{project_name}' file system to '{project_name}' file system - complete")


        logger.log_info(f"copying 'all' file system to '.' file system - start")
        shutil.copytree(
            f"{cache.get_value(f"all-current-root-project-full-path")}/workspace/public/target/all/filesystem",
            f"{cache.get_value(f"all-current-root-project-full-path")}",
            dirs_exist_ok=True
        )
        logger.log_info(f"copying 'all' file system to '.' file system - complete")


        logger.log_info(f"copying 'root' file system to '.' file system - start")
        shutil.copytree(
            f"{cache.get_value(f"all-current-root-project-full-path")}/workspace/public/target/root/filesystem",
            f"{cache.get_value(f"all-current-root-project-full-path")}",
            dirs_exist_ok=True
        )
        logger.log_info(f"copying 'root' file system to '.' file system - complete")

        logger.log_info("all filesystem setup - complete")

    def handle_verify_tools(self):
        logger.log_info(f"verifying tools - start")

        logger.log_info(f"Docker: {subprocess.check_output(
            ["docker", "--version"],
            text=True
        ).strip()}")
        logger.log_info(f"Git: {subprocess.check_output(
            ["git", "--version"],
            text=True
        ).strip()}")
        logger.log_info(f"GitHub CLI: {subprocess.check_output(
            ["gh", "--version"],
            text=True
        ).strip()}")

        logger.log_info(f"verifying tools - complete")


all_utility = Utility()
