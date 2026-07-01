import argparse
from library import handler_manager, value_cache_storage_manager, log_manager


def handle_manager_callback():
    cli_parser = argparse.ArgumentParser(
        description="'cache.view' command",
        epilog="...",
    )
    cli_parser.add_argument(
        "-t",
        "--target",
        help="target",
        dest="target",
        default="value-cache",
        choices={
            "all",
            "value-cache"
        },
    )
    cli_arguments = cli_parser.parse_args()


    if cli_arguments.target == "all":
        handle_target_value_cache()

    elif cli_arguments.target == "value-cache":
        handle_target_value_cache()

    else:
        handler_manager.singleton.handle_cli_argument_set_invalid(
            cli_arguments
        )


def handle_target_value_cache():
    string_output = ""
    for key, value in value_cache_storage_manager.singleton.collection.items():
        string_output += f"- {key}: {value}\n"

    log_manager.singleton.log_info(
        string_output
    )


handler_manager.singleton.handle(
    handle_manager_callback
)


