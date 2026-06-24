import os
import json
import shutil
from pathlib import Path

from all.cache import cache
from all.logger import logger


logger.log_info("start")

cache.set_value(
    "all-full-current-root-project-path",
    Path(__file__).resolve().parent.parent.parent.parent.parent
)
cache.set_value(
    "all-full-previous-cli-path",
    Path.cwd()
)
os.chdir(
    cache.get_value("all-full-current-root-project-path")    
)
cache.set_value(
    "all-full-current-cli-path",
    cache.get_value("all-full-current-root-project-path")
)



cache.set_value(
    "all-full-devops-public-configuration-settings-path",
    f"{cache.get_value("all-full-current-root-project-path")}/devops/public/configuration/settings.json"
)

cache.set_value(
    "all-full-devops-private-configurations-settings-path",
    f"{cache.get_value("all-full-current-root-project-path")}/devops/private/configuration/settings.json"
)

with open(
    cache.get_value("all-full-devops-public-configuration-settings-path"),
    "r",
    encoding="utf-8"
) as file:
    cache.set_value(
        "all-devops-public-configuration-settings-data",
        json.load(file)
    )

with open(
    cache.get_value("all-full-devops-private-configurations-settings-path"),
    "r",
    encoding="utf-8"
) as file:
    cache.set_value(
        "all-devops-private-configuration-settings-data",
        json.load(file)
    )

cache.set_value(
    "all-developing-projects",
    cache.get_value(
        "all-devops-public-configuration-settings-data"
    ).get("all", {}).get("developing-projects", {})
)


all_project_data = {}

for project_name in cache.get_value("all-developing-projects"):
    all_project_data[project_name] = {
        "full-path": f"{cache.get_value("all-full-current-root-project-path")}/{project_name}"
    }

cache.set_value(
    "all-developing-project-data",
    all_project_data
)


cache.set_value(
    "all-full-devops-public-target-all-filesystem-path",
    f"{cache.get_value("all-full-current-root-project-path")}/devops/public/target/all/filesystem"
)


logger.log_info("complete")
    