import script_base.Daemon as daem
import script_base.Project_Interface as ppi
import multiprocessing as mp

def main():
    interface = ppi.interface_manager()
    dctx = mp.get_context('spawn')
    daemon_lifeswitch = dctx.Value('b', True)
    daemon_update_time = dctx.Value('f', 1.0)
    daemon_task = dctx.Process(target=daem.spawn_daemon, args=(daemon_lifeswitch, daemon_update_time))
    daemon_task.start()
    interface.interface_loop()
    daemon_lifeswitch.value = False
    daemon_task.join()

if __name__ == '__main__':
    main()