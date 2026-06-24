import os
import shutil
from pathlib import Path

import all.setup
from all.cache import cache
from all.logger import logger

logger.log_info("start")

for project_name, project_data in cache.get_value("all-developing-project-data").items():
    logger.log_info(f"copying 'all' file system to '{project_name}' file system - start")
    shutil.copytree(
        cache.get_value("all-full-devops-public-target-all-filesystem-path"),
        project_data["full-path"],
        dirs_exist_ok=True
    )
    logger.log_info(f"copying 'all' file system to '{project_name}' file system - complete")

logger.log_info(f"copying 'all' file system to '.' file system - start")
shutil.copytree(
    cache.get_value("all-full-devops-public-target-all-filesystem-path"),
    ".",
    dirs_exist_ok=True
)
logger.log_info(f"copying 'all' file system to '.' file system - complete")

logger.log_info("complete")

