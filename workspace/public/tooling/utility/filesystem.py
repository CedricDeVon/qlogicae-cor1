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

    def clean_folder(self, path):
        directory = Path(path).resolve()

        protected_paths = {
            Path("/"),
            Path.home(),
        }

        if directory in protected_paths:
            utility_logger.log_error(f"Folder '{path}' is invalid")

            raise Exception()

        if not directory.exists():
            utility_logger.log_error(f"Folder '{path}' is invalid")

            raise Exception()

        if not directory.is_dir():
            utility_logger.log_error(f"Folder '{path}' is invalid")

            raise Exception()

        for item in directory.iterdir():
            if item.is_file() or item.is_symlink():
                item.unlink()
                
            elif item.is_dir():
                shutil.rmtree(item)


utility_filesystem = FileSystem()

