import os
import traceback
from importlib import util


class Base:
    """
    Basic resource class. Concrete resources will inherit from this one
    """
    plugins = []

    # For every class that inherits from the current,
    # the class name will be added to pluings
    def __init_subclass__(cls, **kwargs):
        super().__init_subclass__(**kwargs)
        cls.plugins.append(cls)


# Small utility to automatically load modules
def load_module(path):
    print("*** load_module ***")
    name = os.path.split(path)[-1]
    # print(name, path)
    spec = util.spec_from_file_location(name, path)
    # print(spec)
    module = util.module_from_spec(spec)
    # print(module)
    spec.loader.exec_module(module)
    # print(spec)
    return module


print("base.py is working")
# Get current path
path = os.path.abspath(__file__)
dirpath = os.path.dirname(path)
print(path, dirpath)

for fname in os.listdir(dirpath):
    # Load only "real modules"
    if not fname.startswith('.') and \
        not fname.startswith('__') and fname.endswith('.py'):
        try:
            load_module(os.path.join(dirpath, fname))
        except Exception:
            traceback.print_exc()
