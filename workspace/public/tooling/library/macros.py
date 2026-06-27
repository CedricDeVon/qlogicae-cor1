import re

from library import value_cache
from library.target_cache_value import TargetCacheValue


class Macros:
    def __init__(self):
        self.pattern = re.compile(
            r"\{\{\s*([A-Za-z0-9._-]+)\s*\}\}"
        )

    def resolve(
        key,
        values,
        cache,
        stack
    ):
        if key in cache:
            return cache[key]

        if key in stack:
            raise ValueError(
                f"Circular reference detected: {key}"
            )

        stack.add(key)

        value = values[key]

        def replace(match: re.Match) -> str:
            referenced_key = match.group(1)

            if referenced_key not in values:
                raise KeyError(
                    f"Unknown template: {referenced_key}"
                )

            return resolve(
                referenced_key,
                values,
                cache,
                stack
            )

        resolved = self.pattern.sub(
            replace,
            value
        )

        stack.remove(key)

        cache[key] = resolved

        return resolved

    def parse(text, resolved):
        def replace(match: re.Match):
            key = match.group(1)
            return resolved.get(key, match.group(0))

        return self.pattern.sub(replace, text)


singleton = Macros()

