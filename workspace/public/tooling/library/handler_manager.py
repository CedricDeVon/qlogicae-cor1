import json
from pathlib import Path

import yaml

from library import file_log_manager, filesystem_manager, log_manager, macros_manager, system_manager, value_cache_manager
from library.target_cache_value import TargetCacheValue


class HandlerManager:
    def handle_setup(self):
        value_cache_manager.singleton.set_one_value(
            ["root-current-full-path"],
            filesystem_manager.singleton.get_root_workspace_folder(),
            target_cache_value=TargetCacheValue.FOLDER_PATH,
        )
        value_cache_manager.singleton.set_one_value(
            ["root-selection-full-path"],
            f"{
                value_cache_manager.singleton.get_one_value(
                    ['root-current-full-path'],
                    target_cache_value=TargetCacheValue.DEFINED,
                )
            }/selection",
            target_cache_value=TargetCacheValue.DEFINED,
        )
        value_cache_manager.singleton.set_one_value(
            ["root-original-console-full-path"],
            Path.cwd(),
            target_cache_value=TargetCacheValue.FOLDER_PATH,
        )
        value_cache_manager.singleton.set_one_value(
            ["root-previous-console-full-path"],
            value_cache_manager.singleton.get_one_value(
                ["root-original-console-full-path"],
                target_cache_value=TargetCacheValue.FOLDER_PATH,
            ),
            target_cache_value=TargetCacheValue.FOLDER_PATH,
        )
        value_cache_manager.singleton.set_one_value(
            ["root-current-console-full-path"],
            value_cache_manager.singleton.get_one_value(
                ["root-current-full-path"],
                target_cache_value=TargetCacheValue.FOLDER_PATH,
            ),
            target_cache_value=TargetCacheValue.FOLDER_PATH,
        )
        system_manager.singleton.change_cli_filesystem_path(
            value_cache_manager.singleton.get_one_value(
                ["root-current-full-path"],
                target_cache_value=TargetCacheValue.FOLDER_PATH,
            )
        )
        value_cache_manager.singleton.set_one_value(
            ["root-workspace/private/temporary/log/all.log-full-path"],
            f"{
                value_cache_manager.singleton.get_one_value(
                    ['root-current-full-path'],
                    target_cache_value=TargetCacheValue.FOLDER_PATH,
                )
            }/workspace/private/temporary/log/all.log",
        )

        for scope_name in ["private", "public"]:
            for configuration_file in Path(
                f"{
                    value_cache_manager.singleton.get_one_value(
                        ['root-current-full-path'],
                        target_cache_value=TargetCacheValue.FOLDER_PATH,
                    )
                }/workspace/{scope_name}/configuration"
            ).iterdir():
                if not configuration_file.is_file():
                    continue

                raw = {}

                with open(
                    configuration_file.resolve(),
                    # "r",
                    encoding="utf-8",
                ) as current_file:
                    if any(
                        suffix in {".yaml", ".yml"}
                        for suffix in configuration_file.suffixes
                    ):
                        raw = yaml.safe_load(current_file) or {}

                    elif any(
                        suffix in {".json"}
                        for suffix in configuration_file.suffixes
                    ):
                        raw = json.load(current_file) or {}

                    else:
                        raw = current_file.read() or {}

                    value_cache_manager.singleton.set_one_value(
                        [
                            f"root-workspace/{scope_name}/configuration/{configuration_file.name}-raw"
                        ],
                        ({} if raw is None else raw) or {},
                        target_cache_value=TargetCacheValue.ANY,
                    )
                    value_cache_manager.singleton.set_one_value(
                        [
                            f"root-workspace/{scope_name}/configuration/{configuration_file.name}-data"
                        ],
                        ({} if "data" not in raw else raw["data"]) or {},
                        target_cache_value=TargetCacheValue.ANY,
                    )
                    value_cache_manager.singleton.set_one_value(
                        [
                            f"root-workspace/{scope_name}/configuration/{configuration_file.name}-metadata"
                        ],
                        ({} if "metadata" not in raw else raw["metadata"]) or {},
                        target_cache_value=TargetCacheValue.ANY,
                    )
                    value_cache_manager.singleton.set_one_value(
                        [
                            f"root-workspace/{scope_name}/configuration/{configuration_file.name}-full-path"
                        ],
                        configuration_file.resolve(),
                        target_cache_value=TargetCacheValue.FILE_PATH,
                    )
                    
        value_cache_manager.singleton.set_one_value(
            ["all-macros"],
            macros_manager.singleton.resolve_many(
                {
                    key: f"{
                        value_cache_manager.singleton.get_one_value(
                            [key],
                            target_cache_value=TargetCacheValue.FOLDER_PATH,
                        )
                    }"
                    for key in (value_cache_manager.singleton.get_one_value(
                        [
                            f"root-workspace/private/configuration/workspace.yaml-data",
                            "all",
                            "macros",
                            "value-cache",
                        ],
                        target_cache_value=TargetCacheValue.ANY,
                    ) or [])
                    + (value_cache_manager.singleton.get_one_value(
                        [
                            f"root-workspace/public/configuration/workspace.yaml-data",
                            "all",
                            "macros",
                            "value-cache",
                        ],
                        target_cache_value=TargetCacheValue.ANY,
                    ) or [])
                }
                | (value_cache_manager.singleton.get_one_value(
                    [
                        f"root-workspace/private/configuration/workspace.yaml-data",
                        "all",
                        "macros",
                        "file",
                    ],
                    target_cache_value=TargetCacheValue.ANY,
                ) or {})
                | (value_cache_manager.singleton.get_one_value(
                    [
                        f"root-workspace/public/configuration/workspace.yaml-data",
                        "all",
                        "macros",
                        "file",
                    ],
                    target_cache_value=TargetCacheValue.ANY,
                ) or {})
            ) or {},
            target_cache_value=TargetCacheValue.ANY,
        )

    def handle_shutdown(self):
        log_manager.singleton.shutdown()


singleton = HandlerManager()
