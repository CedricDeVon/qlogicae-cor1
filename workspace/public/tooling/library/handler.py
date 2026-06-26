import os
import json
import shutil
import subprocess
from pathlib import Path

import yaml

from library.target_cache_value import TargetCacheValue
from library import logger, filesystem, file_logger, value_cache


class Handler:
    def handle_setup(self):
        # Essential File System Paths
        value_cache.singleton.set_one_value(
            "all-current-root-project-full-path",
            Path(__file__).resolve().parent.parent.parent.parent.parent,
            target_cache_value=TargetCacheValue.FOLDER_PATH
        )
        

        value_cache.singleton.set_one_value(
            "all-original-cli-full-path",
            Path.cwd(),
            target_cache_value=TargetCacheValue.FOLDER_PATH
        )
        value_cache.singleton.set_one_value(
            "all-current-cli-full-path",
            value_cache.singleton.get_one_value(
                "all-current-root-project-full-path",
                target_cache_value=TargetCacheValue.FOLDER_PATH
            ),
            target_cache_value=TargetCacheValue.FOLDER_PATH
        )
        os.chdir(
            value_cache.singleton.get_one_value(
                "all-current-root-project-full-path",
                target_cache_value=TargetCacheValue.FOLDER_PATH
            )            
        )


        # Workspace Log File
        value_cache.singleton.set_one_value(
            "all-workspace-private-log-all-full-path",
            f"{value_cache.singleton.get_one_value(
                "all-current-root-project-full-path",
                target_cache_value=TargetCacheValue.FOLDER_PATH
            )}/workspace/private/temporary/log/all.log"
        )
        file_logger.singleton.add_file_output(
            value_cache.singleton.get_one_value(
                "all-workspace-private-log-all-full-path"
            )
        )


        # Configurations
        value_cache.singleton.set_one_value(
            "all-workspace-public-configuration-settings-full-path",        
            f"{value_cache.singleton.get_one_value(
                "all-current-root-project-full-path",
                target_cache_value=TargetCacheValue.FOLDER_PATH
            )}/workspace/public/configuration/setting.yaml",
            target_cache_value=TargetCacheValue.FILE_PATH
        )
        value_cache.singleton.set_one_value(
            "all-workspace-private-configuration-settings-full-path",
            f"{value_cache.singleton.get_one_value(
                "all-current-root-project-full-path",
                target_cache_value=TargetCacheValue.FOLDER_PATH
            )}/workspace/private/configuration/setting.yaml",
            target_cache_value=TargetCacheValue.FILE_PATH
        )

        with open(
            value_cache.singleton.get_one_value(
                "all-workspace-public-configuration-settings-full-path",
                target_cache_value=TargetCacheValue.FILE_PATH
            ),
            "r",
            encoding="utf-8"
        ) as file:
            value_cache.singleton.set_one_value(
                "all-workspace-public-configuration-settings-data",
                yaml.safe_load(file),
                target_cache_value=TargetCacheValue.DEFINED
            )

        with open(
            value_cache.singleton.get_one_value(
                "all-workspace-private-configuration-settings-full-path",
                target_cache_value=TargetCacheValue.FILE_PATH
            ),
            "r",
            encoding="utf-8"
        ) as file:
            value_cache.singleton.set_one_value(
                "all-workspace-private-configuration-settings-data",
                yaml.safe_load(file),
                target_cache_value=TargetCacheValue.DEFINED
            )        


        value_cache.singleton.set_one_value(
            "all-workspace-projects",
            value_cache.singleton.get_one_value(
                "all-workspace-public-configuration-settings-data",
                target_cache_value=TargetCacheValue.DEFINED
            )["all"]["workspace-projects"],
            target_cache_value=TargetCacheValue.DEFINED
        )   

    def handle_shutdown(self):
        logger.singleton.shutdown()

        
singleton = Handler()
