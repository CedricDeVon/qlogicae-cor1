import time
import logging

from all.timestamp import timestamp


class LogFormat(logging.Formatter):
    def format(
        self,
        record: logging.LogRecord
    ) -> str:
        timestamp_nanoseconds = time.time_ns()

        return (
            f"[{timestamp.generate_standard_timestamp()}] "
            f"[{record.pathname}:{record.funcName}():{record.lineno}] "
            f"[{record.levelname}] - "
            f"{record.getMessage()}"
        )

