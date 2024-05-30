import os
import multiprocessing
import time
from . import Lint
from . import Preprocessor



class Daemon:
    def __init__(self, life_switch, up_time):
        while life_switch.value:
            self.Observe()
            print("Daemon_working")
            time.sleep(up_time.value)
    
    def Observe(self):
        pass

def spawn_daemon(life_switch:multiprocessing.Value, update_time):
    dm = Daemon(life_switch, update_time)