import time
import inspect
import logging
from datetime import datetime, UTC


class LogFormat(logging.Formatter):
    def format(
        self,
        record: logging.LogRecord
    ) -> str:
        timestamp_nanoseconds = time.time_ns()

        return (
            f"[{(
            f"{datetime.fromtimestamp(
                timestamp_nanoseconds /
                1_000_000_000,
                UTC
            ):%Y-%m-%dT%H:%M:%S}"
            f".{timestamp_nanoseconds % 1_000_000_000:09d}"
            "Z"
        )}] "
            f"[{record.pathname}:{record.funcName}():{record.lineno}] "
            f"[{record.levelname}] - "
            f"{record.getMessage()}"
        )

