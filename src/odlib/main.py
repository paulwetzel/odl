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

    return clib_main, clib_utils

def prepare_list(list_object, clib_to_use):
    """
    Prepare a python type list for sending it to a c function

    When calling functions that are originally written in C, one can't simply pass a python list,
    as datastructures in c remain much more strict. THis function takes in a list, alternativly np.array() will
    work as well, and converts it into a format that will make it usable for a c function acessed by ctypes.

    Args:
        list_object (list or np.array): List of elements that should be converted 
        clib_to_use (CDLL type object): CDLL that the list will be passed to

    Returns:
        c_list (ctypes.c): List ready to pass to a c function   
    """

    c_list = (ctypes.c_float * len(list_object))(*list_object)
    clib_to_use.process


