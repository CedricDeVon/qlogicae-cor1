import json
from pathlib import Path

import yaml

from library import (
    file_log_manager,
    filesystem_manager,
    log_manager,
    macros_manager,
    system_manager,
    value_cache_manager,
)
from library.target_cache_value import TargetCacheValue


class HandlerManager:
    def handle_setup(self):
        value_cache_manager.singleton.set_one_value(
            ["root-current-full-path"],
            filesystem_manager.singleton.get_root_workspace_folder(),
            target_cache_value=TargetCacheValue.FOLDER_PATH,
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
                        target_cache_value=TargetCacheValue.DEFINED,
                    )
                    value_cache_manager.singleton.set_one_value(
                        [
                            f"root-workspace/{scope_name}/configuration/{configuration_file.name}-full-path"
                        ],
                        configuration_file.resolve(),
                        target_cache_value=TargetCacheValue.FILE_PATH,
                    )
                

        value_cache_manager.singleton.set_one_value(
            ["all-workspace-default-targets"],
            set(
                value_cache_manager.singleton.get_one_value(
                    [
                        f"root-workspace/public/configuration/workspace.yaml-raw",
                        "data",
                        "all",
                        "selection",
                        "default",
                        "targets",
                    ],
                    target_cache_value=TargetCacheValue.ANY,
                )
                or []
            ),
        )

        value_cache_manager.singleton.set_one_value(
            ["all-workspace-project-targets"],
            set(
                value_cache_manager.singleton.get_one_value(
                    [
                        f"root-workspace/public/configuration/workspace.yaml-raw",
                        "data",
                        "all",
                        "selection",
                        "project",
                        "targets",
                    ],
                    target_cache_value=TargetCacheValue.ANY,
                )
                or []
            ),
        )

        value_cache_manager.singleton.set_one_value(
            ["all-workspace-targets"],
            set(
                value_cache_manager.singleton.get_one_value(
                    [
                        "all-workspace-default-targets"
                    ],
                    target_cache_value=TargetCacheValue.ANY,
                )
                or []
            ) | set(
                value_cache_manager.singleton.get_one_value(
                    [
                        "all-workspace-project-targets"
                    ],
                    target_cache_value=TargetCacheValue.ANY,
                )
                or []
            )
        )        

        value_cache_manager.singleton.set_one_value(
            ["all-workspace-target"],
            value_cache_manager.singleton.get_one_value(
                [
                    f"root-workspace/public/configuration/workspace.yaml-raw",
                    "data",
                    "all",
                    "selection",
                    "target",
                ],
                target_cache_value=TargetCacheValue.ANY,
            )
        )

        value_cache_manager.singleton.set_one_value(
            ["all-macros"],
            macros_manager.singleton.resolve_many(
                {
                    key: f"{
                        value_cache_manager.singleton.get_one_value(
                            [key],
                            target_cache_value=TargetCacheValue.DEFINED,
                        )
                    }"
                    for key in (
                        value_cache_manager.singleton.get_one_value(
                            [
                                f"root-workspace/private/configuration/workspace.yaml-raw",
                                "data",
                                "all",
                                "macros",
                                "value-cache",
                            ],
                            target_cache_value=TargetCacheValue.ANY,
                        )
                        or []
                    )
                    + (
                        value_cache_manager.singleton.get_one_value(
                            [
                                f"root-workspace/public/configuration/workspace.yaml-raw",
                                "data",
                                "all",
                                "macros",
                                "value-cache",
                            ],
                            target_cache_value=TargetCacheValue.ANY,
                        )
                        or []
                    )
                }
                | (
                    value_cache_manager.singleton.get_one_value(
                        [
                            f"root-workspace/private/configuration/workspace.yaml-raw",
                            "data",
                            "all",
                            "macros",
                            "file",
                        ],
                        target_cache_value=TargetCacheValue.ANY,
                    )
                    or {}
                )
                | (
                    value_cache_manager.singleton.get_one_value(
                        [
                            f"root-workspace/public/configuration/workspace.yaml-raw",
                            "data",
                            "all",
                            "macros",
                            "file",
                        ],
                        target_cache_value=TargetCacheValue.ANY,
                    ) or {}
                )
            ) or {},
            target_cache_value=TargetCacheValue.ANY,
        )        

        value_cache_manager.singleton.set_one_value(
            ["all-clean-exclude-targets"],
            {
                macros_manager.singleton.parse_one(
                    value,
                    (value_cache_manager.singleton.get_one_value(
                        [
                            f"all-macros",
                        ],
                        target_cache_value=TargetCacheValue.ANY,
                    ) or {})
                ) for value in
                (value_cache_manager.singleton.get_one_value(
                    [
                        f"root-workspace/public/configuration/workspace.yaml-raw",
                        "data",
                        "all",
                        "clean",
                        "exclude",
                        "targets",
                    ],
                    target_cache_value=TargetCacheValue.ANY,
                ) or [])
            },
        )

        value_cache_manager.singleton.set_one_value(
            ["all-clean-include-targets"],
            {
                value for value in
                (value_cache_manager.singleton.get_one_value(
                    [
                        f"root-workspace/public/configuration/workspace.yaml-raw",
                        "data",
                        "all",
                        "clean",
                        "include",
                        "targets",
                    ],
                    target_cache_value=TargetCacheValue.ANY,
                ) or {})
            },
        )

        value_cache_manager.singleton.set_one_value(
            ["root-workspace/private/temporary/log/all.log-full-path"],
            f"{
                value_cache_manager.singleton.get_one_value(
                    ["root-current-full-path"],
                    target_cache_value=TargetCacheValue.DEFINED,
                )
            }/workspace/private/temporary/log/all.log",
            target_cache_value=TargetCacheValue.DEFINED
        )

        file_log_manager.singleton.add_file_output(
            value_cache_manager.singleton.get_one_value(
                ["root-workspace/private/temporary/log/all.log-full-path"],
                target_cache_value=TargetCacheValue.DEFINED,
            )
        )


    def handle_shutdown(self):
        log_manager.singleton.shutdown()

    def handle(self, callback):
        self.handle_setup()

        callback()

        self.handle_shutdown()


singleton = HandlerManager()
