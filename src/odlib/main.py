import ctypes

__version__ = "0.0.1"

def init_base_functions():
    """
    Initializes base functions from corresponding .so files

    This library makes use of an underlying c core to improve computation time and allow a more efficient runtime
    as opposed to pure python usage. 

    Args:
        None
    
    Returns:
        
    """
    clib_main = ctypes.CDLL("src/odlib/core/main.so")
    clib_utils = ctypes.CDLL("src/odlib/core/main.so")
