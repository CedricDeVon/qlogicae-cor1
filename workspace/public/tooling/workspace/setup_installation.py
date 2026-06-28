import argparse
import os
import subprocess

from library import handler, logger, value_cache
from library.target_cache_value import TargetCacheValue


def handle_all_target_option():
    handle_typescript_target_option()


def handle_typescript_target_option():
    os.chdir(
        f"{
            value_cache.singleton.get_one_value(
                'root-current-full-path',
                target_cache_value=TargetCacheValue.FOLDER_PATH,
            )
        }/selection/typescript"
    )
    logger.singleton.log_info(
        f"{subprocess.check_output(['bun', 'install'], text=True).strip()}"
    )
    os.chdir(
        f"{
            value_cache.singleton.get_one_value(
                'root-current-full-path',
                target_cache_value=TargetCacheValue.FOLDER_PATH,
            )
        }"
    )


cli_parser = argparse.ArgumentParser()

cli_parser.add_argument("--target", default="all")
cli_arguments = cli_parser.parse_args()

handler.singleton.handle_setup()

if "all" in cli_arguments.target:
    handle_all_target_option()

elif "typescript" in cli_arguments.target:
    handle_typescript_target_option()

handler.singleton.handle_shutdown()
