import argparse
from library import handler_manager, value_cache_storage_manager, log_manager


def handle_manager_callback():
    cli_parser = argparse.ArgumentParser(
        description="'run.cache.view' command",
        epilog="...",
    )
    cli_parser.add_argument(
        "-t",
        "--target",
        help="target",
        dest="target",
        default="value-cache",
        choices={
            "value-cache"
        },
    )
    cli_arguments = cli_parser.parse_args()


    if cli_arguments.target == "value-cache":
        string_output = ""
        for key, value in value_cache_storage_manager.singleton.collection.items():
            string_output += f"- {key}: {value}\n"

        log_manager.singleton.log_info(
            string_output
        )

    else:
        log_manager.singleton.log_info(
            f"'{cli_arguments}' is not an existing cli option set"
        )


handler_manager.singleton.handle(
    handle_manager_callback
)


