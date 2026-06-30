import os
import shlex
import subprocess
from collections.abc import Sequence
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
            raise ValueError("command cannot be empty")

        if isinstance(command, str):
            command = shlex.split(command)
            
        elif not isinstance(command, Sequence):
            raise TypeError("command must be a string or a sequence")

        return subprocess.run(
            command,
            check=True,
            text=True,
            encoding="utf-8",
        )


singleton = SystemManager()

# def execute_command(
#     self,
#     command,
# ):
#     if not command:
#         raise Exception("command cannot be empty")

#     result = subprocess.run(
#         command.split(),
#         check=True,
#         capture_output=True,
#         text=True,
#         encoding="utf-8",
#     )

#     return result.stdout.strip()