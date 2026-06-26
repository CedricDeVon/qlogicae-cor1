
from utility.cache import utility_cache
from utility.logger import utility_logger
from utility.handler import utility_handler
from utility.file_logger import utility_file_logger

utility_handler.handle_setup()

utility_cache.view_values()
utility_logger.log_info("Hello")

utility_handler.handle_shutdown()

