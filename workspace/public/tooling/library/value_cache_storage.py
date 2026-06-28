class ValueCacheStorage:
    collection = {}

    def __init__(self):
        self.collection = {}

    def is_key_found(self, keys):
        if not keys:
            return False

        cache = self.collection

        for key in keys:
            if isinstance(cache, dict):
                if key not in cache:
                    return False

            elif isinstance(cache, (list, tuple)):
                if not isinstance(key, int):
                    return False

                if key < 0 or key >= len(cache):
                    return False

            else:
                return False

            cache = cache[key]

        return True

    def get_one_value(self, keys):
        if not keys:
            raise ValueError("'keys' cannot be empty")

        cache = self.collection

        for key in keys:
            if isinstance(cache, dict):
                if key not in cache:
                    raise KeyError(f"key '{key}' not found")

            elif isinstance(cache, (list, tuple)):
                if not isinstance(key, int):
                    raise TypeError(f"'{type(key).__name__}' is not an integer")

                if key < 0 or key >= len(cache):
                    raise IndexError(f"index '{key}' is out of range")

            else:
                raise TypeError(
                    f"cannot traverse into '{type(cache).__name__}'"
                )

            cache = cache[key]

        return cache

    def set_one_value(
        self,
        keys,
        value,
        create_missing=True,
    ):
        if not keys:
            raise ValueError("'keys' cannot be empty")

        cache = self.collection

        for key in keys[:-1]:
            if isinstance(cache, dict):
                if key not in cache:
                    if not create_missing:
                        raise KeyError(f"key '{key}' not found")

                    cache[key] = {}

                elif not isinstance(cache[key], (dict, list)):
                    raise TypeError(
                        f"key '{key}' does not reference a dictionary or list"
                    )

                cache = cache[key]

            elif isinstance(cache, list):
                if not isinstance(key, int):
                    raise TypeError(
                        f"expected an index, got '{type(key).__name__}'"
                    )

                if key < 0 or key >= len(cache):
                    raise IndexError(f"index '{key}' is out of range")

                cache = cache[key]

            else:
                raise TypeError(
                    f"cannot traverse into '{type(cache).__name__}'"
                )

        last = keys[-1]

        if isinstance(cache, dict):
            cache[last] = value

        elif isinstance(cache, list):
            if not isinstance(last, int):
                raise TypeError(f"expected an index, got {type(last).__name__}")

            if last < 0 or last >= len(cache):
                raise IndexError(f"index '{last}' is out of range")

            cache[last] = value

        else:
            raise TypeError("Destination is neither a dictionary nor a list")

    def remove_one_value(self, keys):
        if not keys:
            raise ValueError("keys cannot be empty")

        cache = self.collection

        for key in keys[:-1]:
            if isinstance(cache, dict):
                if key not in cache:
                    raise KeyError(f"key '{key}' not found")

            elif isinstance(cache, list):
                if not isinstance(key, int):
                    raise TypeError(
                        f"expected an index, got {type(key).__name__}"
                    )

                if key < 0 or key >= len(cache):
                    raise IndexError(f"index '{key}' is out of range")

            else:
                raise TypeError(
                    f"cannot traverse into '{type(cache).__name__}'"
                )

            cache = cache[key]

        last = keys[-1]

        if isinstance(cache, dict):
            try:
                del cache[last]
            except KeyError:
                raise KeyError(f"key '{last}' not found") from None

        elif isinstance(cache, list):
            if not isinstance(last, int):
                raise TypeError(f"expected an index, got {type(last).__name__}")

            if last < 0 or last >= len(cache):
                raise IndexError(f"index '{last}' is out of range")

            del cache[last]

        else:
            raise TypeError("destination is neither a dictionary nor a list")

    def clear_all_values(self):
        self.collection.clear()

        return True

    def display_one_item(self, key):
        print(f"{key}: {self.collection[key]}")

        return True

    def display_all_items(self):
        for item in self.collection.items():
            self.display_one_item(item[0])

        return True


singleton = ValueCacheStorage()
