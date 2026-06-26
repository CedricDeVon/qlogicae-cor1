
class Cache:
    data = {}

    def __init__(self):
        self.data = {}

    def get_value(self, key):
        if key not in self.data:            
            raise Exception(
                f"Key '{key}' not found"
            )

        return self.data[key]


    def set_value(self, key, value):
        self.data[key] = value

        return True

    def remove_value(self, key):
        if key not in self.data:
            raise Exception(
                f"Key '{key}' not found"
            )

        del data[key]

        return True


    def view_values(self):
        for key, value in self.data.items():
            print(f"{key}: {value}")

        return True


utility_cache = Cache()
