import os
import subprocess
from pathlib import Path


class SystemManager:
    def change_cli_filesystem_path(
        self,
        value,
    ):
        path = Path(value).expanduser().resolve()

        if not path.exists():
            raise Exception(
                f"directory '{path}' does not exist.",
            )

        if not path.is_dir():
            raise Exception(
                f"'{path}' is not a directory.",
            )

        os.chdir(path)

    def execute_command(
        self,
        command,
    ):
        if not command:
            raise Exception("command cannot be empty")

        result = subprocess.run(
            command,
            check=True,
            capture_output=True,
            text=True,
            encoding="utf-8",
        )

        return result.stdout.strip()


singleton = SystemManager()
