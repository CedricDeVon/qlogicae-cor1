import shutil
from pathlib import Path

from utility.logger import utility_logger


class FileSystem:
    def is_filesystem_path_valid(self, value):
        path = Path(
            value
        )

        if not path.exists():
            utility_logger.log_error(f"Path '{path}' is invalid")

            raise Exception()

    def is_file_path_valid(self, value):
        path = Path(
            value
        )

        if not path.is_file():
            utility_logger.log_error(f"File '{path}' is invalid")

            raise Exception()

    def is_folder_path_valid(self, value):
        path = Path(
            value
        )

        if not path.is_dir():
            utility_logger.log_error(f"Folder '{path}' is invalid")

            raise Exception()

    def copy_paste(self, items):
        pass


utility_filesystem = FileSystem()

