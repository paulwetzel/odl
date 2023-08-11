import ctypes
import numpy as np
import random
import os
from pathlib import Path

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
    curr_dir = os.path.dirname(os.path.abspath(__file__))
    clib_main = ctypes.CDLL(os.path.join(curr_dir, 'core', 'c', 'main.so'))
    clib_zscore = ctypes.CDLL(os.path.join(curr_dir, 'core', 'c', 'zscore.so'))

    return clib_main, clib_zscore

def compute_mean(list_object, clib, core={"c", "python"}, method={"arithmetic"}):
    """
    
    """
    
    if core == "c":
        # The c core will be used for processing
        data_flat = [val for sublist in list_object for val in sublist]
        data_array = (ctypes.c_float * len(data_flat))(*data_flat)

        rows = len(list_object)
        cols = len(list_object[0])
        mean = clib.compute_mean(data_array, rows, cols)
    elif core == "python":
        # The python core will be used for processing
        mean = np.mean(list_object)
    else:
        raise ValueError("Wrong core inserted, must be either c or python")
    
    return mean

def zscore_detection(list_object):
    """
    
    
    """
    clib_main, clib_utils = init_base_functions()
    prepared_list = prepare_list(list_object=list_object)
    mean = compute_mean(list_object=prepared_list, clib=clib_main, core="c", method="arithmetic")
    print(mean)

def create_random_point_set(x_dim, y_dim, num_points, cluster):
    """
    This function will generate a set of random x,y coordinates useful for testing

    Args:
        x_dim (Tuple): For specifying the x interval which the final result will have. [first_x, last_x]
        y_dim (Tuple): For specifying the y interval which the final result fwill have. Same as above
        num_points (Integer): How many points will be generated
        cluster (True/False): Should the reuslting data be in clusters
    
    Returns:
        coordiantes (List od Tuples): 
    """
    x1, x2 = x_dim
    y1, y2 = y_dim
    coordinates = []
    if cluster:
        clusters = random.randint(1, 3)  # Generate 1 to 3 clusters
        points_per_cluster = num_points // clusters
        
        for _ in range(clusters):
            cluster_x = random.uniform(x1, x2)
            cluster_y = random.uniform(y1, y2)
            
            cluster_std_dev = 2 + random.uniform(-0.2, 0.2)  # Adjusted standard deviation
            
            for _ in range(points_per_cluster):
                random_x = random.gauss(cluster_x, cluster_std_dev)
                random_y = random.gauss(cluster_y, cluster_std_dev)
                coordinates.append([random_x, random_y])
    else:
        for _ in range(num_points):
            random_x = random.uniform(x1, x2)
            random_y = random.uniform(y1, y2)
            coordinates.append([random_x, random_y])
    
    return coordinates

data = create_random_point_set(x_dim=[0, 100], y_dim=[0, 100], num_points=50, cluster=True)
zscore_detection(data)
