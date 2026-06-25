import queue
import logging
import asyncio
from pathlib import Path
from logging.handlers import (
    QueueHandler,
    QueueListener
)

from utility.log_format import LogFormat


class Logger:
    def __init__(self):
        self.logger = logging.getLogger(
            "all"
        )

        self.logger.setLevel(
            logging.DEBUG
        )

        self.logger.propagate = False

        self.file_handlers = {}

        self.log_queue = queue.Queue()

        self.stream_handler = (
            logging.StreamHandler()
        )

        self.stream_handler.setFormatter(
            LogFormat()
        )

        self.logger.handlers.clear()

        self.logger.addHandler(
            self.stream_handler
        )

        self.queue_handler = (
            QueueHandler(
                self.log_queue
            )
        )

        self.logger.addHandler(
            self.queue_handler
        )

        self.listener = (
            QueueListener(
                self.log_queue
            )
        )

        self.listener.start()

    def _rebuild_listener(
        self
    ):
        self.listener.stop()

        self.listener = (
            QueueListener(
                self.log_queue,
                *self.file_handlers.values()
            )
        )

        self.listener.start()

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

        self.file_handlers[path] = (
            handler
        )

        self._rebuild_listener()

        return True

    def remove_file_output(
        self,
        file_path
    ):
        path = Path(
            file_path
        ).resolve()

        handler = (
            self.file_handlers.get(
                path
            )
        )

        if handler is None:
            return False

        handler.close()

        del self.file_handlers[path]

        self._rebuild_listener()

        return True

    def clear_file_outputs(
        self
    ):
        for handler in (
            self.file_handlers.values()
        ):
            handler.close()

        self.file_handlers.clear()

        self._rebuild_listener()

        return True

    def shutdown(
        self
    ):
        self.listener.stop()

        for handler in (
            self.file_handlers.values()
        ):
            handler.close()

    def log_debug(
        self,
        message,
        stack_level=2
    ):
        self.logger.debug(
            message,
            stacklevel=stack_level
        )

    def log_info(
        self,
        message,
        stack_level=2
    ):
        self.logger.info(
            message,
            stacklevel=stack_level
        )

    def log_warning(
        self,
        message,
        stack_level=2
    ):
        self.logger.warning(
            message,
            stacklevel=stack_level
        )

    def log_error(
        self,
        message,
        stack_level=2
    ):
        self.logger.error(
            message,
            stacklevel=stack_level
        )

    def log_critical(
        self,
        message,
        stack_level=2
    ):
        self.logger.critical(
            message,
            stacklevel=stack_level
        )


utility_logger = Logger()

