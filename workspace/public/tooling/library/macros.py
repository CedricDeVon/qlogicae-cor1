import re


class Macros:
    def __init__(self):
        self.pattern = re.compile(r"\{\{\s*([A-Za-z0-9._-]+)\s*\}\}")

    def resolve_many(self, values):
        cache = {}

        return {
            key: self.resolve_one(key, values, cache, set()) for key in values
        }

    def resolve_one(self, key, values, cache, stack):
        if key in cache:
            return cache[key]

        if key in stack:
            raise Exception(f"Circular reference detected: {key}")

        if key not in values:
            raise Exception(f"Unknown template: {key}")

        stack.add(key)

        value = values[key]

        if not isinstance(value, str):
            cache[key] = value
            stack.remove(key)
            return value

        def handle_parse_one(match):
            referenced_key = match.group(1)

            return self.resolve_one(referenced_key, values, cache, stack)

        resolved = self.pattern.sub(handle_parse_one, value)

        stack.remove(key)

        cache[key] = resolved

        return resolved

    def parse_many(self, values, resolved):
        return self.parse_one(values, resolved)

    def parse_one(self, value, resolved):
        if isinstance(value, str):
            return self.pattern.sub(
                lambda match: resolved.get(match.group(1), match.group(0)),
                value,
            )

        if isinstance(value, dict):
            return {
                key: self.parse_one(child, resolved)
                for key, child in value.items()
            }

        if isinstance(value, list):
            return [self.parse_one(child, resolved) for child in value]

        if isinstance(value, tuple):
            return tuple(self.parse_one(child, resolved) for child in value)

        if isinstance(value, set):
            return {self.parse_one(child, resolved) for child in value}

        return value


singleton = Macros()
