from all.utility import all_utility
from typescript.utility import typescript_utility


all_utility.handle_setup()
typescript_utility.handle_setup()

all_utility.handle_verify_tools()
typescript_utility.handle_verify_tools()

typescript_utility.handle_shutdown()
all_utility.handle_shutdown();
