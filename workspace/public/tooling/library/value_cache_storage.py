
class ValueCacheStorage:
    collection = {}

    def __init__(self):
        self.collection = {}

    def is_key_found(self, key):
        return key in self.collection

    def get_one_value(self, key):
        return self.collection[key]

    def set_one_value(self, key, value):
        self.collection[key] = value

        return True

    def remove_one_value(self, key):
        del collection[key]

        return True

    def clear_all_values(self):
        self.collection.clear()

        return True

    def display_one_item(self, key):
        print(f"{key}: {self.collection[key]}")
        
        return True

    def display_all_items(self):
        for key, value in self.collection.items():
            self.display_one_item(key)

        return True


singleton = ValueCacheStorage()
