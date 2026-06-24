import os
import json
import shutil
from pathlib import Path

from all.cache import cache
from all.logger import logger


class Utility:
    def handle_setup(self):
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
            "all-full-devops-private-log-all-path",
            f"{cache.get_value("all-full-current-root-project-path")}/devops/private/log/all.log"
        )

        logger.add_file_output(
            cache.get_value("all-full-devops-private-log-all-path")
        )


        logger.log_info("start")

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


        cache.set_value(
            "all-developing-project-data",
            {
                project_name: {
                    "full-path": (
                        f"{cache.get_value('all-full-current-root-project-path')}"
                        f"/{project_name}"
                    )
                }
                for project_name in cache.get_value(
                    "all-developing-projects"
                )
            }
        )


        cache.set_value(
            "all-full-devops-public-target-all-filesystem-path",
            f"{cache.get_value("all-full-current-root-project-path")}/devops/public/target/all/filesystem"
        )

        logger.log_info("complete")

    def handle_shutdown(self):
        logger.shutdown()

    def handle_debug(self):
        self.handle_setup();

        cache.view_values()

        self.handle_shutdown()

    def handle_filesystem_setup(self):
        self.handle_setup();

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

        self.handle_shutdown();


utility = Utility()
