import time
import logging

from library import timestamp


class LogFormat(logging.Formatter):
    def format(
        self,
        record: logging.LogRecord
    ):
        return (
            f"[ {timestamp.singleton.generate_standard_timestamp()} ] "
            f"[ {record.levelname} ] "
            f"{record.getMessage()}"
        )

