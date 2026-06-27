import os
import argparse
import subprocess

from library import logger, handler, value_cache


def handle_all_target_option():
    handle_root_target_option();
    handle_typescript_target_option();


def handle_root_target_option():
    logger.singleton.log_info(f"Docker: {subprocess.check_output(
        ["docker", "--version"],
        text=True
    ).strip()}")
    logger.singleton.log_info(f"Git: {subprocess.check_output(
        ["git", "--version"],
        text=True
    ).strip()}")
    logger.singleton.log_info(f"GitHub CLI: {subprocess.check_output(
        ["gh", "--version"],
        text=True
    ).strip()}")


def handle_typescript_target_option():
    os.chdir(
        f"{value_cache.singleton.get_one_value(
            "all-current-root-project-full-path"
        )}/typescript"
    )
    logger.singleton.log_info(f"Node: {subprocess.check_output(
        ["node", "--version"],
        text=True
    ).strip()}")
    logger.singleton.log_info(f"FNM: {subprocess.check_output(
        ["fnm", "--version"],
        text=True
    ).strip()}")
    logger.singleton.log_info(f"NPM: {subprocess.check_output(
        ["npm", "--version"],
        text=True
    ).strip()}")
    logger.singleton.log_info(f"Bun: {subprocess.check_output(
        ["bun", "--version"],
        text=True
    ).strip()}")
    logger.singleton.log_info(f"Corepack: {subprocess.check_output(
        ["bunx", "corepack", "--version"],
        text=True
    ).strip()}")
    logger.singleton.log_info(f"PNPM: {subprocess.check_output(
        ["bunx", "pnpm", "--version"],
        text=True
    ).strip()}")
    logger.singleton.log_info(f"Yarn: {subprocess.check_output(
        ["bunx", "yarn", "--version"],
        text=True
    ).strip()}")
    os.chdir(
        f"{value_cache.singleton.get_one_value(
            "all-current-root-project-full-path"
        )}"
    )


cli_parser = argparse.ArgumentParser()

cli_parser.add_argument(
    "--target",
    default="all"
)

cli_arguments = cli_parser.parse_args()

handler.singleton.handle_setup()

if "all" in cli_arguments.target:
    handle_all_target_option()

elif "root" in cli_arguments.target:
    handle_root_target_option();

elif "typescript" in cli_arguments.target:
    handle_typescript_target_option();


handler.singleton.handle_shutdown()

