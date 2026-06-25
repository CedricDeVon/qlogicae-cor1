import subprocess

from all.handler import all_handler
from utility.logger import utility_logger


all_handler.handle_setup()


utility_logger.log_info(f"start")
utility_logger.log_info(f"Docker: {subprocess.check_output(
    ["docker", "--version"],
    text=True
).strip()}")
utility_logger.log_info(f"Git: {subprocess.check_output(
    ["git", "--version"],
    text=True
).strip()}")
utility_logger.log_info(f"GitHub CLI: {subprocess.check_output(
    ["gh", "--version"],
    text=True
).strip()}")
utility_logger.log_info(f"complete")


all_handler.handle_shutdown()

