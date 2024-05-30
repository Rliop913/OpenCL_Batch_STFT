import os
import glob
Code_Base:str = "Code_Base/"
Project_Base:str = "Project_Base/"

def TUI_TEXTS(pname:str):
    return """
---------------------------------------------------
-KLPDS VERSION TEST                               -
"""+"LOADED PROJECT ==>"+pname+"""
-                                                 -
-                                                 -
---------------------------------------------------
-MANAGE TOOLS                                     -
-ADD_CODE=>create new code                        -
-M1=>create new feature branch for current project-
-M2=>delete feature branch for current project    -
-M3=>show feature branch for current project      -
-S1=>Daemon update time setting                   -
-QQ=>Quit Daemon and interface                    -
---------------------------------------------------
"""


class interface_manager:
    def __init__(self):
        self.show_projects()
        self.project_name = self.open_project(input("Target Project Name: "))
    
    def fill_values(self, u_time, ppath):
        self.utime=u_time
        self.prpath=ppath

    def show_tui(self):
        print(TUI_TEXTS((os.path.splitext(os.path.basename(self.project_name)))[-2]))


    def show_projects(self):
        print("Please Load Your Project\n")
        pl = glob.glob(Project_Base + "*")
        for i in pl:
            i = os.path.splitext(os.path.basename(i))
            print(i[-2])

    def open_project(self, project_name:str):
        Project_Data_Location = Project_Base + project_name + ".txt"
        if not os.path.exists(Project_Data_Location):
            pd = open(Project_Data_Location, "w")
            pd.write(input("Making New Project. Input Group Name: "))
            pd.close()
        return Project_Data_Location

    def interface_loop(self):
        while(True):
            self.show_tui()
            command = input("ENTER COMMAND: ")
            if command == "QQ":
                break
            if command == "S1":
                self.utime.value = float(input("Enter new update_time"))
            




def add_project_mode(mode_name:str):
    pass

def show_project_modes():
    pass

def delete_current_project(name:str) -> bool:
    
    pass






