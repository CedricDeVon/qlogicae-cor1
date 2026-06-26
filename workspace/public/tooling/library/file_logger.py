import queue
import logging
from pathlib import Path
from logging.handlers import (
    QueueHandler,
    QueueListener
)

from library.log_format import LogFormat
from library.log_options import LogOptions


class FileLogger:
    def __init__(self):
        self.logger = logging.getLogger(
            "file-logger"
        )

        self.logger.setLevel(
            logging.DEBUG
        )

        self.logger.propagate = False

        self.logger.handlers.clear()

        self.file_handlers = {}

        self.log_queue = (
            queue.Queue()
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

    def log(
        self,
        message,
        options=LogOptions()
    ):
        if (
            not options.is_enabled
        ):
            return message

        self.logger.log(
            options.log_level,
            message,
            stacklevel=options.stack_level
        )

        return message

    def log_debug(
        self,
        message,
        options=LogOptions(
            log_level=logging.DEBUG
        )
    ):
        return self.log(
            message,
            options
        )

    def log_info(
        self,
        message,
        options=LogOptions(
            log_level=logging.INFO
        )
    ):
        return self.log(
            message,
            options
        )

    def log_warning(
        self,
        message,
        options=LogOptions(
            log_level=logging.WARNING
        )
    ):
        return self.log(
            message,
            options
        )

    def log_error(
        self,
        message,
        options=LogOptions(
            log_level=logging.ERROR
        )
    ):
        return self.log(
            message,
            options
        )

    def log_critical(
        self,
        message,
        options=LogOptions(
            log_level=logging.CRITICAL
        )
    ):
        return self.log(
            message,
            options
        )

    def rebuild_listener(
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

        return True

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

        handler = (
            logging.FileHandler(
                path,
                encoding="utf-8"
            )
        )

        handler.setFormatter(
            LogFormat()
        )

        self.file_handlers[path] = (
            handler
        )

        self.rebuild_listener()

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

        handler.close()

        del self.file_handlers[
            path
        ]

        self.rebuild_listener()

        return True

    def clear_file_outputs(
        self
    ):
        for handler in (
            self.file_handlers.values()
        ):
            handler.close()

        self.file_handlers.clear()

        self.rebuild_listener()

        return True

    def shutdown(
        self
    ):
        self.listener.stop()

        for handler in (
            self.file_handlers.values()
        ):
            handler.close()

        self.file_handlers.clear()

        return True


singleton = FileLogger()

