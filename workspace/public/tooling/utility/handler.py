import os
import json
import shutil
import subprocess
from pathlib import Path

from utility.cache import utility_cache
from utility.logger import utility_logger


class Handler:
    def handle_setup(self):
        # Essential File System Paths
        utility_cache.set_folder_path_value(
            "all-current-root-project-full-path",
            Path(__file__).resolve().parent.parent.parent.parent.parent
        )
        

        utility_cache.set_folder_path_value(
            "all-original-cli-full-path",
            Path.cwd()
        )
        utility_cache.set_folder_path_value(
            "all-current-cli-full-path",
            utility_cache.get_value(
                "all-current-root-project-full-path"
            )
        )
        os.chdir(
            utility_cache.get_value(
                "all-current-root-project-full-path"
            )    
        )


        # Workspace Log File
        utility_cache.set_value(
            "all-workspace-private-log-all-full-path",
            f"{utility_cache.get_value("all-current-root-project-full-path")}/workspace/private/output/log/all.log"
        )
        utility_logger.add_file_output(
            utility_cache.get_value("all-workspace-private-log-all-full-path")
        )


        # Configurations
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

    def handle_shutdown(self):
        utility_logger.shutdown()

        
utility_handler = Handler()
