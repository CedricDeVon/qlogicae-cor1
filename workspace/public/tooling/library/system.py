import subprocess


class System:
    def change_cli_filesystem_path(self, value):
        os.chdir(
            value
        )

    def execute_command(self, value):
        return subprocess.check_output(
            value.split(),
            text=True
        ).strip()


singleton = System()

