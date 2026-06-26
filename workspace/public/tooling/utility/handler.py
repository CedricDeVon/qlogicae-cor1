import os
import json
import shutil
import subprocess
from pathlib import Path

import yaml

from utility.cache import utility_cache
from utility.logger import utility_logger
from utility.filesystem import utility_filesystem
from utility.file_logger import utility_file_logger


class Handler:
    def handle_setup(self):
        # Essential File System Paths
        utility_cache.set_value(
            "all-current-root-project-full-path",
            utility_filesystem.validate_folder_path(
                Path(__file__).resolve().parent.parent.parent.parent.parent
            )
        )
        

        utility_cache.set_value(
            "all-original-cli-full-path",
            utility_filesystem.validate_folder_path(
                Path.cwd()            
            )
        )
        utility_cache.set_value(
            "all-current-cli-full-path",
            utility_filesystem.validate_folder_path(
                utility_cache.get_value(
                    "all-current-root-project-full-path"
                )            
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
            utility_filesystem.validate_file_path(
                f"{utility_cache.get_value("all-current-root-project-full-path")}/workspace/private/temporary/log/all.log"                
            )
        )
        utility_file_logger.add_file_output(
            utility_filesystem.validate_file_path(
                utility_cache.get_value("all-workspace-private-log-all-full-path")                
            )
        )


        # Configurations
        utility_cache.set_value(
            "all-workspace-public-configuration-settings-full-path",
            utility_filesystem.validate_file_path(
                f"{utility_cache.get_value("all-current-root-project-full-path")}/workspace/public/configuration/setting.yaml"                
            )
        )
        utility_cache.set_value(
            "all-workspace-private-configuration-settings-full-path",
            utility_filesystem.validate_file_path(
                f"{utility_cache.get_value("all-current-root-project-full-path")}/workspace/private/configuration/setting.yaml"                
            )
        )

        with open(
            utility_filesystem.validate_file_path(
                utility_cache.get_value(
                    "all-workspace-public-configuration-settings-full-path"
                )   
            ),
            "r",
            encoding="utf-8"
        ) as file:
            utility_cache.set_value(
                "all-workspace-public-configuration-settings-data",
                yaml.safe_load(file)
            )

        with open(
            utility_filesystem.validate_file_path(
                utility_cache.get_value(
                    "all-workspace-private-configuration-settings-full-path"
                )   
            )            ,
            "r",
            encoding="utf-8"
        ) as file:
            utility_cache.set_value(
                "all-workspace-private-configuration-settings-data",
                yaml.safe_load(file)
            )        


        utility_cache.set_value(
            "all-workspace-projects",
            utility_cache.get_value(
                "all-workspace-public-configuration-settings-data"
            )["all"]["workspace-projects"]
        )   

    def handle_shutdown(self):
        utility_logger.shutdown()

        
utility_handler = Handler()
