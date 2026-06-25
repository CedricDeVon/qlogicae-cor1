import shutil
from pathlib import Path

from all.logger import logger


class FileSystem:
    def __init__(self):
        pass

    def is_filesystem_path_valid(self, value):
        path = Path(
            value
        )

        if not path.exists():
            logger.log_error(f"Path '{path}' is invalid")

            raise Exception()

    def is_file_path_valid(self, value):
        path = Path(
            value
        )

        if not path.is_file():
            logger.log_error(f"File '{path}' is invalid")

            raise Exception()

    def is_folder_path_valid(self, value):
        path = Path(
            value
        )

        if not path.is_dir():
            logger.log_error(f"Folder '{path}' is invalid")

            raise Exception()


filesystem = FileSystem()

