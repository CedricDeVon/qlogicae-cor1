from utility.logger import utility_logger
from utility.filesystem import utility_filesystem


class Cache:
    data = {}

    def __init__(self):
        self.data = {}

    def get_value(self, key):
        if key not in self.data:
            utility_logger.log_error(f"Key '{key}' not found")

            raise Exception()

        return self.data[key]


    def set_value(self, key, value):
        self.data[key] = value

        return True

    def set_filesystem_path_value(self, key, value):
        utility_filesystem.is_filesystem_path_valid(value)

        self.data[key] = value

        return True

    def set_file_path_value(self, key, value):
        utility_filesystem.is_file_path_valid(value)

        self.data[key] = value

        return True

    def set_folder_path_value(self, key, value):
        utility_filesystem.is_folder_path_valid(value)

        self.data[key] = value

        return True

    def remove_value(self, key):
        if key not in self.data:
            utility_logger.log_error(f"Key '{key}' not found")

            raise Exception()

        del data[key]

        return True


    def view_values(self):
        for key, value in self.data.items():
            print(f"{key}: {value}")

        return True


utility_cache = Cache()
