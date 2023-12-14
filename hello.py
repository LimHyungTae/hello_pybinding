#!/usr/bin/env python3

from hello import Test
import numpy as np

if __name__ == '__main__':
    Test.hello_world()
    Test.hello_name("Enguerrand")

    Test.hello_list(np.array([
        1, 2, 3, 4
    ]))

    obj = Test.Person("Guillaume", 20)
    Test.hello_obj(obj)

    print(Test.get_2_names())
