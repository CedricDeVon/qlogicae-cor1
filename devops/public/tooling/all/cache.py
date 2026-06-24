from all.logger import logger

class Cache:
    data = {}

    def __init__(self):
        self.data = {}

    def get_value(self, key):
        if key not in self.data:
            logger.log_error("Key not found in 'Cache'")

            raise Exception()

        return self.data[key]


    def set_value(self, key, value):
        self.data[key] = value

        return True


    def remove_value(self, key):
        if key not in self.data:
            logger.log_error("Key not found in 'Cache'")

            raise Exception()

        del data[key]

        return True


    def view_values(self):
        for key, value in self.data.items():
            print(f"{key}: {value}")

        return True


cache = Cache()
