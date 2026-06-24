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

# print(subprocess.check_output(
#     ["pwd"],
#     text=True
# ))

# os.chdir("./.project/private/tooling")

# print(subprocess.check_output(
#     ["pwd"],
#     text=True
# ))
