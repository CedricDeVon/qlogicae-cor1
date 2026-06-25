import os
import json
import shutil
import subprocess
from pathlib import Path

from utility.cache import utility_cache
from utility.logger import utility_logger
from utility.handler import utility_handler

class Handler:
    def handle_setup(self):
        utility_handler.handle_setup()


        utility_logger.log_info("start")

        
        utility_cache.set_value(
            "all-workspace-public-configuration-settings-full-path",
            f"{utility_cache.get_value("all-current-root-project-full-path")}/workspace/public/configuration/settings.json"
        )
        utility_cache.set_value(
            "all-workspace-private-configuration-settings-full-path",
            f"{utility_cache.get_value("all-current-root-project-full-path")}/workspace/private/configuration/settings.json"
        )

        with open(
            utility_cache.get_value(
                "all-workspace-public-configuration-settings-full-path"
            ),
            "r",
            encoding="utf-8"
        ) as file:
            utility_cache.set_value(
                "all-workspace-public-configuration-settings-data",
                json.load(file)
            )

        with open(
            utility_cache.get_value(
                "all-workspace-private-configuration-settings-full-path"
            ),
            "r",
            encoding="utf-8"
        ) as file:
            utility_cache.set_value(
                "all-workspace-private-configuration-settings-data",
                json.load(file)
            )        

        utility_cache.set_value(
            "all-workspace-project-names",
            utility_cache.get_value(
                "all-workspace-public-configuration-settings-data"
            ).get("all", {}).get("workspace-projects", {})
        )   

        utility_logger.log_info("complete")

    def handle_shutdown(self):
        utility_logger.log_info("start")


        utility_handler.handle_shutdown()


        utility_logger.log_info("complete")

    def handle_setup_filesystem(self):
        utility_logger.log_info("start")


        # # All
        for project_name in utility_cache.get_value("all-workspace-project-names"):
            utility_logger.log_info(f"copying 'all' file system to '{project_name}' file system - start")
            shutil.copytree(
                f"{utility_cache.get_value(f"all-current-root-project-full-path")}/workspace/public/target/all/filesystem",
                f"{utility_cache.get_value(f"all-current-root-project-full-path")}/{project_name}",
                dirs_exist_ok=True
            )
            utility_logger.log_info(f"copying 'all' file system to '{project_name}' file system - complete")


            utility_logger.log_info(f"copying 'projects' file system to '{project_name}' file system - start")
            shutil.copytree(
                f"{utility_cache.get_value(f"all-current-root-project-full-path")}/workspace/public/target/projects/filesystem",
                f"{utility_cache.get_value(f"all-current-root-project-full-path")}/{project_name}",
                dirs_exist_ok=True
            )
            utility_logger.log_info(f"copying 'projects' file system to '{project_name}' file system - complete")


            utility_logger.log_info(f"copying '{project_name}' file system to '{project_name}' file system - start")
            shutil.copytree(
                f"{utility_cache.get_value(f"all-current-root-project-full-path")}/workspace/public/target/{project_name}/filesystem",
                f"{utility_cache.get_value(f"all-current-root-project-full-path")}/{project_name}",
                dirs_exist_ok=True
            )
            utility_logger.log_info(f"copying '{project_name}' file system to '{project_name}' file system - complete")


        utility_logger.log_info(f"copying 'all' file system to '.' file system - start")
        shutil.copytree(
            f"{utility_cache.get_value(f"all-current-root-project-full-path")}/workspace/public/target/all/filesystem",
            f"{utility_cache.get_value(f"all-current-root-project-full-path")}",
            dirs_exist_ok=True
        )
        utility_logger.log_info(f"copying 'all' file system to '.' file system - complete")


        utility_logger.log_info(f"copying 'root' file system to '.' file system - start")
        shutil.copytree(
            f"{utility_cache.get_value(f"all-current-root-project-full-path")}/workspace/public/target/root/filesystem",
            f"{utility_cache.get_value(f"all-current-root-project-full-path")}",
            dirs_exist_ok=True
        )
        utility_logger.log_info(f"copying 'root' file system to '.' file system - complete")


        utility_logger.log_info("complete")


all_handler = Handler()
