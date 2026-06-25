import os
import json
import shutil
import subprocess
from pathlib import Path

from utility.logger import utility_logger
from utility.cache import utility_cache


class Handler:
    def handle_setup(self):
        utility_logger.log_info("start")


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


        # # Workspace Log File
        utility_cache.set_value(
            "all-workspace-private-log-all-full-path",
            f"{utility_cache.get_value("all-current-root-project-full-path")}/workspace/private/log/all.log"
        )
        utility_logger.add_file_output(
            utility_cache.get_value("all-workspace-private-log-all-full-path")
        )


        utility_logger.log_info("complete")

    def handle_shutdown(self):
        utility_logger.log_info("start")

        utility_logger.shutdown()

        utility_logger.log_info("complete")

        
utility_handler = Handler()
