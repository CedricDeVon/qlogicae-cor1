import os
import subprocess
from pathlib import Path

from all.utility import cache

# Recommended Devops path
cache["filesystem-1"] = Path(__file__).resolve().parent.parent.parent.parent.parent # root devops path
os.chdir(cache["filesystem-1"])

cache["filesystem-2"] = Path.cwd() # absolute cmd path

print(cache["filesystem-1"])
print(cache["filesystem-2"])

# Cache Validation
# for key, value in cache.items():
#     print(f"{key} {value}")


# import json

# with open(
#     "config.json",
#     "r",
#     encoding="utf-8"
# ) as file:
#     data = json.load(file)

# print(data)




# import argparse

# parser = argparse.ArgumentParser()

# parser.add_argument(
#     "--sub-project",
#     choices=[
#         "all",
#     ],
#     nargs="+",
#     default=[
#         "all"
#     ],
# )

# arguments = parser.parse_args()

# print(arguments)

# import shutil

# alias = {
#     "relative-all-filesystem": "./.project/private/target/all/filesystem"
# }

# shutil.copytree(
#     alias["relative-all-filesystem"],
#     ".",
#     dirs_exist_ok=True
# )

# shutil.copytree(
#     alias["relative-all-filesystem"],
#     "./typescript",
#     dirs_exist_ok=True
# )


# import os
# import subprocess
# from pathlib import Path

# print(subprocess.check_output(
#     ["pwd"],
#     text=True
# ))



