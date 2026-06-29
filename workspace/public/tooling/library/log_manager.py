import logging

from library import console_log_manager, file_log_manager
from library.log_options import LogOptions


class LogManager:
    def log(
        self,
        message,
        console_options=LogOptions(is_verbose=False),
        file_options=LogOptions(),
    ):
        console_log_manager.singleton.log(
            message,
            LogOptions(
                is_enabled=console_options.is_enabled,
                is_verbose=console_options.is_verbose,
                log_level=console_options.log_level,
                stack_level=console_options.stack_level + 1,
            ),
        )

        file_log_manager.singleton.log(
            message,
            LogOptions(
                is_enabled=file_options.is_enabled,
                is_verbose=file_options.is_verbose,
                log_level=file_options.log_level,
                stack_level=file_options.stack_level + 1,
            ),
        )

        return message

    def log_debug(
        self,
        message,
        console_options=LogOptions(log_level=logging.DEBUG, is_verbose=False),
        file_options=LogOptions(log_level=logging.DEBUG),
    ):
        return self.log(message, console_options, file_options)

    def log_info(
        self,
        message,
        console_options=LogOptions(log_level=logging.INFO, is_verbose=False),
        file_options=LogOptions(log_level=logging.INFO),
    ):
        return self.log(message, console_options, file_options)

    def log_warning(
        self,
        message,
        console_options=LogOptions(log_level=logging.WARNING, is_verbose=False),
        file_options=LogOptions(log_level=logging.WARNING),
    ):
        return self.log(message, console_options, file_options)

    def log_error(
        self,
        message,
        console_options=LogOptions(log_level=logging.ERROR, is_verbose=False),
        file_options=LogOptions(log_level=logging.ERROR),
    ):
        return self.log(message, console_options, file_options)

    def log_critical(
        self,
        message,
        console_options=LogOptions(
            log_level=logging.CRITICAL, is_verbose=False
        ),
        file_options=LogOptions(log_level=logging.CRITICAL),
    ):
        return self.log(message, console_options, file_options)

    def shutdown(self):
        file_log_manager.singleton.shutdown()

        return True


singleton = LogManager()
