import time
import logging

from utility.timestamp import utility_timestamp


class LogFormat(logging.Formatter):
    def format(
        self,
        record: logging.LogRecord
    ):
        return (
            f"[{utility_timestamp.generate_standard_timestamp()}] "
            # f"[{record.pathname}:{record.funcName}():{record.lineno}] "
            f"[{record.levelname}] | "
            f"{record.getMessage()}"
        )

