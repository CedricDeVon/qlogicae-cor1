import argparse
from library import handler_manager, value_cache_manager


def handle_manager_callback():
    cli_parser = argparse.ArgumentParser(
        description="debug tool",
        epilog="...",
    )

    cli_parser.add_argument(
        "-t",
        "--target",
        help="target",
        dest="target",
        default="cache",
        choices={
            "cache"
        },
    )

    cli_arguments = cli_parser.parse_args()

    if cli_arguments.target == "cache":
        value_cache_manager.singleton.display_all_items()


handler_manager.singleton.handle(
    handle_manager_callback
)
