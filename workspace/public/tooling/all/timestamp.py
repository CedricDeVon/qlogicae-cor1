import time
from datetime import datetime, UTC


class TimeStamp:
    def generate_standard_timestamp(self):
        timestamp_nanoseconds = time.time_ns()

        return (
            f"{(
            f"{datetime.fromtimestamp(
                timestamp_nanoseconds /
                1_000_000_000,
                UTC
            ):%Y-%m-%dT%H:%M:%S}"
            f".{timestamp_nanoseconds % 1_000_000_000:09d}"
            "Z"
        )}")

        
timestamp = TimeStamp()

