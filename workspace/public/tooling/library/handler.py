import re
import os
import json
import shutil
import subprocess
from pathlib import Path

import yaml

from library.target_cache_value import TargetCacheValue
from library import logger, filesystem, file_logger, value_cache, macros


class Handler:
    def handle_setup(self):
        # Essential File System Paths
        value_cache.singleton.set_one_value(
            "root-current-full-path",
            Path(__file__).resolve().parent.parent.parent.parent.parent,
            target_cache_value=TargetCacheValue.FOLDER_PATH
        )
        
        value_cache.singleton.set_one_value(
            "root-original-console-full-path",
            Path.cwd(),
            target_cache_value=TargetCacheValue.FOLDER_PATH
        )
        value_cache.singleton.set_one_value(
            "root-previous-console-full-path",
            value_cache.singleton.get_one_value(
                "root-original-console-full-path",
                target_cache_value=TargetCacheValue.FOLDER_PATH
            ),
            target_cache_value=TargetCacheValue.FOLDER_PATH
        )
        value_cache.singleton.set_one_value(
            "root-current-console-full-path",
            value_cache.singleton.get_one_value(
                "root-current-full-path",
                target_cache_value=TargetCacheValue.FOLDER_PATH
            ),
            target_cache_value=TargetCacheValue.FOLDER_PATH
        )
        os.chdir(
            value_cache.singleton.get_one_value(
                "root-current-full-path",
                target_cache_value=TargetCacheValue.FOLDER_PATH
            )            
        )


        value_cache.singleton.set_one_value(
            "root-workspace/private/temporary/log/all.log-full-path",
            f"{value_cache.singleton.get_one_value(
                "root-current-full-path",
                target_cache_value=TargetCacheValue.FOLDER_PATH
            )}/workspace/private/temporary/log/all.log"
        )
        file_logger.singleton.add_file_output(
            value_cache.singleton.get_one_value(
                "root-workspace/private/temporary/log/all.log-full-path"
            )
        )

        for scope_name in ["private", "public"]:            
            for configuration_file in Path(
                f"{value_cache.singleton.get_one_value(
                    "root-current-full-path",
                    target_cache_value=TargetCacheValue.FOLDER_PATH
                )}/workspace/{scope_name}/configuration"            
            ).iterdir():
                if not configuration_file.is_file():
                    continue
                                
                raw = {}
                data = {}
                metadata = {}
                
                with open(configuration_file.resolve(), "r", encoding="utf-8"
                ) as current_file:
                    if any(suffix in {".yaml", ".yml"} for suffix in configuration_file.suffixes):
                        raw = yaml.safe_load(current_file) or {}    
                    
                    elif any(suffix in {".json"} for suffix in configuration_file.suffixes):
                        raw = json.load(current_file) or {}

                    else:
                        raw = current_file.read() or {}

                    value_cache.singleton.set_one_value(
                        f"root-workspace/{scope_name}/configuration/{configuration_file.name}-raw",
                        ({} if raw is None else raw) or {},
                        target_cache_value=TargetCacheValue.ANY
                    )
                    value_cache.singleton.set_one_value(
                        f"root-workspace/{scope_name}/configuration/{configuration_file.name}-data",
                        ({} if not "data" in raw else raw["data"]) or {},
                        target_cache_value=TargetCacheValue.ANY
                    )
                    value_cache.singleton.set_one_value(
                        f"root-workspace/{scope_name}/configuration/{configuration_file.name}-metadata",
                        ({} if not "metadata" in raw else raw["metadata"]) or {},
                        target_cache_value=TargetCacheValue.ANY
                    )
                    value_cache.singleton.set_one_value(
                        f"root-workspace/{scope_name}/configuration/{configuration_file.name}-full-path",
                        configuration_file.resolve(),
                        target_cache_value=TargetCacheValue.FILE_PATH                        
                    )               


        # Parsed
        value_cache.singleton.set_one_value(
            "root-selection-full-path",
            f"{value_cache.singleton.get_one_value(
                "root-current-full-path",
                target_cache_value=TargetCacheValue.DEFINED
            )}/selection",
            target_cache_value=TargetCacheValue.DEFINED
        )
        value_cache.singleton.set_one_value(
            "project-selections",
            value_cache.singleton.get_one_value(
                "root-workspace/public/configuration/settings.yaml-data",
                target_cache_value=TargetCacheValue.DEFINED
            )["project"]["selections"],
            target_cache_value=TargetCacheValue.DEFINED
        )
        value_cache.singleton.set_one_value(
            "project-selections",
            value_cache.singleton.get_one_value(
                "root-workspace/public/configuration/settings.yaml-data",
                target_cache_value=TargetCacheValue.DEFINED
            )["project"]["selections"],
            target_cache_value=TargetCacheValue.DEFINED
        )
        value_cache.singleton.set_one_value(
            "all-value-cache-macros",
            value_cache.singleton.get_one_value(
                "root-workspace/public/configuration/settings.yaml-data",
                target_cache_value=TargetCacheValue.DEFINED
            )["all"]["value-cache-macros"],
            target_cache_value=TargetCacheValue.DEFINED
        )
            

        value_cache.singleton.set_one_value(
            "all-macros",
            macros.singleton.resolve_many(
                {
                    key: f"{value_cache.singleton.get_one_value(
                        key,
                        target_cache_value=TargetCacheValue.FOLDER_PATH
                    )}"
                    for key in value_cache.singleton.get_one_value(
                        "all-value-cache-macros",
                        target_cache_value=TargetCacheValue.DEFINED
                    )
                } |
                value_cache.singleton.get_one_value(
                    "root-workspace/private/configuration/macros.yaml-data",
                    target_cache_value=TargetCacheValue.DEFINED
                ) |
                value_cache.singleton.get_one_value(
                    "root-workspace/public/configuration/macros.yaml-data",
                    target_cache_value=TargetCacheValue.DEFINED
                )
            ),
            target_cache_value=TargetCacheValue.DEFINED
        )

    def handle_shutdown(self):
        logger.singleton.shutdown()


        
singleton = Handler()
