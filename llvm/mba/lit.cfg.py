import lit.formats
import os
from lit.llvm import llvm_config

config.name = 'MBA'
config.test_format = lit.formats.ShTest(True)
config.suffixes = ['.c']
config.excludes = ['input', 'CMakeLists.txt', 'README.txt', 'LICENSE.txt', 'lit.cfg.py']
config.test_source_root = os.path.dirname(__file__)
config.test_exec_root = os.path.join(config.mba_obj_root, 'mba')

llvm_config.with_environment('PATH', [
    config.llvm_tools_dir
], append_path=True)
