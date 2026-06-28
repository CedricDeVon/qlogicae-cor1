from library import filesystem, value_cache_storage
from library.target_cache_value import TargetCacheValue


class ValueCache:
    def is_key_found(self, keys):
        return value_cache_storage.singleton.is_key_found(keys)

    def get_one_value(self, keys, target_cache_value=TargetCacheValue.DEFINED):
        self.throw_if_key_not_found(keys)

        value = value_cache_storage.singleton.get_one_value(keys)
        self.throw_if_value_is_explicitly_invalid(value, target_cache_value)

        return value

    def set_one_value(
        self, keys, value, target_cache_value=TargetCacheValue.DEFINED
    ):
        self.throw_if_value_is_explicitly_invalid(value, target_cache_value)

        return value_cache_storage.singleton.set_one_value(keys, value)

    def remove_one_value(self, keys):
        self.throw_if_key_not_found(keys)

        return value_cache_storage.singleton.remove_one_value(keys)

    def clear_all_values(self):
        return value_cache_storage.singleton.clear_all_values()

    def display_all_items(self):
        return value_cache_storage.singleton.display_all_items()

    def throw_if_value_is_explicitly_invalid(
        self, value, target_cache_value=TargetCacheValue.DEFINED
    ):
        match target_cache_value:
            case TargetCacheValue.FILESYSTEM_PATH:
                return filesystem.singleton.throw_if_filesystem_path_invalid(
                    value
                )

            case TargetCacheValue.FILE_PATH:
                return filesystem.singleton.throw_if_file_path_invalid(value)

            case TargetCacheValue.FOLDER_PATH:
                return filesystem.singleton.throw_if_folder_path_invalid(value)

            case TargetCacheValue.DEFINED:
                return self.throw_if_undefined(value)

            case _:
                return False

        return False

    def throw_if_key_not_found(self, keys):
        if not value_cache_storage.singleton.is_key_found(keys):
            raise Exception(f"key path '{keys}' does not exist")

        return False

    def throw_if_undefined(self, value):
        if value is None:
            raise Exception("value is not defined")

        return False


singleton = ValueCache()
