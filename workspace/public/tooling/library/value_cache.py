from library.target_cache_value import TargetCacheValue
from library import filesystem, value_cache_storage, logger


class ValueCache:
    def is_key_found(self, key):
        return value_cache_storage.singleton.is_key_found(key)

    def get_one_value(self, key, target_cache_value=TargetCacheValue.DEFINED):
        self.throw_if_key_not_found(key)

        value = value_cache_storage.singleton.get_one_value(key)
        self.throw_if_value_is_explicitly_invalid(value, target_cache_value)

        return value

    def set_one_value(self, key, value, target_cache_value=TargetCacheValue.DEFINED):
        self.throw_if_value_is_explicitly_invalid(value, target_cache_value)

        return value_cache_storage.singleton.set_one_value(key, value)

    def remove_one_value(self, key):    
        self.throw_if_key_not_found(key)

        return value_cache_storage.singleton.remove_one_value(key)

    def clear_all_values(self):
        return value_cache_storage.singleton.clear_all_values()

    def display_all_items(self):
        return value_cache_storage.singleton.display_all_items()

    def throw_if_value_is_explicitly_invalid(self, value, target_cache_value=TargetCacheValue.DEFINED):
        match target_cache_value:    
            case TargetCacheValue.FILESYSTEM_PATH:                
                return filesystem.singleton.throw_if_filesystem_path_invalid(value)
                
            case TargetCacheValue.FILE_PATH:                
                return filesystem.singleton.throw_if_file_path_invalid(value)

            case TargetCacheValue.FOLDER_PATH:                
                return filesystem.singleton.throw_if_folder_path_invalid(value)

            case TargetCacheValue.DEFINED:                
                return self.throw_if_undefined(value)

            case _:
                return False

        return False

    def throw_if_key_not_found(self, key):
        if not value_cache_storage.singleton.is_key_found(key):
            raise Exception(
                f"Key '{key}' does not exist"
            )

        return False

    def throw_if_undefined(self, value):
        if value is None:
            raise Exception(
                f"Value is not defined"
            )

        return False


singleton = ValueCache()
