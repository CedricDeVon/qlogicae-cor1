import logging
from pathlib import Path

from all.log_format import LogFormat


class Logger:
    def __init__(self):
        self.logger = logging.getLogger()

        self.logger.setLevel(
            logging.DEBUG
        )

        self.file_handlers = {}

        handler = logging.StreamHandler()

        handler.setFormatter(
            LogFormat()
        )

        self.logger.addHandler(
            handler
        )


    def add_file_output(
        self,
        file_path
    ):
        path = Path(
            file_path
        ).resolve()

        if path in self.file_handlers:
            return False

        path.parent.mkdir(
            parents=True,
            exist_ok=True
        )

        handler = logging.FileHandler(
            path,
            encoding="utf-8"
        )

        handler.setFormatter(
            LogFormat()
        )

        self.logger.addHandler(
            handler
        )

        self.file_handlers[path] = handler

        return True

    def remove_file_output(
        self,
        file_path
    ):
        path = Path(
            file_path
        ).resolve()

        handler = self.file_handlers.get(
            path
        )

        if handler is None:
            return False

        self.logger.removeHandler(
            handler
        )

        handler.close()

        del self.file_handlers[path]

        return True

    def clear_file_outputs(
        self
    ):
        for handler in (
            self.file_handlers.values()
        ):
            self.logger.removeHandler(
                handler
            )

            handler.close()

        self.file_handlers.clear()

        return True

    def log_debug(
        self,
        message,
        stack_level=2
    ):
        self.logger.debug(message, stacklevel=stack_level)

    def log_info(
        self,
        message,
        stack_level=2
    ):
        self.logger.info(message, stacklevel=stack_level)

    def log_warning(
        self,
        message,
        stack_level=3
    ):
        self.logger.warning(message, stacklevel=stack_level)

    def log_error(
        self,
        message,
        stack_level=3
    ):
        self.logger.error(message, stacklevel=stack_level)

    def log_critical(
        self,
        message,
        stack_level=3
    ):
        self.logger.critical(message, stacklevel=stack_level)


logger = Logger()
