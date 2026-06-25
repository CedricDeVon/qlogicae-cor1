import os
import json
import shutil
import subprocess
from pathlib import Path

from all.cache import cache
from all.logger import logger


class Utility:
    def handle_setup(self):
        logger.log_info("'typescript' setup - start")

        logger.log_info("'typescript' setup - complete")

    def handle_shutdown(self):
        logger.log_info("'typescript' shutdown - start")

        logger.log_info("'typescript' shutdown - complete")

    def handle_verify_tools(self):
        logger.log_info(f"'typescript' verifying tools - start")

        os.chdir(
            f"{cache.get_value(
                "all-current-root-project-full-path"
            )}/typescript"
        )

        logger.log_info(f"Node: {subprocess.check_output(
            ["node", "--version"],
            text=True
        ).strip()}")
        logger.log_info(f"FNM: {subprocess.check_output(
            ["fnm", "--version"],
            text=True
        ).strip()}")
        logger.log_info(f"NPM: {subprocess.check_output(
            ["npm", "--version"],
            text=True
        ).strip()}")
        logger.log_info(f"Bun: {subprocess.check_output(
            ["bun", "--version"],
            text=True
        ).strip()}")
        logger.log_info(f"Corepack: {subprocess.check_output(
            ["bunx", "corepack", "--version"],
            text=True
        ).strip()}")
        logger.log_info(f"PNPM: {subprocess.check_output(
            ["bunx", "pnpm", "--version"],
            text=True
        ).strip()}")
        logger.log_info(f"Yarn: {subprocess.check_output(
            ["bunx", "yarn", "--version"],
            text=True
        ).strip()}")

        os.chdir(
            f"{cache.get_value(
                "all-current-root-project-full-path"
            )}"
        )

        logger.log_info(f"'typescript' verifying tools - complete")


typescript_utility = Utility()

